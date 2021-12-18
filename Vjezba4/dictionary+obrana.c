#include "dictionary.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Dictionary create()
{
  Dictionary rjecnik = (Dictionary)malloc(sizeof(Word));
  rjecnik->count = 0;
  rjecnik->next = NULL;
  rjecnik->word = NULL;
  return rjecnik;
}

void add(Dictionary dict, char *str)
{
  Dictionary p = dict;
  Dictionary n = dict->next;

  Dictionary novi = (Dictionary)malloc(sizeof(Word));
  novi->word = (char *)malloc(sizeof(char) * (strlen(str) + 1));
  strcpy(novi->word, str);
  novi->count = 1;

  while (n != NULL)
  {
    if (strcmp(n->word, str) == 0)
    {
      n->count++;
      free(novi->word);
      free(novi);
      return;
    }
    else if (strcmp(n->word, str) > 0)
    {
      novi->next = n;
      p->next = novi;
      return;
    }
    n = n->next;
    p = p->next;
  }

  p->next = novi;
  novi->next = NULL;
}

void print(Dictionary dict)
{
  dict = dict->next;
  while (dict != NULL)
  {
    printf("%s - broj pojavljivanja: %d\n", dict->word, dict->count);
    dict = dict->next;
  }
}

void destroy(Dictionary dict)
{
  Dictionary temp = dict;
  dict = dict->next;
  free(temp);

  while (dict != NULL)
  {
    temp = dict;
    dict = dict->next;
    free(temp->word);
    free(temp);
  }
}

Dictionary filterDictionary(Dictionary indict, int (*filter)(Word *w))
{
  Dictionary p = indict;
  Dictionary n = indict->next;

  while (n != NULL)
  {
    if (filter(n))
    {
      p = p->next;
      n = n->next;
    }
    else
    {
      p->next = n->next;
      free(n->word);
      free(n);
      n = p->next;
    }
  }
  return indict;
}

int filter(Word *w)
{
  if ((w->count > 5 && w->count < 10) && strlen(w->word) > 3)
    return 1;
  else
    return 0;
}

void prvi_na_kraj (Dictionary dict)
{
    Dictionary tmp=dict->next;

    Dictionary n = dict->next;
    Dictionary nova = (Dictionary)malloc(sizeof(Word));
    nova->count=tmp->count;

    while (n != NULL)
    {
        n = n->next;
        dict = dict->next;
    }
    nova->word=strdup(tmp->word);
    dict->next = nova;
    nova->next = NULL;
}
