

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define inf 999
int main(){

    FILE *arquivo = fopen("entrada.txt","r+");
    int numVert, numArest, i ,j;

    if(arquivo){

        fscanf(arquivo,"%d%d",&numVert,&numArest);
       // printf("%d%d",numVert,numArest);
        numVert++;
        int grafo[numVert][numVert],pai[numVert], distancia[numVert], visit[numVert];
        int orig,dest,peso;
        for(i = 0 ; i < numVert ; i ++){
            for( j = 0 ; j < numVert ; j ++ ){
                grafo[i][j] = inf;
            }
        }

        for(i =0 ; i < numArest; i ++){

                fscanf(arquivo,"%d%d%d",&orig,&dest,&peso);

                grafo[orig][dest] = peso;
               // printf("%d %d %d\n", orig, dest, peso);





        }
        int caminhos,k;

        fscanf(arquivo,"%d",&caminhos);

        for ( i = 0 ; i < numVert; i ++){
            distancia[i] = inf;
        }

        for( k = 0 ; k < caminhos; k++){
            int cicloNegativo = 0 ;
            fscanf(arquivo,"%d",&orig);
            fscanf(arquivo,"%d",&dest);
            distancia[orig] = 0 ;

            pai[orig] = NULL;

            for( i =0 ; i < numVert; i ++){

                for(j = 0 ; j < numVert ; j++){

                if( grafo[i][j] != inf ){

                    if(distancia[j]> distancia[i] + grafo[i][j]){

                        distancia[j] = distancia[i] + grafo[i][j];
                        pai[j] = i;
                    }

                    }

                }

            }

            for ( i = 0 ; i< numVert ; i ++){
                for( j = 0 ; j < numVert; j ++){

                if ( grafo[i][j] != inf){

                    if( distancia[j] > distancia[i] + grafo[i][j]){
                        cicloNegativo =1;
                    }

                }
                }
            }

        if(cicloNegativo){
            printf("\nO Grafo possui ciclo de custo negativo.", orig,dest);
        }
        else{
            printf("\nA distancia do vertice %d ao vertice %d e: %d",orig, dest, distancia[dest]);
        }


        }


    }
    else{
        printf("Erro ao abrir arquivo");
    }

return 0;
}
