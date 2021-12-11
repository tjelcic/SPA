#include <stdio.h>
#include <stdlib.h>

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
    int arr[]={1,2,3,4,5,6,7,8,9,10};
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
