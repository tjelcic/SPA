#include <stdio.h>
#include <stdlib.h>

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
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int sz=sizeof(arr)/sizeof(arr[0]),th=9,nth;
    int* newarr=filtriraj(arr,sz,th,&nth);
    for(int i=0; i<nth; i++)
    {
        printf("%d  ", newarr[i]);
    }
    free(newarr);
    return 0;
}
