%{

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n=0,lcount=2048;
int flag1=0,flag2=0,islabel;

FILE *yyin,*outfile;
char *in_name,*out_name;

struct node{
	char *s;
	int val;
	struct node *next;
};

int find(char *label); 
struct node* newnode(int val,char *s);
void push(int val,char *s);

struct node *head=NULL,*tail=NULL;
%}

%%

[a-zA-Z0-9]+[:] 	{
				if(!flag1){
					int k=yyleng-1;
					char *ch=(char*)malloc(sizeof(char)*k);
					yyless(k);
					strcpy(ch,yytext);
					push(lcount,ch);
					lcount=lcount-2;
				}
				else
					islabel=1;
			}

"JMP "[a-zA-Z0-9]+ 	{
				if(flag1){
					char *ch=yytext+4;
					int k=find(ch);
					fprintf(outfile,"JMP %d",k);
				}
			}

"JZ R"[0-9]+[,][a-zA-Z0-9]+	{
					if(flag1){
						if(yytext[5]==','){
							fprintf(outfile, "JZ R%c,",yytext[4]);
						//	printf("%s\n",yytext+6);
							
							int k = find(yytext+6);
							fprintf(outfile, "%d",k);
						}
						else{
							fprintf(outfile, "JZ R%c%c,",yytext[4],yytext[5]);
							printf("%s\n",yytext+6);
						 	int k = find(yytext+7);		
							fprintf(outfile, "%d",k);
						}
					}
				}

"JNZ R"[0-9]+[,][a-zA-Z0-9]+ 	{
					if(flag1){
                                                if(yytext[6]==','){
                                                        fprintf(outfile, "JZ R%c,",yytext[5]);
                                                        int k = find(yytext+7);
							//printf("%s\n",yytext+7);
                                                        fprintf(outfile, "%d",k);
                                                }
                                                else{
                                                        fprintf(outfile, "JZ R%c%c,",yytext[5],yytext[6]);
                                                        int k = find(yytext+8);                            
                                                        fprintf(outfile, "%d",k);
                                                }
                                        }
				}


[\n]		{
			if(!flag1){
				if(lcount<2056)
					lcount++;
				else
					lcount=lcount+2;
			}
			if(flag1){
				if(islabel)
					islabel=0;
				else
					fprintf(outfile, "\n");
			}

		}

.		{
			if(flag1)
				fprintf(outfile,"%s",yytext);
		}

%%

struct node* newnode(int val,char *s){
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->val=val;
	temp->s=s;
	temp->next=NULL;
}

void push(int val,char *s){
	struct node *temp=newnode(val,s);
	if(head==NULL){
		head=temp;
		tail=temp;
	}
	else{
		tail->next=temp;
		tail=tail->next;
	}
}

int find(char *label) {
	
	struct node *temp=head;
	while(temp!=NULL){
		if(strcmp(label,temp->s)==0)
			return temp->val;
		temp=temp->next;
	}
	return -1;
}

int yywrap(){

	if(flag1==0){
		flag1=1;
		flag2=1;
	  	
	  	outfile= fopen(out_name,"w");
	  	yyin = fopen(in_name,"r");
		return 0;
	}
	else
	{	remove(in_name);
		rename(out_name,in_name);
		return 1;
	}
}

void print() {
	struct node* temp=head;
	while(head!=NULL){
		printf("%d %s\n",head->val,head->s);
		head=head->next;
	}
}

int main(int argc,char *argv[]) {
	
	in_name=argv[1];
	out_name="123241324dfadcd.xsm";
	yyin=fopen(argv[1],"r");
	yylex();
//	print();
	return 0;
}


