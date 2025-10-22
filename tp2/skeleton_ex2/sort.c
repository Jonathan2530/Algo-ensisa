#include <stdlib.h>
#include "sort.h"
#include "utils.h"

void selection_sort(int *arr, int n)
{
    // selection sort iterative
    for(int i = 0; i< n-1; i++){
        int min = i;
        for(int j = i+1; j<n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap_int(&arr[i], &arr[min]);
    }
}

void insertion_sort(int *arr, int n)
{
    for(int i = 1; i< n; i++){
        int j = i;
        while(j>0 && arr[j] < arr[j-1]){
            swap_int(&arr[j], &arr[j-1]);
            j = j - 1;
        }
    }
}

void bubble_sort(int *arr, int n)
{
    // bubble sort iterative
    while(!is_sorted_nondecreasing(arr, n)){
        for(int i = 0; i< n-1; i++){
            if(arr[i] > arr[i+1]){
                swap_int(&arr[i], &arr[i+1]);
            }
        }
    }
}

void merge(int *arr, int *tmp, int l, int m, int r)
{
    // merge function
    int i1 = l;
    int i2 = m + 1;
    for(int i = l; i <= r; i++){
        if(i1 <= m && (i2 > r || arr[i1] <= arr[i2])){
            tmp[i] = arr[i1];
            i1++;
        } else if(i2 <= r) {
            tmp[i] = arr[i2];
            i2++;
        }
    }
    for(int i = l; i <= r; i++){
        arr[i] = tmp[i];
    }
}

void mergesort_rec(int *arr, int *tmp, int l, int r)
{
    int p = l + (r - l) / 2;
    if (l < r) {
        mergesort_rec(arr, tmp, l, p);
        mergesort_rec(arr, tmp, p + 1, r);
        merge(arr, tmp, l, p, r);
    }
    // recursive steps of merge sort
}

void merge_sort(int *arr, int n)
{
    if (!arr || n <= 1)
        return;
    int *tmp = (int *)malloc((size_t)n * sizeof(int));
    if (!tmp)
        return;
    mergesort_rec(arr, tmp, 0, n - 1);
    free(tmp);
}
int partition(int *arr, int l, int r)
{
    int j = l;
    int p = arr[r];
    for(int i = l; i < r; i++){
        if(arr[i] <= p){
            swap_int(&arr[i], &arr[j]);
            j++;
        }
    }
    swap_int(&arr[j], &arr[r]);
    return j;
    // partition function
}

void quick_sort_rec(int *arr, int l, int r)
{
    // recursive steps of quick sort
    int p = partition(arr, l, r);
    if(l < p-1){
        quick_sort_rec(arr, l, p-1);
    }
    if(p+1 < r){
        quick_sort_rec(arr, p+1, r);
    }
}

void quick_sort(int *arr, int n)
{
    if (!arr || n <= 1)
        return;
    quick_sort_rec(arr, 0, n - 1);
}