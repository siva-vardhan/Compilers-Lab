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

struct tnode *makeOperatorNode(char *ch,int n,int a,struct Typetable *b,struct tnode *l,struct tnode *m,struct tnode *r)
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
	temp->Gentry=GLookup(ch);
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
else if(temp->nodetype==30)
	{
	
	int p,q,i=0;

	
	p=getReg();
	/*if(temp->left->Lentry!=NULL)
		fprintf(fp,"MOV R%d,%d\nADD R%d, BP\nMOV R%d,[R%d]\n",p,temp->left->Lentry->binding,p,p,p);
	else if(temp->left->Gentry!=NULL)
		fprintf(fp,"MOV R%d,[%d]\n",p,temp->left->Gentry->binding);
	fprintf(fp,"MOV R%d,[R%d]\n",p,p);
	*/
	if(reg>0)
		while(i<reg)
			fprintf(fp,"PUSH R%d\n",i++);
			q=arithmetic(temp->left);
	fprintf(fp,"MOV R0,\"Dealloc\"\n");

	fprintf(fp,"PUSH R0\nPUSH R%d\nPUSH R0\nPUSH R0\nPUSH R0\n",q);
		freeReg();
	fprintf(fp,"CALL 0\n");

	fprintf(fp,"POP R0\nPOP R0\nPOP R0\nPOP R0\nPOP R0\n");
	i--;
	while(i>=0)
		fprintf(fp,"POP R%d\n",i--);

	freeReg();
	}
else if(temp->nodetype==27)
	{
	int p=arithmetic(temp->right);
	int q=getReg();
	if(temp->left->Lentry!=NULL)
		fprintf(fp,"MOV R%d,%d\nADD R%d, BP\nMOV [R%d],R%d\n",q,temp->left->Lentry->binding,q,q,p);
	else if(temp->left->Gentry!=NULL)
		fprintf(fp,"MOV [%d],R%d\n",temp->left->Gentry->binding,p);
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
/*else if(temp->nodetype==28)
	{

	int s,q=getReg();
	int r=getReg();

	if(temp->Lentry!=NULL)
		fprintf(fp,"MOV R%d,%d\nMOV R%d, BP\nADD R%d, R%d\nMOV R%d,[R%d]\n",q,temp->Lentry->binding,r,q,r,q,q);
	else if(temp->Gentry!=NULL)
		fprintf(fp,"MOV R%d,[%d]\n",q,temp->Gentry->binding);

	struct Typetable *tt1;
		if(temp->left->Lentry!=NULL)
			tt1=temp->left->Lentry->type;
		else
			tt1=temp->left->Gentry->type;
		struct tnode *t1=temp->left;

	while(t1->left!=NULL) 
		{

		s=FLookup(tt1,t1->varname)->fieldIndex;
		fprintf(fp,"MOV R%d,%d\nADD R%d,R%d\nMOV R%d,[R%d]\n",r,s-1,q,r,q,q);
				tt1=FLookup(tt1,t1->varname)->type;
		t1=t1->left;

		}
		s=FLookup(tt1,t1->varname)->fieldIndex;
		fprintf(fp,"MOV R%d,%d\nADD R%d,R%d\n",r,s-1,q,r);
		fprintf(fp,"MOV R%d,[R%d]\n",r,q);

fprintf(fp,"MOV R%d,\"Read\"\nPUSH R%d\nMOV R%d,-1\nPUSH R%d\nMOV R%d, %d\nPUSH R%d\nPUSH R%d\nPUSH R%d\nCALL 0\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n",q,q,q,q,q,r,q,q,q,q,q,q,q,q);
			freeReg();
			freeReg();

			return ;
	
	}*/
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
	int i=0;
	if(reg>0)
		while(i<reg)
			fprintf(fp,"PUSH R%d\n",i++);
	fprintf(fp,"MOV R%d,\"Write\"\nPUSH R%d\nMOV R%d,-2\nPUSH R%d\nPUSH R%d\nPUSH R%d\nPUSH R%d\nCALL 0\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n",q,q,q,q,p,q,q,p,q,q,q,q);
	i--;
	while(i>=0)
		fprintf(fp,"POP R%d\n",i--);
	}
