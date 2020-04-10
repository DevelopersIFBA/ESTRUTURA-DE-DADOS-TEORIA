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

void buscaCrescenteIterativa(No *inicio, int val){
    No *aux = NULL;

    aux = inicio->prox;

    if(aux == NULL)
        printf("Lista vazia\n");
    else
        while (aux->valor < val && aux != NULL)
            aux = aux->prox;
            
        
    if(aux->valor == val)
        printf("Encontrado valor %d!\n", val);
    else printf("Nao encontrado valor %d!\n", val);
}

void buscaCrescenteRecursiva(No *atual, int val){
    if(atual->valor > val || atual == NULL)
        printf("Nao achou %d\n",val);
    else if(atual->valor == val)
        printf("Encontrado %d\n",val);
    else
        buscaCrescenteRecursiva(atual->prox, val);
}

int main(){
    No *inicio = (No*) malloc(sizeof(No*));
    No *aux = NULL; // só para nao passar o inicio e por acaso a funcao recursiva mudar 

    int  i;

    for(i=0;i<10;i++)
        inicio = inserirLista(inicio, (i*i*i));

    aux = inicio->prox;

    buscaCrescenteIterativa(inicio, 8);
    buscaCrescenteRecursiva(aux, 22);

    limpar(inicio);
return 0;
}