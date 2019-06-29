%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "y.tab.h"
%}

%%
(extends)	{//printf("%s\n",yytext);
	return EXTENDS;}
(new)	{//printf("%s\n",yytext);
	return NEW;}
(delete)	{//printf("%s\n",yytext);
	return DELETE;}  
(self)	{//printf("%s\n",yytext);
	return SELF;} 
(class)	{//printf("%s\n",yytext);
	return CLASS;} 
(endclass) {//printf("%s\n",yytext);
	return ENDCLASS;}
(type)	{//printf("%s\n",yytext);
	return TYPE;} 
(endtype) {//printf("%s\n",yytext);
	return ENDTYPE;}
(null) {//printf("%s\n",yytext);
	char *c=strdup(yytext);
	yylval=makeOperatorNode(c,-1,26,TLookup(c),NULL,NULL,NULL);
	return NUL;}
(boolean) {//printf("%s\n",yytext);
	return BOOLEAN;} 
(void) {//printf("%s\n",yytext);
	return VOID;}
(alloc) {//printf("%s\n",yytext);
	return ALLOC;} 
(dealloc) {//printf("%s\n",yytext);
	return DEALLOC;}   
(initialize) {//printf("%s\n",yytext);
	return INIT;} 
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
	yylval=makeOperatorNode(ch,-1,18,NULL,NULL,NULL,NULL);return BREAK;}
(continue) {//printf("%s\n",yytext);
	char c[]="continue";char *ch=strdup(c);
	yylval=makeOperatorNode(ch,-1,18,NULL,NULL,NULL,NULL);return CONTINUE;}
(decl) {//printf("DeCL ");
	return DECL;}
(enddecl) {//printf("%s\n",yytext);
	return ENDDECL;}
(int) {//printf("INtd  ");
	return INT;}
(str) {//printf("%s\n",yytext);
	return STR;}

[a-zA-Z][a-zA-Z0-9_]* {//printf("%s\n",yytext);//printf("%s ",yytext);
	char *ch=strdup(yytext);
	yylval=makeOperatorNode(ch,-1,0,NULL,NULL,NULL,NULL);	
	return ID;}
[0-9]+ {//printf("%s\n",yytext);
	char *ch="int";
	int n=atoi(yytext);yylval=makeOperatorNode(NULL,n,0,TLookup(ch),NULL,NULL,NULL);
	return NUM;}
(["](.)*["]) {//printf("%s\n",yytext);
	char *ch1="str";
	char *ch=strdup(yytext);yylval=makeOperatorNode(ch,0,21,TLookup(ch1),NULL,NULL,NULL);return STRVAL;}

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
"." {//printf("%s\n",yytext);
	return *yytext;}
%%

int yywrap()
{
return 1;
}




