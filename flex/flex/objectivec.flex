%{
	#define YY_NO_UNISTD_H 0
    #include <math.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <conio.h>
    #include <locale.h>
	
	#include "objectivec_tab.h"
	#include "tree_structs.h"
	#include "tree_print.h"
	extern int yyparse(void);
		
	void addToBuffer( char* str);
	void addToBufferOcto( char* str, int line);
	void addToBufferHex( char* str, int line);
	void clearBuffer();
	void endChar(int line);
	void handleToken(char * name, char * value, int startPos);
	int handleTokenInt(char * text, int system);
	void handleError(char * error, int line);


	int start = 0;
	char buffer[100000];
%}

%option noyywrap
%option never-interactive
%option yylineno

DIGIT	[0-9]
LETTER	[A-Za-z_]
CHAR [^\\\'\"\n]
WS	[ \t\n]
ID {LETTER}({LETTER}|{DIGIT})*

INT_10    		 ([1-9][0-9]*)|0
INT_16    		 0[xX][0-9a-fA-F]+
INT_8    		 	 0[0-7]+
FLOAT     		 ({DIGIT}*\.{DIGIT}+)|({DIGIT}+[\.]{DIGIT}*)
EXPONENT         		 (({DIGIT}*|{FLOAT})[eE][+-]?{DIGIT}+)

ONE_LINE_COMMENT \/\/.*\n

%x STRING
%x MULTILINE_COMMENT
%x CHAR
%x OCTO_CHAR


%%
%{

%}

{WS} 	{}

"/*"					{ BEGIN(MULTILINE_COMMENT); start = yylineno; }
<MULTILINE_COMMENT>[^*]*		{ addToBuffer(yytext); }
<MULTILINE_COMMENT>"*"+[^*/]* 	{ addToBuffer(yytext); }
<MULTILINE_COMMENT>"*"+"/" 		{ BEGIN(INITIAL);}
<MULTILINE_COMMENT><<EOF>> 		{ BEGIN(INITIAL); handleError("unterminated multiline_comment", start);}

\'					{ BEGIN(CHAR); clearBuffer(); }
\"					{ BEGIN(STRING); clearBuffer(); }
<CHAR>{CHAR}{CHAR} 	{ BEGIN(INITIAL); handleError("More then one char in \'\'", yylineno); }
<CHAR,STRING>\\a			{ addToBuffer("\a"); }
<CHAR,STRING>\\b			{ addToBuffer("\b"); }
<CHAR,STRING>\\f			{ addToBuffer("\f"); }
<CHAR,STRING>\\n			{ addToBuffer("\n"); }
<CHAR,STRING>\\r			{ addToBuffer("\r"); }
<CHAR,STRING>\\t			{ addToBuffer("\t"); }
<CHAR,STRING>\\v			{ addToBuffer("\v"); }
<CHAR,STRING>\\\"			{ addToBuffer("\""); }
<CHAR,STRING>\\\'			{ addToBuffer("\'"); }
<CHAR,STRING>\\\?			{ addToBuffer("\?"); }
<CHAR,STRING>\\\\			{ addToBuffer("\\"); }
<CHAR,STRING>\\0				{ addToBuffer("\0"); }
<CHAR,STRING>\\[0-7]{1,3}		{ addToBufferOcto(yytext+1, yylineno); }
<CHAR,STRING>\\x[0-9a-fA-F]+	{ addToBufferHex(yytext, yylineno);}
<CHAR,STRING>{CHAR}			{ addToBuffer(yytext); }
<CHAR,STRING>\\x				{ BEGIN(INITIAL);handleError("Expected hexadecimal number ", yylineno);}
<STRING>\\\n			{ ; /*Ничего*/}
<CHAR>\n				{ BEGIN(INITIAL); handleError("Expected \' ", yylineno); }
<STRING>\n				{ BEGIN(INITIAL); handleError("Expected \" ", yylineno); }
<CHAR>\' 				{ BEGIN(INITIAL); yylval.char_const=buffer; return CHAR_CONST; }
<STRING>\"				{ BEGIN(INITIAL); yylval.string_const=buffer; return STRING_CONST; }


%{ /* Наверное константы, а не названия типов, назвать const_int, const_float, const_string, const_char */ %}

"void"		{ return VOID; }
"int"		{ return INT; }
"float"		{ return FLOAT; }
"char"		{ return CHAR; }

