struct tnode* makeLeafNode(char *ch,int n,int a)
{
struct tnode *temp;
temp=(struct tnode *)malloc(sizeof(struct tnode));
temp->varname=ch;
temp->val=n;
temp->nodetype=a;
if(ch!=NULL && n==-1 && a==0)
	temp->Gentry=Lookup(ch);
temp->left=NULL;
temp->mid=NULL;
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

struct tnode *makeOperatorNode(char *ch,int a,struct tnode *l,struct tnode *m,struct tnode *r)
{
struct tnode *temp;
temp=(struct tnode *)malloc(sizeof(struct tnode));
temp->varname=ch;
temp->nodetype=a;
temp->val=-1;
temp->left=l;
temp->mid=m;
temp->right=r;
return temp;
}

void prefix(struct tnode *t)
{
if(t==NULL)
	return;
if(t->left==NULL && t->mid==NULL && t->right==NULL)
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
	prefix(t->mid);
	prefix(t->right);
	}
}
void gencode(struct tnode *temp)
{


fprintf(fp,"0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, 4121\n");
gen_step(temp,0,0);
exit_fun();
fclose(fp);
}
void gen_step(struct tnode *temp,int lab1,int lab2)
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
	gen_step(temp->left,lab1,lab2);
	gen_step(temp->right,lab1,lab2);
	}
else if(temp->nodetype==10)
	{
	int label1=getLabel();
	int label2=getLabel();
	relate(temp->left);
	fprintf(fp,"L%d\n",label1);
	gen_step(temp->mid,lab1,lab2);
	fprintf(fp,"JMP L%d\nL%d:\n",label2,label1);
	gen_step(temp->right,lab1,lab2);
	fprintf(fp,"L%d:\n",label2);
	}
else if(temp->nodetype==11)
	{
	int label1=getLabel();
	int label2=getLabel();
	fprintf(fp,"L%d:\n",label1);
	relate(temp->left);
	fprintf(fp,"L%d\n",label2);
	gen_step(temp->right,label1,label2);
	fprintf(fp,"JMP L%d\nL%d:\n",label1,label2);
	}
else if(temp->nodetype==18)
	{
	if(strcmp(temp->varname,"break")==0)
		fprintf(fp,"JMP L%d\n",lab2);
	else if(strcmp(temp->varname,"continue")==0)
		fprintf(fp,"JMP L%d\n",lab1);
	}
else if(temp->nodetype==19)
	{
	int label1=getLabel();
	int label2=getLabel();
	fprintf(fp,"L%d:\n",label1);
	gen_step(temp->right,label1,label2);
	relate(temp->left);
	fprintf(fp,"L%d\n",label2);
	fprintf(fp,"JMP L%d\nL%d:\n",label1,label2);
	}
}
void relate(struct tnode *temp)
{
if(temp==NULL || temp->left==NULL || temp->right==NULL)
	return;
int p=getReg();
int q=*(temp->left->varname);
fprintf(fp,"MOV R%d,[%d]\n",p,4096+q-'a');
q=arithmetic(temp->right);
if(strcmp(temp->varname,"<")==0)
	fprintf(fp,"LT R%d,R%d\n",p,q);
else if(strcmp(temp->varname,">")==0)
	fprintf(fp,"GT R%d,R%d\n",p,q);
else if(strcmp(temp->varname,"<=")==0)
	fprintf(fp,"LE R%d,R%d\n",p,q);
else if(strcmp(temp->varname,">=")==0)
	fprintf(fp,"GE R%d,R%d\n",p,q);
else if(strcmp(temp->varname,"==")==0)
	fprintf(fp,"EQ R%d,R%d\n",p,q);
else if(strcmp(temp->varname,"!=")==0)
	fprintf(fp,"NE R%d,R%d\n",p,q);

fprintf(fp,"JZ R%d, ",p);
freeReg();
freeReg();
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
int evaluator(struct tnode* temp)
{
if(temp==NULL)
	return 0;
if(temp->nodetype==0)
	{
	if(temp->varname==NULL)
		return temp->val;
	else
		{
		char *str=temp->varname;
		int i=*str-'a';
		return arr[i];
		}
	}
if(temp->nodetype==1)
	{
	char *str=temp->left->varname;
	int i=*str-'a';
	scanf("%d",&arr[i]);
	//printf("%d %d\n",i,arr[i]);
	return 0;
	}
if(temp->nodetype==2)
	{
	printf("%d ",evaluator(temp->left));
	return 0 ;
	}
if(temp->nodetype==3)
	{
	char *str=temp->left->varname;
	int i=*str-'a';
	arr[i]=evaluator(temp->right);
	return 0;
	}
if(temp->nodetype==4)
	{
	evaluator(temp->left);
	evaluator(temp->right);
	return 0 ;
	}
if(temp->nodetype==5)
	return evaluator(temp->left)+evaluator(temp->right);
if(temp->nodetype==6)
	return evaluator(temp->left)-evaluator(temp->right);
if(temp->nodetype==7)
	return evaluator(temp->left)*evaluator(temp->right);
if(temp->nodetype==8)
	return evaluator(temp->left)/evaluator(temp->right);
if(temp->nodetype==9)
	return evaluator(temp->left)%evaluator(temp->right);	
if(temp->nodetype==10)
	{
	if(evaluator(temp->left))
		evaluator(temp->mid);
	else
		evaluator(temp->right);
	return 0;	
	}
if(temp->nodetype==11)
	{
	while(evaluator(temp->left))
		evaluator(temp->right);
	return 0;	
	}
if(temp->nodetype==12)
	{
	if(evaluator(temp->left)<evaluator(temp->right))
		return 1;
	else
		return 0;
	}
if(temp->nodetype==13)
	{
	if(evaluator(temp->left)>evaluator(temp->right))
		return 1;
	else
		return 0;
	}
if(temp->nodetype==14)
	{
	if(evaluator(temp->left)<=evaluator(temp->right))
		return 1;
	else
		return 0;
	}
if(temp->nodetype==15)
	{
	if(evaluator(temp->left)>=evaluator(temp->right))
		return 1;
	else
		return 0;
	}
if(temp->nodetype==16)
	{
	if(evaluator(temp->left)!=evaluator(temp->right))
		return 1;
	else
		return 0;
	}
if(temp->nodetype==17)
	{
	if(evaluator(temp->left)==evaluator(temp->right))
		return 1;
	else
		return 0;
	}
}
int getLabel()
{
return label++;
}

struct Gsymbol *Lookup(char *name)
{
struct Gsymbol *temp=head;
while(temp!=NULL)
{
if(strcmp(temp->name,name)==0)
 return temp;
else 
 temp=temp->next;
}

return temp;
}

void Install(char *name,int type,int size)
{
struct Gsymbol *new=(struct Gsymbol *)malloc(sizeof(struct Gsymbol));
new->name=name;
new->type=type;
new->size=size;
new->binding=bind;
bind=bind+size;
new->next=NULL;
if(head==NULL)
head=new;
else
{
struct Gsymbol *temp=head;
while(temp->next!=NULL)
temp=temp->next;
temp->next=new;
}
}
void insert(char *ch,int type,int size)
{
if(Lookup(ch)==NULL)
	Install(ch,type,size);
else
	{
	printf("Error:Variable Redeclared\n");
	exit(1);
	}
}
void print_tab(struct Gsymbol *temp)
{
if(temp!=NULL)
{
printf("Name : %s Type : %d Size :%d Binding :%d\n",temp->name,temp->type,temp->size,temp->binding);
print_tab(temp->next);
}
}
