#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 5
#define inf 99
int grafo[n][n] = {{inf,7,inf,inf,8},
                   {7,inf,29,inf,inf},
                   {inf,29,inf,14,inf},
                   {inf,inf,14,inf,1},
                   {8,inf,inf,1,inf},};

int visitados[n];
int distancias[n];
int pai[n];

void dijkstra(int g[n][n],int vi ,int vf ) {

    int i, j;
    for( i = 0 ; i < n ; i ++ ){
        distancias[i] = inf;
        visitados[i] =0 ;
        pai[i] = -1;
    }

    distancias[vi] = 0 ;



    for ( i = 0 ; i < n ; i ++){

        int menor = inf , u ;

        for( j = 0 ; j < n ; j ++){

            if( visitados[j] == 0 && distancias[j] < menor){
                menor = distancias [j];
                u = j;
            }

        }
    visitados[u] = 1;


        for( j = 0 ; j < n ; j ++ ){

        if( distancias[j] > distancias[u] + g[u][j]) {
            distancias[j] = distancias[u] + g[u][j];
            pai[j] = u;
                }
        }



    }


    printf("distancias de %d para %d e %d",vi,vf,distancias[vf]);



}

int main(){

    dijkstra(grafo,0,4);

return 0;
}
