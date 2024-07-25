#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 5
int visit[N] ={0};
int m[N][N] = {{0,1,0,1,0},
               {0,0,1,0,0},
               {0,1,0,0,0},
               {0,0,0,0,0},
               {0,0,0,0,0},
               {0,0,0,0,0}};

void dfs(int v){
    int i;
    printf("%d",v);
    visit[v] =1;
    for (i = 0 ; i < N ; i++){

        if( m[v][i] == 1 && visit[i] == 0){

            dfs(i);
        }

    }




}

int main(){

    dfs(0);

return 0;
}


