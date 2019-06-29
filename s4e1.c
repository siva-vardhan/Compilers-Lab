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


void gencode(struct tnode *temp)
{


fprintf(fp,"0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, %d\n",bind-1);
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
	write_fun(temp->left);
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
else if(temp->nodetype==20)
	{
	int label1=getLabel();
	int label2=getLabel();
	fprintf(fp,"L%d:\n",label1);
	gen_step(temp->right,label1,label2);
	relate(temp->left);
	fprintf(fp,"L%d\n",label1);
	fprintf(fp,"L%d:\n",label2);
	}
}
void relate(struct tnode *temp)
{
if(temp==NULL || temp->left==NULL || temp->right==NULL)
	return;
int p,q;
/*
if(temp->left->nodetype==22)
p=arithmetic(temp->left);
else if(temp->left->nodetype==23)
p=arithmetic(temp->left);
else{
p=getReg();
q=temp->left->Gentry->binding;
fprintf(fp,"MOV R%d,[%d]\n",p,q);
}
*/
p=arithmetic(temp->left);
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
int p;
if(temp->nodetype==22)
	{
	int pos=temp->left->Gentry->binding;
	int num=arithmetic(temp->right);
	int r=getReg();
	fprintf(fp,"MOV R%d,%d\nADD R%d,R%d\n",r,pos,num,r);
	freeReg();
	fprintf(fp,"MOV R%d,\"Read\"\nPUSH R%d\nMOV R%d,-1\nPUSH R%d\nMOV R%d, R%d\nPUSH R%d\nPUSH R%d\nPUSH R%d\nCALL 0\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n",q,q,q,q,q,num,q,q,q,q,q,q,q,q);
	freeReg();
	return;
	}
else if(temp->nodetype==23)
	{

	int pos=temp->left->Gentry->binding;

	int i=arithmetic(temp->mid);
	int j=arithmetic(temp->right);
	int n=temp->left->Gentry->col;
	int p=getReg();	

	fprintf(fp,"MOV R%d,%d\n",p,n);
	fprintf(fp,"MUL R%d,R%d\n",i,p);
	freeReg();
	fprintf(fp,"ADD R%d,R%d\n",i,j);
	fprintf(fp,"MOV R%d,%d\n",j,pos);
	fprintf(fp,"ADD R%d,R%d\n",i,j);
	freeReg();
	printf("\n %d\n",n);

	fprintf(fp,"MOV R%d,\"Read\"\nPUSH R%d\nMOV R%d,-1\nPUSH R%d\nMOV R%d, R%d\nPUSH R%d\nPUSH R%d\nPUSH R%d\nCALL 0\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n",q,q,q,q,q,i,q,q,q,q,q,q,q,q);
	freeReg();

	}
else
{
p=temp->Gentry->binding;
//fprintf(fp,"PUSH R%d",p);
fprintf(fp,"MOV R%d,\"Read\"\nPUSH R%d\nMOV R%d,-1\nPUSH R%d\nMOV R%d, %d\nPUSH R%d\nPUSH R%d\nPUSH R%d\nCALL 0\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n",q,q,q,q,q,p,q,q,q,q,q,q,q,q);
freeReg();
}
}
void write_fun(struct tnode *temp)
{

int q=getReg();
if(temp->varname!=NULL && temp->nodetype==21)
	{	
	int p=getReg();
	printf("\n %s \n",temp->varname);
	fprintf(fp,"MOV R%d,%s\n",p,temp->varname);
	fprintf(fp,"MOV R%d,\"Write\"\nPUSH R%d\nMOV R%d,-2\nPUSH R%d\nPUSH R%d\nPUSH R%d\nPUSH R%d\nCALL 0\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n",q,q,q,q,p,q,q,p,q,q,q,q);
	}
else
{
int p=arithmetic(temp);
fprintf(fp,"MOV R%d,\"Write\"\nPUSH R%d\nMOV R%d,-2\nPUSH R%d\nPUSH R%d\nPUSH R%d\nPUSH R%d\nCALL 0\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n",q,q,q,q,p,q,q,p,q,q,q,q);

}
freeReg();
freeReg();
}
void assign(struct tnode *temp)
{
int p=arithmetic(temp->right);
int n1=temp->right; //0
int n2=temp->left->Gsymbol->type;
if(!(n1==0 && n2==1) || !(n1==21 && n2==2))
{
printf("Type mismatch");
exit(1);
}
if(temp->left->nodetype==22)
	{
	int pos=temp->left->left->Gentry->binding;
	int num=arithmetic(temp->left->right);
	int r=getReg();
	fprintf(fp,"MOV R%d,%d\nADD R%d,R%d\nMOV [R%d],R%d\n",r,pos,num,r,num,p);
	freeReg();
	}
else if(temp->left->nodetype==23)
	{
	int pos=temp->left->left->Gentry->binding;
	int i=arithmetic(temp->left->mid);
	int j=arithmetic(temp->left->right);
	int n=temp->left->left->Gentry->col;
	int r=getReg();	
	fprintf(fp,"MOV R%d,%d",r,n);
	fprintf(fp,"MUL R%d,R%d\n",i,r);
	freeReg();
	fprintf(fp,"ADD R%d,R%d\n",i,j);
	fprintf(fp,"MOV R%d,%d\n",j,pos);
	fprintf(fp,"ADD R%d,R%d\n",i,j);
	freeReg();
	
	fprintf(fp,"MOV [R%d],R%d\n",i,p);
	freeReg();
	}
else
{
int q=temp->left->Gentry->binding;
printf(" %d ",q);
fprintf(fp,"MOV [%d],R%d\n",q,p);
}
freeReg(); 
}
int arithmetic(struct tnode *temp)
{
int p,q;
if(temp->nodetype==22)
	{
	p=getReg();
	q=arithmetic(temp->right);
	int pos=temp->left->Gentry->binding;
	fprintf(fp,"MOV R%d,%d\nADD R%d,R%d\nMOV R%d,[R%d]\n",p,pos,q,p,p,q);
	freeReg();
	return p;
	}
if(temp->nodetype==23)
	{
	int pos=temp->left->Gentry->binding;

	int i=arithmetic(temp->mid);
	int j=arithmetic(temp->right);
	int n=temp->left->Gentry->col;
	int p=getReg();	

	fprintf(fp,"MOV R%d,%d\n",p,n);
	fprintf(fp,"MUL R%d,R%d\n",i,p);
	freeReg();
	fprintf(fp,"ADD R%d,R%d\n",i,j);
	fprintf(fp,"MOV R%d,%d\n",j,pos);
	fprintf(fp,"ADD R%d,R%d\n",i,j);
	freeReg();
	fprintf(fp,"MOV R%d,[R%d]\n",i,i);
	//fprintf(fp,"MOV R%d,\"Read\"\nPUSH R%d\nMOV R%d,-1\nPUSH R%d\nMOV R%d, R%d\nPUSH R%d\nPUSH R%d\nPUSH R%d\nCALL 0\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n",q,q,q,q,q,i,q,q,q,q,q,q,q,q);
	//freeReg();
	return i;
	}
if(temp->varname!=NULL && temp->nodetype==21)
	{
	p=getReg();
	printf("\n %s \n",temp->varname);
	fprintf(fp,"MOV R%d,%s\n",p,temp->varname);
	return p;
	}
if(temp->left==NULL && temp->right==NULL)
	{
	p=getReg();
	if(temp->varname==NULL)
		fprintf(fp,"MOV R%d, %d\n",p,temp->val);
	else
		fprintf(fp,"MOV R%d, [%d]\n",p,temp->Gentry->binding);	
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

void Install(char *name,int type,int size,int col)
{
struct Gsymbol *new=(struct Gsymbol *)malloc(sizeof(struct Gsymbol));
new->name=name;
new->type=type;
if(col!=0)
{
new->row=size;
new->col=col;
new->size=size*col;
}
else
{
new->size=size;
new->row=size;
}
new->binding=bind;
bind=bind+new->size;
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
void insert(char *ch,int type,int size,int col)
{
if(Lookup(ch)==NULL)
	Install(ch,type,size,col);
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
printf("Name : %s Type : %d Size :%d row : %d col : %d Binding :%d\n",temp->name,temp->type,temp->size,temp->row,temp->col,temp->binding);
print_tab(temp->next);
}
}












void infix(struct tnode *t)
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
	prefix(t->left);
	if(t->varname!=NULL)
		printf("%s ",t->varname);
	else if(t->val!=-1)
		printf("%d ",t->val);

	prefix(t->mid);
	prefix(t->right);
	}
}
