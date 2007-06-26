#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "vartree.h"

/**
    Add a variable occurency to tree
*/
Group * insertGroup(Group * g_root, char * tag, char * name, int line)
{
  int cmp;
  
#ifdef DEBUG
  printf("Got %s, %s at %d\n", tag, name, line);
#endif
  
  if (g_root == NULL)
    {
      g_root = newGroup(tag);
      g_root->var = insertVariable(g_root->var, name, line);
    }
  else
    if ((cmp = strcmp(tag, g_root->tag)) == 0)
      {
        g_root->total_count++;
        g_root->var = insertVariable(g_root->var, name, line);
      }
    else
      if (cmp > 0)
        g_root->right = insertGroup(g_root->right, tag, name, line);
      else
        g_root->left = insertGroup(g_root->left, tag, name, line);
  
  return g_root;
}

/**
   Add a variable occurency to variable group
*/
Variable * insertVariable(Variable * v_root, char * name, int line)
{
  int cmp;
  Line * nl;

  if (v_root == NULL)
    {
      v_root = newVariable(name);
      v_root->last_line = newLine(line);
    }
  else
    if ((cmp = strcmp(name, v_root->name)) == 0)
      {
        v_root->count++;
        if (line == v_root->last_line->number)
          v_root->last_line->count++;
        else
          {
            nl = newLine(line);
            nl->prev = v_root->last_line;
            v_root->last_line = nl;
          }
      }
    else
      if (cmp > 0)
        v_root->right = insertVariable(v_root->right, name, line);
      else
        v_root->left = insertVariable(v_root->left, name, line);

  return v_root;
}

/**
   Return a pointer to a new empty group for tag.
*/
Group * newGroup(char * tag)
{
  Group * g = allocateGroup();
  g->tag = strdup(tag);
  g->left = g->right = NULL;
  g->total_count = 1;
  g->var = NULL;

  return g;
}

/**
   Return a pointer to a new empty node for specified variable name.
   Inserting a line into node is expected.
*/
Variable * newVariable(char * name)
{
  Variable * v = allocateVariable();
  v->count = 1;
  v->name = strdup(name);
  v->last_line = NULL;
  v->left = v->right = NULL;
  
  return v;
}

/**
   Return a pointer to a new line node with count of occurencies in line equal to 1.
*/
Line * newLine(int line)
{
  Line * l = allocateLine();
  l->number = line;
  l->count = 1;
  l->prev = NULL;

  return l;
}

Group * allocateGroup(void)
{
  return (Group *)malloc(sizeof(Group));
}

Variable * allocateVariable(void)
{
  return (Variable *)malloc(sizeof(Variable));
}

Line * allocateLine(void)
{
  return (Line *)malloc(sizeof(Line));
}

void printGroup(Group * g)
{
  if (g != NULL)
    {
      printGroup(g->left);

      printf("Group %s, %d variables:\n", g->tag, g->total_count);
      printVariable(g->var);
      
      printGroup(g->right);
    }
}

void printVariable(Variable * var)
{
  if (var != NULL)
    {
      printVariable(var->left);

      printf("\tVariable %s, occured %d times:\n", var->name, var->count);
      printLines(var->last_line);

      printVariable(var->right);
    }
}

void printLines(Line * l)
{
  if (l != NULL)
    {
      printLines(l->prev);

      printf("\t\tLine %d, %d times\n", l->number, l->count);
    }
}

