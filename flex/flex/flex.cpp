// flex.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "struct_print.h"
#include "objectivec.tab.h"
#include "lex.yy.c"
#include <locale.h>
#include <string>

extern int yyparse(void);
extern int yylex(void);

void _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "russian");
	char * l = setlocale(LC_ALL, NULL);
	freopen("output.txt", "w", stdout);
	yyin = fopen("test.m", "r");
	yylex();
}

