%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *yyin;
#include "s2t1.h"
#include "s2t1.c"
int yylex(void);
#define YYSTYPE tnode*
%}

%token NUM VAR BEG END READ WRITE
%left '+' '-'
%left '%' '*' '/'
%right '='

%%
Program : BEG Slist END ';' {gencode($2);exit(1);}
	| BEG END ';' {exit(1);}
	;
Slist  : Slist Stmt {$$=makeOperatorNode(NULL,4,$1,$2);}
	| Stmt {$$=$1;}
	;
Stmt : InputStmt {$$=$1;}
	| OutputStmt {$$=$1;}
	| AsgStmt {$$=$1;}
	;
InputStmt : READ '(' VAR ')' ';' {char *c="read";
				$$=makeOperatorNode(c,1,$3,NULL);}
	;
OutputStmt : WRITE '(' expr ')' ';' {char *c="write";
$$=makeOperatorNode(c,2,$3,NULL);}
	;
AsgStmt : VAR '=' expr ';' {char *c="=";
$$=makeOperatorNode(c,3,$1,$3);}
	;
expr : expr '+' expr {char *c="+";$$=makeOperatorNode(c,5,$1,$3);}
	| expr '-' expr {char *c="-";$$=makeOperatorNode(c,6,$1,$3);}
	| expr '*' expr {char *c="*";$$=makeOperatorNode(c,7,$1,$3);}
	| expr '/' expr {char *c="/";$$=makeOperatorNode(c,8,$1,$3);}
	| expr '%' expr {char *c="%";$$=makeOperatorNode(c,9,$1,$3);}
	| '(' expr ')' {$$=$2;}
	| NUM {$$=$1;}
	| VAR {$$=$1;}
	;
%%
yyerror(char const *s)
{
printf("yyerror %s",s);
}
int main(int argc,char *argv[])
{
if(argc>2)
{
yyin=fopen(argv[1],"r");
fp=fopen(argv[2],"w");
yyparse();
return 0;
}
}

