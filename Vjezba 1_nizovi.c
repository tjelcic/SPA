#include <stdio.h>
#include <stdlib.h>
#define ZAD 3

int arr[]={1,2,3,4,5,6,7,8,9,10};

#if ZAD==1
int* podniz(int *niz, int start, int stop)
{
    int n=stop-start+1;
    int* arr=(int*)malloc(n*sizeof(n));
    if (!arr)
        return NULL;

    for(int i=0;i<n;i++)
    {
        arr[i]=niz[i+start];
    }
    return arr;
}

int main()
{
    int start, stop;
    printf("unesite pocetak i kraj niza:\n");
    scanf("%d %d",&start,&stop);
    int n=stop-start+1;
    int *novi=podniz(arr,start,stop);
    for(int i=0;i<n;i++)
    {
        printf("%d ", novi[i]);
    }
    free(novi);
    return 0;
}

#elif ZAD==2

int* filtriraj(int *niz, int n, int th, int *nth)
{
    int cnt=0, i, j;

    for (int i=0;i<n;i++)
    {
        if (niz[i]<th)
            cnt++;
    }

    int* arr=(int*) malloc (sizeof(int)*cnt);
    if (!arr)
        return NULL;

    for (i=0,j=0; i<n; i++,j++)
    {
        if (niz[i]<th)
        {
            arr[j]=niz[i];
        }
    }
    *nth=cnt;
    return arr;
}

int main()
{
    int sz=sizeof(arr)/sizeof(arr[0]),th=9,nth;
    int* newarr=filtriraj(arr,sz,th,&nth);
    for(int i=0; i<nth; i++)
    {
        printf("%d  ", newarr[i]);
    }
    free(newarr);
    return 0;
}

#elif ZAD==3

int** podijeli (int* niz, int n)
{
    int** p=(int**)malloc(sizeof(int)*2);
    if (!p)
        return NULL;
    int sz = n/2;
    int* arr1= (int*)malloc(sizeof(int)*sz);
    if (!arr1)
        return NULL;
    int* arr2 = (int*)malloc(sizeof(int)*sz);
    if (!arr2)
        return NULL;

    for(int i=0,j=0; i<n; i++,j++)
    {
        while (i<sz)
        {
            arr1[i]=niz[i];
            i++;
        }
        arr2[j]=niz[i];
    }

    p[0]=arr1;
    p[1]=arr2;

    return p;
}

int main()
{
    int n=sizeof(arr)/sizeof(arr[0]);
    int**p=podijeli(arr,n);
    int*a1=p[0];
    int*a2=p[1];
    printf("Prvi niz:\n");
    for (int i=0; i<n/2; i++)
    {
        printf("%d ", a1[i]);
    }
    printf("\nDrugi niz:\n");
    for (int i=0; i<n/2; i++)
    {
        printf("%d ", a2[i]);
    }
    free(p);
    free(a1);
    free(a2);
    return 0;
}

#endif // ZAD
