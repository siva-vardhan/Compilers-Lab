%option noyywrap
%{
	#include <stdlib.h>
	#include <stdio.h>
int s=0;
%}
	


%%
 
[0-9]+ {printf("num%d ",++s);}
[+*/()] {printf("op ");}
(siva) {printf("Yes");}
(["](.)*["]) {char *ch=strdup(yytext);int n=strlen(ch);ch[n-1]='\0';ch[0]='\0';printf("Hii %s ",yytext);} 

%%
 
int main()
{
	yylex();
	return 1;
}
