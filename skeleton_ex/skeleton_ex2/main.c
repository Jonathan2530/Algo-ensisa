#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "utils.h"

int main(void)
{
    int taille = 25000;
    int* tab = malloc(taille * sizeof(int));
    generer_tableau_aleatoire(tab, taille, 0, 100000);
    
    int n = 10;
    int* tab1 = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++){
        tab1[i] = (i%3)*i;
    }

    printf("Avant tri : ");
    print_array(tab1, n);
    selection_sort(tab1, n);
    printf("tri selection : ");
    print_array(tab1, n);

    for (int i = 0; i < n; i++){
        tab1[i] = (i%3)*i;
    }
    insertion_sort(tab1, n);
    printf("tri insertion : ");
    print_array(tab1, n);

    // Bubble sort
    clock_t t1 = clock();
    int* tab2 = malloc(taille * sizeof(int));
    copy_array(tab, tab2, taille);
    bubble_sort(tab2, taille);
    printf("bubble sort: ");
    printf("Le tableau est trie: %d\n", is_sorted_nondecreasing(tab2, taille));

    // Merge sort
    clock_t t2 = clock();
    int* tab3 = malloc(taille * sizeof(int));
    copy_array(tab, tab3, taille);
    merge_sort(tab3, taille);
    printf("Merge sort: ");
    printf("Le tableau est trie: %d\n", is_sorted_nondecreasing(tab3, taille));

    // Quick sort
    clock_t t3 = clock();
    int* tab4 = malloc(taille * sizeof(int));
    copy_array(tab, tab4, taille);
    quick_sort(tab4, taille);
    printf("Quick sort: ");
    printf("Le tableau est trie: %d\n", is_sorted_nondecreasing(tab4, taille));
    clock_t t4 = clock();

    printf("temps bubble sort : %lf\n", (double)(t2-t1)/CLOCKS_PER_SEC);
    printf("temps merge sort : %lf\n", (double)(t3-t2)/CLOCKS_PER_SEC);
    printf("temps quick sort : %lf\n", (double)(t4-t3)/CLOCKS_PER_SEC);

    printf("Quicksort est %d fois plus rapide que bubblesort\n", (int)((double)(t2 - t1) / (double)(t4 - t3)));
    // implement main here
    // create array example using malloc
    // use sorting algorithms and compare runtime
    free(tab1);
    free(tab2);
    free(tab3);
    free(tab4);
    free(tab);
    return 0;
}
