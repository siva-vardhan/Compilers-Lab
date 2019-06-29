struct tnode* makeLeafNode(int n)
{
struct tnode *temp;
temp=(struct tnode *)malloc(sizeof(struct tnode));
temp->op=NULL;
temp->val=n;
temp->left=NULL;
temp->right=NULL;
return temp;
}
int reg[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
FILE *fp;
void gencode(struct tnode *temp)
{


fprintf(fp,"0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, 4095\n");
int p=arithmetic(temp);
int q=getReg();
fprintf(fp,"MOV R%d,\"Write\"\nPUSH R%d\nMOV R%d,-2\nPUSH R%d\nPUSH R%d\nPUSH R%d\nPUSH R%d\nCALL 0\nINT 10\n",q,q,q,q,p,q,q);
fclose(fp);
}
int getReg()
{
int i;
for(i=0;i<20;i++)
	if(reg[i]==0)
		{
		reg[i]=1;
		break;
		}
if(i==20) 
	{
	printf("Out of Registers\n");
	exit(1);
	}
else
return i;
}
void freeReg(int p)
{
if(p>=0 && p<20)
reg[p]=0;
}
int arithmetic(struct tnode *temp)
{
int p,q;
if(temp->left==NULL && temp->right==NULL)
	{
	p=getReg();
	fprintf(fp,"MOV R%d, %d\n",p,temp->val);
	return p;
	}
else
	{
	p=arithmetic(temp->left);
	q=arithmetic(temp->right);
	if(*(temp->op)=='+')
		fprintf(fp,"ADD R%d, R%d\n",p,q);
	else if(*(temp->op)=='-')
		fprintf(fp,"SUB R%d, R%d\n",p,q);
	else if(*(temp->op)=='*')
		fprintf(fp,"MUL R%d, R%d\n",p,q);
	else if(*(temp->op)=='/')
		fprintf(fp,"DIV R%d, R%d\n",p,q);
	else if(*(temp->op)=='%')
		fprintf(fp,"MOD R%d, R%d\n",p,q);
	freeReg(q);
	return p;	
	}
}
struct tnode *makeOperatorNode(char c,struct tnode *l,struct tnode *r)
{
struct tnode *temp;
temp=(struct tnode *)malloc(sizeof(struct tnode));
temp->op=malloc(sizeof(char));
*(temp->op)=c;
temp->left=l;
temp->right=r;
return temp;
}

int evaluate(struct tnode *t)
{
if(t->op==NULL)
	return t->val;
else
	{
	switch(*(t->op))
		{
		case '+': return evaluate(t->left) + evaluate(t->right);
		break;
		case '-' : return evaluate(t->left) - evaluate(t->right);
		break;
		case '*' : return evaluate(t->left) * evaluate(t->right);
		break;
		case '/' : return evaluate(t->left) / evaluate(t->right);
		break;
		case '%' : return evaluate(t->left) % evaluate(t->right);    
		break;
		}
	}
}
void prefix(struct tnode *t)
{
if(t==NULL)
	return;
if(t->left==NULL && t->right==NULL)
	{
	printf("%d ",t->val);
	return;
	}
else
	{
	printf("%c ",*(t->op));
	prefix(t->left);
	prefix(t->right);
	}
}
void postfix(struct tnode *t)
{
if(t==NULL)
	return;
if(t->left==NULL && t->right==NULL)
	{
	printf("%d ",t->val);
	return;
	}
else
	{

	postfix(t->left);
	postfix(t->right);
	printf("%c ",*(t->op));
	}
}
