%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "s5t1.h"
#include "s5t1.c"
FILE *yyin,*fp;
#define YYSTYPE tnode*
int yylex();
%}

%token NUM ID BEG END READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE L G LE GE NE EE REPEAT UNTIL BREAK CONTINUE DECL ENDDECL INT STR STRVAL MAIN RETURN
%left '+' '-'
%left '*' '/' '%'
%right '='

%%

Program : GDeclBlock FDefBlock MainBlock {print_gtab(head);printf("\n");exit(1);}
	| GDeclBlock MainBlock {print_gtab(head);printf("\n");exit(1);} 
	| MainBlock {print_ltab(l1);printf("\n");exit(1);}
	;
GDeclBlock : DECL GDeclList ENDDECL | DECL ENDDECL
GDeclList : GDeclList GDecl | GDecl
GDecl : Type GidList ';'
GidList : GidList ',' Gid | Gid
Gid : ID {Ginsert($1->varname,type,size,NULL,-1);}
	| ID '[' NUM ']' {Ginsert($1->varname,type,$3->val,NULL,-1);}
	| ID '(' ParamList ')' {Ginsert($1->varname,type,0,h1,++fl);h1=NULL;}
	;
Type : INT {type=1;size=1;}
	| STR {type=2;size=1;}
	;


FDefBlock : FDefBlock FDef | FDef
FDef : Fdef '{' LdeclBlock Body '}' {print_ltab(l1);printf("\n");
	struct Lsymbol *t1=l1;
	//print_ltab(t1);
	//printf("i=%d\n",i);
if(i>1 && t1!=NULL)
	while(t1!=NULL && i!=(t1->binding))
		{
		//printf("\ni=%d Name : %s binding=%d\n",i,t1->name,t1->binding);
		t1=t1->next;
			}
			//printf("SIVY\n");
	if(l1!=NULL)	
	while(t1!=NULL)
		{
		fprintf(fp,"PUSH R0\n");
		t1=t1->next;
		}
		//printf("ISVN\n");
	i=1;
	gencode($4);
	 l1=NULL;}
	 ;
Fdef : Type ID '(' ParamList ')' {
	fnret=type;
	struct Gsymbol *temp=Lookup($2->varname);
	
	fprintf(fp,"F%d:\n",temp->flabel);
	fprintf(fp,"PUSH BP\nMOV BP,SP\n");
	if(temp==NULL)
		{
		printf("%s not declared\n",$2->varname);
		exit(1);
		}
	struct Paramstruct *t1=h1,*t2=temp->paramlist;
	h1=NULL;
	i=1;
	int p,q;
	p=getReg();
	q=getReg();
	while(t1!=NULL && t2!=NULL)
		{
		if(strcmp(t1->name,t2->name)!=0 || t1->type!=t2->type)
			{
			printf("Arguments of %s not matching\n",$2->varname);
			exit(1);
			}
		Linsert(t1->name,t1->type);
		fprintf(fp,"MOV R%d,BP\n",p);
		fprintf(fp,"MOV R%d,%d\n",q,i+2);
		fprintf(fp,"SUB R%d, R%d\n",p,q);
		fprintf(fp,"MOV R0,[R%d]\n",p);
		i++;
		fprintf(fp,"PUSH R0\n");
		t1=t1->next;
		t2=t2->next;
		
		}
	freeReg();
	freeReg();		
	if(t1!=NULL || t2!=NULL)
		{
		printf("Arguments of %s not matching\n",$2->varname);
		exit(1);
		}
	
	}	
	;
ParamList : ParamList ',' Param | Param | 
Param : Type ID {Pinsert($2->varname,type);}

LdeclBlock : DECL LDecList ENDDECL {bin=0;}//{print_ltab(l1);printf("\n");} 
	| DECL ENDDECL {bin=0;}
	;
LDecList : LDecList LDecl | LDecl
LDecl : Type IdList ';'
IdList : IdList ',' ID  {Linsert($3->varname,type);}
	| ID {Linsert($1->varname,type);}
	;

expr :ID '(' ')' {
		struct Gsymbol *temp=Lookup($1->varname);
		if(temp==NULL)
			{
			printf("%s not declared\n",$1->varname);
			exit(1);
			}
		if(temp->paramlist!=NULL)
			{printf("Incorrect no of attributes for %s while calling\n",$1->varname);
			exit(1);
			} 
		temp=Lookup($1->varname);
		$$=makeOperatorNode($1->varname,-1,25,temp->type,NULL,NULL,NULL);
			
		}
			
			
	 | ID '(' ArgList ')' {printf("\n\n\n");prefix($1);printf("\n\n");prefix($3);printf("\n\n\n");
	 			struct Gsymbol *temp=Lookup($1->varname);
				if(temp==NULL)
					{	
					printf("%s not declared\n",$1->varname);
					exit(1);
					}
				struct Paramstruct *t2=temp->paramlist;
				struct tnode *t1=$3;
				while(t1!=NULL && t2!=NULL)
					{
					if(t1->type!=t2->type)
						{
						printf("Incorrect type of attributes for %s while calling\n",$1->varname);
						exit(1);
						}
					t1=t1->mid;		
					t2=t2->next;
					}		
				if(t1!=NULL || t2!=NULL)
					{
					printf("Incorrect no of attributes for %s while calling\n",$1->varname);
					exit(1);
					}
				temp=Lookup($1->varname);
				$$=makeOperatorNode($1->varname,-1,25,temp->type,$3,NULL,NULL);
			
	 			}
ArgList : ArgList ',' expr {$$=$1;
			while($1->mid!=NULL)
				$1=$1->mid;
			$1->mid=$3;

			}
	| expr {$$=$1;}
	;

