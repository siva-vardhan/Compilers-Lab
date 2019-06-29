%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "s4e1.h"
#include "s4e1.c"
FILE *yyin,*fp;
#define YYSTYPE tnode*
int yylex();
%}

%token NUM ID BEG END READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE L G LE GE NE EE REPEAT UNTIL BREAK CONTINUE DECL ENDDECL INT STR STRVAL
%left '+' '-'
%left '*' '/' '%'
%right '='

%%
Program : BEG Declarations Slist END ';' {printf("\n");print_tab(head);infix($3);printf("\n");//evaluator($3);
					gencode($3);}
	| BEG Declarations END ';' {printf("\n");print_tab(head);}
	;
Slist : Slist Stmt {$$=makeOperatorNode(NULL,4,$1,NULL,$2);}
	| Stmt {$$=$1;}
	;
Stmt : InputStmt {$$=$1;}
	| OutputStmt {$$=$1;}
	| AsgStmt {$$=$1;}
	| IfStmt {$$=$1;}
	| WhileStmt {$$=$1;}
	| DoWhile {$$=$1;}
	| RepUntil {$$=$1;}
	| BREAK ';' {$$=$1;}
	| CONTINUE ';' {$$=$1;}
	;

InputStmt : READ '(' expr ')' ';' {char *c="read";
				$$=makeOperatorNode(c,1,$3,NULL,NULL);}
	;
OutputStmt : WRITE '(' expr ')' ';' {char *c="write";
				$$=makeOperatorNode(c,2,$3,NULL,NULL);}
	;
AsgStmt : arrexpr '=' expr ';' {char *c="=";
$$=makeOperatorNode(c,3,$1,NULL,$3);}
	;
IfStmt : IF '(' E ')' THEN Slist ELSE Slist ENDIF ';' {char *c="if";$$=makeOperatorNode(c,10,$3,$6,$8);}
	| IF '(' E ')' THEN Slist ENDIF ';' {char *c="if";$$=makeOperatorNode(c,10,$3,$6,NULL);}
	;
DoWhile : DO Slist WHILE '(' E ')' ';' { char *c="dowhile";
$$=makeOperatorNode(c,19,$5,NULL,$2);}
	;
RepUntil : REPEAT Slist UNTIL '(' E ')' ';' {char *c="dowhile";
$$=makeOperatorNode(c,20,$5,NULL,$2);}
	;
WhileStmt : WHILE '(' E ')' DO Slist ENDWHILE ';' {char *c="while";
$$=makeOperatorNode(c,11,$3,NULL,$6);}		
	;


E : expr L expr {char *c="<";$$=makeOperatorNode(c,12,$1,NULL,$3);}
	| expr G expr {char *c=">";$$=makeOperatorNode(c,13,$1,NULL,$3);}
	| expr LE expr {char *c="<=";$$=makeOperatorNode(c,14,$1,NULL,$3);}
	| expr GE expr {char *c=">=";$$=makeOperatorNode(c,15,$1,NULL,$3);}
	| expr NE expr {char *c="!=";$$=makeOperatorNode(c,16,$1,NULL,$3);}
	| expr EE expr {char *c="==";$$=makeOperatorNode(c,17,$1,NULL,$3);}
	;
expr : expr '+' expr {char *c="+";$$=makeOperatorNode(c,5,$1,NULL,$3);}
	| expr '-' expr {char *c="-";$$=makeOperatorNode(c,6,$1,NULL,$3);}
	| expr '*' expr {char *c="*";$$=makeOperatorNode(c,7,$1,NULL,$3);}
	| expr '/' expr {char *c="/";$$=makeOperatorNode(c,8,$1,NULL,$3);}
	| expr '%' expr {char *c="%";$$=makeOperatorNode(c,9,$1,NULL,$3);}
	| '(' expr ')' {$$=$2;}
	| NUM {$$=$1;}
	| STRVAL {$$=$1;}
	| arr_expr {$$=$1;}
	;

arr_expr :  ID '[' expr ']' {$$=makeOperatorNode(NULL,22,$1,NULL,$3);
			}
	| ID {$$=$1;}
	|  ID '[' expr ']' '[' expr ']' {$$=makeOperatorNode(NULL,23,$1,$3,$5);
			}
	;
Declarations : DECL DeclList ENDDECL | DECL ENDDECL
DeclList : DeclList Decl | Decl
Decl : Type VarList ';'
Type : INT {type=1;size=1;}
	| STR {type=2;size=1;}
	;	
VarList : VarList ',' ID {insert($3->varname,type,size,0);}
	| ID {insert($1->varname,type,size,0);}
	| VarList ',' ID '[' NUM ']' {insert($3->varname,type,$5->val,0);}
	| ID '[' NUM ']' {insert($1->varname,type,$3->val,0);}
	| ID '[' NUM ']' '[' NUM ']' {insert($1->varname,type,$3->val,$5->val);}
	| VarList ',' ID '[' NUM ']' '[' NUM ']' {insert($3->varname,type,$5->val,$7->val);}
	;
%%
int yyerror(char *s)
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

}
return 1;
}
