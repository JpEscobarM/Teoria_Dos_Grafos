#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 3
int pai[tam] ={0};
int visit[tam] = {0}

int g[tam][tam]={ {0,0,0},
                  {0,0,0},
                  {0,0,0},}


void dfsComPai(int v){
    visit[v] += 1;
    for( int i = 0 ; i < tam; i++){
        if( g[v][i] == 1 && visit[i] == 0 ){
            pai[i] = v;
            dfsComPai(i);
        }

    }


}



int main(){


return 0;
}