"struct"	{ return STRUCT; }
"enum"		{ return ENUM; }

"static"	{ return STATIC; }

"if"		{ return IF; }
"else"		{ return ELSE; }

"while"		{ return WHILE; }

"return"	{ return RETURN; }

"extern"			{ return EXTERN; }
"@interface" 		{ return @INTERFACE; }
"@implementation" 	{ return @IMPLEMENTATION; }
"@protocol" 		{ return @PROTOCOL; }
"@end" 				{ return @END; }

"@private" 		{ return @PRIVATE; }
"@protected" 	{ return @PROTECTED; }
"@public" 		{ return @PUBLIC; }

"@class" 		{ return @CLASS; }

"YES" 			{ return YES; }
"NO" 			{ return NO; }

{ID} 		{ yylval.id = yytext; return ID; }
{INT_10} 	{ yylval.int_const=atoi(yytext); return INT_CONST };
{INT_16} 	{ yylval.int_const=handleTokenInt(yytext, 16); return INT_CONST }; 
{INT_8} 	{ yylval.int_const=handleTokenInt(yytext, 8); return INT_CONST };
{FLOAT}		{ yylval.float_const=atof(yytext); return FLOAT_CONST; }

{ONE_LINE_COMMENT} { }


"="			{ return '='; }

"+"			{ return '+'; }
"++"		{ return INC; }
"+="		{ return ADD_ASSIGN; }
"-"			{ return '-'; }
"--"		{ return DEC; }
"-="		{ return SUB_ASSSIGN; }
"*"			{ return '*'; }
"*="		{ return MUL_ASSIGN; }
"/"			{ return '/'; }
"/="		{ return DIV_ASSIGN; }
"%"			{ return '%'; }
"%="		{ return MOD_ASSIGN; }


"=="		{ return EQUAL; }
"<"			{ return '<'; }
"<="		{ return LESS_OR_EQUAL; }
">"			{ return '>'; }
">="		{ return GREATER_OR_EQUAL; }
"!="		{ return NOT_EQUAL; }
"!"			{ return '!'; }

"\|\|"		{ return OR; }
"&&"		{ return AND; }

"->"		{ return ARROW; }

"\["		{ return '['; }
"\]"		{ return ']'; }
"("			{ return '('; }
")"			{ return ')'; }
"{"			{ return '{'; }
"}"			{ return '}'; }
";"			{ return ';'; }
","			{ return ','; }

[\@UuL] 	{ return STRING_MODIFIER; }

'\.'		{ return '.'; }
. 			{ handleToken("unknown character", yytext, yylineno); }

%%

void addToBuffer( char* str){
	//printf("Buf founded: %s\n",str);
	strcat(buffer, str);
}

void addToBufferOcto( char* str, int line){
	int num = strtol(str, NULL, 8);
	//printf("Oct founded: %d", num);
	if ( num > 255){
		handleError("too big number for char", line);
	}
	else {
		char sub[2];
		sub[0] = (char)num;
		sub[1] = 0;
		strcat(buffer, sub);
	}
}

void addToBufferHex( char* str, int line){
	char * buf = (char *)malloc(strlen(str));
	strcpy(buf, str);
	buf[0] = '0';
	int num = strtol(buf, NULL, 16);
	//printf("Hex founded: %d from str: %s handled str: %s\n", num, str,buf);
	if ( num > 255){
		handleError("too big number for char", line);
	}
	else {
		char sub[2];
		sub[0] = (char)num;
		sub[1] = 0;
		strcat(buffer, sub);
	}
}


void clearBuffer(){
	buffer[0] = 0;
}

// Глянуть, что убрать
void endChar(int line){
	if ( strlen(buffer) == 0){
		handleError("Empty char",line);
	} else {
		handleToken("char", buffer, line);
	}
}

void handleToken(char * name, char * value, int startPos){
	printf("Founed: %s at line %d \nvalue: %s\n\n", name, startPos, value);
} 

int handleTokenInt(char * text, int system) {
	char numstr[40];
	int num = strtol(text, NULL, system);
	return num;
}

void handleError(char * error, int line){
	printf("Error at line %d: %s\n\n",line, error);
} 

// МБ тоже убрать
void main(int argc, char *argv[])
{
    if(argc>1)
    {
	freopen("output.txt", "w", stdout);    	
	yyin=fopen(argv[1],"r");
    }
    yyparse();
    tree_print();
    getch();
}
