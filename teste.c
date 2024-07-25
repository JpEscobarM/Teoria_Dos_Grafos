#include <stdio.h>
#include <stdlib.h>
#include <string.h>






char **nomes;
int **amizade;

int pronome(char **nomes, char nome[100]){
    int i,j;
    for(i = 0 ; i < 5 ; i++){

        if( strcmp(nomes[i] ,nome) == 0  ){

            return -1;

        }
        }
    for( j = 0; j<5 ; j ++ ){
    if (strcmp(nomes[j] ,"0") == 0  ){
        return j;
    }

            }
}

int menu(){


    int op = 0;
    printf("\n\n=============================");
    printf("\n\t===MENU===\n");
    printf("[1] - RELACIONAR AMIZADE\n");
    scanf("%d", &op);
    fgetc(stdin);
    return op;
}

int main(){

     char teste[50];
  strcpy(teste,"Cleiton Rasta");

    nomes = malloc( 5* sizeof(char*));
    for(int i = 0 ; i < 5 ; i ++){

        nomes[i] = malloc( 100* sizeof(char));
        strcpy(nomes[i] ,"0");
    }

    for(int i = 0 ; i < 5 ; i ++){

        strcpy(nomes[i],teste);
    }

    amizade = malloc (5 * sizeof(int*));
    for(int i = 0 ; i < 5 ; i++ ){
        amizade[i] = malloc(5*sizeof(int));
    }

                printf("NOMES NA REDE: ");
                for( int i ; i< 5 ; i ++){
                    printf("%s", *(nomes+i));
                }

return 0;
}
