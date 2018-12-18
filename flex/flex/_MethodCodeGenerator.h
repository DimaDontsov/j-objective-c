﻿#pragma once
#include <string>
#include <vector>
#include "TableFiller.h"

#include "_JVMCommands.h"

class MethodCodeGenerator : public NodeVisiter {
    
    unsigned short localVarsCount;
    string code;
    vector<JVMCommand*> commands;
    unordered_map<string, TypeInfo> localVars;
    unordered_map<string, int> localVarsNumber;
    
    JavaConstantTable* table;
    FunctionInfo* info;
	int numberCurrentRow;

    void genCode( FunctionInfo* info){
        


		this->info = info;

		if (info->functionNode->body != NULL)
			info->functionNode->body->visit(this);
    }

    void genCode( MethodInfo* info){

        this->info = info;
        

        if( info->methodType == METHOD_LOCAL)
            localVarsCount = 1;
        else localVarsCount = 0;
		localVars.clear();
		localVarsNumber.clear();
		//localVarsNumber = info->localVarsNumber;

        //localVarsCount += info->params.size();
    }

    void addCommand(JVMCommand* command) {
		numberCurrentRow += command->toBytes().size();
		commands.push_back( command );
	}

public:
    unsigned short getLocalVarsCount(){
        //return this->localVarsCount;
        return this->localVarsNumber.size(); 
    }

    void visit( StatementNode* node) override {
        if( node->stmtType == STMT_COMPOUND) {
			for (auto ichildStmt = node->childs.begin(); ichildStmt != node->childs.end(); ichildStmt++)
			{
				 auto childStmt = *ichildStmt;
				 childStmt->visit(this);
			}
        } else if( node->stmtType == STMT_ARRAY_DECL) {
            this->localVarsNumber[ node->name] = localVarsNumber.size();


        } else if( node->stmtType == STMT_VAR_DECL) {
            this->localVarsNumber[ node->name] = localVarsNumber.size();

        } else if( node->stmtType == STMT_EXPR) {
            node->expr->visit( this);
        } else if( node->stmtType == STMT_IF) {

			node->condition->left->visit(this);
			node->condition->right->visit(this);

			int ifLine = numberCurrentRow;
			int numberIfCommand = commands.size();
			addCommand( new IF_ICMP(node->condition->operationType, 0, false));

			node->truthStmt->visit(this);

			int gotoLine = 0;
			int numberGotoCommand = 0;
			if (node->wrongStmt != NULL) {
				gotoLine = numberCurrentRow;
				numberGotoCommand = commands.size();
				addCommand( new GOTO(0));
			}
			

			int shift = numberCurrentRow - ifLine;
			commands[numberIfCommand] = new IF_ICMP(node->condition->operationType, shift, false);

			if (node->wrongStmt != NULL) {
				node->wrongStmt->visit(this);

				shift = numberCurrentRow - gotoLine;
				commands[numberGotoCommand] = new GOTO(shift);
			}
			
        } else if( node->stmtType == STMT_RETURN) {
            VISIT_IF_NOT_NULL(node->expr);	
			
            if ( info->returnType.type == TYPE_VOID)
                addCommand( new VRETURN());
            else if ( info->returnType.type == TYPE_POINTER)
                addCommand( new ARETURN());
            else
                addCommand( new IRETURN());
        } else if( node->stmtType == STMT_WHILE) {
			
			int gotoLine = numberCurrentRow;
			int numberGotoCommand = commands.size();
			addCommand( new GOTO(0));

			node->truthStmt->visit(this);

			int shift = numberCurrentRow - gotoLine;
			commands[numberGotoCommand] = (new GOTO(shift));

			node->condition->left->visit(this);
			node->condition->right->visit(this);

			shift = gotoLine + 3 - numberCurrentRow;
			addCommand( new IF_ICMP(node->condition->operationType, shift, true));
        }
    }

