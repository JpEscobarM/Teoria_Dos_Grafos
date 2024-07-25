#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main()
{

    FILE *file = fopen("grafo.txt","r");
    int vert,arest, grauTotal=0, grauAux;
    int aresta1,aresta2;
    int flag = 0, flagCaminho=0, caminhoInvalido = 0;

    if(file)
    {
        fscanf(file,"%d%d",&vert,&arest);

        int m[vert][vert];
        int visit[vert];
        int pai[vert];

        for(int i = 0 ; i < vert ; i ++)
        {
            visit[i] = 0;
        }

        for(int i = 0 ; i < vert ; i ++)
        {
            pai[i] = -2;
        }

        for(int i = 0 ; i < vert ; i ++ )
        {
            for( int j = 0 ; j< vert ; j ++)
            {
                m[i][j] = 0;
            }
        }

        for(int i = 0 ; i < arest ; i++)
        {

            fscanf(file,"%d%d",&aresta1,&aresta2);
            m[aresta1][aresta2] = m[aresta2][aresta1] = 1;
            grauTotal+=2;
        }


        int testes = 0;
        int orig,dest;
        int tamCaminho,fimCiclo,origCiclo,i,j;

        fscanf(file,"%d", &testes);
        printf("Tamanho de testes: %d\n",testes);

        int numTestes;

        for( numTestes = 0 ; numTestes < testes ; numTestes++)
        {

            fscanf(file,"%d",&tamCaminho);
            printf("\t---TESTE NUMERO: %d---\n",(numTestes+1));
            printf("%d ", tamCaminho);

            for(int i = 0; i < vert ; i++)
            {
                visit[i] =0 ;

            }

            for(i = 0; i < vert ; i++)
            {
                pai[i] =-2 ;

            }




            //Pega vertice inicial do ciclo
            fscanf(file,"%d", &orig);
            printf("%d ", orig);
            pai[orig] = -1;
            visit[orig] = 1;
            grauAux = grauTotal;
            origCiclo = orig;

            for( j = 1 ; j < tamCaminho ; j++)
            {

                fscanf(file,"%d", &dest);
                printf("%d ", dest);


                //Verifica se existe caminho na matriz
                if(m[orig][dest] == 1)
                {
                    flagCaminho =1;
                    grauAux-=2;
                }
                else
                {
                    flagCaminho = 0;
                }


               //Verifica se o pai é diferente do anterior.
                if( pai[dest] != -2 )
                {
                    if( pai[dest] != orig)
                    {
                        flag = 1;
                    }
                }
                else
                {
                    flag = 0;
                }

                if(flag == 1)
                {

                    visit[dest] -=1;
                }
                pai[dest] = orig;

                visit[dest] += 1;


                orig = dest;

                if(flagCaminho == 0)
                {
                    caminhoInvalido = 1;
                }

            }
            fimCiclo = dest;


           if(caminhoInvalido == 1)
            {

                 printf("//Caminho Invalido\n");
            }
            else
            {
                int somaVisit = 0;
                for( i = 0; i < vert ; i++)
                {
                    somaVisit+= visit[i];
                }

                if(grauAux < 0 && origCiclo == fimCiclo)
                {

                  printf("//Caminho valido mas nao euleriano\n");

                }
                else if( somaVisit == vert && origCiclo == fimCiclo)
                {

                  printf("//Ciclo Euleriano\n");
                }

                else if(somaVisit == vert && origCiclo != fimCiclo)
                {

                   printf("//Caminho euleriano, mas nao e um ciclo\n");
                }


                somaVisit = 0 ;

            }

        }//for de testes de caminho

    }

    else
    {
        printf("Erro ao abrir arquivo.");
    }
    fclose(file);

    return 0;
}





