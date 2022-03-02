#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int n = 10;

typedef struct
{
    void* ignore;
    int prioritet;
}Element;

typedef struct
{
    Element *niz;
}Red;

void print_red (Red *q)
{
    for (int i = 0; i < n; i++)
    {
        printf ("Element: %d\n",q->niz[i].prioritet);
    }
}

void switch_el (Red *q,int l, int d)
{
    Element temp = q->niz[l];
    q->niz[l] = q->niz[d];
    q->niz[d] = temp;
}

void fix_up (Red *q,int i)
{
    if (i == 0)
        return;
    int parent_index = (i-1)/2;
    Element parent_element = q->niz[parent_index];
    if (parent_element.prioritet < q->niz[i].prioritet)
    {
        switch_el(q,parent_index,i);
        fix_up(q,parent_index);
    }
}

void add (Red *q,int i)
{
    q->niz[i].prioritet = rand()%n;
    fix_up(q,i);
}

void fix_down (Red *q, int i)
{
    int l = 2*i+1;
    int d = 2*i+2;
    if (d >= n && l >= n)
        return;

    if (l < n && d >= n)
    {
        if (q->niz[i].prioritet < q->niz[l].prioritet) {
            switch_el(q,i,l);
        }
    }
    else if (d < n && l >= n)
    {
        if (q->niz[i].prioritet < q->niz[d].prioritet) {
            switch_el(q, i, d);
        }
    }
    else if (q->niz[i].prioritet < q->niz[l].prioritet && q->niz[l].prioritet >= q->niz[d].prioritet)
    {
        switch_el(q,i,l);
        fix_down(q,l);
    }
    else if (q->niz[i].prioritet < q->niz[d].prioritet && q->niz[d].prioritet >= q->niz[l].prioritet)
    {
        switch_el(q,i,d);
        fix_down (q,d);
    }
}

void remove_first (Red *q)
{
    q->niz[0] = q->niz[n-1];
    n--;
    q->niz = (Element*)realloc(q->niz,n*sizeof(Element));
    fix_down(q,0);
}

int main ()
{
    srand(time(NULL));
    Red *q = (Red*)malloc(sizeof(Red));
    q->niz = (Element*)malloc(n*sizeof(Element));
    for (int i = 0; i < n; i++)
    {
        add(q,i);
    }

    printf ("\tNiz\n");
    print_red(q);
    printf ("\tUklanjanje elementa na vrhu\n");
    remove_first(q);
    print_red(q);
    free (q->niz);
    free (q);
    return 0;
}
