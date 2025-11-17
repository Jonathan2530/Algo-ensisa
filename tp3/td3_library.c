#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Noeud {
    int value;
    struct Noeud* left;
    struct Noeud* right;
};

typedef struct Noeud noeud;


noeud* creer_noeud(int v) {
    noeud* n = malloc(sizeof(noeud));
    n->value = v;
    n->left = NULL;
    n->right = NULL;
    return n;
}


noeud* inserer(noeud* n, int v) {
    if (n == NULL) {
        return creer_noeud(v);
    }
    if (v < n->value) {
        n->left = inserer(n->left, v); //inserer a gauche
    } 
    else if (v > n->value) {
        n->right = inserer(n->right, v); //inserer a droite
    }
    return n;
}

bool search(noeud* n, int v) {
    if (n == NULL) {
        //arbre vide
        return false; 
    }
    if (v == n->value) {
        return true; 
    }
    else if (v < n->value) {
        return search(n->left, v);
    } 
    else {
        return search(n->right, v);
    }
}

void read_file(char* nom_fichier) {
    FILE* fichier = fopen(nom_fichier, "r");
    int k = 0;
    int id = 0;

    // construction de l'arbre
    noeud* arbre = NULL;
    fscanf(fichier, "%d\n", &k); //1ere ligne = nbr de livres
    for(int i = 0; i < k; i++) {
        fscanf(fichier, "%d", &id);
        arbre = inserer(arbre, id);
    }
    
    // recherches
    fscanf(fichier, "\n%d\n", &k); //1ere ligne = nbr de recherches
    for(int i = 0; i < k; i++) {
        fscanf(fichier, "%d", &id);
        bool trouve = search(arbre, id);
        if(trouve){
            printf("YES\n");
        }else{
            printf("NO\n");
         }
    }
    fclose(fichier);

}

void main(void) {
   
    read_file("test01.txt");
}