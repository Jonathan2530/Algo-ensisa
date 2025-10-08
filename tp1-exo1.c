#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int fibonacci(int x){
    if (x == 0 || x == 1){
        return x;
    }
    else{
        return fibonacci(x-1) + fibonacci(x-2);
    }
}

int fibonacci_2(int x, int* tab){
    if (x <= 1){
        return x;
    }
    if (tab[x] != -1){
        return tab[x];
    }
    tab[x] = fibonacci_2(x-1, tab) + fibonacci_2(x-2, tab);
    return tab[x];
}


void test_fib(int n){
     for( int i = 0; i < n; i++){
        printf("fibonacci naif(%i) = %i\n", i, fibonacci(i));
    }
}

void test_fib_2(int n){
    for( int i = 0; i < n; i++){
        int* tab = malloc((i+1)*sizeof(int));
        for(int j = 0; j < i+1; j++){
            tab[j] = -1;
        }
        printf("fibonacci efficace(%i) = %i\n", i, fibonacci_2(i, tab));
    }
}


int main(){

    test_fib(20);
    test_fib_2(20);

    // fibonacci naive
    float t1 = clock();
    int x = fibonacci(20);
    float t2 = clock();

    // fibonacci efficace
    float t3 = clock();
    int* tab = malloc((21)*sizeof(int));
    for(int j = 0; j < 21; j++){
        tab[j] = -1;
    }
    int y = fibonacci_2(20, tab);
    float t4 = clock();

    printf("\nAvec fibonacci naif\n");
    printf("Calcul fib(20) : %f\n\n", (t2 - t1)/CLOCKS_PER_SEC);
    printf("Avec fibonacci efficace\n");
    printf("Calcul fib(20) : %f\n", (t4 - t3)/CLOCKS_PER_SEC);
    

   return 0;
}