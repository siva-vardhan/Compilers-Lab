%{

#include<stdio.h>
#include<stdlib.h>
#include "y.tab.h"
#include<string.h>

%}

%%

([a-z][0-9])   {
		yylval.string=(char *)malloc(3*sizeof(char));
		yylval.string=strdup(yytext);
                return WORD;
        }

"+"     { return PLUS;}
"-"     { return MINUS;}
"*"     { return MUL;}
"/"     { return DIV;}
"\n"    { return NEWLINE;}
[()]	{ return *yytext;}
[" "]   {}
.       {printf("Unknown Error\n");
	exit(1);
        }

%%

int yywrap() {
        return 1;
}

            
