#include <stdio.h>
#include <stdlib.h>

// Usarei esse setup para a maioria das questões (só atualizar cada função depois) 

typedef struct no{
    int valor;
    struct no *prox;
} No;

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

    return inicio;
}

void contarIterativa(No *inicio){
    No *aux = NULL;
    aux = inicio->prox;
    int cont = 0;

    if(inicio == NULL)
        printf("Lista vazia");
    else{
        while (aux != NULL) {
            cont++;
            aux = aux->prox;
        }

        printf("Tamanho da lista: %d\n",cont);
    }   
}

int contarRecursiva(No *atual, int cont){

    if(atual == NULL)
        return cont;
    else{
        cont++;
        return contarRecursiva(atual->prox, cont);
    }
}

int main(){
    No *inicio = (No*) malloc(sizeof(No*));
    int contRecursiva = 0, i;
    
    for(i=0;i<10;i++)
        inicio = inserirLista(inicio, (i*i*i));


    contarIterativa(inicio);
    contRecursiva =  contarRecursiva(inicio->prox, contRecursiva);
    printf("Tamanho da lista recursiva: %d\n",contRecursiva);

    return 0;
}
