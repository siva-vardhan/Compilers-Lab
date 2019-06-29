%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "s8t1.h"
#include "s8t1.c"
FILE *yyin,*fp;
#define YYSTYPE tnode*
int yylex();
%}

%token NUM ID BEG END READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE L G LE GE NE EE REPEAT UNTIL BREAK CONTINUE DECL ENDDECL INT STR STRVAL MAIN RETURN TYPE ENDTYPE NUL ALLOC DEALLOC BOOLEAN VOID INIT CLASS ENDCLASS SELF NEW DELETE EXTENDS
%left '+' '-'
%left '*' '/' '%'
%right '='

%%

Program : TDeclBlock ClassDefBlock GDeclBlock FDefBlock MainBlock {print_gtab(head);printf("\n");print_ltab(l1);printf("\n");print_classtable(c1);exit(1);}
	| TDeclBlock ClassDefBlock GDeclBlock MainBlock {print_gtab(head);printf("\n");print_ltab(l1);printf("\n");print_classtable(c1);exit(1);} 
	| TDeclBlock ClassDefBlock MainBlock {/*print_ltab(l1);printf("\n");*/exit(1);}
	;

ClassDefBlock : CLASS ClassDefList ENDCLASS //{print_classtable(c1);}
		|
		;
ClassDefList : ClassDefList ClassDef
		| ClassDef
		;
ClassDef : Cname '{' DECL Fieldlists MethodDecl ENDDECL MethodDefns'}' {Cptr->fieldcount=fc;Cptr->methodcount=mc;bind=bind+8;/*print_classtable(Cptr);*/}
	;
Cname : ID {Cptr=CInstall($1->varname,NULL);fc=0;mc=0;}
	| ID EXTENDS ID {Cptr=CInstall($1->varname,$3->varname);
			int i;
			for(i=0;i<8;i++)
				mcheck[i]=0;
			}
	;
Fieldlists : Fieldlists FId
	| 
	;
FId : Typef ID ';' {Class_FInstall(Cptr,typ,$2->varname);}
	| ID ID ';' {Class_FInstall(Cptr,$1->varname,$2->varname);}
	;
Typef : INT {char *ch="int";typ=strdup(ch);}//type=TLookup(ch);size=1;ctype=CLookup(ch);}
	| STR {char *ch="str";typ=strdup(ch);}//type=TLookup(ch);size=1;ctype=CLookup(ch);}

	;

MethodDecl : MethodDecl MDecl
		| MDecl
		;
MDecl : Typef ID '(' ParamList ')' ';' {++fl;Class_MInstall(Cptr,$2->varname,typ,h1);mc++;h1=NULL;}
	| ID ID '(' ParamList ')' ';'  {++fl;Class_MInstall(Cptr,$2->varname,$1->varname,h1);mc++;h1=NULL;}
	;

MethodDefns : MethodDefns FDef
		| FDef
		;
		
Stmt : arr_expr '=' NEW '(' ID ')' ';'  {
					/*$1->Lentry=LLookup($1->varname);
					if($1->Lentry!=NULL)
						{
						$1->ctype=$1->Lentry->ctype;
						$1->type=$1->Lentry->type;
						}
					else
						{
						$1->Gentry=GLookup($1->varname);
						if($1->Gentry!=NULL)
							{
							$1->ctype=$1->Gentry->ctype;
							$1->type=$1->Gentry->type;
							}
						}
					*/
						//printf("siva %s %s siva\n",$1->ctype->name,$5->varname);
					if($1->ctype==NULL)
						{
						
						printf("Types %s %s not matched to create new\n",$1->ctype->name,$5->varname);
						exit(1); 
						}
					if(strcmp($1->ctype->name,$5->varname)!=0)
						{
						struct Classtable *cc1=CLookup($5->varname);
						
						while(cc1!=NULL && strcmp(cc1->name,$1->ctype->name)!=0)
							cc1=cc1->parentptr;
						if(cc1==NULL)
							{
							printf("Types %s %s not matched to create new\n",$1->ctype->name,$5->varname);
							exit(1);
							}
						}
					char *c="new",*c2="int",*c3="=";
					$3=makeOperatorNode(c,-1,29,TLookup(c2),$5,NULL,NULL);
					$$=makeOperatorNode(c3,-1,36,NULL,$1,NULL,$3);
				    }
	| DELETE '(' Field ')' ';'     {
					char *c="dealloc",*c2="int";
					$$=makeOperatorNode(c,-1,30,TLookup(c2),$3,NULL,NULL);
				      }
	;


