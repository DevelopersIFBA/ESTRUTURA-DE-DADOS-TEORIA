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

void alturaLista(No *inicio, int val){
    No *aux = NULL;
    int contAltura = 0, passou = 0;

    aux = inicio;

    if(inicio==NULL)
        printf("Lista vazia\n");
    else
        while (aux != NULL){
            if(aux->valor == val)
                passou = 1;
            
            if(passou == 1)
                contAltura++;

            aux = aux->prox;
        }
            

    if(passou == 0)
        printf("Nao existe essa celula\n");
    else if(contAltura == 1)
        printf("Essa é a última célula da lista\n");
    else
        printf("Altura da celula = %d\n",(contAltura -1));
}

int main(){
    No *inicio = (No*) malloc(sizeof(No*));
    int  i;
    
    for(i=0;i<10;i++)
        inicio = inserirLista(inicio, (i*i*i));

    alturaLista(inicio, 729);

return 0;
}