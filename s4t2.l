%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "y.tab.h"
%}

%%
(if) {return IF;}
(then) {return THEN;}
(else) {return ELSE;}
(endif) {return ENDIF;}
(while) {return WHILE;}
(do) {return DO;}
(endwhile) {return ENDWHILE;}
(begin) {return BEG;}
(end) {return END;}
(read) {return READ;}
(write) {return WRITE;}
(repeat) {return REPEAT;}
(until) {return UNTIL;}
(break) {char c[]="break";char *ch=strdup(c);
	yylval=makeLeafNode(ch,-1,18,0);return BREAK;}
(continue) {char c[]="continue";char *ch=strdup(c);
	yylval=makeLeafNode(ch,-1,18,0);return CONTINUE;}
(decl) {return DECL;}
(enddecl) {return ENDDECL;}
(int) {return INT;}
(str) {return STR;}

[a-zA-Z][a-zA-Z0-9]* {char *ch=strdup(yytext);
	yylval=makeLeafNode(ch,-1,0,0);	
	return ID;}
[0-9]+ {int n=atoi(yytext);yylval=makeLeafNode(NULL,n,0,1);
	return NUM;}
(["](.)*["]) {char *ch=strdup(yytext);yylval=makeLeafNode(ch,0,21,2);return STRVAL;}

[-] {return *yytext;}
[=] {return *yytext;}
[' '] {}
\n {}
[+*/%] {return *yytext;}
[,] {return *yytext;}
[()] {return *yytext;}
[;] {return *yytext;}
[<] {return L;}
[>] {return G;}
(<=) {return LE;}
(>=) {return GE;}
(!=) {return NE;}
(==) {return EE;}
"[" {return *yytext;}
"]" {return *yytext;}
%%

int yywrap()
{
return 1;
}

