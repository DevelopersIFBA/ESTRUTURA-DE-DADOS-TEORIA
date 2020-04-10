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

No *buscarMedio(No *inicio){
    No *aux = NULL, *aux2 = NULL, *atual = NULL;
    aux = inicio->prox;
    aux2 = inicio->prox;
    int it = 0;

    if(aux== NULL)
        return NULL;
    else
        while (aux!=NULL){
            it++;
            if(it == 2){
                atual = aux2;
                aux2 = aux2->prox;
                it = 0;
            }
            aux = aux->prox;
        }
    
    return atual;
}

int main(){
    No *inicio = (No*) malloc(sizeof(No*));
    No *aux = NULL; // só para nao passar o inicio e por acaso a funcao recursiva mudar 

    int  i;

    for(i=0;i<11;i++)
        inicio = inserirLista(inicio, (i*i*i));

    
    aux = buscarMedio(inicio);

    printf("Ponto médio: %d\n", aux->valor);

    limpar(inicio);
return 0;
}