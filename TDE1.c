
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main()
{
    long int posi;
    FILE *file = fopen("grafo.txt","r+");
    int vert,arest;
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





            fscanf(file,"%d", &orig);
            printf("%d ", orig);
            pai[orig] = -1;
            visit[orig] = 1;

            origCiclo = orig;

            for( j = 1 ; j < tamCaminho ; j++)
            {

                fscanf(file,"%d", &dest);
                printf("%d ", dest);



                if(m[orig][dest] == 1)
                {
                    flagCaminho =1;
                }
                else
                {
                    flagCaminho = 0;
                }

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
                //fputs("//Caminho Invalido\n",file);
                 printf("//Caminho Invalido\n");
            }
            else
            {
                int somaVisit = 0;
                for( i = 0; i < vert ; i++)
                {
                    somaVisit+= visit[i];
                }
                if( somaVisit == vert && origCiclo == fimCiclo)
                {
                  // fputs("//Ciclo Euleriano\n",file);
                  printf("//Ciclo Euleriano\n");
                }
                if(somaVisit > vert && origCiclo == fimCiclo)
                {
                  //  fputs("//Caminho valido mas não euleriano\n",file);
                  printf("//Caminho valido mas não euleriano\n");

                }
                if(somaVisit == vert && origCiclo != fimCiclo)
                {
                  // fputs("//Caminho euleriano, mas não é um ciclo\n",file);
                   printf("//Caminho euleriano, mas não é um ciclo\n");
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


