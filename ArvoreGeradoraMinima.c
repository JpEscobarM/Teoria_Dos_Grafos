#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define tam 6
#define inf 99

int grafo[tam][tam] = {{inf,3,2,inf,5,4},
                       {3,inf,3,4,inf,4},
                       {2,3,inf,5,2,4},
                       {inf,4,5,inf,4,6},
                       {5,inf,2,4,inf,2},
                       {4,4,4,6,2,inf},  };



int main(){


int i, j ;


    int visitados[tam], distancias[tam], pai[tam];
    for( i = 0 ; i < tam ; i ++){

        distancias[i] = inf ;
        visitados[i] =0 ;

    }

    distancias[0] = 0;

    pai [0] = -1;

    for( i = 0 ; i < tam; i ++){

        int menor = inf,u;
        for ( j =0; j < tam ; j ++ ){

                if( visitados[j] == 0 && distancias[j] < menor){
                    menor = distancias[j]; u = j;
                }

        }
    visitados[u] = 1;
    for( j = 0 ; j < tam ; j++ ){

        if ( visitados[j] == 0 && grafo[u][j] < distancias [j]){
         distancias [j] = grafo[u][j]; pai[j] = u;
        }

    }



    }
    printf("Distancias: ");
    for( i = 0 ; i < tam ; i ++ ){
        printf("%d ", distancias[i]);
    }
    printf("\npai: ");
    for( i = 0 ; i < tam ; i ++ ){
        printf("%d ", pai[i]);
    }


return 0;
}