FieldFunction : SELF '.' ID '(' ArgList ')' {
						char *c="self";
					   	$$=makeOperatorNode(c,-1,33,NULL,$3,NULL,NULL);
			
						$3->left=$5;
						//$$->type=$3->type;
						
						struct Memberfunclist *temp=Class_MLookup(Cptr,$3->varname);
						if(temp==NULL)
							{
							printf("Method %s not declared in class %s\n",$3->varname,Cptr->name);
							exit(1);
							}
						$$->type=temp->type;					    
						struct Paramstruct *t2=temp->paramlist;
						struct tnode *t1=$5;
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
							
					    
					    }


		| ID '.' ID '(' ArgList ')'  {
					    	$$=$1;
						$$->nodetype=34;
						$$->left=$3;
							$3->left=$5;
						//$$->type=$3->type;
						struct Classtable *tt;
						//$1->Lentry=LLookup($1->varname);
						//if($1->Lentry!=NULL)
						//	$1->ctype=$1->Lentry->ctype;
						//else
						//	{
							$1->Gentry=GLookup($1->varname);
							if($1->Gentry!=NULL)
								$1->ctype=$1->Gentry->ctype;
							else
								{
								printf("Variable %s not declared \n",$1->varname);
								exit(1);
								}
						//	}
						tt=$1->ctype;		
						struct Memberfunclist *temp=Class_MLookup(tt,$3->varname);
						if(temp==NULL)
							{
							printf("Method %s not declared in class %s\n",$3->varname,tt->name);
							exit(1);
							}
						$$->type=temp->type;					    
						struct Paramstruct *t2=temp->paramlist;
						struct tnode *t1=$5;
						//int ccc=0;
						//printf("vard\n");
						//	if(strcmp($1->varname,"second")==0)
						//		{
						//		printf("%s \n",t1->varname);
								
						//		}
						//	printf("vard\n");
							
						//	t1=$5;
						while(t1!=NULL && t2!=NULL)
							{
							if(strcmp(t1->type->name,t2->type->name)!=0)
								{
								printf("Incorrect type of attributes %s %s for %s while calling\n",t1->type->name,t2->type->name,$1->varname);				
								
								exit(1);
								}
							//if(strcmp($1->varname,"second")==0)
							//printf("\nCompared %s %s %d\n",t1->type->name,t2->type->name,++ccc);
							t1=t1->mid;		
							t2=t2->next;
							}		
						if(t1!=NULL || t2!=NULL)
							{
							printf("Incorrect no of attributes for %s while calling\n",$1->varname);
							//printf("vvvvvvvvvvvvvvvvvvv\n");
							//prefix($5);
							//	printf("SSSSSSSSSSSS\n");
							//	print_par(temp->paramlist);
							//	printf("\n\n");
							//printf("vardhan\n");
							//prefix(t1);
							//printf("siva\n");
							//print_par(t2);
							exit(1);
							}

						struct Classtable *cc1=GLookup($1->varname)->ctype;
						if(Class_MLookup(cc1,$3->varname)==NULL)
							{
							printf("Compilation error due to function %s not declared in parent section %s\n",$3->varname,cc1->name);
							exit(1);
							}
					     }

	
		| Field '.' ID '(' ArgList ')' 	{
						   	$$=$1;
							$$->nodetype=35;
							
							struct tnode *tt1=$1;
							if(tt1->left->left!=NULL)
								{
								printf("Members cannot be accessed\n");
								exit(1);
								}
							//while(tt1->left!=NULL)
							//	tt1=tt1->left;
							tt1->left->left=$3;
							$3->left=$5;
							//$$->type=$3->type;
							struct Classtable *tt=CLookup(tt1->varname);	
							struct Memberfunclist *temp=Class_MLookup($$->ctype,$3->varname);
							if(temp==NULL)
								{
								printf("Method %s not declared in class %s\n",$3->varname,tt->name);
								exit(1);
								}
							$$->type=temp->type;					    
							struct Paramstruct *t2=temp->paramlist;
							struct tnode *t1=$5;
							
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


						}
		| SELF '.' ID '(' ')'   {
						char *c="self";
					   	$$=makeOperatorNode(c,-1,33,NULL,$3,NULL,NULL);
						$3->left=NULL;
						//$$->type=$3->type;
						
						struct Memberfunclist *temp=Class_MLookup(Cptr,$3->varname);
						if(temp==NULL)
							{
							printf("Method %s not declared in class %s\n",$3->varname,Cptr->name);
							exit(1);
							}
						$$->type=temp->type;					    
						struct Paramstruct *t2=temp->paramlist;
						if(t2!=NULL)
							{
							printf("Incorrect no of attributes for %s while calling\n",$1->varname);
							exit(1);
							}

					}
		| ID '.' ID '(' ')'     {
		
						$$=$1;
						$$->nodetype=34;
						$$->left=$3;
							$3->left=NULL;
						//$$->type=$3->type;
						
						struct Classtable *tt;
						//$1->Lentry=LLookup($1->varname);
						//if($1->Lentry!=NULL)
						//	$1->ctype=$1->Lentry->ctype;
						//else
						//	{
							$1->Gentry=GLookup($1->varname);
							if($1->Gentry!=NULL)
								$1->ctype=$1->Gentry->ctype;
							else
								{
								printf("Variable %s not declared \n",$1->varname);
								exit(1);
								}
						//	}
						tt=$1->ctype;		
						struct Memberfunclist *temp=Class_MLookup(tt,$3->varname);
						if(temp==NULL)
							{
							printf("Method %s not declared in class %s\n",$3->varname,tt->name);
							exit(1);
							}
							
						$$->type=temp->type;					    
						struct Paramstruct *t2=temp->paramlist;

				
						if(t2!=NULL)
							{
							printf("Incorrect no of attributes for %s while calling\n",$1->varname);
							exit(1);
							}
						struct Classtable *cc1=GLookup($1->varname)->ctype;
						if(Class_MLookup(cc1,$3->varname)==NULL)
							{
							printf("Compilation error due to function %s not declared in parent section %s\n",$3->varname,cc1->name);
							exit(1);
							}


					}
					
		| Field '.' ID '(' ')'  {
					   	$$=$1;
						$$->nodetype=35;

						struct tnode *tt1=$1;
						if(tt1->left->left!=NULL)
								{
								printf("Members cannot be accessed\n");
								exit(1);
								}
						//while(tt1->left!=NULL)
						//	tt1=tt1->left;
						tt1->left->left=$3;
						$3->left=NULL;
						//$$->type=$3->type;
						struct Classtable *tt=CLookup(tt1->varname);	
						struct Memberfunclist *temp=Class_MLookup(tt,$3->varname);
						if(temp==NULL)
							{
							printf("Method %s not declared in class %s\n",$3->varname,tt->name);
							exit(1);
							}
						$$->type=temp->type;					    
						struct Paramstruct *t2=temp->paramlist;
				
						if(t2!=NULL)
							{
							printf("Incorrect no of attributes for %s while calling\n",$1->varname);
							exit(1);
							}
	

					}
		
		;




