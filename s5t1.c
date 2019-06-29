int getLabel()
{
return label++;
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

struct tnode *makeOperatorNode(char *ch,int n,int a,int b,struct tnode *l,struct tnode *m,struct tnode *r)
{
struct tnode *temp;
temp=(struct tnode *)malloc(sizeof(struct tnode));
temp->varname=ch;
temp->nodetype=a;
temp->type=b;
temp->val=n;
temp->left=l;
temp->mid=m;
temp->right=r;
if(ch!=NULL && n==-1 && a==0)
	{
	temp->Gentry=Lookup(ch);
	temp->Lentry=LLookup(ch);
	}
return temp;
}


void gencode(struct tnode *temp)
{
gen_step(temp,0,0);
exit_fun();
reg=0;

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
else  if(temp->nodetype==24)
	{
	int p=arithmetic(temp->left);
	int q=getReg();
	struct Lsymbol *t1=l1;
	while(t1!=NULL)
		{
		fprintf(fp,"POP R%d\n",q);
		t1=t1->next;
		}
	int r=getReg();
	fprintf(fp,"MOV R%d, BP\n",q);
	fprintf(fp,"MOV R%d, 2\n",r);
	fprintf(fp,"SUB R%d, R%d\n",q,r);
	fprintf(fp,"MOV [R%d],R%d\n",q,p);
	fprintf(fp,"POP R%d\nMOV BP,R%d\nRET\n",r,r);
	freeReg();
	freeReg();
	freeReg();
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
fprintf(fp,"MOV R%d, \"Exit\"\nPUSH R%d\nPUSH R%d\nPUSH R%d\nPUSH R%d\nPUSH R%d\nCALL 0\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n",p,p,p,p,p,p,p,p,p,p,p);
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
	}
else if(temp->nodetype==23)
	{
	int pos=temp->left->Gentry->binding;
	int num=arithmetic(temp->right);
	int r=getReg();
	int n1=arithmetic(temp->mid);
	fprintf(fp,"MOV R%d,%d\nADD R%d,R%d\n",r,pos,num,r);
	freeReg();
	fprintf(fp,"MOV R%d,\"Read\"\nPUSH R%d\nMOV R%d,-1\nPUSH R%d\nMOV R%d, R%d\nPUSH R%d\nPUSH R%d\nPUSH R%d\nCALL 0\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n",q,q,q,q,q,num,q,q,q,q,q,q,q,q);
	freeReg();
	}
else
{
if(temp->Lentry!=NULL){
	p=temp->Lentry->binding;
	fprintf(fp,"MOV R%d,\"Read\"\nPUSH R%d\nMOV R%d,-1\nPUSH R%d\nMOV R%d,%d\nADD R%d, BP\nPUSH R%d\nPUSH R%d\nPUSH R%d\nCALL 0\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n",q,q,q,q,q,p,q,q,q,q,q,q,q,q,q);	
	}
else
	{
	p=temp->Gentry->binding;
//fprintf(fp,"PUSH R%d",p);
fprintf(fp,"MOV R%d,\"Read\"\nPUSH R%d\nMOV R%d,-1\nPUSH R%d\nMOV R%d, %d\nPUSH R%d\nPUSH R%d\nPUSH R%d\nCALL 0\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n",q,q,q,q,q,p,q,q,q,q,q,q,q,q);
	}
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

if(temp->left->type!=temp->right->type)
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
else
{
int q,r;
if(temp->left->Lentry!=NULL)
	{
	q=temp->left->Lentry->binding;
	r=getReg();
	fprintf(fp,"MOV R%d, %d\n",r,q);
	//fprintf(fp,"MOV R%d, %d\n",q);
	fprintf(fp,"ADD R%d, BP\n",r);
	fprintf(fp,"MOV [R%d],R%d\n",r,p);
	freeReg();	
	}
else
	{
	q=temp->left->Gentry->binding;
printf(" %d ",q);
fprintf(fp,"MOV [%d],R%d\n",q,p);
	}
}
freeReg(); 
}
int arithmetic(struct tnode *temp)
{
int p,q;

if(temp->nodetype==25)
	{

	printf("\n\n\nSIVA\n");
	prefix(temp);

	int i=0;
			printf("\n\n\nSIVA\ni=%d reg=%d\n",i,reg);

	while(i<reg)
		fprintf(fp,"PUSH R%d\n",i++);
	printf("YED SI\n");

	struct tnode *t1=temp->left,*t2=temp->left,*t3;
	int p,q,j=0;
	prefix(t1);
	//int k=0;
	while(t1!=NULL)
		{
		t2=t1;
		while(t2->mid!=NULL)
			t2=t2->mid;
		printf("\n\nsiva");
		
		p=arithmetic(t2);
		fprintf(fp,"PUSH R%d\n",p);
		freeReg();
		j++;
		t3=t1;
		
		if(t3==t2){
			temp->left=NULL;
			break;
			}
		while(t2!=(t3->mid))
			t3=t3->mid;
		t3->mid=NULL;
		//printf("\n\n\nSIVAVARDHAN");
		//prefix(t1);
		//k++;
		//if(k==5)
		//exit(1);
		//t2=NULL;

		prefix(temp);
		t1=temp->left;
		
		}
	temp->Gentry=Lookup(temp->varname);	
	printf("GEntry=%x flabel=%d\n",temp->Gentry,temp->Gentry->flabel);
	fprintf(fp,"PUSH R0\nCALL F%d\n",temp->Gentry->flabel);
	p=getReg();
	q=getReg();
	fprintf(fp,"POP R%d\n",p);

	while(j--)
		fprintf(fp,"POP R%d\n",q);
	while(i>0)
		fprintf(fp,"POP R%d\n",--i);
	freeReg();
	return p;	
	}


else if(temp->nodetype==22)
	{
	p=getReg();
	q=arithmetic(temp->right);
	int pos=temp->left->Gentry->binding;
	fprintf(fp,"MOV R%d,%d\nADD R%d,R%d\nMOV R%d,[R%d]\n",p,pos,q,p,p,q);
	freeReg();
	return p;
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
	int q=getReg();
	if(temp->varname==NULL)
		fprintf(fp,"MOV R%d, %d\n",p,temp->val);
	else if(temp->Lentry!=NULL){
		fprintf(fp,"MOV R%d, %d\n",q,temp->Lentry->binding);
		fprintf(fp,"ADD R%d, BP\n",q);
		fprintf(fp,"MOV R%d, [R%d]\n",p,q);
		freeReg();
		}
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


struct Gsymbol *GLookup(char *name)
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

void GInstall(char *name,int type,int size,struct Paramstruct *p1,int l1)
{
if(Lookup(name)!=NULL)
	{
	printf("Error:%s Variable Redeclared \n",ch);
	exit(1);
	}
struct Gsymbol *new=(struct Gsymbol *)malloc(sizeof(struct Gsymbol));
new->name=name;
new->type=type;
new->size=size;
if(size!=0)
	new->binding=bind;
bind=bind+size;
new->paramlist=p1;
new->flabel=l1;
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

void LInstall(char *name,int type)
{
if(LLookup(name)!=NULL)
	{
	printf("Error: %s Variable Redeclared\n",ch);
	exit(1);
	}
struct Lsymbol *new=(struct Lsymbol *)malloc(sizeof(struct Lsymbol));
new->name=name;
new->type=type;
new->binding=(++bin);
new->next=NULL;
if(l1==NULL)
l1=new;
else
{
struct Lsymbol *temp=l1;
while(temp->next!=NULL)
temp=temp->next;
temp->next=new;
}
}
struct Lsymbol *LLookup(char *name)
{
struct Lsymbol *temp=l1;
while(temp!=NULL)
{
if(strcmp(temp->name,name)==0)
 return temp;
else 
 temp=temp->next;
}
}

void PInstall(char *ch,int type)
{
struct Paramstruct *temp=(struct Paramstruct *)malloc(sizeof(struct Paramstruct));
temp->name=ch;
temp->type=type;
temp->next=NULL;
struct Paramstruct *t1=h1;
if(h1==NULL)
h1=temp;
else
{
while(t1->next!=NULL)
t1=t1->next;
t1->next=temp;
}
}

void print_gtab(struct Gsymbol *temp)
{
if(temp!=NULL)
{
printf("Name : %s Type : %d Size :%d Binding :%d ParamList : %x FLAbel : %d\n",temp->name,temp->type,temp->size,temp->binding,temp->paramlist,temp->flabel);
if(temp->paramlist!=NULL)
	print_par(temp->paramlist);
print_gtab(temp->next);
}
}

void print_ltab(struct Lsymbol *temp)
{
if(temp!=NULL)
{
printf("Name : %s Type : %d Binding : %d\n",temp->name,temp->type,temp->binding);
print_ltab(temp->next);
}
}
void print_par(struct Paramstruct *temp)
{
while(temp!=NULL){
printf("Name : %s Type : %d\n",temp->name,temp->type);
temp=temp->next;
}
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
