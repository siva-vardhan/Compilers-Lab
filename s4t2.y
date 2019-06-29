%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "s4t2.h"
#include "s4t2.c"
FILE *yyin,*fp;
#define YYSTYPE tnode*
int yylex();
%}

%token NUM ID BEG END READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE L G LE GE NE EE REPEAT UNTIL BREAK CONTINUE DECL ENDDECL INT STR STRVAL
%left '+' '-'
%left '*' '/' '%'
%right '='

%%
Program : BEG Declarations Slist END ';' {printf("\n");print_tab(head);prefix($3);printf("\n");//evaluator($3);
					gencode($3);}
	| BEG Declarations END ';' {printf("\n");print_tab(head);}
	;
Slist : Slist Stmt {$$=makeOperatorNode(NULL,4,0,$1,NULL,$2);}
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

InputStmt : READ '(' arr_expr ')' ';' {char *c="read";
				$$=makeOperatorNode(c,1,0,$3,NULL,NULL);}
	;
OutputStmt : WRITE '(' expr ')' ';' {char *c="write";
				$$=makeOperatorNode(c,2,0,$3,NULL,NULL);}
	;
AsgStmt : arr_expr '=' expr ';' {char *c="=";
$$=makeOperatorNode(c,3,0,$1,NULL,$3);}
	;
IfStmt : IF '(' E ')' THEN Slist ELSE Slist ENDIF ';' {char *c="if";$$=makeOperatorNode(c,10,0,$3,$6,$8);}
	| IF '(' E ')' THEN Slist ENDIF ';' {char *c="if";$$=makeOperatorNode(c,10,0,$3,$6,NULL);}
	;
DoWhile : DO Slist WHILE '(' E ')' ';' { char *c="dowhile";
$$=makeOperatorNode(c,19,0,$5,NULL,$2);}
	;
RepUntil : REPEAT Slist UNTIL '(' E ')' ';' {char *c="dowhile";
$$=makeOperatorNode(c,20,0,$5,NULL,$2);}
	;
WhileStmt : WHILE '(' E ')' DO Slist ENDWHILE ';' {char *c="while";
$$=makeOperatorNode(c,11,0,$3,NULL,$6);}		
	;


E : expr L expr {char *c="<";$$=makeOperatorNode(c,12,0,$1,NULL,$3);}
	| expr G expr {char *c=">";$$=makeOperatorNode(c,13,0,$1,NULL,$3);}
	| expr LE expr {char *c="<=";$$=makeOperatorNode(c,14,0,$1,NULL,$3);}
	| expr GE expr {char *c=">=";$$=makeOperatorNode(c,15,0,$1,NULL,$3);}
	| expr NE expr {char *c="!=";$$=makeOperatorNode(c,16,0,$1,NULL,$3);}
	| expr EE expr {char *c="==";$$=makeOperatorNode(c,17,0,$1,NULL,$3);}
	;
expr : expr '+' expr {char *c="+";if($1->type!=$3->type) {printf("Type conflict\n");exit(1);}$$=makeOperatorNode(c,5,$1->type,$1,NULL,$3);}
	| expr '-' expr {char *c="-";$$=makeOperatorNode(c,6,$1->type,$1,NULL,$3);}
	| expr '*' expr {char *c="*";$$=makeOperatorNode(c,7,$1->type,$1,NULL,$3);}
	| expr '/' expr {char *c="/";$$=makeOperatorNode(c,8,$1->type,$1,NULL,$3);}
	| expr '%' expr {char *c="%";$$=makeOperatorNode(c,9,$1->type,$1,NULL,$3);}
	| '(' expr ')' {$$=$2;}
	| NUM {$$=$1;}
	| STRVAL {$$=$1;}
	| arr_expr {$$=$1;}
	
arr_expr : ID {$1->type=$1->Gentry->type;$$=$1;}
	|  ID '[' expr ']' {$$=makeOperatorNode(NULL,22,$1->Gentry->type,$1,NULL,$3);
			}
	;
Declarations : DECL DeclList ENDDECL | DECL ENDDECL
DeclList : DeclList Decl | Decl
Decl : Type VarList ';'
Type : INT {type=1;size=1;}
	| STR {type=2;size=1;}
	;	
VarList : VarList ',' ID {insert($3->varname,type,size);}
	| ID {insert($1->varname,type,size);}
	| VarList ',' ID '[' NUM ']' {insert($3->varname,type,$5->val);}
	| ID '[' NUM ']' {insert($1->varname,type,$3->val);}
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
