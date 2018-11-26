#pragma once

#include <string>
#include <list>
#include "TreeClass.h"

using namespace std;

class TypeNode : public Node {
public:
	VarType varType;
	TypeNode* childType;

	string name;
	TypeNode() {
		this->name = "";
		this->childType = NULL;
		this->varType = TYPE_VOID;
	}

	TypeNode(Type_st * st) {

		this->varType = st->var_type;
		if( this->varType == TYPE_CUSTOM)
			this->name = st->name;
		this->childType = nullptr;
		if( st->childType)
			this->childType = new TypeNode(st->childType);
	}
	
};



class ExprNode;

class ExprListNode
{
public:
	list<ExprNode*> exprs;
	ExprListNode(Expr_list_st* st);
};

class ExprNode : public Node {
public:
	ExprType exprType;
	OperationType operationType;
	VarType constType;

	ExprNode* left;
	ExprNode* right;

	ExprListNode* arrayElems;
	string name; /* ��� / ��� ������� / ��� ����������� ���� / ��� ����������� ������ */
	int intVal;
	double floatVal;
	bool boolVal;
	char charVal;
	string strVal;
	/* ����� ������ */
	ExprNode* object; /* ������ � �������� ���������� ���� ��� ����� */
	/// TODO:: struct Method_call_arg_list_st* method_args; 
	/*!!!!!!!!!!!!!!!!!!!!!!!!!!*/
	/* ����� �������*/
	ExprListNode* funcArgs;
	ExprNode() {
		this->left = nullptr;
		this->right = nullptr;
		this->arrayElems = nullptr;
		this->name = "";
		this->strVal = "";
		this->object = nullptr;
		this->funcArgs = nullptr;
	}

	ExprNode(Expression_st* st) {
		this->left = nullptr;
		this->right = nullptr;
		this->arrayElems = nullptr;
		this->name = "";
		this->strVal = "";
		this->object = nullptr;
		this->funcArgs = nullptr;

		this->exprType = st->exprType;
		this->operationType = st->operationType;
		this->constType = st->const_type;
		if (st->exprType == EXPR_ARRAY_ELEM_CALL) {
			this->arrayElems = new ExprListNode(st->array_elems);
		}
		else if (this->exprType == EXPR_OPERATION) {
			if (this->operationType == OP_VALUE) {
				if (this->constType == TYPE_CUSTOM) {
					this->name = st->identifier;
				}
				else if (this->constType == TYPE_BOOL) {
					this->boolVal = st->bool_value;
				}
				else if (this->constType == TYPE_CHAR) {
					this->charVal = st->char_value;
				}
				else if (this->constType == TYPE_FLOAT) {
					this->floatVal = st->float_value;
				}
				else if (this->constType == TYPE_INT) {
					this->intVal = st->int_value;
				}
				else if (this->constType == TYPE_STRING) {
					this->strVal = st->string_value;
				}
			}
			else if (this->operationType == OP_UPLUS
				|| this->operationType == OP_UMINUS
				|| this->operationType == OP_LOGICAL_NOT
				) {
				this->left = new ExprNode(st->left);
			}
			else  {
				this->left = new ExprNode(st->left);
				this->right = new ExprNode(st->right);
			}
		}
		else if (this->exprType == EXPR_FUNC_CALL) {
			this->name = st->identifier;
			this->funcArgs = new ExprListNode(st->func_args);
		}
		else if (this->exprType == EXPR_INVAR_CALL) {
			this->object = new ExprNode(st->object);
			this->name = st->identifier;
		}
		else if (this->exprType == EXPR_METHOD_CALL) {
			this->object = new ExprNode(st->object);
			this->name = st->identifier;
			/// TODO::
			//this->methodArgs = 
		}
	}

};



ExprListNode::ExprListNode(Expr_list_st* st) {
	auto last = st;
	while (last) {
		this->exprs.push_back(new ExprNode(last->expr));
		last = last->next;
	}
}

class StatementNode : public Node {
public:
	StatementType stmtType;
	ExprNode* expr;
	ExprNode* condition;
	StatementNode* truthStmt;
	StatementNode* wrongStmt;
	list<StatementNode*> childs;

	/*���������� ����������*/
	TypeNode* varType;
	string name;
	///TODO:: ������ � �����������

	StatementNode(Statement_st* st) {
		this->expr = nullptr;
		this->condition = nullptr;
		this->truthStmt = nullptr;
		this->wrongStmt = nullptr;

		this->varType = nullptr;
		this->name = "";

		this->stmtType = st->stmt_type;

		if (this->stmtType == STMT_ARRAY_DECL) {
			/// TODO::
		}
		else if (this->stmtType == STMT_COMPOUND) {
			auto last = st->stmt_list;
			/// TODO: ������� �� ������, ������� �������
			while (last) {
				auto child = new StatementNode(last->stmt);
				this->childs.push_back( child);
				// ��������� ���������� � ����������� �� ��� ��������� ����
				if (child->stmtType == STMT_VAR_DECL || child->stmtType == STMT_ARRAY_DECL) {
					Expression_st* left  = CreateIDExpression(last->stmt->identifier);
					Expression_st* expr;
					if (child->stmtType == STMT_ARRAY_DECL) {
						expr = CreateArrayInitExpr(left, last->stmt->array_elems);
					}
					else if (child->stmtType = STMT_VAR_DECL) {
						expr = CreateExpression(OP_ASSIGN, left, last->stmt->expr);
					}
					StatementNode* assign = new StatementNode( CreateExpressionStatement(expr));
					this->childs.push_back(assign);
				} 
				last = last->next;
			}
		}
		else if (this->stmtType == STMT_EXPR) {
			this->expr = new ExprNode(st->expr);
		}
		else if (this->stmtType == STMT_IF) {
			this->condition = new ExprNode(st->condition);
			this->truthStmt = new StatementNode(st->truth_stmt);
			this->wrongStmt = st->wrong_stmt ? new StatementNode(st->wrong_stmt) : nullptr;
		}
		else if (this->stmtType == STMT_RETURN) {
			this->expr = new ExprNode(st->condition);
		}
		else if (this->stmtType == STMT_VAR_DECL) {
			this->varType = new TypeNode(st->var_type);
			this->name = st->identifier;
			
		}
	}
};