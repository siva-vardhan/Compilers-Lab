%{
#include<stdio.h>
#include "y.tab.h"
#include<stdlib.h>
#include<string.h>
%}
%%
[0-9]+ {
	//printf("NUM");
	int n=atoi(yytext);
	//printf("%d",n);
	yylval=makeLeafNode(NULL,n);
	return NUM;	
	}
[a-z] {
	//printf("VAR");
	char *ch=strdup(yytext);
	yylval=makeLeafNode(ch,-1);
	return VAR;	
	}
(begin) {/*printf("BEGIN");*/ return BEG;}
(end) {/*printf("END");*/ return END;}
(read) {/*printf("READ");*/ return READ;}
(write) {/*printf("WRITE");*/ return WRITE;}
- {/*printf("MINUS");*/ return *yytext;}
[' '] {/*printf("SPACE");*/}
[+*/%=()] {/*printf("%s",yytext);*/ return *yytext;}
\n {/*printf("NEWLINE");*/}
; {/*printf("SEMICOLON");*/ return *yytext;}


%%

int yywrap()
{
return 1;
}

