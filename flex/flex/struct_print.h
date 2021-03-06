#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <iostream>

#include "tree_structs.h"
typedef long long ll;
typedef long double ld;

using namespace std;

int max_id = 1;
unordered_map<void*, int> ids;
unordered_map<void*, string> labels;
struct Edge{
	void* st;
	string label;

	Edge( void* st){ this->st = st;}
	Edge( void* st, string label){ this->st = st; this->label =label; }
	const Edge& operator= (void * st){ this->st = st;}
	static Edge left( void* st) { return Edge(st, "left"); }
	static Edge right( void* st) { return Edge(st, "right"); }
	static Edge numb( void* st, int num) { return Edge(st, to_string((ll)num)); }
};
unordered_map<void*, vector<Edge>> g;


void printDot() {
    string dot = "digraph Program {\n";
    for( auto i = ids.begin(); i != ids.end(); i++) {
        dot += "\t" + to_string((long long)i->second) + "  [label=\"" + labels[i->first] + "\"];\n"; 
    }
    dot += "\n\n\n";
    for( auto i = g.begin(); i != g.end(); i++){ 
        for( auto in = i->second.begin(); in != i->second.end(); in++) {
			if ( ids[in->st] != 0) {
				dot += "\t" + to_string((long long)ids[i->first]) + "->" + to_string((long long)ids[in->st]) + 
					+ "[label=\"" + in->label +"\"];\n";
            }
        }
    }
    dot += "}";
    freopen("graph.txt","w", stdout);
    cout << dot;
	//freopen("CON","w", stdout);
}

int getNextId() {
    return max_id++;
}
void print(Expression_st* st);
void print(Expr_list_st* st) {
    if (st != NULL) {
        ids[st] = getNextId();
        labels[st] = string("Func_call_arg_list / array_elems");
        Expr_list_st* next = st;
		int number = 1;
        while( next){
            g[st].push_back(Edge::numb(next->expr, number));
            print(next->expr);
            next = next->next;
			number++;
        }
    }
}

void print( Method_call_arg_st* st){
    ids[st] = getNextId();
    string lbl = string("method_arg_out_name: ") + (st->outer_name ? string(st->outer_name) : string("<no-out-name>"));
    labels[st] = lbl;
    if( st->value) {
        g[st].push_back( st->value);
        print( st->value);
    }
}


void print( Method_call_arg_list_st* st){
    ids[st] = getNextId();
    labels[st] = "args";
    auto next = st;
    int i = 1;
    while( next){
        g[st].push_back(Edge::numb(next->arg, i++));
        print(next->arg);
        next = next->next;
    }
}


