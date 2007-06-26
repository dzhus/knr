/**
 * K&R 6.6
 * Naive version of C preprocessor.
 *
 * Limitations: macro definitions are case-sensitive, multibyte
 * strings are not supported.
 *
 * Directive `#define` itself is case-insensitive, so `#DEFine` or
 * `#DEFINE` are all the same.
 *
 * Lines with `#define` are stripped from output.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "getty.h"
#include "compare.h"

#define HASHSIZE 101
#define MAXWORD 1000

typedef struct nlist 
{
  struct nlist * next;
  char * name;
  char * def;
} Entry;

enum state
  {NAME, DEF, EOL, CLEAR, U_DEF};


static struct nlist * hashtab[HASHSIZE];

void install(char * name, char * def);
void undef(char * name);
struct nlist * lookup(char * name);

unsigned hash(char * s);

int main (void)
{
  char
    * word = (char *)malloc(sizeof(char) * (MAXWORD + 1)),
    * prev_word = (char *)malloc(sizeof(char) * (MAXWORD + 1)),
    c;

  Entry * replace;
  
  int i, state = CLEAR;
  
  while ((c = getword(word, MAXWORD, (state == DEF || state == U_DEF) ? 1 : 0)) != EOF)
    {
      //printf("Got %s\n", word);

      /* @note This check is dirty */
      if (strcmp(strtolower(word), "#define") == 0)
        {
          state = NAME;
          continue;
        }
      else
        if (strcmp(strtolower(word), "#undef") == 0)
        {
          state = U_DEF;
          continue;
        }
      
      if (isalnum(c) || c == '_' || c == '#')
          switch (state)
            {
            case NAME:
              strcpy(prev_word, word);
              state = DEF;
              break;
            case DEF:
              install(prev_word, word);
              state = EOL;
              break;
            case U_DEF:
              undef(word);
              state = EOL;
              break;
            case CLEAR:
              if ((replace = lookup(word)) != NULL)
                printf("%s", replace->def);
              else
                printf("%s", word);
              break;
            }
      else
        if (state == CLEAR)
          putchar(c);
        else
          if (state == EOL && c == '\n')
            state = CLEAR;
    }

   
  /* struct nlist * entry = hashtab[0];
  for (i = 0; i < HASHSIZE; i++)
    for (entry = hashtab[i]; entry != NULL; entry = entry->next)
    printf("%s to %s\n", entry->name, entry->def); */
  
  return 0;
}

void install(char * name, char * def)
{
  Entry * e;
  unsigned hashval;

  if ((e = lookup(name)) == NULL)
    {
      e = (Entry *)malloc(sizeof(Entry));
      
      hashval = hash(name);
      
      e->name = strdup(name);
      
      e->def = strdup(def);
            
      e->next = hashtab[hashval];
      hashtab[hashval] = e;
    }
  else
    /* Replace old definition */
    {
      e->def = strdup(def);
    }
}

void undef(char * name)
{
  Entry * e;
  int i;

  if ((e = lookup(name)) != NULL)
    {
      free(e->name);
      free(e->def);
      
      if (e->next != NULL)
        e = e->next;
      else
        e = NULL;
    }
}

Entry * lookup(char * name)
{
  Entry * e;

  for (e = hashtab[hash(name)]; e != NULL; e = e->next)
    if (strcmp(name, e->name) == 0)
      return e;

  return NULL;
}

unsigned hash(char * s)
{
  unsigned hashval;

  for (hashval = 0; *s != '\0'; s++)
    hashval = *s + 31 * hashval;
  return hashval % HASHSIZE;
}
