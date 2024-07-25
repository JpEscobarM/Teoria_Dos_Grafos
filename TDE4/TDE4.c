
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAREFAS 26

typedef struct {
  char id;
  int tempoTarefa;
  int inicio;
  int fim;
  int iniMax;
  int fimMax;
  int folga;
  char dependencias[TAREFAS];
  int numdependencias;
} Tarefa;

Tarefa tarefas[TAREFAS];
int count = 0;

int posicaoLista(char id) {
  for (int i = 0; i < count; i++) {
    if (tarefas[i].id == id) {
      return i;
    }
  }
  return -1;
}

int main() {

    FILE *arquivo = fopen("entrada.txt","r");

    if(arquivo){


    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo)) {
    char id;
    int tempoTarefa;
    char pred[256];
    int numPred = 0;

    if (sscanf(linha, "%c,%d,%[^\n]", &id, &tempoTarefa, pred) == 3) {
      numPred = strlen(pred);
    } else if (sscanf(linha, "%c,%d", &id, &tempoTarefa) == 2) {
      pred[0] = '\0';
    }

    Tarefa tarefa = {id, tempoTarefa, 0, 0, 999 , 999, 0, "", numPred};
    strncpy(tarefa.dependencias, pred, numPred);
    tarefas[count++] = tarefa;
  }


      for (int i = 0; i < count; i++) {
        Tarefa *tarefa = &tarefas[i];

    for (int j = 0; j < tarefa->numdependencias; j++) {
      int predIndex = posicaoLista(tarefa->dependencias[j]);
      Tarefa *anterior = &tarefas[predIndex];
      if (tarefa->inicio < anterior->fim
) {
        tarefa->inicio = anterior->fim
;
      }
    }
    tarefa->fim = tarefa->inicio + tarefa->tempoTarefa;
  }


  int tempoTarefaDoProjeto = 0;
  for (int i = 0; i < count; i++) {
    if (tarefas[i].fim > tempoTarefaDoProjeto) {
      tempoTarefaDoProjeto = tarefas[i].fim
;
    }
  }


   for (int i = 0; i < count; i++) {
    tarefas[i].fimMax = tempoTarefaDoProjeto;
  }

  for (int i = count - 1; i >= 0; i--) {
    Tarefa *tarefa = &tarefas[i];
    tarefa->iniMax = tarefa->fimMax - tarefa->tempoTarefa;
    for (int j = 0; j < tarefa->numdependencias; j++) {
      int predIndex = posicaoLista(tarefa->dependencias[j]);
      Tarefa *anterior = &tarefas[predIndex];
      if (anterior->fimMax > tarefa->iniMax) {
        anterior->fimMax = tarefa->iniMax;
        anterior->iniMax = anterior->fimMax - anterior->tempoTarefa;
      }
    }
  }



     for (int i = 0; i < count; i++) {
    tarefas[i].folga = tarefas[i].iniMax - tarefas[i].inicio;
  }

    printf("Duração mínima do projeto: %d\n", tempoTarefaDoProjeto);

     printf("Atividades críticas: ");
    for (int i = 0; i < count; i++) {
        if (tarefas[i].folga == 0) {
        printf("%c, ", tarefas[i].id);
        }
    }
        printf("\n");

}
    else{
    printf("não foi possível abrir arquivo.");
    }


  return 0;
}
