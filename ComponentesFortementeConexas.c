#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 10
//      1 2 3 4 5 6 7 8 9 10 11
int g[n][n]= {{0,1,0,0,0,0,1,0,0,0,0}, //1 //GRAFO ORIGINAL
    {0,0,1,0,0,0,0,0,0,0,0},//2
    {0,0,0,1,0,1,0,0,0,0,0},//3
    {0,0,1,0,1,0,0,0,0,0,0},//4
    {0,0,0,0,0,1,0,0,1,0,0},//5
    {0,0,0,0,0,0,0,0,0,0,0},//6
    {0,0,0,0,0,1,0,0,0,0,1},//7
    {0,0,0,0,0,0,1,0,0,1,1},//8
    {0,0,0,0,0,1,0,1,0,0,0},//9
    {0,0,0,0,1,0,0,0,1,0,0},//10
    {0,0,0,0,0,0,1,0,0,0,0},
};//11

/*            A B C D E F G H I J
int g[n][n]= {{0,0,0,0,0,0,0,0,0,0}, //A
              {0,0,0,0,0,0,0,0,0,0},//B
              {0,0,0,0,0,0,0,0,0,0},//C
              {0,0,0,0,0,0,0,0,0,0},//D
              {0,0,0,0,0,0,0,0,0,0},//E
              {0,0,0,0,0,0,0,0,0,0},//F
              {0,0,0,0,0,0,0,0,0,0},//G
              {0,0,0,0,0,0,0,0,0,0},//H
              {0,0,0,0,0,0,0,0,0,0},//I
              {0,0,0,0,0,0,0,0,0,0},//J
};//11
*/


int posnum[n] = {0};
int visitado[n]= {0};
int nump=0;
int countCFC=0;

void printMatriz(int g[n][n])
{

    int i,j;
    for( i = 0 ; i < n ; i ++)
    {
        printf("\n");
        for( j =0; j < n ; j ++)
        {
            printf("%d", g[i][j]);
        }
    }
    printf("%\n");

}

void dfsModificado( int vi)
{

    visitado[vi] = 1;
    for( int i = 0 ; i < n ; i++)
    {

        if( g[vi][i] == 1 && visitado[i] == 0 )
        {
            dfsModificado(i);
        }
    }
    nump++;
    posnum[vi] = nump;



}


void dfs(int v, int grafo[n][n])
{

    int i;
    visitado[v] = 1;

    for( i = 0 ; i < n ; i ++ )
    {
        if(grafo[v][i] == 1 && visitado[i] == 0 )
        {

            dfs(i,grafo);
        }

    }
}


void componentesFortementeConexas(int grafo[n][n])
{

    int i,j ;



    int vert=0;
    int flag = 1;

    for( i = 0 ; i < n ; i ++)
    {
        visitado[i] = 0;
    }


    while(flag)
    {

    int maior = 0;
    for(i = 0 ; i < n ; i ++)
        {
            if( posnum[i] > maior && visitado[i] == 0)//PEGA O MAIOR
            {
                maior = posnum[i];
                vert = i;
            }
        }


       dfs(vert,grafo);

        countCFC++;
       //CONTAGEM DE COMPONENTES

        for( i = 0 ; i < n ; i ++)
        {
            flag = 0 ;
            if(visitado[i] == 0 )
            {
                flag =1; //SE AINDA EXISTIR VERTICE NAO VISITADO

            }
        }

    }

countCFC--;
}

int main()
{

    printMatriz(g);
  //  dfsModificado(0);
    int gInverso[n][n];

    int i,j;

    for( i = 0 ; i< n ; i ++)
    {
        for(j =0 ; j < n ; j++)
        {

            gInverso[j][i] = 0;


        }
    }
    for( i = 0 ; i< n ; i ++)
    {
        for(j =0 ; j < n ; j++)
        {

            if(g[i][j] == 1)
            {

                gInverso[j][i] = 1;


            }

        }
    }

    printf("\n");
    dfsModificado(0);
    for(i = 0 ; i < n ; i ++)
    printf("Vertice: %d posição pós ordem: %d\n", i, posnum[i]);
  //  componentesFortementeConexas(gInverso);

   // printf("%d", countCFC);

    return 0;
}
