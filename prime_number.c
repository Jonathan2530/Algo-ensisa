#include <stdio.h>
#include <stdlib.h>

int nb_prime(int n){
    int sum = 0;
    int b = 1;
    for(int i = 2; i<n; i++){
        for (int j = 2; j < i; j++){
            if(i % j == 0){
                b = 0;
            }
        }
        if(b == 1){
            sum++;
        }
        b = 1;
    }
    return sum;
}

int nb_prime_efficace(int n){
    int* t = malloc(n*sizeof(int));
    for(int i = 0; i<n; i++){
        t[i] = 1;
    }
    for(int i = 2; i <= n; i++){
        for(int j = 2*i; j <= n; j+=i){
            t[j] = 0;
        }
    }
    int sum = 0;
    for(int i = 2; i<n; i++){
        sum += t[i];
    }
    return sum;
}

int main(){

    int i = 10;
    printf("Il y a %d nombres premiers entre 0 et %d\n", nb_prime(i), i);
    printf("Il y a %d nombres premiers entre 0 et %d\n", nb_prime_efficace(i), i);

    return 0;
}