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

void ehCrescente(No *inicio){
    No *aux = NULL;

    aux = inicio->prox;

    if(aux == NULL)
        printf("Lista vazia\n");
    else
        while (aux->prox->valor > aux->valor && aux != NULL)
            aux = aux->prox;
        
    if(aux->prox == NULL)
        printf("Lista crescente!\n");
    else printf("Lista nao crescente\n");
}

int main(){
    No *inicio = (No*) malloc(sizeof(No*));
    int  i;

    for(i=0;i<10;i++)
        inicio = inserirLista(inicio, (i*i*i));

    inicio = inserirLista(inicio, 21);

    ehCrescente(inicio);

    limpar(inicio);
return 0;
}