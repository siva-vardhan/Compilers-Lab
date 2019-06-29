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
void stack_fun_init()
{
int i;
//for(i=0;i<8;i++)
	//fprintf(fp,"MOV [%d],-1\n",bind+i);

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
		if(strcmp(t1->name,"self")!=0)
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
else if(temp->nodetype==36)
	{
	int i=0;
	int p,q;
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
	int t1;
	int c1=CLookup(temp->right->left->varname)->class_index;
	c1=4096+c1*8;
	if(Cptr!=NULL && strcmp(temp->left->varname,"self")==0 && temp->left->left!=NULL && Class_FLookup(Cptr,temp->left->left->varname)!=NULL)
		{
			q=getReg();
			int r=getReg();
		t1=Class_FLookup(Cptr,temp->left->left->varname)->fieldIndex;
		int t2;
		if(LLookup(temp->left->varname)!=NULL)
			t2=LLookup(temp->left->varname)->binding;
		fprintf(fp,"MOV R%d, %d\n",q,t2);
		fprintf(fp,"ADD R%d, BP\n",q);
		fprintf(fp,"MOV R%d, [R%d]\n",q,q);
		fprintf(fp,"MOV R%d, %d\n",r,t1);
		fprintf(fp,"ADD R%d, R%d\n",q,r);
		fprintf(fp,"MOV [R%d], R%d\n",q,p);
		fprintf(fp,"ADD R%d, 1\n",q);
		fprintf(fp,"MOV [R%d], %d\n",q,c1);
		freeReg();
		freeReg();
		}
	else if(GLookup(temp->left->varname)!=NULL)
		{
		t1=GLookup(temp->left->varname)->binding;
		fprintf(fp,"MOV [%d],R%d\n",t1,p);
			fprintf(fp,"MOV [%d],%d\n",t1+1,c1);
		}
		
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
if(temp->nodetype==32)
	{
	p=addr_eval(temp->nodetype);
	fprintf(fp,"MOV R%d,\"Read\"\nPUSH R%d\nMOV R%d,-1\nPUSH R%d\nMOV R%d, R%d\nPUSH R%d\nPUSH R%d\nPUSH R%d\nCALL 0\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n",q,q,q,q,q,p,q,q,q,q,q,q,q,q);
	freeReg();
	freeReg();
	}
else if(temp->nodetype==22)
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
if(temp->left->nodetype==28 || temp->left->nodetype==32)
	{
//printf(" VVVVVVVVVV %d AAAAAAAAAAAA\n",temp->left->nodetype);
	int q=addr_eval(temp->left);
	fprintf(fp,"MOV [R%d],R%d\n",q,p);
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


int addr_eval(struct tnode *temp)
{
if(temp->nodetype==28)
	{
	int s,q=getReg();
	int r=getReg();

	if(temp->Lentry!=NULL)
		fprintf(fp,"MOV R%d,%d\nADD R%d, BP\nMOV R%d,[R%d]\n",q,temp->Lentry->binding,q,q,q);
	else if(temp->Gentry!=NULL)
		fprintf(fp,"MOV R%d,[%d]\n",q,temp->Gentry->binding);

	struct Typetable *tt1;
	if(temp->Lentry!=NULL)
			tt1=temp->Lentry->type;
	else
		tt1=temp->Gentry->type;
		struct tnode *t1=temp->left;
	
	//tt1=temp->type;
	while(t1->left!=NULL) 
		{
		s=FLookup(tt1,t1->varname)->fieldIndex;
		fprintf(fp,"MOV R%d,%d\nADD R%d,R%d\nMOV R%d,[R%d]\n",r,s-1,q,r,q,q);
				tt1=FLookup(tt1,t1->varname)->type;
		t1=t1->left;

		}

		s=FLookup(tt1,t1->varname)->fieldIndex;
		fprintf(fp,"MOV R%d,%d\nADD R%d,R%d\n",r,s-1,q,r);
		//fprintf(fp,"MOV [R%d],R%d\n",q,p);
			freeReg();
			return q;
	}
else if(temp->nodetype==32)
	{

	int ss1,ss2,ss3;
	struct Fieldlist *ft=Class_FLookup(Cptr,temp->left->varname);
	if(ft==NULL)
		{
		printf("self variable %s is not found in class\n",temp->left->varname);
		exit(1);
		}
	if(LLookup(temp->varname)==NULL)
		{
		printf("The variable using self cannot be accessed \n");
		exit(1);
		}
	ss1=LLookup(temp->varname)->binding;
	ss2=ft->fieldIndex;
	int p,q;
	p=getReg();
	q=getReg();
	fprintf(fp,"MOV R%d,%d\n",p,ss1);
	fprintf(fp,"ADD R%d,BP\n",p);
	fprintf(fp,"MOV R%d,[R%d]\n",p,p);
	fprintf(fp,"MOV R%d,%d\n",q,ss2);
	fprintf(fp,"ADD R%d,R%d\n",p,q);
	struct tnode *t1=temp->left->left;
	struct Typetable *tt1=Class_FLookup(Cptr,temp->left->varname)->type;
	while(t1!=NULL && tt1!=NULL)
		{
		printf("9999999999999999999999999999999999999999999999999999999999999999999999\n");
		ss3=FLookup(tt1,t1->varname)->fieldIndex;
		fprintf(fp,"MOV R%d, [R%d]\n",p,p);
		fprintf(fp,"MOV R%d, %d\n",q,ss3-1);
		fprintf(fp,"ADD R%d, R%d\n",p,q);
		tt1=FLookup(tt1,t1->varname)->type;
		t1=t1->left;
		}
		
		
	freeReg();

	return p;
	}
	

}



int arithmetic(struct tnode *temp)
{
int p,q;
char *ccc="null";
if(temp->nodetype==32)
	{
	p=addr_eval(temp);
	fprintf(fp,"MOV R%d, [R%d]\n",p,p);
	return p;
	}

else if(temp->varname!=NULL && strcmp(ccc,temp->varname)==0)
	{
	p=getReg();
	fprintf(fp,"MOV R%d, 0\n",p);
	return p;
	}
else if(temp->nodetype==33)
	{
	int ss1,ss2;
	if(LLookup(temp->varname)==NULL)
		{
		printf("self(%s ) is not found in self.id(arglist)\n",temp->varname);
		exit(1);
		}
	ss1=LLookup(temp->varname)->binding;
	if(Class_MLookup(Cptr,temp->left->varname)==NULL)
		{
		printf("function %s is not (found) defined in self.id(arglist)\n",temp->left->varname);
		exit(1);
		}
	ss2=Class_MLookup(Cptr,temp->left->varname)->funcposition;
	
	
	int i=0,j;
	while(i<reg)
		fprintf(fp,"PUSH R%d\n",i++);

	temp=temp->left;
	struct tnode *t1=temp->left,*t2=temp->left,*t3;
	j=0;
	p=getReg();
	q=getReg();
	fprintf(fp,"MOV R%d,%d\n",q,ss1);
	fprintf(fp,"ADD R%d,BP\n",q);
	fprintf(fp,"MOV R%d,[R%d]\n",p,q);
	fprintf(fp,"PUSH R%d\n",p);
	
	fprintf(fp,"MOV R%d,1\n",p);
	fprintf(fp,"ADD R%d,R%d\n",q,p);
	fprintf(fp,"MOV R%d,[R%d]\n",p,q);
	fprintf(fp,"PUSH R%d\n",p);
	freeReg();
	freeReg();
	while(t1!=NULL)
		{
		t2=t1;
		while(t2->mid!=NULL)
			t2=t2->mid;
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
		t1=temp->left;		
		}
	p=getReg();
	q=getReg();
	fprintf(fp,"PUSH R0\n");
	fprintf(fp,"MOV R%d, %d\n",p,ss1+1);
	fprintf(fp,"ADD R%d, BP\n",p);
	fprintf(fp,"MOV R%d, [R%d]\n",p,p);
	fprintf(fp,"MOV R%d, %d\n",q,ss2);
	fprintf(fp,"ADD R%d, R%d\n",p,q);
	fprintf(fp,"MOV R%d, [R%d]\n",p,p);
	fprintf(fp,"CALL R%d\n",p);
	
	fprintf(fp,"POP R%d\n",p);

	while(j--)
		fprintf(fp,"POP R%d\n",q);
	fprintf(fp,"POP R%d\n",q);
	fprintf(fp,"POP R%d\n",q);
	while(i>0)
		fprintf(fp,"POP R%d\n",--i);
	
	freeReg();
	return p;	
	
	}
else if(temp->nodetype==34)
	{
	int ss1,ss2;
	if(GLookup(temp->varname)==NULL)
		{
		printf("%s is not found in id.id(arglist)\n",temp->varname);
		exit(1);
		}
	ss1=GLookup(temp->varname)->binding;
	//struct Classtable *c=CLookup(temp->varname);
	if(Class_MLookup(temp->ctype,temp->left->varname)==NULL)
		{

		printf("function %s is not (found) defined or class %s is not found in id.id(arglist)\n",temp->left->varname,temp->varname);
		exit(1);
		}
	ss2=Class_MLookup(temp->ctype,temp->left->varname)->funcposition;
	
	
	int i=0,j;
	while(i<reg)
		fprintf(fp,"PUSH R%d\n",i++);

	
	j=0;
	p=getReg();
	q=getReg();
	fprintf(fp,"MOV R%d,[%d]\n",p,ss1);
	
	fprintf(fp,"PUSH R%d\n",p);
	
	fprintf(fp,"MOV R%d,[%d]\n",p,ss1+1);
	fprintf(fp,"PUSH R%d\n",p);
	freeReg();
	freeReg();
	
	temp=temp->left;
	struct tnode *t1=temp->left,*t2=temp->left,*t3;
	while(t1!=NULL)
		{
		t2=t1;
		while(t2->mid!=NULL)
			t2=t2->mid;
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
		t1=temp->left;		
		}
	p=getReg();
	q=getReg();
	fprintf(fp,"PUSH R0\n");
	fprintf(fp,"MOV R%d, [%d]\n",p,ss1+1);

	fprintf(fp,"MOV R%d, %d\n",q,ss2);
	fprintf(fp,"ADD R%d, R%d\n",p,q);
	fprintf(fp,"MOV R%d, [R%d]\n",p,p);
	fprintf(fp,"CALL R%d\n",p);
	
	fprintf(fp,"POP R%d\n",p);

	while(j--)
		fprintf(fp,"POP R%d\n",q);
	fprintf(fp,"POP R%d\n",q);
	fprintf(fp,"POP R%d\n",q);
	while(i>0)
		fprintf(fp,"POP R%d\n",--i);
	
	freeReg();
	return p;	
	
	}
else if(temp->nodetype==35)
	{

	int ss1,ss2,ss3;
	if(LLookup(temp->varname)==NULL)
		{
		printf("self is not found in self.id.id(arglist)\n");
		exit(1);
		}
	ss1=LLookup(temp->varname)->binding;

	if(Cptr==NULL || Class_FLookup(Cptr,temp->left->varname)==NULL)
		{
		printf("Cptr=null or field %s is not found in self.id.id(arglist)\n",temp->left->varname);
		exit(1);
		}
	ss2=Class_FLookup(Cptr,temp->left->varname)->fieldIndex;
	temp->left->ctype=Class_FLookup(Cptr,temp->left->varname)->ctype;


	if(Class_MLookup(temp->left->ctype,temp->left->left->varname)==NULL)
		{
		printf("function %s is not (found) defined in self.id.id(arglist)\n");
		exit(1);
		}
	ss3=Class_MLookup(temp->left->ctype,temp->left->left->varname)->funcposition;
	

	int i=0,j;
	while(i<reg)
		fprintf(fp,"PUSH R%d\n",i++);

	temp=temp->left->left;
	struct tnode *t1=temp->left,*t2=temp->left,*t3;
	j=0;
	p=getReg();
	q=getReg();
	fprintf(fp,"MOV R%d,%d\n",p,ss1);
	fprintf(fp,"ADD R%d,BP\n",p);
	fprintf(fp,"MOV R%d,[R%d]\n",p,p);
	fprintf(fp,"MOV R%d, %d\n",q,ss2);
	fprintf(fp,"ADD R%d, R%d\n",p,q);
	fprintf(fp,"MOV R%d, [R%d]\n",q,p);
	fprintf(fp,"PUSH R%d\n",q);
	
	fprintf(fp,"MOV R%d,1\n",q);
	fprintf(fp,"ADD R%d,R%d\n",p,q);
	fprintf(fp,"MOV R%d,[R%d]\n",q,p);
	fprintf(fp,"PUSH R%d\n",q);
	freeReg();
	freeReg();
	
	while(t1!=NULL)
		{
		t2=t1;
		while(t2->mid!=NULL)
			t2=t2->mid;
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
		t1=temp->left;		
		}
	p=getReg();
	q=getReg();
	fprintf(fp,"PUSH R0\n");
	fprintf(fp,"MOV R%d, %d\n",p,ss1);
	fprintf(fp,"ADD R%d, BP\n",p);
	fprintf(fp,"MOV R%d, [R%d]\n",p,p);
	fprintf(fp,"MOV R%d, %d\n",q,ss2+1);
	fprintf(fp,"ADD R%d, R%d\n",p,q);
	fprintf(fp,"MOV R%d, [R%d]\n",p,p);
	fprintf(fp,"MOV R%d, %d\n",q,ss3);
	fprintf(fp,"ADD R%d, R%d\n",p,q);
	fprintf(fp,"MOV R%d, [R%d]\n",p,p);
	fprintf(fp,"CALL R%d\n",p);
	
	fprintf(fp,"POP R%d\n",p);

	while(j--)
		fprintf(fp,"POP R%d\n",q);
	fprintf(fp,"POP R%d\n",q);
	fprintf(fp,"POP R%d\n",q);
	while(i>0)
		fprintf(fp,"POP R%d\n",--i);
	
	freeReg();

	return p;	
	
	}
else if(temp->nodetype==26)
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
	/*if(strcmp(ch,temp->varname)==0)
		{
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

	//printf("\n\n\nSIVA\n");
	//prefix(temp);


	//		printf("\n\n\nSIVA\ni=%d reg=%d\n",i,reg);
	int i=0;
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
else if(temp->varname!=NULL && temp->nodetype==21)
	{
	p=getReg();
	printf("\n %s \n",temp->varname);
	fprintf(fp,"MOV R%d,%s\n",p,temp->varname);
	return p;
	}
else if(temp->left==NULL && temp->right==NULL)
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

void fill_class(struct Classtable *temp)
{
if(temp!=NULL)
	{
	struct Memberfunclist *f1=temp->vfuncptr;
	int i=0,c=temp->class_index;
	for(i=0;i<8;i++)
		fprintf(fp,"MOV [%d],-1\n",4096+c*8+i);
	while(f1!=NULL)
		{
		fprintf(fp,"MOV [%d],F%d\n",4096+c*8+f1->funcposition,f1->flabel);
		f1=f1->next;
		}
	fill_class(temp->next);
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

struct Gsymbol* GInstall(char *name,char *type,int size,struct Paramstruct *p1,int l1)
{
if(GLookup(name)!=NULL)
	{
	printf("Error:%s Variable Redeclared \n",name);
	exit(1);
	}
struct Gsymbol *new=(struct Gsymbol *)malloc(sizeof(struct Gsymbol));
new->name=name;
new->type=TLookup(type);
if(new->type==NULL)
new->ctype=CLookup(type);
new->size=size;
if(size!=0)
	new->binding=bind;
if(ctype==NULL)
	bind=bind+size;
else
	bind=bind+2;
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

struct Lsymbol* LInstall(char *name,char *type)
{
if(LLookup(name)!=NULL)
	{
	printf("Error: %s Variable Redeclared\n",name);
	exit(1);
	}
struct Lsymbol *new=(struct Lsymbol *)malloc(sizeof(struct Lsymbol));
new->name=name;
new->type=TLookup(type);
//if(new->type==NULL)
//	new->ctype=CLookup(type);
char *s1="self";
if(strcmp(s1,name)!=0)
	new->binding=(++bin);
else
	new->binding=-(bin+4);
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
pc=0;
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
pc++;
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
struct Fieldlist* FInstall(char *name,int ind,char *type)
{
struct Fieldlist* t1=(struct Fieldlist *)malloc(sizeof(struct Fieldlist));
t1->name=name;
t1->fieldIndex=ind;
t1->type=TLookup(type);
t1->ctype=CLookup(type);
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
void class_copy(struct Classtable *ch,struct Classtable *par)
{
struct Fieldlist *mf,*n1,*n2;
struct Memberfunclist *vf,*f1,*f2;
mf=par->memberfield;
vf=par->vfuncptr;
if(mf!=NULL)
	{
	n1=(struct Fieldlist *)malloc(sizeof(struct Fieldlist));
	n1->name=mf->name;
	n1->fieldIndex=mf->fieldIndex;
	n1->type=mf->type;
	n1->ctype=mf->ctype;

	mf=mf->next;
		ch->memberfield=n1;
	while(mf!=NULL)
		{
		n2=(struct Fieldlist *)malloc(sizeof(struct Fieldlist));
		n2->name=mf->name;
		n2->fieldIndex=mf->fieldIndex;
		n2->type=mf->type;
		n2->ctype=mf->ctype;
		n1->next=n2;
		n1=n2;
		mf=mf->next;
		}
	n1->next=NULL;
	}
else
	ch->memberfield=NULL;

if(vf!=NULL)
	{
	f1=(struct Memberfunclist *)malloc(sizeof(struct Memberfunclist));
	f1->name=vf->name;
	f1->funcposition=vf->funcposition;
	f1->flabel=vf->flabel;
	//fprintf(fp,"MOV [%d],F%d\n",bind+vf->funcposition,vf->flabel);
	f1->type=vf->type;
	f1->ctype=vf->ctype;
	f1->paramlist=param_copy(vf->paramlist);
	vf=vf->next;
		ch->vfuncptr=f1;
	while(vf!=NULL)
		{
		f2=(struct Memberfunclist *)malloc(sizeof(struct Memberfunclist));
		f2->name=vf->name;
		f2->funcposition=vf->funcposition;
		f2->flabel=vf->flabel;
		f2->type=vf->type;
		f2->ctype=vf->ctype;
		f2->paramlist=param_copy(vf->paramlist);


		f1->next=f2;
		f1=f2;
		vf=vf->next;
		}
	f1->next=NULL;
	}
else
	ch->memberfield=NULL;
}


struct Paramstruct* param_copy(struct Paramstruct *p1)
{
if(p1==NULL)
	return NULL;
struct Paramstruct *pp1,*pp2,*pp3;
pp1=(struct Paramstruct *)malloc(sizeof(struct Paramstruct));
pp1->name=p1->name;
pp1->type=p1->type;
pp1->next=NULL;
pp2=pp1;
p1=p1->next;
while(p1!=NULL)
	{
	pp3=(struct Paramstruct *)malloc(sizeof(struct Paramstruct));
	pp3->name=p1->name;
	pp3->type=p1->type;
	pp3->next=NULL;
	pp2->next=pp3;
	pp2=pp3;
p1=p1->next;
	}
return pp1;
}
struct Classtable* CInstall(char *name,char *parent_class_name)
{
struct Classtable *new=(struct Classtable *)malloc(sizeof(struct Classtable));
new->name=name;
new->parentptr=NULL;
if(parent_class_name!=NULL)
	{
	new->parentptr=CLookup(parent_class_name);
	class_copy(new,new->parentptr);
	if(new->parentptr==NULL)
		{
		printf("Parent Class %s not declared for %s\n",parent_class_name,name);
		exit(1);
		}
	fc=new->parentptr->fieldcount;
	mc=new->parentptr->methodcount;
	}
new->next=NULL;
new->class_index=cl_c++;
struct Classtable *temp=c1;
if(c1==NULL)
	c1=new;
else 
	{
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=new;
	}
return new;
}

struct Classtable* CLookup(char *name)
{
struct Classtable *temp=c1;
while(temp!=NULL)
	{
	if(strcmp(name,temp->name)==0)
		return temp;
	temp=temp->next;
	}
return temp;
}

void Class_FInstall(struct Classtable *cptr,char *typename,char *name)
{
if(fc>=8) 
	{
	printf("Too many fields in %s\n",Cptr->name);
	exit(1);
	}
struct Fieldlist *new=Class_FLookup(cptr,name);
if(new!=NULL)
	{
	printf("Field %s is redeclared in %s\n",name,cptr->name);
	exit(1);
	}
	/*
if(cptr->parentptr!=NULL)
	{
	new=Class_FLookup(cptr->parentptr,name);
	if(new!=NULL)
		{
		printf("Field %s is redeclared in %s\n",name,cptr->parentptr->name);
		exit(1);
		}
	}
	*/
new=(struct Fieldlist *)malloc(sizeof(struct Fieldlist));
new->name=name;
new->fieldIndex=fc++;
new->type=TLookup(typename);
new->ctype=CLookup(typename);
if(new->ctype!=NULL)
	fc++;
new->next=NULL;
struct Fieldlist *t1=cptr->memberfield;
if(t1==NULL)
	cptr->memberfield=new;
else
	{
	while(t1->next!=NULL)
		t1=t1->next;
	t1->next=new;
	}
}

void Class_MInstall(struct Classtable *cptr,char *name,char *type,struct Paramstruct *Paramlist)
{
struct Memberfunclist *new=Class_MLookup(cptr,name);
if(new!=NULL && cptr->parentptr==NULL)
	{
	printf("Method %s is redeclared in %s\n",name,cptr->name);
	exit(1);
	}
if(new==NULL)
	{
	new=(struct Memberfunclist *)malloc(sizeof(struct Memberfunclist));
	new->name=name;
	new->type=TLookup(type);
	new->ctype=Class_MLookup(cptr,type);
	new->paramlist=Paramlist;
	new->funcposition=mc;
	new->flabel=fl;
	//fprintf(fp,"MOV [%d],F%d\n",bind+mc,fl);
	new->next=NULL;
	struct Memberfunclist *t1=cptr->vfuncptr;
	if(t1==NULL)
		cptr->vfuncptr=new;
	else
		{
		while(t1->next!=NULL)
			t1=t1->next;
		t1->next=new;
		}
	}
else
	{
	//print_par(Class_MLookup(cptr,name)->paramlist);
	//	printf("\n\n");
	//	print_par(Paramlist);
	//print_classtable(c1);	
	if(check_par_type(new->paramlist,Paramlist))
		{
		new->flabel=++fl;
		//fprintf(fp,"MOV [%d],F%d\n",bind+new->funcposition,fl);
		}
	else
		{
		
		printf("Arguments are not matched in parent class %s and child class %s\n",cptr->name,cptr->parentptr->name);
		exit(1);
		}	
	}
}
int check_par_type(struct Paramstruct *p1,struct Paramstruct *p2)
{
if(p1==NULL && p2==NULL)
	return 1;
if((p1==NULL && p2!=NULL) || (p1!=NULL && p2==NULL))
	return 0;
if(strcmp(p1->name,p2->name)==0)
	if(p1->type!=NULL && p2->type!=NULL && strcmp(p1->type->name,p2->type->name)==0)
		{
		printf("name1 : %s type1 : %s name2 : %s type2 : %s\n",p1->name,p1->type->name,p2->name,p2->type->name); 
		return check_par_type(p1->next,p2->next);
		}
return 0;
	
}
struct Memberfunclist* Class_MLookup(struct Classtable *ctype,char *name)
{
struct Memberfunclist *t1=ctype->vfuncptr;
while(t1!=NULL)
	{
	if(strcmp(name,t1->name)==0)
		return t1;
	t1=t1->next;
	}
return t1;
}

struct Fieldlist* Class_FLookup(struct Classtable *ctype,char *name)
{
struct Fieldlist *t1=ctype->memberfield;
while(t1!=NULL)
	{
	if(strcmp(name,t1->name)==0)
		return t1;
	t1=t1->next;
	}
return t1;
} 

void print_classtable(struct Classtable *t1)
{
if(t1!=NULL)
	{
	if(t1->parentptr==NULL)
		printf("Cname : %s class_index=%d fieldcount=%d methodcount=%d\n",t1->name,t1->class_index,t1->fieldcount,t1->methodcount);
	else
		printf("Cname : %s parent_class_name:%s class_index=%d fieldcount=%d methodcount=%d\n",t1->name,t1->parentptr->name,t1->class_index,t1->fieldcount,t1->methodcount);
	print_f(t1->memberfield);
	print_methods(t1->vfuncptr);
	
	print_classtable(t1->next);
	}
}
void print_methods(struct Memberfunclist *t1)
{
if(t1!=NULL)
	{
	if(t1->type!=NULL)
	printf("met_name=%s type=%s funpos=%d flabel=%d\n",t1->name,t1->type->name,t1->funcposition,t1->flabel);
	print_par(t1->paramlist);
	//prefix(t1->paramlist);
	print_methods(t1->next);
	}
}

void print_gtab(struct Gsymbol *temp)
{
if(temp!=NULL)
{
if(temp->type!=NULL)
	printf("Name : %s Type : %s Size :%d Binding :%d ParamList : %x FLAbel : %d\n",temp->name,temp->type->name,temp->size,temp->binding,temp->paramlist,temp->flabel);
else if(temp->ctype!=NULL)
	printf("Name : %s Type : %s Size :%d Binding :%d ParamList : %x FLAbel : %d\n",temp->name,temp->ctype->name,temp->size,temp->binding,temp->paramlist,temp->flabel);
if(temp->paramlist!=NULL)
	print_par(temp->paramlist);
print_gtab(temp->next);
}
}

void print_ltab(struct Lsymbol *temp)
{
if(temp!=NULL)
{
if(temp->type!=NULL)
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
if(temp->type!=NULL)
	printf("\tname : %s fieldIndex : %d type : %s  \n",temp->name,temp->fieldIndex,temp->type->name);
if(temp->ctype!=NULL)
	printf("\tname : %s fieldIndex : %d ctype : %s  \n",temp->name,temp->fieldIndex,temp->ctype->name);
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
