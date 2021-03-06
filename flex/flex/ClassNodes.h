﻿#pragma once
#include "CommonNodes.h"

const string JavaLangObject = "java/lang/object";
const string defaultParentClass = "NSObject";
//const string defaultParentClass = JavaLangObject;

enum FieldAccess {
    ACCESS_PUBLIC,
    ACCESS_PROTECTED,
    ACCESS_PRIVATE
};
enum MethodType {
    METHOD_STATIC,
    METHOD_LOCAL
};

FieldAccess DEF_FIELD_ACCESS = ACCESS_PROTECTED;
FieldAccess DEF_METHOD_ACCESS = ACCESS_PROTECTED;


class ClassMethodParamNode : public Node {
public:
    string outerName;
    string innerName;
    TypeNode* type;

    void visit(NodeVisiter*) override;

    ClassMethodParamNode( Class_method_param_declaration_st* st){
        if ( st->outerName != NULL)
			this->outerName = st->outerName;
		else
			this->outerName = "";
        this->innerName = st->innerName;
        this->type = new TypeNode(st->val_type);
    }
    static void FillFrom(list<ClassMethodParamNode*>& list, Class_method_param_declaration_list_st* st){
        auto last = st;
        while( last){
            list.push_back( new ClassMethodParamNode( last->param));
            last = last->next;
        }
    }
};

// Если будут ошибки, не забудь исправаить и ClassMethodImplementationNode
class ClassMethodDeclarationNode : public Node {
public:
    FieldAccess access;
    MethodType methodType;
    string name;
    list<ClassMethodParamNode*> params;
    TypeNode* returnType;

    void visit(NodeVisiter*) override;

    ClassMethodDeclarationNode() {
        this->access = DEF_METHOD_ACCESS;
        this->methodType = METHOD_LOCAL;
        this->name = "";
        this->returnType = nullptr;
    }

    ClassMethodDeclarationNode(Class_method_declaration_st* st, Field_access_en access){
        
        this->methodType = st->methodType == STATIC ? METHOD_STATIC : METHOD_LOCAL;
        this->name = st->name;
        this->returnType = new TypeNode( st->returnType);

        ClassMethodParamNode::FillFrom( this->params, st->params);

        this->access = 
            access == A_PUBLIC ? ACCESS_PUBLIC :
            access == A_PROTECTED ? ACCESS_PROTECTED :
            access == A_PRIVATE ? ACCESS_PRIVATE :
            DEF_METHOD_ACCESS;
    }

    static void FillFrom(list<ClassMethodDeclarationNode*>& list, Class_methods_declaration_block_list_st* st) {
        auto blockListLast = st;
        while( blockListLast){
            auto blockLast = blockListLast->list;
            Field_access_en access = blockLast->access;
            auto last = blockLast->list;
            while( last){
                list.push_back(new ClassMethodDeclarationNode(last->method, access));
                last = last->next;
            }
            blockListLast = blockListLast->next;
        } 
    }
};


class ClassFieldDeclarationNode : public Node {
public:
    FieldAccess access;
    string name;
    TypeNode* type;

    void visit(NodeVisiter*) override;

    ClassFieldDeclarationNode(){
        this->access = DEF_FIELD_ACCESS;
        this->name = "";
        this->type = nullptr;
    }

    ClassFieldDeclarationNode( Class_invariant_declaration_st* st, Field_access_en access){
        this->name = st->name;
        this->type = new TypeNode(st->val_type);
    
        this->access = 
            access == A_PUBLIC ? ACCESS_PUBLIC :
            access == A_PROTECTED ? ACCESS_PROTECTED :
            access == A_PRIVATE ? ACCESS_PRIVATE :
            DEF_FIELD_ACCESS;
    }


    static void FillFrom( list<ClassFieldDeclarationNode*>& fields, Class_invariants_declaration_block_list_st * st ){
        auto blockListLast = st;
        while( blockListLast){
            auto blockLast = blockListLast->list;
            Field_access_en access = blockLast->access;
            auto last = blockLast->list;
            while( last){
                fields.push_back(new ClassFieldDeclarationNode(last->invariant, access));
                last = last->next;
            }
            
            blockListLast = blockListLast->next;
        } 
    }
};


class ClassDeclarationNode : public Node {
public:
    string name;
    string parentName;
    list<ClassFieldDeclarationNode*> fields;
    list<ClassMethodDeclarationNode*> methods;
    
