#include <stdio.h>
#include <stdlib.h>

int qtdVertices, qtdArestas;

void dfs(int v, int nivel, int vnivel[], int grafo[][qtdVertices])
{
vnivel[v]=nivel;
int i;
for (i=0;i<qtdVertices;i++)
   {
   if (grafo[v][i]==1 && vnivel[i]==-1)
      {
      grafo[v][i]=2;
      grafo[i][v]=0;
      dfs(i,nivel+1,vnivel,grafo);
      }
   }
}

int lowpoint(int v, int low[],int vnivel[],int grafo[][qtdVertices]){

        if( low[v]!= -1){return low[v]; };


        low[v] = v;

        int i;

        for( i  = 0 ; i < qtdVertices ; i ++){

            if( grafo[v][i] == 2 && vnivel[lowpoint(i,low,vnivel,grafo)] < vnivel[low[v]]){
                low[v] = low[i] ;
            }
            else{

                if( grafo[v][i] ==1 && vnivel[i] < vnivel[low[v]]){
                    low[v] = i;

                }

            }

        }
        return low[v];
}

int main(){

    FILE *arquivo = fopen("arquivo.txt","r");


    if(arquivo){

        //le a quantidade de grafos no arquivo
        int qtdGrafos = 0, i , j ,k, orig=0, dest=0;
        fscanf(arquivo,"%d",&qtdGrafos);


        for(k = 0 ; k < qtdGrafos; k ++){

            fscanf(arquivo,"%d%d",&qtdVertices,&qtdArestas);
            qtdVertices++;


            int grafo[qtdVertices][qtdVertices];

            for(i=0; i<qtdVertices; i++){
                for(j=0; j<qtdVertices; j ++){
                    grafo[i][j] =0;
                }
            }
            for(i=0; i < qtdArestas; i++){

                fscanf(arquivo,"%d%d",&orig,&dest);
                grafo[dest][orig]=grafo[orig][dest] = 1;

            }

            int vnivel[qtdVertices], low[qtdVertices];

            for(i=0; i < qtdVertices;i++){
                vnivel[i] =-1; low[i] = -1;
            }

            dfs(1,0,&vnivel,&grafo);

             for(i=0; i < qtdVertices; i ++){
                for(j=0; j < qtdVertices; j ++){

                    if(grafo[i][j]==1 && vnivel[i]<vnivel[j]){
                        grafo[i][j] = 0;
                    }

                }
             }
            lowpoint(1,low,vnivel,grafo);

             for(i=0; i<qtdVertices; i++){
                for(j=0; j<qtdVertices; j ++){
                    printf("%d", grafo[i][j]);
                }
                printf("\n");
            }
                printf("\n");



            int articulacoes[qtdVertices],demarcadores[qtdVertices];

            for(i=0;i<qtdVertices; i++){
               demarcadores[i] = -1;
               articulacoes[i]=0;


            }

            int vRaiz =1, filhosRaiz =0;
            for(i=1;i<qtdVertices;i++){
               if( grafo[vRaiz][i] == 2){
                filhosRaiz++;
                if(filhosRaiz > 2 ){
                    articulacoes[vRaiz] = vRaiz;
                }
                }
            }


            for(i=0; i < qtdVertices; i ++){
                for( j =0 ; j < qtdVertices ;j ++){

                    if(grafo[i][j] == 2 ){
                        if( low[j] == i || low[j] == j){
                            demarcadores[i] = j;
                            if(i!=vRaiz){
                                articulacoes[i] = i;
                            }
                        }


                    }
                }
            }
            printf("LowPoint's: ");
            for(i=1;i<qtdVertices; i++){
                printf("%d:%d ", i,low[i]);
            }
             int tem=0;
            printf("\npontes: ");
             for(i=0; i < qtdVertices; i ++){
                for( j =0 ; j < qtdVertices ;j ++){

                    if(grafo[i][j] == 2 ){
                        if( low[j] == j){
                        tem =1;
                        printf("%d,%d ",i,j);

                        }
                    }
                }
            }
            if(!tem){
                printf("nenhuma\n");
            }

           tem=0;
            printf("\narticulacoes: ");
            for(i=0; i < qtdVertices; i ++){
                 if(articulacoes[i] != 0){
                    tem = 1;
                    printf("%d ", articulacoes[i]);
                 }
            }
            if(!tem ){
                printf("nenhuma\n");
            }

            tem = 0;

            printf("\ndemarcadores: ");
            for(i=0; i < qtdVertices; i ++){
                    if(demarcadores[i] != -1){
                        tem =1;
                        printf("%d ",demarcadores[i]);

                    }
            }
            if(!tem){
                printf("nenhum\n");
            }


            printf("\nComponentes biconexas: ");

            for(i=0; i < qtdVertices; i ++)
                printf("%d",demarcadores[i]);

            int k,artic;
            for(k = qtdVertices ; k > 0 ;k--){
                if(demarcadores[k]!= -1){

                    for(i=0; i < qtdVertices; i ++){
                        for(j=0; j<qtdVertices; j++){

                            if( j == demarcadores[k]) {
                                artic = i;
                                printf("%d", artic);
                              if( grafo[i][j] == 2 ){



                              }

                            }
                        }
                    }


                        }
                printf("%d\n", demarcadores[k]);
                 demarcadores[k]=0;

                }




        }//PERCORRENDO GRAFO
    fclose(arquivo);
    }//ABERTURA DO ARQUIVO
    else{
        printf("não foi possivel realizar a abertura do arquivo.");
    }

return 0;
}
