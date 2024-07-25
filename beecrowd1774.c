#include <stdio.h>
#define INF 312312
int main(){



    int qtdRoteadores, qtdCabos, rot1,rot2, tamCabo,soma;


         scanf("%d",&qtdRoteadores);


         scanf("%d",&qtdCabos);

    int visitados[qtdRoteadores], distancias[qtdRoteadores];
    int g[qtdRoteadores][qtdRoteadores];






    int i,j;
        for( i = 0 ; i < qtdRoteadores ; i ++ ){
            for( j = 0 ; j < qtdRoteadores ; j ++){

               g [j][i] = g[i][j] = INF;

            }

        }








        for( i = 0 ; i < qtdCabos; i++){


            scanf("%d",&rot1);


            scanf("%d",&rot2);


            scanf("%d",&tamCabo);

            rot1--;
            rot2--;

            g[rot1][rot2] = g[rot2][rot1] = tamCabo;


        }



    for ( i = 0 ; i < qtdRoteadores ; i ++ ){

        visitados[i] =0;
        distancias[i] = INF;

    }
    distancias[0] = 0 ;

    for ( i = 0 ; i < qtdRoteadores ; i ++ ){

        int menor = INF, u;

        for( j = 0 ; j < qtdRoteadores ; j ++){
            if( visitados[j] == 0 && distancias[j] < menor){
               menor = distancias[j] ; u = j;
               }
        }
        visitados[u] = 1 ;

        for ( j = 0; j < qtdRoteadores ; j++){

            if( visitados[j] == 0 && g[u][j] < distancias[j] ){
                distancias[j] = g[u][j] ;
            }

        }

    }


        soma = 0;

        for( i = 0 ; i < qtdRoteadores ; i++) {
            if(distancias[i] != INF){
            soma += distancias[i];
            }
        }


    printf("%d\n",soma);

return 0;
}
