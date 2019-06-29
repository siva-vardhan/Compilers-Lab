%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "s6t1.h"
#include "s6t1.c"
FILE *yyin,*fp;
#define YYSTYPE tnode*
int yylex();
%}

%token NUM ID BEG END READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE L G LE GE NE EE REPEAT UNTIL BREAK CONTINUE DECL ENDDECL INT STR STRVAL MAIN RETURN TYPE ENDTYPE NUL ALLOC DEALLOC BOOLEAN VOID INIT
%left '+' '-'
%left '*' '/' '%'
%right '='

%%

Program : TDeclBlock GDeclBlock FDefBlock MainBlock {print_gtab(head);printf("\n");exit(1);}
	| TDeclBlock GDeclBlock MainBlock {print_gtab(head);printf("\n");exit(1);} 
	| TDeclBlock MainBlock {print_ltab(l1);printf("\n");exit(1);}
	;

TDeclBlock : TYPE TDeclList ENDTYPE | TYPE ENDTYPE
TDeclList : TDeclList TDecl | TDecl
TId : ID '{' {ttype=TInstall($1->varname,0,NULL);//$$=$1;
//print_t(T1);
	}
	;
TDecl : TId TDe '}' {//struct Typetable *t1=TLookup(type);
		ttype->fields=f1;ttype->size=ind;f1=NULL;ind=0;print_t(T1);}
	;

TDe : TDe TDec | TDec
TDec : Type Tidlist ';' 

Tidlist : Tidlist ',' ID {FInstall($3->varname,++ind,type);print_f(f1);}
	| ID {FInstall($1->varname,++ind,type);print_f(f1);}
	;

GDeclBlock : DECL GDeclList ENDDECL | DECL ENDDECL
GDeclList : GDeclList GDecl | GDecl
GDecl : Type GidList ';'
GidList : GidList ',' Gid | Gid
Gid : ID {GInstall($1->varname,type,size,NULL,-1);}
	| ID '[' NUM ']' {GInstall($1->varname,type,$3->val,NULL,-1);}
	| ID '(' ParamList ')' {GInstall($1->varname,type,0,h1,++fl);h1=NULL;}
	;
Type : INT {char *ch="int";type=TLookup(ch);size=1;}
	| STR {char *ch="str";type=TLookup(ch);size=1;}
	| ID {char *ch=strdup($1->varname);type=TLookup(ch);if(type==NULL)size=type->size;}	
	;

PType : INT {char *ch="int";ptype=TLookup(ch);size=1;}
	| STR {char *ch="str";ptype=TLookup(ch);size=1;}
	| ID {char *ch=strdup($1->varname);ptype=TLookup(ch);if(type==NULL)size=type->size;}	
	;
FDefBlock : FDefBlock FDef | FDef
FDef : Fdef '{' LdeclBlock Body '}' {//print_ltab(l1);printf("\n");
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

	 l1=NULL;

	}
	 ;
