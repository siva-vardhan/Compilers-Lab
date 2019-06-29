%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "y.tab.h"
%}

%%
(return) {//printf("%s\n",yytext);
	return RETURN;} 
(main) {//printf("%s\n",yytext);
	return MAIN;}
(if) {//printf("%s\n",yytext);
	return IF;}
(then) {//printf("%s\n",yytext);
	return THEN;}
(else) {//printf("%s\n",yytext);
	return ELSE;}
(endif) {//printf("%s\n",yytext);
	return ENDIF;}
(while) {//printf("%s\n",yytext);
	return WHILE;}
(do) {//printf("%s\n",yytext);
	return DO;}
(endwhile) {//printf("%s\n",yytext);
	return ENDWHILE;}
(begin) {//printf("BEgiN ");
	return BEG;}
(end) {//printf("End ");
	return END;}
(read) {//printf("%s\n",yytext);
	return READ;}
(write) {//printf("%s\n",yytext);
	return WRITE;}
(repeat) {//printf("%s\n",yytext);
	return REPEAT;}
(until) {//printf("%s\n",yytext);
	return UNTIL;}
(break) {//printf("%s\n",yytext);
	char c[]="break";char *ch=strdup(c);
	yylval=makeOperatorNode(ch,-1,18,0,NULL,NULL,NULL);return BREAK;}
(continue) {//printf("%s\n",yytext);
	char c[]="continue";char *ch=strdup(c);
	yylval=makeOperatorNode(ch,-1,18,0,NULL,NULL,NULL);return CONTINUE;}
(decl) {//printf("DeCL ");
	return DECL;}
(enddecl) {//printf("%s\n",yytext);
	return ENDDECL;}
(int) {//printf("INtd  ");
	return INT;}
(str) {//printf("%s\n",yytext);
	return STR;}

[a-zA-Z][a-zA-Z0-9]* {//printf("%s\n",yytext);//printf("%s ",yytext);
	char *ch=strdup(yytext);
	yylval=makeOperatorNode(ch,-1,0,0,NULL,NULL,NULL);	
	return ID;}
[0-9]+ {//printf("%s\n",yytext);
	int n=atoi(yytext);yylval=makeOperatorNode(NULL,n,0,1,NULL,NULL,NULL);
	return NUM;}
(["](.)*["]) {//printf("%s\n",yytext);
	char *ch=strdup(yytext);yylval=makeOperatorNode(ch,0,21,2,NULL,NULL,NULL);return STRVAL;}

[-] {//printf("%s\n",yytext);
	return *yytext;}
[=] {//printf("%s\n",yytext);
	return *yytext;}
[' '] {//printf("%s\n",yytext);
	}
\n {//printf("%s\n",yytext);
	}
[+*/%] {//printf("%s\n",yytext);
	return *yytext;}
[,] {//printf("%s\n",yytext);
	return *yytext;}
[(){}] {//printf("%s\n",yytext);
	return *yytext;}
[;] {//printf("%s\n",yytext);
	return *yytext;}
[<] {//printf("%s\n",yytext);
	return L;}
[>] {//printf("%s\n",yytext);
	return G;}
(<=) {//printf("%s\n",yytext);
	return LE;}
(>=) {//printf("%s\n",yytext);
	return GE;}
(!=) {//printf("%s\n",yytext);
	return NE;}
(==) {//printf("%s\n",yytext);
	return EE;}
"[" {//printf("%s\n",yytext);
	return *yytext;}
"]" {//printf("%s\n",yytext);
	return *yytext;}
%%

int yywrap()
{
return 1;
}
