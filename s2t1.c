struct tnode* makeLeafNode(char *ch,int n)
{
struct tnode *temp;
temp=(struct tnode *)malloc(sizeof(struct tnode));
temp->varname=ch;
temp->val=n;
temp->left=NULL;
temp->right=NULL;
return temp;
}

int getReg()
{
if(reg<20)
	return reg++;
printf("Registers exhausted\n");
exit(1);
}
void freeReg()
{
reg--;
}

struct tnode *makeOperatorNode(char *ch,int a,struct tnode *l,struct tnode *r)
{
struct tnode *temp;
temp=(struct tnode *)malloc(sizeof(struct tnode));
temp->varname=ch;
temp->nodetype=a;
temp->val=-1;
temp->left=l;
temp->right=r;
return temp;
}

void prefix(struct tnode *t)
{
if(t==NULL)
	return;
if(t->left==NULL && t->right==NULL)
	{
	if(t->varname!=NULL)
		printf("%s ",t->varname);
	else if(t->val!=-1)	
		printf("%d ",t->val);
	return;
	}
else
	{
	if(t->varname!=NULL)
		printf("%s ",t->varname);
	else if(t->val!=-1)
		printf("%d ",t->val);
	prefix(t->left);
	prefix(t->right);
	}
}
void gencode(struct tnode *temp)
{


fprintf(fp,"0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, 4121\n");
gen_step(temp);
exit_fun();
fclose(fp);
}
void gen_step(struct tnode *temp)
{
if(temp==NULL)
	return;
if(temp->nodetype==1)
	read_fun(temp->left);
else if(temp->nodetype==2)
	write_fun(temp);
else if(temp->nodetype==3)
	assign(temp);
else if(temp->nodetype==4)
	{
	gen_step(temp->left);
	gen_step(temp->right);
	}



}
void exit_fun()
{
int p=getReg();
fprintf(fp,"MOV R%d, \"Exit\"\nPUSH R%d\nPUSH R%d\nPUSH R%d\nPUSH R%d\nPUSH R%d\nCALL 0\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d",p,p,p,p,p,p,p,p,p,p,p);
}
void read_fun(struct tnode *temp)
{
int q=getReg();

int p=*(temp->varname)-'a'+4096;
//fprintf(fp,"PUSH R%d",p);
fprintf(fp,"MOV R%d,\"Read\"\nPUSH R%d\nMOV R%d,-1\nPUSH R%d\nMOV R%d, %d\nPUSH R%d\nPUSH R%d\nPUSH R%d\nCALL 0\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n",q,q,q,q,q,p,q,q,q,q,q,q,q,q);
freeReg();
}
void write_fun(struct tnode *temp)
{
int q=getReg();
int p=arithmetic(temp->left);
fprintf(fp,"MOV R%d,\"Write\"\nPUSH R%d\nMOV R%d,-2\nPUSH R%d\nPUSH R%d\nPUSH R%d\nPUSH R%d\nCALL 0\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n",q,q,q,q,p,q,q,p,q,q,q,q);
freeReg();
}
void assign(struct tnode *temp)
{
int p=arithmetic(temp->right);
int q=*(temp->left->varname)-'a'+4096;
fprintf(fp,"MOV [%d],R%d\n",q,p);
freeReg(); 
}
int arithmetic(struct tnode *temp)
{
int p,q;
if(temp->left==NULL && temp->right==NULL)
	{
	p=getReg();
	if(temp->varname==NULL)
		fprintf(fp,"MOV R%d, %d\n",p,temp->val);
	else
		fprintf(fp,"MOV R%d, [%d]\n",p,*(temp->varname)-'a'+4096);	
	return p;
	}
else
	{
	p=arithmetic(temp->left);
	q=arithmetic(temp->right);
	if(*(temp->varname)=='+')
		fprintf(fp,"ADD R%d, R%d\n",p,q);
	else if(*(temp->varname)=='-')
		fprintf(fp,"SUB R%d, R%d\n",p,q);
	else if(*(temp->varname)=='*')
		fprintf(fp,"MUL R%d, R%d\n",p,q);
	else if(*(temp->varname)=='/')
		fprintf(fp,"DIV R%d, R%d\n",p,q);
	else if(*(temp->varname)=='%')
		fprintf(fp,"MOD R%d, R%d\n",p,q);
	freeReg();
	return p;	
	}
}