Fdef : Type ID '(' ParamList ')' {
	fnret=type;
	struct Gsymbol *temp=GLookup($2->varname);
	
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
		if(strcmp(t1->name,t2->name)!=0 || strcmp(t1->type->name,t2->type->name)!=0)
			{
			printf("Arguments of %s not matching\n",$2->varname);
			exit(1);
			}
		LInstall(t1->name,t1->type);
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
Param : PType ID {PInstall($2->varname,ptype);
			//printf("VVVVVVVVVVVVVVVV %s AAAAAAAAAAAAAAA",ptype->name);
		}

LdeclBlock : DECL LDecList ENDDECL {bin=0;}//{print_ltab(l1);printf("\n");} 
	| DECL ENDDECL {bin=0;}
	;
LDecList : LDecList LDecl | LDecl
LDecl : Type IdList ';'
IdList : IdList ',' ID  {LInstall($3->varname,type);}
	| ID {LInstall($1->varname,type);}
	;

expr :ID '(' ')' {
		struct Gsymbol *temp=GLookup($1->varname);
		if(temp==NULL)
			{
			printf("%s not declared\n",$1->varname);
			exit(1);
			}
		if(temp->paramlist!=NULL)
			{printf("Incorrect no of attributes for %s while calling\n",$1->varname);
			exit(1);
			} 
		temp=GLookup($1->varname);
		$$=makeOperatorNode($1->varname,-1,25,temp->type,NULL,NULL,NULL);
			
		}
			
			
	 | ID '(' ArgList ')' {//printf("\n\n\n");prefix($1);printf("\n\n");prefix($3);printf("\n\n\n");
	 			struct Gsymbol *temp=GLookup($1->varname);
				if(temp==NULL)
					{	
					printf("%s not declared\n",$1->varname);
					exit(1);
					}
				struct Paramstruct *t2=temp->paramlist;
				struct tnode *t1=$3;
				while(t1!=NULL && t2!=NULL)
					{
					if(strcmp(t1->type->name,t2->type->name)!=0)
						{
						printf("Incorrect type of attributes %s %s for %s while calling\n",t1->type->name,t2->type->name,$1->varname);
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
				temp=GLookup($1->varname);
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
	fprintf(fp,"MOV SP, %d\nMOV BP, %d\n",bind,bind);
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
Slist : Slist Stmt {$$=makeOperatorNode(NULL,-1,4,NULL,$1,NULL,$2);}
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
	| RETURN expr ';' {if(strcmp(fnret->name,$2->type->name)!=0) {printf("Return type Error");exit(1);} 
				char *c="return";
				$$=makeOperatorNode(c,-1,24,$2->type,$2,NULL,NULL);}
	| DEALLOC '(' expr ')' ';' {char *c="dealloc",*c2="int";$$=makeOperatorNode(c,-1,30,TLookup(c2),$3,NULL,NULL);}      
	;

InputStmt : READ '(' arr_expr ')' ';' {char *c="read";
				$$=makeOperatorNode(c,-1,1,NULL,$3,NULL,NULL);}
	;
OutputStmt : WRITE '(' expr ')' ';' {char *c="write";
				$$=makeOperatorNode(c,-1,2,NULL,$3,NULL,NULL);}
	;
AsgStmt : arr_expr '=' expr ';' {char *c="=";if($3->nodetype!=29 && ($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0)) {printf("Type conflict for %s = %d\n",$1->varname,$3->val);exit(1);}
				$$=makeOperatorNode(c,-1,3,NULL,$1,NULL,$3);
				if($1->type->size>8) 
					{
					printf("Too many member fields for %s\n",$1->varname);
					exit(1);
					}
				if($3->nodetype==29)
					$$->nodetype=27;
				}
	| arr_expr '=' NUL ';' {
				char *c="=";
				//printf("RRRRRRRRRRRRRRR %s %s EEEEEEEEEEEEEEEEEE",$1->type->name,$3->type->name);
				//if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) 
				 char *ch1="int",*ch2="str",*ch3="boolean",*ch4=$1->type->name;
				if(strcmp(ch4,ch1)==0 || strcmp(ch4,ch2)==0 || strcmp(ch4,ch3)==0)
					{
					printf("NULL not be defined in this way\n");
					exit(1);
					}
				$$=makeOperatorNode(c,-1,3,NULL,$1,NULL,$3);
				}
	;
IfStmt : IF '(' E ')' THEN Slist ELSE Slist ENDIF ';' {char *c="if";$$=makeOperatorNode(c,-1,10,NULL,$3,$6,$8);}
	| IF '(' E ')' THEN Slist ENDIF ';' {char *c="if";$$=makeOperatorNode(c,-1,10,NULL,$3,$6,NULL);}
	;
DoWhile : DO Slist WHILE '(' E ')' ';' { char *c="dowhile";
$$=makeOperatorNode(c,-1,19,NULL,$5,NULL,$2);}
	;
RepUntil : REPEAT Slist UNTIL '(' E ')' ';' {char *c="dowhile";
$$=makeOperatorNode(c,-1,20,NULL,$5,NULL,$2);}
	;
WhileStmt : WHILE '(' E ')' DO Slist ENDWHILE ';' {char *c="while";
$$=makeOperatorNode(c,-1,11,NULL,$3,NULL,$6);}		
	;


E : expr L expr {char *c="<";if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) {printf("Type conflict\n");exit(1);}$$=makeOperatorNode(c,-1,12,NULL,$1,NULL,$3);}
	| expr G expr {char *c=">";if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) {printf("Type conflict\n");exit(1);}$$=makeOperatorNode(c,-1,13,NULL,$1,NULL,$3);}
	| expr LE expr {char *c="<=";if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) {printf("Type conflict\n");exit(1);}$$=makeOperatorNode(c,-1,14,NULL,$1,NULL,$3);}
	| expr GE expr {char *c=">=";if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) {printf("Type conflict\n");exit(1);}$$=makeOperatorNode(c,-1,15,NULL,$1,NULL,$3);}
	| expr NE expr {char *c="!=";if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) {printf("Type conflict\n");exit(1);}$$=makeOperatorNode(c,-1,16,NULL,$1,NULL,$3);}
	| expr EE expr {char *c="==";if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) {printf("Type conflict\n");exit(1);}$$=makeOperatorNode(c,-1,17,NULL,$1,NULL,$3);}
	| expr NE NUL {char *c="!=";//if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) 
			char *ch1="int",*ch2="str",*ch3="boolean",*ch4=$1->type->name;
				if(strcmp(ch4,ch1)==0 || strcmp(ch4,ch2)==0 || strcmp(ch4,ch3)==0)
			{printf("Type conflict\n");exit(1);}$$=makeOperatorNode(c,-1,16,NULL,$1,NULL,$3);}
	| expr EE NUL {char *c="==";//if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) 
			char *ch1="int",*ch2="str",*ch3="boolean",*ch4=$1->type->name;
				if(strcmp(ch4,ch1)==0 || strcmp(ch4,ch2)==0 || strcmp(ch4,ch3)==0){printf("Type conflict\n");exit(1);}$$=makeOperatorNode(c,-1,17,NULL,$1,NULL,$3);}
	;
