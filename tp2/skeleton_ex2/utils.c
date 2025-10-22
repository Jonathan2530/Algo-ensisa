#include "utils.h"
#include <stdio.h>
#include <time.h>

void swap_int(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

bool is_sorted_nondecreasing(int *arr, int n)
{
    for(int i = 0; i < n-1; i++){
        if (arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
}

void copy_array(int *src, int *dst, int n)
{
    for(int i = 0; i< n;i++){
        dst[i] = src[i];
    }
    // copy array elements src into dst
}

void print_array(int *arr, int n)
{
    for(int i = 0; i< n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void generer_tableau_aleatoire(int *tab, int taille, int min, int max) {
    for (int i = 0; i < taille; i++) {
        tab[i] = rand() % (max - min + 1) + min;
    }
}