    void visit(NodeVisiter*) override;

    ClassDeclarationNode( Class_declaration_st* st ){
        this->name = st->name;
        this->parentName = st->parentName ? st->parentName : defaultParentClass;
        ClassFieldDeclarationNode::FillFrom( this->fields, st->invariants_declaration_list);
        ClassMethodDeclarationNode::FillFrom( this->methods, st->methods_declaraion_list);
    }
};


// TODO::???Возможно отнаследовать от объявления???
class ClassMethodImplementationNode : public Node {
public:    
    MethodType methodType;
    string name;
    list<ClassMethodParamNode*> params;
    TypeNode* returnType;
    StatementNode* body;
    
    void visit(NodeVisiter*) override;

    ClassMethodImplementationNode(){
        this->methodType = METHOD_LOCAL;
        this->name = "";
        this->returnType = nullptr;
        this->body = nullptr;  
    }
    
    ClassMethodImplementationNode(Class_method_impl_st* st){

        this->methodType = st->methodType == STATIC ? METHOD_STATIC : METHOD_LOCAL;
        this->name = st->name;
        this->returnType = new TypeNode( st->returnType);
        ClassMethodParamNode::FillFrom( this->params, st->params);
        this->body = new StatementNode( st->body);  
        
    }

    static void FillFrom(list<ClassMethodImplementationNode*>& list, Class_method_impl_list_st* st) {
     auto last = st;
        while( last){
            list.push_back(new ClassMethodImplementationNode( last->method));
            last = last->next;
        }
    }
};

class ClassImplementationNode : public Node {
public:
    string name;
    list<ClassMethodImplementationNode*> methods;
    
    void visit(NodeVisiter*) override;
    
    ClassImplementationNode( Class_impl_st* st){
        this->name = st->name;

        ClassMethodImplementationNode::FillFrom(this->methods, st->methods);
    }
};


class MethodCallArgNode : public ExprNode {
public:
    string outerName;
    
    void visit(NodeVisiter*) override;
    
    MethodCallArgNode( Method_call_arg_st* st) : ExprNode(st->value){
        this->outerName = st->outer_name ? st->outer_name : "";
    }
    
    MethodCallArgNode( Expression_st* st) : ExprNode(st){
        this->outerName = "";
    }

    MethodCallArgNode( ExprNode* n){
        this->arrayElems = n->arrayElems;
        this->boolVal = n->boolVal;
        this->charVal = n->charVal;
        this->constantNum = n->constantNum;
        this->constType = n->constType;
        this->exprType = n->exprType;
        this->floatVal = n->floatVal;
        this->funcArgs = n->funcArgs;
        this->intVal = n->intVal;
        this->isAlloc = n->isAlloc;
        this->left = n->left;
        this->methodCallArgs = n->methodCallArgs;
        this->name = n->name;
        this->object = n->object;
        this->operationType = n->operationType;
        this->outerName = "";
        this->returnType = n->returnType;
        this->right = n->right;
        this->strVal = n->strVal;
        
//        this->
    }


    static void FillFrom( vector<MethodCallArgNode*>& list, Method_call_arg_list_st* st){
        auto last = st;
        while ( last){
            list.push_back( new MethodCallArgNode(last->arg));
            last = last->next;
        }
    }

    
    static void FillFrom( vector<MethodCallArgNode*>& list, Expr_list_st* st){
        auto last = st;
        while ( last){
            list.push_back( new MethodCallArgNode(last->expr));
            last = last->next;
        }
    }
    
};

class EnumElem {
public:
    string name;
    int value;
    EnumElem() {
        name = "";
        value = 0;
    }
    EnumElem(string n, int val){
        this->name = n;
        this->value = val;
    }
};

class EnumNode : public ExprNode{
public:
    string name;
    vector<EnumElem> elems;
    void visit(NodeVisiter*) override;

    EnumNode( Enum_declaration_st* st){
        this->name = st->identifier;
        int curVal = 0;
        auto last = st->enumerator_list;
        while( last){
            if( last->enumerator->isValueSet ){
                curVal = last->enumerator->value;
            }
            this->elems.push_back( EnumElem(last->enumerator->identifier, curVal));
            curVal++;
            last = last->next;
        }
    }

};