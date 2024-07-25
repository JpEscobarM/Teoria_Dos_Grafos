#include <stdio.h>
#include <stdlib.h>
#define n 5

int G[n][n]={{0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},};

int H[n][n]={{1,1,1,1,1},
            {1,1,1,1,1},
            {1,1,1,1,1},
            {1,1,1,1,1},
            {1,1,1,1,1}, };


int verificaComplemento(int g1[n][n], int g2[n][n]){

    int i, j;

    for ( i = 0 ; i  < n ; i ++){
        for(j = 0 ; j < n ; j ++){

            if( (g1[i][j] != 0 && g2[i][j] == 0) || (g1[i][j] == 0 && g2[i][j] != 0) ){

            }
            else{
                return 0;
            }


        }
    }


return 1;
}
int main(){
    int v;
   v =  verificaComplemento(H,G);
    printf("%d",v );
return 0;
}
