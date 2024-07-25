#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char **nomes;

int pronome(char **nomes, char nome[100]){
    int i,j;
    for(i = 0 ; i < 5 ; i++){

        if( strcmp(nomes[i] ,nome) == 0  ){
            printf("Ja contem esse nome");
            break;

        }
        }
    for( j = 0; j<5 ; j ++ ){
    if ( strcmp(nomes[j] ,"\0") == 0 ){
        return j;
    }

            }
}





int menu(){
    int op = 0;
    printf("\n\t--MENU--\n");
    printf("[1] - adicionar nome\n");

    scanf("%d", &op);
    fgetc(stdin);
    return op;
}

int main(){


    nomes = malloc( 5* sizeof(char*));

    for(int i = 0 ; i < 5 ; i ++){

        nomes[i] = malloc( 100* sizeof(char));
        strcpy(nomes[i] ,"\0");
    }

     char *nome;
    nome = malloc( 100* sizeof(char));

    int op = 1 ;
    while( op != 0){

        op = menu();

        switch(op){

    case 1:     printf("digite o nome que deseja adicionar a rede: ");

                fgets(nome, 100, stdin);
                int pos = 0;

                pos = pronome(nomes,nome);

                if( pos != 0){
                strcpy(nome,nomes[pos];
                }

    break;



    default:    printf("opcao invalida, tente novamente!\n\n\n");

    break;
        }

    }




return 0;
}