    void visit( ExprNode* node) override {
        if ( node->exprType == EXPR_ARRAY_ELEM_CALL) {
            //if( node->returnType->childType->varType == TYPE_POINTER) throw new runtime_error(" array of objects unsupported yet");
        }
        else if ( node->exprType == EXPR_FUNC_CALL) {
            FOR_EACH( methodNode, node->methodCallArgs){
                VISIT_IF_NOT_NULL( (*methodNode));
            }
            addCommand( new INVOKE_STATIC( node->constantNum));
        }
        else if ( node->exprType == EXPR_INVAR_CALL) {

        }
        else if ( node->exprType == EXPR_METHOD_CALL) {
            
            VISIT_IF_NOT_NULL( node->object);
            FOR_EACH( methodNode, node->methodCallArgs){
                VISIT_IF_NOT_NULL( (*methodNode));
            }

            if ( node->object->returnType->varType == TYPEE_CLASS) {
                if ( node->isAlloc) {
                    int classid = table->classByMethod[ node->constantNum];
                    addCommand( new NEW( classid));
                    addCommand( new DUP());
                    addCommand( new INVOKE_SPECIAL( table->constructors[node->object->returnType->name]));
                }
                else {
                    addCommand( new INVOKE_STATIC( node->constantNum));
                }
            } else if ( node->object->returnType->varType == TYPE_POINTER) {
                

                addCommand( new INVOKE_VIRTUAL( node->constantNum));
            } else throw new runtime_error( "method call from not object (code gen)");
        }
        else if ( node->exprType == EXPR_OPERATION) {
            if( node->operationType == OP_VALUE) {
				if (node->constType == TYPE_CUSTOM) {
                    auto type = node->returnType;
					int number = localVarsNumber[node->name];
                    if ( type->varType == TYPE_INT) {
						addCommand( new ILOAD(number));
                    } else if ( type->varType == TYPE_POINTER){
                        addCommand( new ALOAD(number));
                    }
				} else if (node->constType == TYPE_INT) {
					addCommand( new SIPush(node->intVal));
                } else if ( node->constType == TYPE_STRING) {
                    addCommand( new LDC_W( table->strings[ node->strVal]));
                }
                
            } else if( node->operationType == OP_ADD) {
				node->left->visit(this);
				node->right->visit(this);
				addCommand( new IADD());
			}  else if( node->operationType == OP_SUB) {
				node->left->visit(this);
				node->right->visit(this);
				addCommand( new ISUB());
			} else if( node->operationType == OP_MUL) {
				node->left->visit(this);
				node->right->visit(this);
                addCommand( new IMUL());
            } else if( node->operationType == OP_DIV) {
				node->left->visit(this);
				node->right->visit(this);
                addCommand( new IDIV());
            } else if( node->operationType == OP_MOD) {
				node->left->visit(this);
				node->right->visit(this);
                // a % b === a - (c * b), ��� c = a / b - ����� ����� �����
				addCommand( new IREM());
			} else if( node->operationType == OP_ASSIGN) {
                node->right->visit(this);
                int number = localVarsNumber[node->left->name];
                if ( node->right->returnType->varType == TYPE_INT){
				    addCommand( new ISTORE(number));
                } else if (node->right->returnType->varType == TYPE_POINTER){
                    addCommand( new ASTORE(number)); 
                } else if ( node->right->returnType->varType == TYPE_ARRAY){
                    addCommand( new LDC_W( table->ints[ node->right->arrayElems->exprs.size()]));
                    
                    if ( node->right->returnType->childType->varType == TYPE_POINTER){
                        int classid =table->classNumByName[ node->right->returnType->childType->childType->name];
                        addCommand( new ANEW_ARRAY( classid));
                        int index = 0;
                        FOR_EACH( elem, node->right->arrayElems->exprs){
                            addCommand( new DUP());
                            addCommand( new SIPush( index));
                            index++;
                            (*elem)->visit( this);
                            addCommand( new AASTORE());
                        }
                        addCommand( new ALOAD( localVarsNumber[ node->left->name]));
                    }
                    else {

                        addCommand( new NEW_ARRAY( node->right->returnType->childType->childType->varType));
                        int index = 0;
                        FOR_EACH( elem, node->right->arrayElems->exprs){
                            addCommand( new DUP());
                            addCommand( new SIPush( index));
                            index++;
                            (*elem)->visit( this);
                            addCommand( new IASTORE());
                        }
                        addCommand( new ALOAD( localVarsNumber[ node->left->name]));
                    }
                    
                }
            } else if( node->operationType == OP_ASSIGN_ARRAY) {
                // �������� ���-�� ��� �������� �����
                FOR_EACH( elem, node->arrayElems->exprs) {
                    (*elem)->visit(this);
                }
                //node->right->visit(this);
				// ���� ������� ����� ����� ����������
				//commands.push_back( new ISTORE());
            } else if( node->operationType == OP_LESS || 
						node->operationType == OP_LESS_OR_EQUAL ||
						node->operationType == OP_GREATER ||
						node->operationType == OP_GREATER_OR_EQUAL ||
						node->operationType == OP_EQUAL ||
						node->operationType == OP_NOT_EQUAL )
			{
				/*node->left->visit(this);
				node->right->visit(this);*/
            } else if( node->operationType == OP_LOGICAL_NOT) {
                
            } else if( node->operationType == OP_AND) {
                
            } else if( node->operationType == OP_OR) {
                
            } else if( node->operationType == OP_UPLUS) {
                node->left->visit(this);
            } else if( node->operationType == OP_UMINUS) {
                addCommand( new SIPush(-1));
				node->left->visit(this);
				addCommand( new IMUL());
            } 
        }
    }


    string genCode( JavaMethodTableRecord& method, JavaConstantTable* table){
        commands.clear();
        this->table = table;
        localVars.clear();
		localVarsNumber.clear();
		//localVarsNumber = info->localVarsNumber;
		numberCurrentRow = 0;
        

        if ( method.methodInfo)
            this->genCode( method.methodInfo);
        else 
            if( method.funcInfo->isDefault){}
            else this->genCode( method.funcInfo);
        string methodCode;
        FOR_EACH( com, commands){
            methodCode += (*com)->toBytes();
        }
        return methodCode;
    }
    
};