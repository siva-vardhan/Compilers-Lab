int count=0;
typedef struct tnode
{
int val;
char *varname;
struct Typetable *type;
int nodetype;
struct Gsymbol *Gentry;
struct Lsymbol *Lentry;
struct tnode *left,*mid,*right;
}tnode;

struct Gsymbol
{
char *name;
struct Typetable *type;
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
int bin,ind=0;
struct Lsymbol{
char *name;
struct Typetable *type;
int binding;
struct Lsymbol *next;
};
struct Lsymbol *l1;
int i=1;
int fl=-1;
int bind=4096;
struct Typetable *type,*ttype,*ptype;
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
struct Fieldlist *next;
};
struct Fieldlist *f1;


struct Paramstruct* PInstall(char *ch,struct Typetable *type);

struct Lsymbol* LLookup(char *name);
struct Lsymbol* LInstall(char *name,struct Typetable *type);
struct Typetable *fnret;
struct Gsymbol* GLookup(char *name);
struct Gsymbol* GInstall(char *name,struct Typetable *type,int size,struct Paramstruct *,int );

struct tnode* makeOperatorNode(char *c,int n,int a,struct Typetable *b,struct tnode *l,struct tnode *m,struct tnode *r);
void prefix(struct tnode *temp);
int reg=0;
FILE *fp;
void gencode(struct tnode *temp);
int arithmetic(struct tnode *temp);
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