TDeclBlock : TYPE TDeclList ENDTYPE | TYPE ENDTYPE
TDeclList : TDeclList TDecl | TDecl
TId : ID '{' {type=TInstall($1->varname,0,NULL);//$$=$1;
//print_t(T1);
	}
	;
TDecl : TId TDe '}' {//struct Typetable *t1=TLookup(type);
		type->fields=f1;type->size=ind;f1=NULL;ind=0;/*print_t(T1);*/}
	;

TDe : TDe TDec | TDec
TDec : Type Tidlist ';' 

Tidlist : Tidlist ',' ID {FInstall($3->varname,++ind,typ);/*print_f(f1);*/}
	| ID {FInstall($1->varname,++ind,typ);/*print_f(f1);*/}
	;

GDeclBlock : DECL GDeclList ENDDECL | DECL ENDDECL
GDeclList : GDeclList GDecl | GDecl
GDecl : Type GidList ';'
GidList : GidList ',' Gid | Gid
Gid : ID {GInstall($1->varname,typ,size,NULL,-1);}
	| ID '[' NUM ']' {GInstall($1->varname,typ,$3->val,NULL,-1);}
	| ID '(' ParamList ')' {GInstall($1->varname,typ,0,h1,++fl);h1=NULL;}
	;
Type : INT {char *ch="int";typ=strdup(ch);type=TLookup(ch);size=1;ctype=CLookup(ch);}
	| STR {char *ch="str";typ=strdup(ch);type=TLookup(ch);size=1;ctype=CLookup(ch);}
	| ID {char *ch=strdup($1->varname);typ=strdup(ch);type=TLookup(ch);
		if(type!=NULL) size=type->size;ctype=CLookup(ch);}	
	;