else
{
int p=arithmetic(temp);
int i=0;
	if(reg>0)
		while(i<reg)
			fprintf(fp,"PUSH R%d\n",i++);
fprintf(fp,"MOV R%d,\"Write\"\nPUSH R%d\nMOV R%d,-2\nPUSH R%d\nPUSH R%d\nPUSH R%d\nPUSH R%d\nCALL 0\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n",q,q,q,q,p,q,q,p,q,q,q,q);
i--;
	while(i>=0)
		fprintf(fp,"POP R%d\n",i--);
}
freeReg();
freeReg();
}
void assign(struct tnode *temp)
{
int p=arithmetic(temp->right);
if(temp->left->nodetype==28)
	{

	int s,q=getReg();
	int r=getReg();

	if(temp->left->Lentry!=NULL)
		fprintf(fp,"MOV R%d,%d\nADD R%d, BP\nMOV R%d,[R%d]\n",q,temp->left->Lentry->binding,q,q,q);
	else if(temp->left->Gentry!=NULL)
		fprintf(fp,"MOV R%d,[%d]\n",q,temp->left->Gentry->binding);
											  
	struct Typetable *tt1;
	if(temp->left->Lentry!=NULL)
			tt1=temp->left->Lentry->type;
	else
		tt1=temp->left->Gentry->type;
		struct tnode *t1=temp->left->left;

	while(t1->left!=NULL) 
		{
		s=FLookup(tt1,t1->varname)->fieldIndex;
		fprintf(fp,"MOV R%d,%d\nADD R%d,R%d\nMOV R%d,[R%d]\n",r,s-1,q,r,q,q);
				tt1=FLookup(tt1,t1->varname)->type;
		t1=t1->left;

		}

		s=FLookup(tt1,t1->varname)->fieldIndex;
		fprintf(fp,"MOV R%d,%d\nADD R%d,R%d\n",r,s-1,q,r);
		fprintf(fp,"MOV [R%d],R%d\n",q,p);
			freeReg();
			freeReg();
			freeReg();

			return ;
	
	}
	/*
else if(strcmp(temp->left->type->name,temp->right->type->name)!=0)
{
printf("Type mismatch for %s : %s     %s : %s",temp->left->type->name,temp->left->type,temp->right->type->name,temp->right->type);
exit(1);
}*/
if(temp->left->nodetype==22)
	{
	int pos=temp->left->left->Gentry->binding;
	int num=arithmetic(temp->left->right);
	int r=getReg();
	fprintf(fp,"MOV R%d,%d\nADD R%d,R%d\nMOV [R%d],R%d\n",r,pos,num,r,num,p);
	freeReg();
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
if(temp->nodetype==26)
	{
	p=getReg();
	fprintf(fp,"MOV R%d,0\n",p);
	return p;
	}
else if(temp->nodetype==28)
	{
char *ch="p";
temp->Lentry=LLookup(temp->varname);
temp->Gentry=GLookup(temp->varname);
/*if(strcmp(ch,temp->varname)==0){
		prefix(temp);
printf("Lentry : %x Gentry : %x\n",temp->Lentry,temp->Gentry);
if(temp->Lentry==NULL)
		printf("Siva ");
else if(temp->Gentry==NULL)
		printf("Vardhan ");
else if(temp->Gentry!=NULL)
		printf("reddy ");
if(temp->Lentry!=NULL)
	printf("KKKKKKKKKKKKK lentry->binding=%x ",temp->Lentry->binding);
else if(temp->Gentry!=NULL){
printf("SSSSSSSSSSSS Gentry->binding=%d head->bind =%d x->bind=%d i->bind=%d",temp->Gentry->binding,GLookup("head")->binding,LLookup("x")->binding,GLookup("i")->binding);
print_gtab(head);
printf("\n\n\n");
print_gtab(temp->Gentry);
}
		}
*/
		q=getReg();
	p=getReg();

	printf("p=%d q=%d\n",p,q);

	int s;
	struct Typetable *tt1;
	if(temp->Lentry!=NULL){
		fprintf(fp,"MOV R%d,%d\nADD R%d, BP\nMOV R%d,[R%d]\n",q,temp->Lentry->binding,q,q,q);
			tt1=temp->Lentry->type;
printf("SIVA ");
print_ltab(temp->Lentry);
			}
	else if(temp->Gentry!=NULL){
		fprintf(fp,"MOV R%d,[%d]\n",q,temp->Gentry->binding);
			tt1=temp->Gentry->type;
printf("VARDHAN ");
print_gtab(temp->Gentry);
			}


		struct tnode *t1=temp->left;
//count++;	
//if(count==2) exit(1);	
	while(t1!=NULL) 
		{
		s=FLookup(tt1,t1->varname)->fieldIndex;
							
		fprintf(fp,"MOV R%d,%d\nADD R%d,R%d\nMOV R%d,[R%d]\n",p,s-1,q,p,q,q);
		tt1=FLookup(tt1,t1->varname)->type;
		t1=t1->left;


		}
		//fprintf(fp,"MOV [R%d],R%d\n",q,p);
			freeReg();

	return q;
	}
else if(temp->nodetype==29)
	{
	int i=0;
	if(reg>0)
		while(i<reg)
			fprintf(fp,"PUSH R%d\n",i++);
	fprintf(fp,"MOV R0,\"Alloc\"\n");
	fprintf(fp,"PUSH R0\nMOV R0,0\nPUSH R0\nPUSH R0\nPUSH R0\nPUSH R0\n");
	fprintf(fp,"CALL 0\n");
	p=getReg();
	fprintf(fp,"POP R%d\nPOP R19\nPOP R19\nPOP R19\nPOP R19\n",p);
	i--;
	while(i>=0)
		fprintf(fp,"POP R%d\n",i--);
	return p;
	}
else if(temp->nodetype==31)
	{
	int i=0;
	if(reg>0)
		while(i<reg)
			fprintf(fp,"PUSH R%d\n",i++);
	fprintf(fp,"MOV R0,\"Initialize\"\n");
	fprintf(fp,"PUSH R0\nPUSH R0\nPUSH R0\nPUSH R0\nPUSH R0\n");
	fprintf(fp,"CALL 0\n");
	p=getReg();
	fprintf(fp,"POP R%d\nPOP R0\nPOP R0\nPOP R0\nPOP R0\n",p);
	i--;
	while(i>=0)
		fprintf(fp,"POP R%d\n",i--);
	return p;
	}
else if(temp->nodetype==25)
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
	temp->Gentry=GLookup(temp->varname);	
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

struct Gsymbol* GInstall(char *name,struct Typetable *type,int size,struct Paramstruct *p1,int l1)
{
if(GLookup(name)!=NULL)
	{
	printf("Error:%s Variable Redeclared \n",name);
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
return new;
}

struct Lsymbol* LInstall(char *name,struct Typetable *type)
{
if(LLookup(name)!=NULL)
	{
	printf("Error: %s Variable Redeclared\n",name);
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
return new;
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

struct Paramstruct* PInstall(char *ch,struct Typetable *type)
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
return temp;
}

void TypeTableCreate()
{
struct Typetable *tt1=(struct Typetable *)malloc(sizeof(struct Typetable));
struct Typetable *tt2=(struct Typetable *)malloc(sizeof(struct Typetable));
struct Typetable *tt3=(struct Typetable *)malloc(sizeof(struct Typetable));
struct Typetable *tt4=(struct Typetable *)malloc(sizeof(struct Typetable));
struct Typetable *tt5=(struct Typetable *)malloc(sizeof(struct Typetable));

char ch1[5]="int";
tt1->name=strdup(ch1);
tt1->size=1;
tt1->fields=NULL;
tt1->next=tt2;

char ch2[5]="str";
tt2->name=strdup(ch2);
tt2->size=1;
tt2->fields=NULL;
tt2->next=tt3;

char ch3[10]="boolean";
tt3->name=strdup(ch3);
tt3->size=1;
tt3->fields=NULL;
tt3->next=tt4;

char ch4[5]="void";
tt4->name=strdup(ch4);
tt4->size=1;
tt4->fields=NULL;
tt4->next=tt5;

char ch5[5]="null";
tt5->name=strdup(ch5);
tt5->size=1;
tt5->fields=NULL;
tt5->next=NULL;
T1=tt1;
}

struct Typetable* TLookup(char *name)
{
struct Typetable *tt1=T1;
//printf("TLOOKUP:\n");
while(tt1!=NULL)
	{
	if(strcmp(tt1->name,name)==0)
		return tt1;
	//printf("tname : %s name : %s\n",tt1->name,name);	
	tt1=tt1->next;
	}
	return NULL;
}
struct Fieldlist* FInstall(char *name,int ind,struct Typetable *type)
{
struct Fieldlist* t1=(struct Fieldlist *)malloc(sizeof(struct Fieldlist));
t1->name=name;
t1->fieldIndex=ind;
t1->type=type;
t1->next=NULL;
if(f1==NULL)
{f1=t1;
return f1;
}
struct Fieldlist *t2=f1;
while(t2->next!=NULL)
	t2=t2->next;
t2->next=t1;
return t1;
}
struct Typetable* TInstall(char *name, int size, struct Fieldlist *fields)
{
struct Typetable *tt1=(struct Typetable *)malloc(sizeof(struct Typetable));
tt1->name=name;
tt1->size=size;
tt1->fields=fields;
tt1->next=NULL;
struct Typetable *temp=T1;
if(T1==NULL)
{
T1=tt1;
return T1;
}
while(temp->next!=NULL)
	temp=temp->next;
temp->next=tt1;
return tt1;
}
struct Fieldlist* FLookup(struct Typetable *type,char *name)
{
struct Fieldlist *temp=type->fields;
while(strcmp(temp->name,name)!=0)
	temp=temp->next;
return temp;
}
int GetSize(struct Typetable* type)
{
int size=0;
struct Fieldlist *temp=type->fields;
while(temp!=NULL)
	{
	//if(strcmp("int",temp->name)==0 || strcmp("str",temp->name)==0 || strcmp("boolean",temp->name)==0)
	size=size+1;
	temp=temp->next;
	}
return size;
}




void print_gtab(struct Gsymbol *temp)
{
if(temp!=NULL)
{
printf("Name : %s Type : %s Size :%d Binding :%d ParamList : %x FLAbel : %d\n",temp->name,temp->type->name,temp->size,temp->binding,temp->paramlist,temp->flabel);
if(temp->paramlist!=NULL)
	print_par(temp->paramlist);
print_gtab(temp->next);
}
}

void print_ltab(struct Lsymbol *temp)
{
if(temp!=NULL)
{
printf("Name : %s Type : %s Binding : %d\n",temp->name,temp->type->name,temp->binding);
print_ltab(temp->next);
}
}
void print_par(struct Paramstruct *temp)
{
while(temp!=NULL){
printf("Name : %s Type : %s\n",temp->name,temp->type->name);
temp=temp->next;
}
}
void print_t(struct Typetable *temp)
{
if(temp!=NULL)
{
printf("Name : %s size : %d \n",temp->name,temp->size);
if(temp->fields!=NULL)
	print_f(temp->fields);
print_t(temp->next);
}
}
void print_f(struct Fieldlist *temp)
{
if(temp!=NULL)
{
printf("\tname : %s fieldIndex : %d type : %s \n",temp->name,temp->fieldIndex,temp->type->name);
print_f(temp->next);
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