MainBlock : INT MAIN '(' ')' '{' LdeclBlock Body '}'
	{
	fprintf(fp,"M1:\n");
	fprintf(fp,"MOV SP, %d\nMOV BP, %d\n",bind-1,bind);
	struct Lsymbol *t1=l1;
	int p=getReg();
	while(t1!=NULL){
		fprintf(fp,"PUSH R%d\n",p);
		t1=t1->next;
		}
	freeReg();
	gencode($7);
	l1=NULL;
	print_ltab(l1);printf("\n");
	 
	 l1=NULL;
	}
	;
Body : BEG Slist END  {printf("\n");prefix($2);printf("\n");//evaluator($3);
	$$=$2;
	//gencode($2);
	//l1=NULL;
	}
	| BEG END  //{printf("\n");print_gtab(head);}
	;
Slist : Slist Stmt {$$=makeOperatorNode(NULL,-1,4,0,$1,NULL,$2);}
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
	| RETURN expr ';' {if(fnret!=$2->type) {printf("Return type Error");exit(1);} char c[]="return";char *ch=strdup(c);
	         $$=makeOperatorNode(ch,-1,24,$2->type,$2,NULL,NULL);}
	;

InputStmt : READ '(' arr_expr ')' ';' {char *c="read";
				$$=makeOperatorNode(c,-1,1,0,$3,NULL,NULL);}
	;
OutputStmt : WRITE '(' expr ')' ';' {char *c="write";
				$$=makeOperatorNode(c,-1,2,0,$3,NULL,NULL);}
	;
AsgStmt : arr_expr '=' expr ';' {char *c="=";if($1->type!=$3->type) {printf("Type conflict\n");exit(1);}
$$=makeOperatorNode(c,-1,3,0,$1,NULL,$3);}
	;
IfStmt : IF '(' E ')' THEN Slist ELSE Slist ENDIF ';' {char *c="if";$$=makeOperatorNode(c,-1,10,0,$3,$6,$8);}
	| IF '(' E ')' THEN Slist ENDIF ';' {char *c="if";$$=makeOperatorNode(c,-1,10,0,$3,$6,NULL);}
	;
DoWhile : DO Slist WHILE '(' E ')' ';' { char *c="dowhile";
$$=makeOperatorNode(c,-1,19,0,$5,NULL,$2);}
	;
RepUntil : REPEAT Slist UNTIL '(' E ')' ';' {char *c="dowhile";
$$=makeOperatorNode(c,-1,20,0,$5,NULL,$2);}
	;
WhileStmt : WHILE '(' E ')' DO Slist ENDWHILE ';' {char *c="while";
$$=makeOperatorNode(c,-1,11,0,$3,NULL,$6);}		
	;


E : expr L expr {char *c="<";if($1->type!=$3->type) {printf("Type conflict\n");exit(1);}$$=makeOperatorNode(c,-1,12,0,$1,NULL,$3);}
	| expr G expr {char *c=">";if($1->type!=$3->type) {printf("Type conflict\n");exit(1);}$$=makeOperatorNode(c,-1,13,0,$1,NULL,$3);}
	| expr LE expr {char *c="<=";if($1->type!=$3->type) {printf("Type conflict\n");exit(1);}$$=makeOperatorNode(c,-1,14,0,$1,NULL,$3);}
	| expr GE expr {char *c=">=";if($1->type!=$3->type) {printf("Type conflict\n");exit(1);}$$=makeOperatorNode(c,-1,15,0,$1,NULL,$3);}
	| expr NE expr {char *c="!=";if($1->type!=$3->type) {printf("Type conflict\n");exit(1);}$$=makeOperatorNode(c,-1,16,0,$1,NULL,$3);}
	| expr EE expr {char *c="==";if($1->type!=$3->type) {printf("Type conflict\n");exit(1);}$$=makeOperatorNode(c,-1,17,0,$1,NULL,$3);}
	;
expr : expr '+' expr {char *c="+";if($1->type!=$3->type) {printf("Type conflict\n");exit(1);}$$=makeOperatorNode(c,-1,5,$1->type,$1,NULL,$3);}
	| expr '-' expr {char *c="-";if($1->type!=$3->type) {printf("Type conflict\n");exit(1);}$$=makeOperatorNode(c,-1,6,$1->type,$1,NULL,$3);}
	| expr '*' expr {char *c="*";if($1->type!=$3->type) {printf("Type conflict\n");exit(1);}$$=makeOperatorNode(c,-1,7,$1->type,$1,NULL,$3);}
	| expr '/' expr {char *c="/";if($1->type!=$3->type) {printf("Type conflict\n");exit(1);}$$=makeOperatorNode(c,-1,8,$1->type,$1,NULL,$3);}
	| expr '%' expr {char *c="%";if($1->type!=$3->type) {printf("Type conflict\n");exit(1);}$$=makeOperatorNode(c,-1,9,$1->type,$1,NULL,$3);}
	| '(' expr ')' {$$=$2;}
	| NUM {$$=$1;}
	| STRVAL {$$=$1;}
	| arr_expr {$$=$1;}
	
arr_expr : ID {
	if($1->Lentry!=NULL) 
		$1->type=$1->Lentry->type;
	else if($1->Gentry!=NULL)
		$1->type=$1->Gentry->type;
	else
		{printf("%s not declared\n",$1->varname);
		exit(1);}			
	$$=$1;}
	|  ID '[' expr ']' {$$=makeOperatorNode(NULL,-1,22,$1->Gentry->type,$1,NULL,$3);
			}
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
fprintf(fp,"0\nM1\n0\n0\n0\n0\n0\n0\n");
yyparse();
fclose(fp);
}
return 1;
}

