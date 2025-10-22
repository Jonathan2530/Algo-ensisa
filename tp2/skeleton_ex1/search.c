#include <math.h>
#include <stdio.h>
#include "search.h"
#include "utils.h"

int linear_search(int *arr, int n, int target)
{
    // linear search, return index of target
    // return -1 if not found
    for(int i = 0; i< n; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int jump_search(int *arr, int n, int target)
{
    if(!is_sorted_nondecreasing(arr, n)){
        return -1;
    }
    int pas = (int)(sqrt(n));
    int i = 0;
    while((i<n) && (arr[i] <= target)){
            i = i + pas;
    }
    for(int j = i - pas; j<min_int(i, n); j++){
        if(arr[j] == target){
            return j;
        }
    }
    return -1;
    // jump search on sorted array, return index
    // of target, return -1 if not found
}

int binary_search(int *arr, int n, int target)
{
    if(!is_sorted_nondecreasing(arr, n)){
        return -1;
    }
    int deb = 0;
    int fin = n-1;
    while(deb <= fin ){
        int moy = (deb+fin) /2;
        if (arr[moy] == target){
            return moy;
        }
        else{
            if(arr[moy] < target){
                deb = moy + 1;
            }
            else{
                fin = moy;
            }
        }
    }
    // binary search on sorted array, return index
    // of target, return -1 if not found
    return -1;
}