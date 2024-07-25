#include <stdio.h>
#include <string.h>
#include <stdlib.h>









int main(){

    int N, E, i, j, orig, dest, h;

    scanf("%d%d",&N&E);

    int g[N][N];

    for( i = 0 ;  i < N ; i ++){
        for ( j = 0 ; j < N ; j++){

            g[i][j] = -1;

        }

    }

    for ( i = 0 ; i < E ; i ++){

        scanf("%d%d%d", &orig, &dest, &h);

    }


return 0;}
