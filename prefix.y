%{
#include<stdio.h>
#include<string.h>
int yylex();
char *concat(char *a,char *b,char *c)
{
char *ch=(char *)malloc(sizeof(a)+sizeof(b)+sizeof(c));
strcpy(ch,a);
strcat(ch,b);
strcat(ch,c);
return ch;
}
%}

%union 
{
char *str;
}
%type<str>VAR expr start
%token VAR
%left '+' '-'
%left '*' '/' '%'

%%
start : expr '\n' {printf("%s\n",$1);exit(1);}
	;
expr : expr '+' expr {char *c=(char *)malloc(sizeof(char));
			strcpy(c,'+');
			$$=concat(c,$1,$3);}
	| expr '-' expr {char *c=(char *)malloc(sizeof(char));
			strcpy(c,'-');
			$$=concat(c,$1,$3);}
	| expr '*' expr {char *c=(char *)malloc(sizeof(char));
			strcpy(c,'*');
			$$=concat(c,$1,$3);}
	| expr '/' expr {char *c=(char *)malloc(sizeof(char));
			strcpy(c,'/');
			$$=concat(c,$1,$3);}
	| expr '%' expr {char *c=(char *)malloc(sizeof(char));
			strcpy(c,'%');
			$$=concat(c,$1,$3);}
	| '(' expr ')' {$$=$2;}
	| VAR {$$=$1;}
	;
%%
void yyerror(char const *s)
{
    printf("yyerror  %s\n",s);
    return ;
}
int main()
{
yyparse();
return 1;
}
