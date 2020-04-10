#include <stdio.h>
#include <stdlib.h>

/** OBS
 *  Para resolver essa questão vou supor que a lista é apenas de inteiros 
 *  e que nenhum numero vai se repetir.
 *  vou usar o valor da posição para definir a tal celular C que a questão informa
 *  Poderia usar a posição da célula para resolver esse problema
 */ 

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

    printf("%d\n",novo->valor);
    
    return inicio;
}

void profundidadeLista(No *inicio, int val){
    No *aux = NULL;
    int contProf = 0;

    aux = inicio->prox;

    if(inicio==NULL)
        printf("Lista vazia\n");
    else
        while (aux->valor != val && aux != NULL){
            contProf++;

            aux = aux->prox;
        }

    if(aux == NULL)
        printf("Nao existe essa celula\n");
    else if(contProf == 0)
        printf("Essa é a primeira célula da lista\n");
    else
        printf("Altura da celula = %d\n",(contProf+1));
}

int main(){
    No *inicio = (No*) malloc(sizeof(No*));
    int  i;
    
    for(i=0;i<10;i++)
        inicio = inserirLista(inicio, (i*i*i));

    profundidadeLista(inicio, 1);

return 0;
}