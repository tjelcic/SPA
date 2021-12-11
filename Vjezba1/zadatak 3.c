#include <stdio.h>
#include <stdlib.h>

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
    int arr[]={1,2,3,4,5,6,7,8,9,10};
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
