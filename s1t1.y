%{
#include<stdio.h>
#include<stdlib.h>


#define YYSTYPE tnode*
#include "s1t1.h"
#include "s1t1.c"
int yylex(void);

%}

%token NUM 
%left '+' '-'
%left '%' '*' '/'

%%
start : expr '\n' {printf("answer %d\nprefix form: ",evaluate($1));prefix($1);printf("\npostfix form: ");postfix($1);printf("\n");gencode($1);exit(1);}
	;
expr : expr '+' expr {$$=makeOperatorNode('+',$1,$3);}
	| expr '-' expr {$$=makeOperatorNode('-',$1,$3);}
	|expr '*' expr {$$=makeOperatorNode('*',$1,$3);}
	|expr '/' expr {$$=makeOperatorNode('/',$1,$3);}
	|expr '%' expr {$$=makeOperatorNode('%',$1,$3);}
	| '(' expr ')' {$$=$2;}
	| NUM {$$=$1;}
	;
%%
yyerror(char const *s)
{
printf("yyerror %s",s);
}
int main(int argc,char *argv[])
{
if(argc>1)
{
fp=fopen(argv[1],"w");
if(fp==NULL)
	printf("%s",argv[1]);	
yyparse();
return 0;
}
}
