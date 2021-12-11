#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float x,y;
}Tocka;

typedef struct
{
    Tocka* arr;
    int n;
}Poligon;

Poligon* novi_poligon(float *niz_x, float *niz_y, int n)
{
    Poligon* newpol = (Poligon*)malloc(sizeof(Poligon));
    if (!newpol)
        return NULL;

    newpol->arr = (Tocka*)malloc(sizeof(Tocka)*n);
    if (!newpol->arr)
        return NULL;

    for (int i = 0; i < n; i++)
    {
        newpol->arr[i].x = niz_x[i];
        newpol->arr[i].y = niz_y[i];
    }

    return newpol;
}

Tocka** pozitivni(Poligon* p, int* np)
{
    int cnt = 0;

    for (int i = 0; i < (p->n); i++)
    {
        if ((p->arr[i].x > 0) && (p->arr[i].y > 0))
            cnt++;
    }

    Tocka** parr = (Tocka**)malloc(sizeof(Tocka*) * cnt);
    if (!parr)
        return NULL;

    for (int i = 0, j = 0; i < (p->n); i++)
    {
        if ((p->arr[i].x > 0) && (p->arr[i].y > 0)) {
            parr[j] = &(p->arr[i]);
            j++;
        }
    }

    *np = cnt;
    return parr;
}

int main()
{
    float arr_x[]={5.5,2.7,-2.5,-1.8};
    float arr_y[]={2.2,1.4,-1.6,-3.2};
    int n=sizeof(arr_x)/sizeof(arr_x[0]);

    Poligon* pol=novi_poligon(arr_x,arr_y,n);
    pol->n=n;

    printf("Poligon ima koordinate:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x: %0.1f, y: %0.1f\n", pol->arr[i].x, pol->arr[i].y);
    }

    int np;
    Tocka** parr=pozitivni(pol,&np);
    printf("Pozitivni vrhovi su:\n");
    for (int i = 0; i < np; i++)
    {
        printf("x: %0.1f y: %0.1f\n", parr[i]->x,parr[i]->y);
    }
    return 0;
}