void print( Expression_st* st) {
    if (st != NULL) {
        ids[st] = getNextId();
        switch(st->exprType) {
            case EXPR_OPERATION: {
                switch(st->operationType) {
                    case OP_ADD: {
                        labels[st] = "+";
						g[st].push_back(Edge::left(st->left));
                        g[st].push_back(Edge::right(st->right));
                        print(st->left);
                        print(st->right);
						break;
                    }
                    case OP_SUB: {
                        labels[st] = "-";
                        g[st].push_back(Edge::left(st->left));
                        g[st].push_back(Edge::right(st->right));
                        print(st->left);
                        print(st->right);
						break;
                    }
                    case OP_MUL: {
                        labels[st] = "*";
                        g[st].push_back(Edge::left(st->left));
                        g[st].push_back(Edge::right(st->right));
                        print(st->left);
                        print(st->right);
						break;
                    }
                    case OP_DIV: {
                        labels[st] = "/";
                        g[st].push_back(Edge::left(st->left));
                        g[st].push_back(Edge::right(st->right));
                        print(st->left);
                        print(st->right);
						break;
                    }
                    case OP_MOD: {
                        labels[st] = "%";
                        g[st].push_back(Edge::left(st->left));
                        g[st].push_back(Edge::right(st->right));
                        print(st->left);
                        print(st->right);
						break;
                    }
                    case OP_ASSIGN: {
                        labels[st] = "=";
                        g[st].push_back(Edge::left(st->left));
                        g[st].push_back(Edge::right(st->right));
                        print(st->left);
                        print(st->right);
						break;
                    }
                    case OP_ASSIGN_ARRAY: {
						g[st].push_back(Edge::left(st->left));
						g[st].push_back(Edge::right(st->array_elems));
						print(st->left);
						break;
                    }
                    case OP_LESS: {
                        labels[st] = "<";
                        g[st].push_back(Edge::left(st->left));
                        g[st].push_back(Edge::right(st->right));
                        print(st->left);
                        print(st->right);
						break;
                    }
                    case OP_LESS_OR_EQUAL: {
                        labels[st] = "<=";
                        g[st].push_back(Edge::left(st->left));
                        g[st].push_back(Edge::right(st->right));
                        print(st->left);
                        print(st->right);
						break;
                    }
                    case OP_GREATER: {
                        labels[st] = ">";
                        g[st].push_back(Edge::left(st->left));
                        g[st].push_back(Edge::right(st->right));
                        print(st->left);
                        print(st->right);
						break;
                    }
                    case OP_GREATER_OR_EQUAL: {
                        labels[st] = ">=";
                        g[st].push_back(Edge::left(st->left));
                        g[st].push_back(Edge::right(st->right));
                        print(st->left);
                        print(st->right);
						break;
                    }
                    case OP_EQUAL: {
                        labels[st] = "==";
                        g[st].push_back(Edge::left(st->left));
                        g[st].push_back(Edge::right(st->right));
                        print(st->left);
                        print(st->right);
						break;
                    }
                    case OP_NOT_EQUAL: {
                        labels[st] = "!=";
                        g[st].push_back(Edge::left(st->left));
                        g[st].push_back(Edge::right(st->right));
                        print(st->left);
                        print(st->right);
						break;
                    }
                    case OP_LOGICAL_NOT: {
                        labels[st] = "!";
                        g[st].push_back(Edge::left(st->left));
                        print(st->left);
						break;
                    }
                    case OP_AND: {
                        labels[st] = "&&";
                        g[st].push_back(Edge::left(st->left));
                        g[st].push_back(Edge::right(st->right));
                        print(st->left);
                        print(st->right);
						break;
                    }
                    case OP_OR: {
                        labels[st] = "||";
                        g[st].push_back(Edge::left(st->left));
                        g[st].push_back(Edge::right(st->right));
                        print(st->left);
                        print(st->right);
						break;
                    }
                    case OP_UPLUS: {
                        labels[st] = "UPLUS";
                        g[st].push_back(Edge::left(st->left));
                        print(st->left);
						break;
                    }
                    case OP_UMINUS: {
                        labels[st] = "UMINUS";
                        g[st].push_back(Edge::left(st->left));
                        print(st->left);
						break;
                    }
                    case OP_VALUE: {
                        labels[st] = "Value ";
                        switch(st->const_type) {
                            case TYPE_INT: {
                                labels[st] += string("Const_INT ") + to_string((ll)st->int_value);
								break;
                            }
                            case TYPE_FLOAT: {
                                labels[st] += string("Const_FLOAT ") + to_string((ld)st->float_value);
								break;
                            }
                            case TYPE_CHAR: {
                                labels[st] += string("Const_CHAR \'") + string(1, st->char_value) + "\'";
								break;
                            }
                            case TYPE_STRING: {
                                labels[st] +="Const_STRING \\\"" + string(st->string_value) + "\\\"";
								break;
                            }
                            case TYPE_BOOL: {
                                labels[st] += string("Const_BOOL ") + string(st->bool_value ? "true" : "false"); 
								break;
                            }
                            case TYPE_CUSTOM: {
                                labels[st] += string("Identifier ") + string(st->identifier) ;
								break;
                            }
                            case TYPE_POINTER: {
                                labels[st] += "Pointer ";
								break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
            case EXPR_ARRAY_ELEM_CALL: {
                labels[st] = "Array_elem_call ";
                g[st].push_back(Edge(st->left, "array" ));
                print(st->left);
                g[st].push_back(Edge(st->right, "index"));
                print(st->right);
				break;
            }
            case EXPR_FUNC_CALL: {
                labels[st] = "Func_call " + string(st->identifier) + "()";
                g[st].push_back(st->func_args);
                print(st->func_args);
				break;
            }
            case EXPR_METHOD_CALL: {
                labels[st] = "Method_call: " + string(st->identifier);
                if ( st->object) {
                    g[st].push_back(Edge(st->object,"object"));
                    print(st->object);
                }
                if ( st->method_args) {
                    g[st].push_back(Edge(st->method_args, "args"));
                    print(st->method_args);
                }
				break;
            }
            case EXPR_INVAR_CALL: {
                labels[st] = "invar_call: " + string(st->identifier);
                if( st->object){
                    g[st].push_back( st->object);
                    print(st->object);
                }
                break;
            }
        }
    }
}
void print( Statement_st* st);

void print( Statements_List_st* st) {
    if (st != NULL) {
        ids[st] = getNextId();
        labels[st] = "Statements_list";
        Statements_List_st* next = st;
		int number = 1;
        while( next){
            g[st].push_back(Edge::numb(next->stmt, number));
            print(next->stmt);
            next = next->next;
			number++;
        }
    }
}

void print(Type_st * st) {
    if (st != NULL) {
        ids[st] = getNextId();
        switch(st->var_type) {
            case TYPE_VOID: {
                labels[st] = "void";
				break;
            }
            case TYPE_INT: {
                labels[st] = "int";
				break;
            }
            case TYPE_FLOAT: {
                labels[st] = "float";
				break;
            }
            case TYPE_CHAR: {
                labels[st] = "char";   
				break;
            }
            case TYPE_STRING: {
                labels[st] = "string";
				break;
            }
            case TYPE_BOOL: {
                labels[st] = "bool";  
				break;
            }
            case TYPE_CUSTOM: {
                labels[st] = string(st->name);   
				break;
            }
            case TYPE_POINTER: {
                labels[st] += "* (pointer)";
				g[st].push_back(st->childType);
				print(st->childType);
				break;
            } 
        }
    }
}

void print( Statement_st* st) {
    if (st != NULL) {
        ids[st] = getNextId();
        switch(st->stmt_type) {
            case STMT_WHILE: {
                labels[st] = "While_stmt";
		        g[st].push_back(Edge(st->condition, "condition"));
                g[st].push_back(Edge(st->truth_stmt, "true"));
                print(st->condition);
                print(st->truth_stmt);
                break;
            }
            case STMT_IF: {
                labels[st] = "If_stmt";
		        g[st].push_back(Edge(st->condition, "condition"));
                g[st].push_back(Edge(st->truth_stmt, "true"));
                g[st].push_back(Edge(st->wrong_stmt, "false"));
                print(st->condition);
                print(st->truth_stmt);
                print(st->wrong_stmt);
                break;
            }
            case STMT_EXPR: {
                labels[st] = "Expr";
		        g[st].push_back(st->expr);
                print(st->expr);
                break;
            }
            case STMT_VAR_DECL: {
                labels[st] = "Var_decl_stmt " + string(st->identifier);
				if (st->var_type) {
					g[st].push_back(Edge(st->var_type, "type"));
					print(st->var_type);
				}

				if (st->expr) {
					g[st].push_back(st->expr);
					print(st->expr);
				}
                break;
            }
			case STMT_ARRAY_DECL: {
				ids[st] = getNextId();
				labels[st] = "array_decl: " + string(st->identifier) + "[" + to_string((ll)st->array_size ) + "]";
				if (st->var_type) {
					g[st].push_back(Edge(st->var_type, "type"));
					print(st->var_type);
				}

				if (st->expr) {
                    g[st].push_back(Edge(st->array_elems, "val"));
                    print(st->array_elems);
				}
                break;
			}
            case STMT_RETURN: {
                labels[st] = "Return_stmt";
		        g[st].push_back(st->expr);
                print(st->expr);
                break;
            }
            case STMT_COMPOUND: {
                labels[st] = "Compound_stmt";
		        g[st].push_back(st->stmt_list);
                print(st->stmt_list);
                break;
            }
            default: {
                labels[st] = "Empty_stmt";
                break;
            }
        }
    }
}

void print(Class_method_param_declaration_st* st) {
	ids[st] = getNextId();
	labels[st] = "param name out: " + (st->outerName ? string(st->outerName) : "<no-name>") + " in: " + string(st->innerName) ;
	if (st->val_type) {
		g[st].push_back(st->val_type);
		print(st->val_type);
	}
}

void print(Class_method_param_declaration_list_st* st) {
	ids[st] = getNextId();
	labels[st] = "params";
	auto next = st;
	int i = 1;
	while (next) {
		g[st].push_back(Edge::numb(next->param, i++));
		print(next->param);
		next = next->next;
	}
}

void print(Class_method_declaration_st* st) {
	ids[st] = getNextId();
	string lbl = "decl ";
	if (st->methodType == STATIC) {
		lbl += " static ";
	}
	else if (st->methodType == NON_STATIC) {
		lbl += " non_static ";
	}
	lbl += st->name;
	labels[st] = lbl;
	if (st->returnType) {
		g[st].push_back(Edge(st->returnType, "return"));
		print(st->returnType);
	}

	if (st->params) {
		g[st].push_back(st->params);
		print(st->params);
	}
}

void print(Class_methods_declaration_block_st* st) {
	ids[st] = getNextId();
	string acs;
	if (st->access == A_NOT_SET)
		acs = "ACСESS NOT SET";
	else if (st->access == A_PRIVATE)
		acs = "PRIVATE";
	else if (st->access == A_PROTECTED)
		acs = "PROTECTED";
	else if (st->access == A_PUBLIC)
		acs = "PUBLIC";

	labels[st] = acs;
	auto next = st->list;
	while (next) {
		if (next->method) {
			g[st].push_back(next->method);
			print(next->method);
		}
		next = next->next;
	}
}

void print(Class_methods_declaration_block_list_st* st) {
	ids[st] = getNextId();
	labels[st] = "Method_decl - s";
	auto next = st;
	while (next) {
		if (next->list) {
			g[st].push_back(next->list);
			print(next->list);
		}
		next = next->next;
	}
}
void print(Class_invariant_declaration_st* st) {
	ids[st] = getNextId();
	labels[st] = "invar: " + string(st->name);
	if (st->val_type) {
		g[st].push_back(st->val_type);
		print(st->val_type);
	}

}
void print(Class_invariants_declaration_block_st* st) {
	ids[st] = getNextId();
	string acs;
	if (st->access == A_NOT_SET)
		acs = "ACSESS NOT SET";
	else if (st->access == A_PRIVATE)
		acs = "PRIVATE";
	else if (st->access == A_PROTECTED)
		acs = "PROTECTED";
	else if (st->access == A_PRIVATE)
		acs = "PRIVATE";

	labels[st] = acs;

	auto next = st->list;
	if (next) {
		if (next->invariant) {
			g[st].push_back(next->invariant);
			print(next->invariant);
		}
		next = next->next;
	}

}

void print(Class_invariants_declaration_block_list_st* st) {
	ids[st] = getNextId();
	labels[st] = "class inv";
	auto  next = st;
	while (next) {
		if (next->list) {
			g[st].push_back(next->list);
			print(next->list);
		}
		next = next->next;
	}
}

void print( Class_declaration_st* st) {
    if (st != NULL) {
		ids[st] = getNextId();
		if (st->parentName) {
			labels[st] = "Class_decl class " + string(st->name) + " : " + string(st->parentName) ;
		}
		else {
			labels[st] = "Class_decl class " + string(st->name);
		}
		if (st->methods_declaraion_list) {
			g[st].push_back(st->methods_declaraion_list);
			print(st->methods_declaraion_list);
		}

		if (st->invariants_declaration_list) {
			g[st].push_back(st->invariants_declaration_list);
			print(st->invariants_declaration_list);
		}
	}
}

void print(Class_method_impl_st* st) {
	ids[st] = getNextId();
	string lbl = "impl: ";
	if (st->methodType == STATIC) {
		lbl += " static ";
	}
	else if (st->methodType == NON_STATIC) {
		lbl += " non_static ";
	}
	lbl += st->name;
	labels[st] = lbl;

	if (st->body) {
		g[st].push_back(st->body);
		print(st->body);
	}

	if (st->params) {
		g[st].push_back(st->params);
		print(st->params);
	}

	if (st->returnType) {
		g[st].push_back(st->returnType);
		print(st->returnType);
	}

}
void print(Class_method_impl_list_st* st) {
	ids[st] = getNextId();
	labels[st] = "Class method impls";
	auto next = st;
	while (next) {
		if (next->method) {
			g[st].push_back(next->method);
			print(next->method);
		}
		next = next->next;
	}
}

void print( Class_impl_st* st ) {
    if (st != NULL) {
		ids[st] = getNextId();
		labels[st] = "Class_impl class " + string(st->name);
		if (st->methods) {
			g[st].push_back(st->methods);
			print(st->methods);
		}
	}
}

void print( Enumerator_st* st) {
    if (st != NULL) {
        ids[st] = getNextId();
        labels[st] = string(st->identifier) + " = " + to_string((ll)st->value);
    }
}

void print( Enumerator_list_st* st) {
    if (st != NULL) {
        ids[st] = getNextId();
        labels[st] = "Enumerator list";
        Enumerator_list_st* next = st;
		int number = 1;
        while( next){
            g[st].push_back(Edge::numb(next->enumerator, number));
            print(next->enumerator);
            next = next->next;
			number++;
        }
    }
}

void print( Enum_declaration_st* st) {
    if (st != NULL) {
		ids[st] = getNextId();
		labels[st] = "Enum_decl enum " + string(st->identifier);
		g[st].push_back(st->enumerator_list);
        print(st->enumerator_list);
	}
}

void print(Func_arg_st* st) {
    if (st != NULL) {
        ids[st] = getNextId();
        labels[st] = string(st->name);
        g[st].push_back(Edge(st->val_type, "type"));
        print( st->val_type);
    }
}

void print(Func_arg_list_st* st) {
    if (st != NULL) {
        ids[st] = getNextId();
        labels[st] = "Func_arg_list";
        Func_arg_list_st* next = st;
		int number = 1;
        while( next){
            g[st].push_back(Edge::numb(next->arg, number));
            print(next->arg);
            next = next->next;
			number++;
        }
    }
}
void print( Func_declaration_st* st) {
    if (st != NULL) {
        ids[st] = getNextId();
		labels[st] = "Func_decl function " + string(st->name) + "()";
		g[st].push_back(Edge(st->return_type, "type"));
        print( st->return_type);
		g[st].push_back(st->args);
        print( st->args);
    }
}

void print( Func_impl_st* st) {
    if (st != NULL) {
		ids[st] = getNextId();
		labels[st] = "Func_impl function " + string(st->name) + "()";
        if( st->return_type){
            g[st].push_back(Edge(st->return_type, "type"));
            print( st->return_type);
        }

        if( st->args) {
            g[st].push_back(st->args);
            print( st->args);
        }

        if( st->body){
            g[st].push_back(st->body);
            print(st->body);
        }
    }
}

void print( Extern_code_st* st) {
    if (st != NULL) {
		ids[st] = getNextId();
		labels[st] = "Extern code";
        if( st->class_decl) {
            g[st].push_back(st->class_decl);
            print( st->class_decl);
        }

        if( st->class_impl) {
            g[st].push_back(st->class_impl);
		    print( st->class_impl);
        }

        if ( st->enum_decl){
            g[st].push_back(st->enum_decl);
            print( st->enum_decl);
        }

        if( st->func_decl){
            g[st].push_back(st->func_decl);
            print( st->func_decl);
        }

        if( st->func_impl){
            g[st].push_back(st->func_impl);
            print( st->func_impl);
        }
    }
}

void print( Program_st* st ) {
    if (st != NULL) {
        ids[st] = getNextId();
        labels[st] = "Program";

        Program_st* next = st;
        int number = 1;
        while( next){
            g[st].push_back(Edge::numb(next->code, number));
            print( next->code);
            next = next->next;
            number++;
        }
    }
    printDot();
}
