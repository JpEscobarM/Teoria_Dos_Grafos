
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 5
#define inf 999
float grafo[n][n] = {{0,0.7,inf,inf,0.8},
                   {0.7,inf,0.29,inf,inf},
                   {inf,29,inf,0.14,inf},
                   {inf,inf,0.14,inf,0.1},
                   {0.8,inf,inf,0.1,inf},};

void dijkstra(float g[n][n], int vi, int vf){

    float distancias[n];
    float pai[n];
    float probabilidade[n];
    float visitados[n];
    int count = 1;
    int i, j ;

    for( i = 0 ; i < n ; i ++){
        probabilidade[i]=0;
        distancias[i] = inf ;
        pai[i] = -1;
        visitados[i] = 0 ;
    }

    distancias[vi] = 1;
    probabilidade[vi] = 1;
    for ( i  = 0 ; i < n ; i ++){
        int menor =  inf, u;



        for( j = 0 ; j < n ; j ++){

            if( visitados[j] == 0 && distancias[j] < menor){
               menor = distancias[j]; u = j;


            }
            }

        visitados[u] = 1.0;


        for( j = 0 ; j < n ; j ++){

            if( visitados[j] == 0 && distancias[j] < distancias[u] + g[u][j]){

                distancias[j] =  distancias[u] + g[u][j];
                pai[j] = u;
                probabilidade[j] = (distancias[u]+ g[u][j])  * 100;

            }

        }




    }
for( i = 0 ; i < n; i ++){
    printf("%f|", pai[i]);
    printf("%f|",probabilidade[i]);
}
printf("\nA distancia de %d ate %d é: %f", vi,vf,distancias[vf]);

}


int main(){

    dijkstra(grafo,0,4);

return 0;
}
