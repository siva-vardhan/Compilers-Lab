int count=0,set=0;
int mcheck[8];
typedef struct tnode
{
	int val;
	char *varname;
	struct Typetable *type;
	struct Classtable *ctype;
	int nodetype;
	struct Gsymbol *Gentry;
	struct Lsymbol *Lentry;
	struct tnode *left,*mid,*right;
}tnode;

struct Gsymbol
{
	char *name;
	struct Typetable *type;
	struct Classtable *ctype;
	int size;
	int binding;
	struct Paramstruct *paramlist;
	int flabel;
	struct Gsymbol *next;
};
struct Gsymbol *head;

struct Paramstruct 
{
	char *name;
	struct Typetable *type;
	struct Paramstruct *next;
};
struct Paramstruct *h1;
int bin,pc,ind=0,s1=0;
struct Lsymbol{
	char *name;
	struct Typetable *type;
	//int self;
	//struct Classtable *ctype;
	int binding;
	struct Lsymbol *next;
};
struct Lsymbol *l1;
int i=1;
int fl=-1;
int bind=4096;
struct Typetable *type,*ptype;
char *typ;
struct Classtable *ctype;
int size;

struct Typetable
{
	char *name;
	int size;
	struct Fieldlist *fields;
	struct Typetable *next;
};
struct Typetable *T1;

struct Fieldlist{
	char *name;
	int fieldIndex;
	struct Typetable *type;
	struct Classtable *ctype;
	struct Fieldlist *next;
};
struct Fieldlist *f1;

struct Memberfunclist
{
	char *name;
	struct Typetable *type;
	struct Classtable *ctype;
	struct Paramstruct *paramlist;
	int funcposition;
	int flabel;
	struct Memberfunclist *next;
};

struct Classtable
{
	char *name;
	struct Fieldlist *memberfield;
	struct Memberfunclist *vfuncptr;
	struct Classtable *parentptr;
	int class_index;
	int fieldcount;
	int methodcount;
	struct Classtable *next;
	
};
struct Classtable *c1,*Cptr;

int fc,mc,ci=-1,cl_c=0;

struct Classtable* CInstall(char *name,char *parent_class_name);
struct Classtable* CLookup(char *name);
void Class_FInstall(struct Classtable *cptr,char *typename,char *name);
void Class_MInstall(struct Classtable *cptr,char *name,char *type,struct Paramstruct *Paramlist);
struct Memberfunclist* Class_MLookup(struct Classtable *ctype,char *name);
struct Fieldlist* Class_FLookup(struct Classtable *ctype,char *name);
void print_classtable(struct Classtable *t1);
void print_methods(struct Memberfunclist *t1);

struct Paramstruct* PInstall(char *ch,struct Typetable *type);
struct Lsymbol* LLookup(char *name);
struct Lsymbol* LInstall(char *name,char *type);
struct Typetable *fnret;
struct Gsymbol* GLookup(char *name);
struct Gsymbol* GInstall(char *name,char *type,int size,struct Paramstruct *,int );

struct tnode* makeOperatorNode(char *c,int n,int a,struct Typetable *b,struct tnode *l,struct tnode *m,struct tnode *r);
void prefix(struct tnode *temp);
int reg=0;
FILE *fp;
void gencode(struct tnode *temp);
int arithmetic(struct tnode *temp);
int addr_eval(struct tnode *temp);
void assign(struct tnode *temp);
void gen_step(struct tnode *temp,int ,int);
void exit_fun();
void read_fun(struct tnode *temp);
void write_fun(struct tnode *temp);
int arr[26];
int evaluator(struct tnode* temp);
int label=0,label1,label2;
int getLabel();
void relate(struct tnode *temp);
void print_gtab(struct Gsymbol *temp);
void print_ltab(struct Lsymbol *t);
void print_par(struct Paramstruct *);
void print_t(struct Typetable *temp);
void print_f(struct Fieldlist *temp);
void TypeTableCreate();
struct Typetable* TLookup(char *name);
struct Typetable* TInstall(char *name,int size,struct Fieldlist *fields);
struct Fieldlist* FLookup(struct Typetable *type,char *name);
int GetSize(struct Typetable *type);
struct Paramstruct* param_copy(struct Paramstruct *p1);
int check_par_type(struct Paramstruct *p1,struct Paramstruct *p2);
void stack_fun_init();
