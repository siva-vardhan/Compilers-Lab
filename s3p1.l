%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int ins=-7,temp=0;
FILE *fp;
struct node
{
int add;
char *str;
struct node *next;
};
struct node *head=NULL;

%}

%%
([LFM][0-9]+:) {struct node *new=(struct node *)malloc(sizeof(struct node));
	char *ch=strdup(yytext);
	ch[strlen(ch)-1]='\0';
	new->str=ch;
	new->add=2056+2*(ins-1);
	new->next=head;
	head=new;

	ins--;
	}
([LFM][0-9]+) {
	char *ch=strdup(yytext);
	if(temp==1)
		fprintf(fp,"%s",ch);
	else
		{
		struct node *t=head;
		while(t!=NULL && strcmp(t->str,ch)!=0)
			t=t->next;
		if(t==NULL)	
			{
			printf("Invalid Address\n");
			t=head;
			while(t!=NULL){
				printf("(%s %d) ",t->str,t->add);
				t=t->next;
			}
				printf("%s ",ch);
			exit(1);
			}
		else
			fprintf(fp,"%d\n",t->add);
			
		}
		}
[\n] {ins++;fprintf(fp,"\n");}

. {fprintf(fp,"%s",yytext);}
%%
int yywrap()
{
return 1;
}

int main(int argc,char *argv[])
{
if(argc>2)
{
yyin=fopen(argv[1],"r");
fp=fopen("ss1.c","w");
temp=1;
yylex();
fclose(yyin);
fclose(fp);
temp=2;
yyin=fopen("ss1.c","r");
fp=fopen(argv[2],"w");
yylex();
fclose(yyin);
fclose(fp);
}
return 0;
}
