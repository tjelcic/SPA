#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_niz(int *niz, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", niz[i]);
    }
    printf("\n");
}

int compare(const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int* generiraj(int n)
{
    int* niz = (int*)malloc(sizeof(int) * n);
    niz[0] = rand() % 5;
    for (int i = 1; i < n; i++)
    {
        niz[i] = niz[i - 1] + 1 + rand() % 5;
    }
    return niz;
}

void shuffle(int *niz, int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = (rand() * rand()) % n;
        int tmp = niz[i];
        niz[i] = niz[j];
        niz[j] = tmp;
    }
}

int* presjek(int *niz1, int n1, int *niz2, int n2)   //O(N^2)
{
    shuffle(niz1, n1);
    shuffle(niz2, n2);

    clock_t start, end;
    start = clock();

    int *niz3 = (int*)malloc(3 * n1 * sizeof(int));

    int k = 0;
    for (int i = 0; i < n1; i++)   //O(N)
    {
        for (int j = 0; j < n2; j++)  //O(N)
        {
            if (niz1[i] == niz2[j])
            {
                niz3[k] = niz1[i];
                k++;
            }
        }
    }

    niz3 = (int*)realloc(niz3, k * sizeof(int));
    end = clock();
    double total = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Vrijeme za presjek niz1[%d] i niz2[%d]:%Lf\n", n1, n2, total);
    return niz3;
}

int* presjek_jedan_sortiran(int *niz1, int n1, int *niz2, int n2)   //O(NlogN+logN)
{
    shuffle(niz1, n1);
    shuffle(niz2, n2);

    clock_t start, end;
    start = clock();

    qsort(niz2, n2, sizeof(int), compare);//O(logN)

    int *niz3 = (int*) malloc(3 * n1 * sizeof(int));

    int j = 0;
    int *br;
    for (int i = 0; i < n2; i++)   //O(N)
    {
        br = (int*)bsearch(&niz1[i], niz2, n2, sizeof(int), compare);// O(logN)
        if (br != NULL)
        {
            niz3[j] = *br;
            j++;
        }
    }

    niz3 = (int*)realloc(niz3, j * sizeof(int));
    end = clock();
    double total = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Vrijeme za presjek nesortiranog i sortiranog niz1[%d] i niz2[%d]:%Lf\n", n1, n2, total);
    return niz3;
}

int* presjek_oba_sortirana(int *niz1, int n1, int *niz2, int n2)  //O(N^2 + 2logN)
{
    shuffle(niz1, n1);
    shuffle(niz2, n2);

    clock_t start, end;
    start = clock();

    qsort(niz1, n1, sizeof(int), compare);//O(logN)
    qsort(niz2, n2, sizeof(int), compare);//O(logN)

    int *niz3 = malloc(3 * n1 * sizeof(int));

    int k = 0;
    for (int i = 0; i < n1; i++)  //O(N)
    {
        for (int j = 0; j < n2; j++)  //O(N)
        {
            if (niz1[i] == niz2[j])
            {
                niz3[k] = niz1[i];
                k++;
            }
        }
    }

    niz3 = (int*)realloc(niz3, k * sizeof(int));
    end = clock();
    double total = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Vrijeme za presjek oba sortirana niz1[%d] i niz2[%d]:%Lf\n", n1, n2, total);
    return niz3;
}

int main()
{
    srand(time(NULL));
    int *niz1;
    int *niz2;
    int *niz3;

    for (int i = 100000; i <= 3000000; i += 300000)
    {
        printf("Iteracija %d: \n", i);
        niz1 = generiraj(i);
        niz2 = generiraj(i);
        niz3 = presjek(niz1, i, niz2, i);
        niz3 = presjek_jedan_sortiran(niz1, i, niz2, i);
        niz3 = presjek_oba_sortirana(niz1, i, niz2, i);
        printf("\n");
        free(niz1);
        free(niz2);
        free(niz3);
    }
    return 0;
}