PType : INT {char *ch="int";ptype=TLookup(ch);size=1;}
	| STR {char *ch="str";ptype=TLookup(ch);size=1;}
	| ID {char *ch=strdup($1->varname);ptype=TLookup(ch);if(ptype!=NULL)size=ptype->size;}	
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
		if(strcmp(t1->name,"self")!=0)
			fprintf(fp,"PUSH R0\n");
		t1=t1->next;
		}
		//printf("ISVN\n");
	i=1;
//exit(1);
	gencode($4);
					print_ltab(l1);
	//exit(1); 
	 l1=NULL;

	}
	 ;
Fdef : Type ID '(' ParamList ')' {

	fnret=type;

	struct Gsymbol *temp=GLookup($2->varname);
	struct Memberfunclist *f1=NULL;
	if(temp==NULL)
		f1=Class_MLookup(Cptr,$2->varname);

	if(temp==NULL && f1==NULL)
		{
		printf("%s not declared\n",$2->varname);
		exit(1);
		}
	if(temp!=NULL)
		fprintf(fp,"F%d:\n",temp->flabel);
	else 
		fprintf(fp,"F%d:\n",f1->flabel);
	fprintf(fp,"PUSH BP\nMOV BP,SP\n");
	
	
		
	struct Paramstruct *t1=h1,*t2;
	if(temp!=NULL)
		t2=temp->paramlist;
	else
		t2=f1->paramlist;
	h1=NULL;
	i=1;
	int p,q;
	p=getReg();
	q=getReg();
	
	s1=0;
	while(t1!=NULL && t2!=NULL)
		{
		if(strcmp(t1->name,t2->name)!=0 || strcmp(t1->type->name,t2->type->name)!=0)
			{
			printf("Arguments of %s not matching\n",$2->varname);
			exit(1);
			}
		LInstall(t1->name,t1->type->name);
		fprintf(fp,"MOV R%d,BP\n",p);
		fprintf(fp,"MOV R%d,%d\n",q,i+2);
		fprintf(fp,"SUB R%d, R%d\n",p,q);
		fprintf(fp,"MOV R0,[R%d]\n",p);
		i++;
		fprintf(fp,"PUSH R0\n");
		t1=t1->next;
		t2=t2->next;
		s1++;
		}
	//if(l1!=NULL)
	//	l1->self=s1+2;
	char *s="self";
	char *st="int";
	LInstall(s,st);
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
IdList : IdList ',' ID  {if(type==NULL)	
			{
			printf("The field %s cannot be installed locally\n",$3->varname);
			exit(1);
			}
			LInstall($3->varname,type->name);}
	| ID {if(type==NULL)	
			{
			printf("The field %s cannot be installed locally\n",$1->varname);
			exit(1);
			}
			LInstall($1->varname,type->name);}
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
	fill_class(c1);
	struct Lsymbol *t1=l1;
	int p=getReg();
	while(t1!=NULL){
		fprintf(fp,"PUSH R%d\n",p);
		t1=t1->next;
		}
	freeReg();
//exit(1);
	gencode($7);
//exit(1);
	//print_ltab(l1);printf("\n");
	// printf("SSSSSSSSSSSSSSSSSSSSSSS           fn_name : %s   self : %d      dddddddddddddddddddddddd\n",l1->
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
AsgStmt : arr_expr '=' expr ';' {
				char *c="=";
				if($3->ctype!=NULL && $3->ctype->name!=NULL && $3->left==NULL && $3->right==NULL && $3->mid==NULL && CLookup($3->ctype->name)!=NULL)
					{

					if(GLookup($1->varname)==NULL || GLookup($3->varname)==NULL)
						{
						printf("ID = ID is not valid for %s, %s\n",$1->varname,$3->varname);
						exit(1);
						}
					$1->ctype=GLookup($1->varname)->ctype;
					$3->ctype=GLookup($3->varname)->ctype;
					if($1->ctype==NULL || $3->ctype==NULL)
						{
						printf("ID = ID is not valid for types %s, %s\n",$1->varname,$3->varname);
						exit(1);
						}
					if(strcmp($1->ctype->name,$3->ctype->name)!=0 && $3->ctype->parentptr==NULL)
						{
						printf("ID = ID is not valid for %s, %s with types %s %s\n",$1->varname,$3->varname,$1->ctype->name,$3->ctype->name);
						exit(1);
						}
					struct Classtable *tt1=$3->ctype->parentptr;
					while(tt1!=NULL)
						{
						if(strcmp($1->ctype->name,tt1->name)==0)
							break;
						tt1=tt1->parentptr;
						}
					if(strcmp($1->ctype->name,$3->ctype->name)==0 || tt1!=NULL)
						{
						$$=makeOperatorNode(c,-1,37,NULL,$1,NULL,$3);
						}
					else
						{
						printf("ID = ID is invalid operation for %s, %s\n",$1->varname,$3->varname);
						exit(1);
						}
					
					}
				else
					{
					if($3->nodetype!=29 && ($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0)) 						{
						printf("Type conflict for %s = %d\n",$1->varname,$3->val);
						exit(1);
						}
					$$=makeOperatorNode(c,-1,3,NULL,$1,NULL,$3);
					if($1->type->size>8) 
						{
						printf("Too many member fields for %s\n",$1->varname);
						exit(1);
						}
					if($3->nodetype==29)
						$$->nodetype=27;
					}
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


E : expr L expr {char *c="<";if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) {printf("Type conflict <\n");exit(1);}$$=makeOperatorNode(c,-1,12,NULL,$1,NULL,$3);}
	| expr G expr {char *c=">";if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) {printf("Type conflict >\n");exit(1);}$$=makeOperatorNode(c,-1,13,NULL,$1,NULL,$3);}
	| expr LE expr {char *c="<=";if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) {printf("Type conflict <=\n");exit(1);}$$=makeOperatorNode(c,-1,14,NULL,$1,NULL,$3);}
	| expr GE expr {char *c=">=";if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) {printf("Type conflict >=\n");exit(1);}$$=makeOperatorNode(c,-1,15,NULL,$1,NULL,$3);}
	| expr NE expr {char *c="!=";if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) {printf("Type conflict !=\n");exit(1);}$$=makeOperatorNode(c,-1,16,NULL,$1,NULL,$3);}
	| expr EE expr {char *c="==";if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) {printf("Type conflict ==\n");exit(1);}$$=makeOperatorNode(c,-1,17,NULL,$1,NULL,$3);}
	| expr NE NUL {char *c="!=";//if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) 
			char *ch1="int",*ch2="str",*ch3="boolean",*ch4=$1->type->name;
				if(strcmp(ch4,ch1)==0 || strcmp(ch4,ch2)==0 || strcmp(ch4,ch3)==0)
			{printf("Type conflict !=null\n");exit(1);}$$=makeOperatorNode(c,-1,16,NULL,$1,NULL,$3);}
	| expr EE NUL {char *c="==";//if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) 
			char *ch1="int",*ch2="str",*ch3="boolean",*ch4=$1->type->name;
				if(strcmp(ch4,ch1)==0 || strcmp(ch4,ch2)==0 || strcmp(ch4,ch3)==0){printf("Type conflict ==null\n");exit(1);}$$=makeOperatorNode(c,-1,17,NULL,$1,NULL,$3);}
	;
