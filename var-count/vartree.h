#ifndef VARTREE_INC
#define VARTREE_INC

typedef struct t_var
{
  char * name;
  int count;
  struct t_line * last_line;
  
  struct t_var * left;
  struct t_var * right;
} Variable;

typedef struct t_line
{
  int number;
  int count;
  
  struct t_line * prev;
} Line;

typedef struct t_group
{
  char * tag;
  int total_count;
  
  struct t_var * var;
  struct t_group * left;
  struct t_group * right;
} Group;

Group * insertGroup(Group * g_root, char * tag, char * name, int line);
Variable * insertVariable(Variable * v_root, char * name, int line);
Line * insertLine(int line);

Group * newGroup(char * tag);
Variable * newVariable(char * name);
Line * newLine(int line);

Group * allocateGroup(void);
Variable * allocateVariable(void);
Line * allocateLine(void);

void printGroup(Group * g);
void printVariable(Variable * var);
void printLines(Line * l);

#endif
