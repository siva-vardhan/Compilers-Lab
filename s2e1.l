%{
#include<stdio.h>
#include<stdlib.h>
#include "y.tab.h"
%}


%%
[0-9]+ {yylval=atoi(yytext);return NUM;}
[a-z] {int i=*yytext;yylval=i-'a';return VAR;}
(begin) {return BEG;}
(end) {return END;}
(read) {return READ;}
(write) {return WRITE;}
- {return *yytext;}
= {return *yytext;}

[+/*%();] {return *yytext;}
. {yyerror("unknown character");exit(1);}
%%

int yywrap()
{
return 1;
}
