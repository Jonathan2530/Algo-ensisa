#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "utils.h"
#include <unistd.h> 

int main(void)
{
    // implement main here
    // create array example using malloc
    // use searching algorithms and compare runtime
    int* tab1 = malloc(5*sizeof(int));
    for (int i = 0; i < 5; i++){
        tab1[i] = i;
    }
    
    printf("Indice de l'element 3 dans tab1 : %d  (linear_s)\n", linear_search(tab1, 5, 3));
    printf("Indice de l'element 12 dans tab1 : %d (linear_s)\n", linear_search(tab1, 5, 12));
    printf("Indice de l'element 3 dans tab1 : %d  (jump_s)\n", jump_search(tab1, 5, 3));
    printf("Indice de l'element 12 dans tab1 : %d   (jump_s)\n", jump_search(tab1, 5, 12));
    printf("Indice de l'element 3 dans tab1 : %d  (binary_s)\n", binary_search(tab1, 5, 3));
    printf("Indice de l'element 12 dans tab1 : %d   (binary_s)\n", binary_search(tab1, 5, 12));

    int n = 25000;
    int* tab2 = malloc(n*sizeof(int));
    tab2[0] = 2;
    for(int i = 1; i<n; i++){
        tab2[i] = tab2[i-1] + i%7;
    }
    
    clock_t t1 = clock();
    int u = linear_search(tab2, n, 43703);
    clock_t t2 = clock();
    int v = jump_search(tab2, n, 12770);
    clock_t t3 = clock();
    int w = binary_search(tab2, n, 12770);
    clock_t t4 = clock();

    printf("%d %d %d\n", u, v, w);

    printf("temps linear search : %lf\n", (double)(t2-t1)/CLOCKS_PER_SEC);
    printf("temps jump search : %lf\n", (double)(t3-t2)/CLOCKS_PER_SEC);
    printf("temps binary search : %lf\n", (double)(t4-t3)/CLOCKS_PER_SEC);

    free(tab1);
    free(tab2);

    return 0;
}
