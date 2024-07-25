#include <stdio.h.
#include <string.h>
#include <stdlib.h>
#define tam 5
int grafo[tam][tam]={ {0,1,0,0,1},
                      {1,0,1,0,0},
                      {0,1,0,1,0},
                      {0,0,1,0,1},
                      {1,0,0,1,0},};



int verificaGrau(g[tam][tam]){

    int i,Grau[tam];
    for( i = 0 ; i < tam, i++){

        Grau[i] =  0;
        for( int j =0 ; j < tam ; j ++){
            Grau [i] += g[i][j];
            if(Grau[i]%2 != 0 ){
                return 0;
            }

        }

    }

    return 1;
}

int main(){

   printf("%d ", verificaGrau (grafo));

return 0;
}