expr : expr '+' expr {char *c="+";if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) {printf("Type conflict +\n");exit(1);}$$=makeOperatorNode(c,-1,5,$1->type,$1,NULL,$3);}
	| expr '-' expr {char *c="-";if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) {printf("Type conflict -\n");exit(1);}$$=makeOperatorNode(c,-1,6,$1->type,$1,NULL,$3);}
	| expr '*' expr {char *c="*";if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) {printf("Type conflict *\n");exit(1);}$$=makeOperatorNode(c,-1,7,$1->type,$1,NULL,$3);}
	| expr '/' expr {char *c="/";if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) {printf("Type conflict /\n");exit(1);}$$=makeOperatorNode(c,-1,8,$1->type,$1,NULL,$3);}
	| expr '%' expr {char *c="%";if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) {printf("Type conflict \"%\"\n");exit(1);}$$=makeOperatorNode(c,-1,9,$1->type,$1,NULL,$3);}
	| '(' expr ')' {$$=$2;}
	| NUM {$$=$1;}
	| STRVAL {$$=$1;}
	| arr_expr{$$=$1;}
	| FieldFunction {$$=$1;}
	;
arr_expr : ID {
	if($1->Lentry!=NULL)
		{ 
		$1->type=$1->Lentry->type;
		//$1->ctype=$1->Lentry->ctype;
		}
	else if($1->Gentry!=NULL)
		{
		$1->type=$1->Gentry->type;
		$1->ctype=$1->Gentry->ctype;
		//if($1->ctype!=NULL && $1->ctype->name!=NULL && $1->left==NULL && $1->right==NULL && $1->mid==NULL && CLookup($1->ctype->name)!=NULL)
			//set=1;
		}
	else
		{printf("%s not declared\n",$1->varname);
		exit(1);}			
	$$=$1;}
	|  ID '[' expr ']' {$$=makeOperatorNode(NULL,-1,22,$1->Gentry->type,$1,NULL,$3);
			}
	| ALLOC '(' ')' {char *c="alloc",*c2="int";$$=makeOperatorNode(c,-1,29,TLookup(c2),NULL,NULL,NULL);
		//printf("RRRRRRRRRR ");//$$=makeOperatorNode(c3,-1,3,0,$1,NULL,$2);prefix($$);printf("DDDDDDDDDDD\n");
				}
	| INIT '(' ')' {char *c="initialize",*c2="int";$$=makeOperatorNode(c,-1,31,TLookup(c2),NULL,NULL,NULL);}

	| Field {$$=$1;}
	;
	
