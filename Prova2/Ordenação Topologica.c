#include <stdio.h>
#include <stdlib.h>
#define n 10

int g[n][n]= {{0,1,0,0,0,0,0,0,0,0}, //A
              {0,0,1,0,0,0,0,0,0,0},//B
              {0,0,0,0,1,0,0,0,0,0},//C
              {0,0,0,0,0,1,0,0,0,0},//D
              {0,0,0,0,0,0,1,0,1,0},//E
              {0,0,0,0,1,0,0,0,0,0},//F
              {0,0,0,0,0,0,0,0,0,0},//G
              {0,0,0,0,0,0,0,1,0,0},//H
              {0,0,0,0,0,0,0,0,1,0},//I
              {0,0,0,0,0,0,0,0,1,0},//J
};//11


void ordenacaoTopologica( int g[n][n]){
    int i,j;
    int grau[n];
    int lista[n];
    int listaIndex = 0;
    memset(grau,0,sizeof(grau));

    for(i = 0 ; i < n ;  i++){ // calcula os graus de entrada
        for(j=0; j < n ; j ++){
            if(g[i][j] == 1){
                grau[j]++;
            }
        }
    }


    for( i = 0 ; i < n ; i ++){
        if(grau[i] == 0){
            lista[listaIndex++] = i;
        }
    }
    int Head = 0 ;
    while(Head < listaIndex){

        int v = lista[Head];
        printf("%d ", v);

        for(int i = 0 ; i < n ; i ++){
            if( g[v][i] == 1){
                grau[i]--;
                if(grau[i] == 0 ){
                    lista[listaIndex++] = i;
                }
            }
        }



    Head++;
    }

printf("\n");
}


int main(){


        ordenacaoTopologica(g);


return 0;
}
