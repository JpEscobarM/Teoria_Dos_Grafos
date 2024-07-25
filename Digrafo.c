#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 10

int count = 0 ;

typedef struct{

    int matriz[TAM][TAM];
    int arestas;

}Grafo;

void inicializa( Grafo *g  ){

    int i, j ;

    for(i  =0  ; i < TAM ; i ++ ){
        for( j = 0 ; j < TAM ; j ++){

            g->matriz[i][j] =  0 ;

        }

    }

    g->arestas = 0 ;

}
// ALCANCE -------------------------------
int visit[TAM];

void explorar(Grafo g, int v){
    int j;
    visit[v] = 1 ;
    for( j  = 0 ; j < TAM ; j++ ){
            if (g.matriz[v][j] == 1 && visit [j] != 1 ){
                explorar (g , j);
            }

    }
}


int alcanceGrafo(Grafo g, int origem, int destino){
    int i;
    for( i = 0 ; i < TAM ; i ++ ){

        visit[i] = 0;

    }
    explorar(g, origem);
    for(i = 0 ; i < TAM ; i ++){
        printf("%d |", visit[i]);
    }

    if ( visit [ destino ] == 1 ){
        return 1;
    }
    else{
        return 0;
    }
}
// ALCANCE -------------------------------



// BUSCA EM LARGURA / Breadth-first search ------
void explorarBfs(Grafo g, int v){


}



int visit2[TAM];

int breadthFirsSearch(Grafo g, int origem){

    int j;

    count = 0 ;
    for( j  = 0 ; j < TAM ; j ++ ){
        visit2[j] = 0 ;
    }
    explorarBfs(g , origem);
    for( j = 0 ; j < TAM ; j ++){
        printf ( "%d |", visit2[j]);
    }
    printf("\n");
}



// BUSCA EM LARGURA / Breadth-first search ------




//BUSCA EM PROFUNDIDADE / Depth-first search -----------

void explorarDfs(Grafo g , int v){
    int i,j;
    printf("%d - >" , v);
    visit[v] = ++count;
    for ( j = 0 ; j < TAM ; j ++ ){
        if ( g.matriz[v][j] == 1 && visit[j] == 0  ){
            explorarDfs(g, j );
        }
    }

}



void buscaProfundidade(Grafo g, int origem){

int i , j ;

    for( i =0 ; i < TAM ; i ++){
        visit[i] = 0;
    }
    explorarDfs(g ,origem);
    printf("\n");
        for( j = 0 ;  j < TAM ; j ++){
        printf("%d |", visit[j]);
    }
    printf("\n");
}


//BUSCA EM PROFUNDIDADE -----------


void addAresta(Grafo *g , int linha , int coluna){

    g->matriz[linha][coluna] = 1 ;

    g->arestas++;

}

void removeAresta(Grafo *g , int linha , int coluna){

    g->matriz[linha][coluna] = 0;
    g->arestas--;

}

void printfGrafo(Grafo *g){

    int i , j ;
    printf("\n   ");
    for( i  = 0 ; i < TAM ; i ++ ){
        printf("%3d" , i );
    }
    printf("\n");
    for( i = 0 ; i < TAM ; i ++ ){
            printf("%3d", i );
       for ( j = 0 ; j < TAM ; j++ ){
            printf("%3d", g->matriz[i][j]);
       }
       printf("\n");
    }

}

int menu(){
    int op;

    printf("\n1 - ADICIONAR ARESTA");
    printf("\n2 - REMOVER ARESTA");
    printf("\n3 - ALCANCE");
    printf("\n4 - DFS");
    printf("\n0 - SAIR\n");
    scanf("%d", &op );
    return op;
}



int main(){

    Grafo g1;
    int linha, coluna ;
    int op;
    inicializa(&g1);

    while( op != 0){
        printfGrafo(&g1);
        op = menu();
        switch(op){
        case 1:printf("digite a LINHA e COLUNA que deseja adicionar a aresta ");
               printf("\nLinha: "); scanf("%d",&linha);
               printf("\nColuna: "); scanf("%d",&coluna);
               addAresta(&g1, linha , coluna);
        break;
        case 2:printf("digite a LINHA e COLUNA que deseja remover a aresta ");
               printf("\nLinha: "); scanf("%d",&linha);
               printf("\nColuna: "); scanf("%d",&coluna);
               removeAresta(&g1, linha , coluna);
        break;
        case 3:printf("digite a LINHA e COLUNA que deseja verificaro alcance ");
               printf("\nOrigem: "); scanf("%d",&linha);
               printf("\nDestino: "); scanf("%d",&coluna);
              if(  alcanceGrafo(g1, linha , coluna) == 1){
                printf("\nPossui alcance do vertice %d para  o vertice %d",linha , coluna);

              }
              else{
                printf("nao possui alcance");
              }
        break;
        case 4:printf("Vertice de origem:  ");
               printf("\nOrigem: "); scanf("%d",&linha);
               buscaProfundidade(g1, linha);
        break;
        case 0: printf("saindo...");
                op = 0 ;
        break;
        default: printf("opção invalida!");
        break;
        }


    }


return 0;
}
