#include <stdio.h>
#include <stdlib.h>


struct SVille{
    int voisin;
    struct SVille* suiv;
};

typedef struct SVille* ville;

struct SGraphe{
    int nbville;
    struct SVille** listesvoisins;
};


typedef struct SGraphe* graphe;

ville creerville(int v){
    ville m=malloc(sizeof(struct SVille));
    m->voisin=v;
    m->suiv=NULL;
    return m;
}

graphe creergraphe(int n){
    graphe g=malloc(sizeof(struct SGraphe));
    g->nbville=n;
    g->listesvoisins=malloc(n*sizeof(struct SVille*));
    for(int i=0;i<n;i++){
        g->listesvoisins[i]=NULL;
    }
    return g;
}

void creerchemin(graphe g, int x, int y){
    ville c1=creerville(x);
    c1->suiv=g->listesvoisins[y];
    g->listesvoisins[y]=c1;

    ville c2=creerville(y);
    c2->suiv=g->listesvoisins[x];
    g->listesvoisins[x]=c2;
}


//BFS shortestpath


int shortestpath(graphe g,int aladdin,int jasmine){
    int n=g->nbville;
    int* visite=malloc(n*sizeof(int));
    int* distance=malloc(n*sizeof(int)); 
    int* file=malloc(n*sizeof(int));
    //initialisation
    for(int i=0;i<n;i++){
        visite[i]=0;
        distance[i]=-1;
    }
    int debut=0;
    int fin=0;

    visite[aladdin]=1;
    distance[aladdin]=0;
    file[fin++]=aladdin;

    while (debut!=fin){
        int actuel=file[debut++];
        if(actuel==jasmine){break;}
        ville tmp=g->listesvoisins[actuel];
        while(tmp!=NULL){
            int voisin=tmp->voisin;
            if(!visite[voisin]){
                visite[voisin]=1;
                distance[voisin]=distance[actuel]+1;
                file[fin++]=voisin;
            }
            tmp=tmp->suiv;
        }
    }
    int resultat=distance[jasmine];
    free(visite);
    free(distance);
    free(file);
    return resultat;
}

void dfs(graphe g, int start, int* visited){
    visited[start] = 1;
    ville n = g->listesvoisins[start];
    while(n != NULL){
        int v = n->voisin;
        if(visited[v] == 0){
            dfs(g, v, visited);
        }
        n = n->suiv;
    }
}

int nb_royaumes(graphe g){
    int n=g->nbville;
    int visited[n];
    for(int i=0; i<n; i++){
        visited[i] = 0;
    }
    int royaumes = 0;
    int i = 0;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            royaumes++;
            dfs(g, i, visited);
        }
    }
    return royaumes;
}


void main(){
    FILE* fichier = fopen("test08.txt", "r");
    int n,m;
    fscanf(fichier, "%d %d", &n, &m);
    graphe g=creergraphe(n);
    for(int i=0; i<m; i++){
        int u,v;
        fscanf(fichier,"%d %d",&u,&v);
        u--;
        v--;
        creerchemin(g,u,v);
    }
    printf("%d\n",nb_royaumes(g));  

    int aladdin, jasmine;
    fscanf(fichier,"%d",&aladdin);
    fscanf(fichier,"%d",&jasmine);
    aladdin--;
    jasmine--;
    int etapes=shortestpath(g,aladdin,jasmine);
    printf("%d\n",etapes);
}