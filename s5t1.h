typedef struct tnode
{
int val;
char *varname;
int type;
int nodetype;
struct Gsymbol *Gentry;
struct Lsymbol *Lentry;
struct tnode *left,*mid,*right;
}tnode;

struct Gsymbol
{
char *name;
int type;
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
int type;
struct Paramstruct *next;
};
struct Paramstruct *h1;
int bin;
struct Lsymbol{
char *name;
int type;
int binding;
struct Lsymbol *next;
};
struct Lsymbol *l1;
int i=1;
int fl=-1;
int bind=4096;
int type;
int size;
//void Ginsert(char *,int,int,struct Paramstruct *,int);
void PInstall(char *,int);
//void Linsert(char *,int);
struct Lsymbol *LLookup(char *name);
void LInstall(char *name,int type);
int fnret;
struct Gsymbol *Lookup(char *name);
void GInstall(char *name,int type,int size,struct Paramstruct *,int );
//struct tnode* makeLeafNode(char *ch,int n,int a,int b);
struct tnode* makeOperatorNode(char *c,int n,int a,int b,struct tnode *l,struct tnode *m,struct tnode *r);
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
