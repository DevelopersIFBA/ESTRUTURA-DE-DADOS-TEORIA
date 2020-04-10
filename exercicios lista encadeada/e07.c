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

void comparaListasIterativa(No *inicio1, No *inicio2){
    No *aux1 = NULL, *aux2 = NULL;

    aux1 = inicio1->prox;
    aux2 = inicio2->prox;

    if(aux1 == NULL && aux2 == NULL)
        printf("Listas vazias e iguais\n");
    else
        while (aux1 != NULL && aux2 != NULL){
            if(aux1->valor == aux2->valor){
                aux1 = aux1->prox;
                aux2 = aux2->prox;
            }else break;
        }

    aux1 == aux2 ? printf("Listas iguais\n") : printf("Listas diferentes em : l1(%d) e l2(%d)\n",aux1->valor, aux2->valor);

}

// No caso dessa comparação recursiva estou precisando subentender que se as listas são vazias, elas são iguais
void comparaListasRecursiva(No *l1, No *l2){
    if(l1 == NULL || l2 == NULL)
        printf("Listas iguais\n"); 
    else if(l1->valor != l2->valor){
        printf("Listas diferentes em: l1(%d) e l2(%d)\n",l1->valor, l2->valor);
        exit(0);
    }else
        comparaListasRecursiva(l1->prox, l2->prox);
}

int main(){
    No *inicio = (No*) malloc(sizeof(No*));
    No *inicio2 = (No*) malloc(sizeof(No*));

    No *aux = NULL, *aux2 = NULL; // só para nao passar o inicio e por acaso a funcao recursiva mudar 

    int  i;

    for(i=0;i<10;i++)
        inicio = inserirLista(inicio, (i*i*i));

    for(i=0;i<10;i++)
        inicio2 = inserirLista(inicio2, (i*i*i));

    aux = inicio->prox;
    aux2 = inicio2->prox;

    comparaListasIterativa(inicio, inicio2);
    comparaListasRecursiva(aux, aux2);

    limpar(inicio);
    limpar(inicio2);
return 0;
}