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

        int distancias[tam], pai[tam], cicloNegativo =0;

        for( int i = 0 ; i < tam ; i ++){
            distancias[i]= inf;
            pai[i] = 0;

        }
        pai[0] = -1;
        distancias[0] =0;

        for( int i = 0 ; i < tam ; i ++) {

            for( int j =0; j < tam ; j ++){

                if( grafo[i][j] != inf){

                    if( distancias[j] > distancias [i] + grafo [i][j]){

                        distancias[j] = distancias [i] + grafo[i][j];
                        pai [j] = i;

                    }


                }

            }

        }
        for(int i = 0 ; i < tam ; i ++) {

            for( int j =0; j < tam ; j ++){

                if( grafo[i][j] != inf){

                    if( distancias[j] > distancias [i] + grafo [i][j]){

                        cicloNegativo =1 ;

                    }


                }

            }

        }

        if (cicloNegativo){
            printf("grafo contém ciclo negativo");
        }
        else{
            printf("distancias: \n");
            for(int  i = 0 ; i < tam ; i ++ ){
                printf("|%d", distancias[i]);
            }
            printf("|\n");

            printf("pai: \n");
            for(int  i = 0 ; i < tam ; i ++ ){
                printf("|%d", pai[i]);
            }
            printf("|");
        }


return 0;

}