Field : SELF '.' ID {
			$3->left=NULL;
			$3->mid=NULL;
			$3->right=NULL;
			char *c="self";
			$$=makeOperatorNode(c,-1,32,NULL,$3,NULL,NULL);
		
		/*	$3->Gentry=GLookup($1->varname);
			$3->Lentry=LLookup($1->varname);
			
			if($1->Lentry!=NULL)			
				$1->type=$1->Lentry->type;
			else if($1->Gentry!=NULL)
				$1->type=$1->Gentry->type;
			else
				{
				printf("variable not declared\n");
				exit(1);
				}

			*/
			struct Fieldlist *ft=Class_FLookup(Cptr,$3->varname);
			if(ft==NULL)
				{
				printf("Variable %s not declared in class %s\n",$3->varname,Cptr->name);
				exit(1);
				}
			$$->ctype=ft->ctype;
			$$->type=ft->type;
			//if(ft->ctype!=NULL)
			//printf("Vardhan %s Vardhan\n",ft->ctype->name);
       		    }
	| Field '.' ID {
			char *c=$1->type->name,*c1="int",*c2="str",*c3="boolean";
			if($1->nodetype==32 && (strcmp(c,c1)==0 || strcmp(c,c2)==0 || strcmp(c,c3)==0))
				{
				printf("Members cannot be accessed\n");
				exit(1);
				}
			$$=$1;
			
			$1=$$;
			while($1->left!=NULL)
				$1=$1->left;
			$1->left=$3;
			
			if($1->type!=NULL)
				$$->type=(FLookup($1->type,$3->varname))->type;
			/*else if($1->ctype!=NULL)
				{
				$$->ctype=(Class_FLookup($1->ctype,$3->varname))->ctype;
				$$->type=(Class_FLookup($1->ctype,$3->varname))->type;
				}
		     */
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
				{			
				$1->type=$1->Lentry->type;
				//$1->ctype=$1->Lentry->ctype;
				}
			else if($1->Gentry!=NULL)
				{
				$1->type=$1->Gentry->type;
				$1->ctype=$1->Gentry->ctype;
				}
			else
				{
				printf("variable not declared\n");
				exit(1);
				}

			
			struct Fieldlist *ft=FLookup($1->type,$3->varname);

			if(ft==NULL)
				{
				ft=Class_FLookup($1->ctype,$3->varname);
				if(ft==NULL)
					{
					printf("Variable %s cannot be accessed\n",$3->varname);
					exit(1);
					}
				else
					{
					$$->ctype=ft->ctype;
					$$->type=ft->type;
					}
				}
			else	
				{
				$$->type=ft->type;
				$$->ctype=ft->ctype;
				}

			

	
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
TypeTableCreate();
yyparse();
fclose(fp);
}
return 1;
}

