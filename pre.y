%{

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int yylex();

char * concat(char *string1, char *string2, char *string3){
        char *str = (char *)malloc(sizeof(string1)+sizeof(string2)+sizeof(string3));
        strcat(string1," ");
        strcpy(str,string1);
        strcat(string2," ");
        strcat(str,string2);
        strcat(string3," ");
        strcat(str,string3);
        return str;
}

%}

%union
{
	char* string;
}

%type<string>WORD expr start
%token WORD PLUS MINUS MUL DIV NEWLINE
%left PLUS MINUS
%left MUL DIV

%%

start : expr NEWLINE    {printf("%s\n",$1);
                        exit(1);}
      ;

expr : expr PLUS expr   {char *out=(char*)malloc(sizeof(char));
                        strcpy(out,"+");
                        $$=concat(out,$1,$3);}
     | expr MINUS expr  {char *out=(char*)malloc(sizeof(char));
                        strcpy(out,"-");
                        $$=concat(out,$1,$3);}
     | expr MUL expr    {char *out=(char*)malloc(sizeof(char));
                        strcpy(out,"*");
                        $$=concat(out,$1,$3);}
     | expr DIV expr    {char *out=(char*)malloc(sizeof(char));
                        strcpy(out,"/");
                        $$=concat(out,$1,$3);}
     | '(' expr ')'	{$$=$2;}
					
     | WORD	        {$$=$1;}
     ;


%%

yyerror(char const *s) {
        printf("yyerror %s\n",s);
}

int main() {
        yyparse();
	return 0;
}
