%{
#include<stdio.h>
#include<stdlib.h>
int yyerror();
FILE *fp,*yyin;
int arr[26];
%}

%token READ WRITE BEG END NUM VAR
%right '='
%left '+' '-'
%left '*' '/' '%'



%%
start : BEG Slist END ';' {exit(1);}
	| BEG END ';' {exit(2);}
	;
Slist : Slist Stmt  {}
	| Stmt  {}
	;
Stmt : InputStmt | OutputStmt |  assignStmt
	;
InputStmt : READ '(' VAR ')' ';' {scanf("%d",&arr[$3]);}
	;
OutputStmt : WRITE '(' expr ')' ';' {printf("%d",$3);}
	;
assignStmt : VAR '=' expr ';' {/*int i;
		printf("$1=%d $3=%d\n",$1,$3);
		for(i=0;i<26;i++)
			printf("%d ",arr[i]);
			printf("\n");
		for(i=0;i<26;i++)
			if(arr[i]==$1)
				break;
		printf("i=%d arr[i]=%d\n",i,arr[i]);
		if(i<26)
			arr[i]=$3;*/
//printf("VAR=%d expr=%d\n",$1,$3);
arr[$1]=$3;
		}
	;
expr : expr '+' expr {$$=$1+$3;}
	| expr '*' expr {$$=$1*$3;}
	| expr '-' expr {$$=$1-$3;}
	| expr '/' expr {$$=$1/$3;}
	| expr '%' expr {$$=$1%$3;}
	| VAR {$$=arr[$1];}
	| '(' expr ')' {$$=$2;}
	| NUM {$$=$1;}	
	;

%%
int yyerror(char *ch)
{
printf("yyerror %s",ch);
}

int main(int argc,char *argv[])
{
int i;
if(argc>1)
	{
	for(i=0;i<26;i++)
		arr[i]=0;
	yyin=fopen(argv[1],"r");
	yyparse();
	}
return 1;
}
