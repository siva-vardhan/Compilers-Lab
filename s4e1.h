typedef struct tnode
{
int val;
char *varname;
int type;
int nodetype;
struct Gsymbol *Gentry;
struct tnode *left,*mid,*right;
}tnode;
struct Gsymbol
{
char *name;
int type;
int size;
int row;
int col;
int binding;
struct Gsymbol *next;
};
int bind=4096;
int type;
int size;
void insert(char *,int,int,int);
struct Gsymbol *head;
struct Gsymbol *Lookup(char *name);
void Install(char *name,int type,int size,int col);
struct tnode* makeLeafNode(char *ch,int n,int a);
struct tnode* makeOperatorNode(char *c,int a,struct tnode *l,struct tnode *m,struct tnode *r);
void infix(struct tnode *temp);
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
void print_tab(struct Gsymbol *temp);
