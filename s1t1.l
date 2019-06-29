%{
#include<stdio.h>
#include "y.tab.h"
#include<stdlib.h>
%}

%%
[0-9]+ {yylval=makeLeafNode(atoi(yytext));return NUM;}

[ \t]	{}
- 	{return *yytext;}
[()+*/%\n]	{return *yytext;}
.	{yyerror("unknown character\n");exit(1);}
%%
int yywrap()
{
return 1;
}
