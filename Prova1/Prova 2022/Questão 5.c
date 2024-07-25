#include <stdio.h>
#include <stdlib.h>
#define n 5
int visitado[10] = {0};
int m[n][n] =  {{1,1,0,0,0,},
                {1,1,1,0,0,},
                {0,1,0,0,0,},
                {0,0,0,0,1,},
                {0,0,0,1,0,},
                            };

void dfs ( int v ){

    int i;

    visitado[v] = 1;
    for( i =0 ; i < n; i ++){
        if( m [v][i] == 1 && visitado[i] == 0){
            dfs(i);
        }

}
}
int componentesConexas(int m[n][n]){

    int qtdComponentes = 0;
    int vi = 0;
    int i;
    for( i = 0 ; i < n ; i ++){
        if(visitado[i] == 0){
            dfs(i);
            qtdComponentes++;
        }

    }

return qtdComponentes;
}

int main(){

    int qtd = componentesConexas(m);
    printf("%d", qtd);


    return 0;
}
