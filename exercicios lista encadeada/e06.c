#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
} No;


void limpar(No *inicio){
    No *aux = NULL;

    aux = inicio->prox;

    while (aux!=NULL){
        inicio->prox = aux->prox;
        free(aux);
        aux = aux->prox;
    }
}

No *inserirLista(No *inicio, int val){
    No *novo = NULL, *aux = inicio;

    novo = (No*) malloc(sizeof(No*));
    
    if(aux->prox == NULL){
        novo->prox = NULL;
        novo->valor = val;
        inicio->prox = novo;
    }else{
        while (aux->prox != NULL){
            aux = aux->prox;
        }

        novo->prox = NULL;
        novo->valor = val;
        aux->prox = novo;
    }

    printf("%d\n",novo->valor);
    
    return inicio;
}

void buscaMinimoIterativa(No *inicio){
    No *aux = NULL;
    int minimo = 0;

    aux = inicio->prox;
    minimo = aux->valor;

    if(aux == NULL)
        printf("Lista vazia\n");
    else
        while (aux != NULL){
            if(aux->valor < minimo)
                minimo = aux->valor;
            aux = aux->prox;
        }

    printf("Valor mínimo da lista %d\n", minimo);
}

void buscaMinimoRecursiva(No *atual, int minimo){
    if(atual == NULL)
        printf("Valor mínimo da lista %d\n",minimo);
    else{
        if(atual->valor < minimo)
            minimo = atual->valor;
        buscaMinimoRecursiva(atual->prox, minimo);
    }       
}

int main(){
    No *inicio = (No*) malloc(sizeof(No*));
    No *aux = NULL; // só para nao passar o inicio e por acaso a funcao recursiva mudar 

    int  i;

    for(i=0;i<10;i++)
        inicio = inserirLista(inicio, (i*i*i));

    //inicio = inserirLista(inicio, -32);

    aux = inicio->prox;

    buscaMinimoIterativa(inicio);
    buscaMinimoRecursiva(aux, aux->valor);

    limpar(inicio);
return 0;
}