expr : expr '+' expr {char *c="+";if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) {printf("Type conflict\n");exit(1);}$$=makeOperatorNode(c,-1,5,$1->type,$1,NULL,$3);}
	| expr '-' expr {char *c="-";if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) {printf("Type conflict\n");exit(1);}$$=makeOperatorNode(c,-1,6,$1->type,$1,NULL,$3);}
	| expr '*' expr {char *c="*";if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) {printf("Type conflict\n");exit(1);}$$=makeOperatorNode(c,-1,7,$1->type,$1,NULL,$3);}
	| expr '/' expr {char *c="/";if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) {printf("Type conflict\n");exit(1);}$$=makeOperatorNode(c,-1,8,$1->type,$1,NULL,$3);}
	| expr '%' expr {char *c="%";if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) {printf("Type conflict\n");exit(1);}$$=makeOperatorNode(c,-1,9,$1->type,$1,NULL,$3);}
	| '(' expr ')' {$$=$2;}
	| NUM {$$=$1;}
	| STRVAL {$$=$1;}
	| arr_expr {$$=$1;}
	;
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
	| Field {$$=$1;}
	;
	
Field : Field '.' ID {
			$$=$1;
			$$->type=(FLookup($1->type,$3->varname))->type;
			$1=$$;
			while($1->left!=NULL)
				$1=$1->left;
			$1->left=$3;

		     }
		     
	| ID '.' ID {
		
			$$=$1;
			$$->nodetype=28;
			$$->left=$3;
		$3->left=NULL;
		$3->mid=NULL;
		$3->right=NULL;
			$1->Gentry=GLookup($1->varname);
			$1->Lentry=LLookup($1->varname);
			
			if($1->Lentry!=NULL)			
				$1->type=$1->Lentry->type;
			else if($1->Gentry!=NULL)
				$1->type=$1->Gentry->type;
			else
				{
				printf("variable not declared\n");
				exit(1);
				}

			
			struct Fieldlist *ft=FLookup($1->type,$3->varname);
			if(ft==NULL)
				{
				printf("Variable cannot be accessed\n");
				exit(1);
				}
			$$->type=ft->type;
	

	
			}
	| ALLOC '(' ')' {char *c="alloc",*c2="int";$$=makeOperatorNode(c,-1,29,TLookup(c2),NULL,NULL,NULL);
		//printf("RRRRRRRRRR ");//$$=makeOperatorNode(c3,-1,3,0,$1,NULL,$2);prefix($$);printf("DDDDDDDDDDD\n");
				}
	| INIT '(' ')' {char *c="initialize",*c2="int";$$=makeOperatorNode(c,-1,31,TLookup(c2),NULL,NULL,NULL);}
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
TypeTableCreate();
yyparse();
fclose(fp);
}
return 1;
}

