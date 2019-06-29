%{
#include<stdio.h>
#include "y.tab.h"
%}


%%
([a-z][0-9]) {//yylval.str=(char *)malloc(3*sizeof(char));
yylval.str=strdup(yytext);return VAR;}
'-' {return *yytext;}
[+/*%()\n] {return *yytext;}
%%

int yywrap()
{
return 1;
}
