typedef struct tnode
{
int val;
char *varname;
int type;
int nodetype;
struct tnode *left,*right;
}tnode;

struct tnode* makeLeafVar(char *ch,int n);
struct tnode* makeOperatorNode(char *c,int a,struct tnode *l,struct tnode *r);
void prefix(struct tnode *temp);
int reg=0;
FILE *fp;
void gencode(struct tnode *temp);
int arithmetic(struct tnode *temp);
void assign(struct tnode *temp);
void gen_step(struct tnode *temp);
void exit_fun();
void read_fun(struct tnode *temp);
void write_fun(struct tnode *temp);

