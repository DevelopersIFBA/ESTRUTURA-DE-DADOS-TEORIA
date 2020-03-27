#include <stdio.h>
#include <stdlib.h>
#define LISTA_NAO_EXISTE -1
#define ERRO_AO_ALOCAR -2


//Definição do tipo Aluno
typedef struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
}Aluno;

//Definição do tipo Lista
struct elemento{
    Aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;  // STRUCT P/ ELEMENTOS DA LISTA
typedef struct elemento* Lista;  // STRUCT PONTEIRO PARA O INICIO DA LISTA


//######################################
//           CABEÇALHO FUNÇÕES
//######################################

Lista* cria_lista();
void libera_lista(Lista* inicio);
int insere_lista_final(Lista* inicio, Aluno alunos);
int tamanho_lista(Lista* inicio);
void imprime_lista(Lista* inicio);
//######################################



int main(){
    Aluno alunos[4] = {{2,"Andre",9.5,7.8,8.5},
                 {4,"Ricardo",7.5,8.7,6.8},
                 {1,"Bianca",9.7,6.7,8.4},
                 {3,"Ana",5.7,6.1,7.4}};
    int i;

    Lista* inicio = cria_lista();
    printf("Tamanho: %d\n\n\n\n",tamanho_lista(inicio));

    for(i=0; i < 4; i++)
        insere_lista_final(inicio,alunos[i]);

    imprime_lista(inicio);
    printf("\n\n\n\n Tamanho: %d\n",tamanho_lista(inicio));

    libera_lista(inicio);

    return 0;
}


Lista* cria_lista(){
    Lista* inicio = (Lista*) malloc(sizeof(Lista));
    if(inicio != NULL)
        *inicio = NULL;
    return inicio;
}

int insere_lista_final(Lista* inicio, Aluno alunos){
    
    if(inicio == NULL) 
        return LISTA_NAO_EXISTE;
    
    Elem *novo;
    novo = (Elem*) malloc(sizeof(Elem));

    if(novo == NULL)
        return ERRO_AO_ALOCAR;

    novo->dados = alunos;
    novo->prox = NULL; // O PROXIMO É NULL POIS (*novo) É O ULTIMO ELEMENTO, PORTANTO NÃO TEM PROXIMO

    if((*inicio) == NULL){  // SE (*inicio) É NULL, ENTÃO A LISTA ESTA VAZIA
        *inicio = novo;     // O INICIO PORTANTO, SERÁ O (*novo)
    }
    else{
        Elem *aux;            // CRIA-SE UMA VARIAVEL AUXILIAR, QUE IRA PERCORRER TODA LISTA ATE ACHAR O ULTIMO
        aux = *inicio;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    return 1;
}

void imprime_lista(Lista* inicio){
    if(inicio == NULL)
        return;
    Elem* aux = *inicio;
    while(aux != NULL){
        printf("Matricula: %d\n",aux->dados.matricula);
        printf("Nome: %s\n",aux->dados.nome);
        printf("Notas: %f %f %f\n",aux->dados.n1,
                                   aux->dados.n2,
                                   aux->dados.n3);
        printf("-------------------------------\n");

        aux = aux->prox;
    }
}


//#########################################
//        FUNÇÕES AUXILIARES
//#########################################

int tamanho_lista(Lista* inicio){
    int cont = 0;

    if(inicio == NULL)
        return 0;

    Elem* aux = *inicio;
    
    while(aux != NULL){
        cont++;
        aux = aux->prox;
    }
    return cont;
}

void libera_lista(Lista* inicio){
    if(inicio != NULL){
        Elem* aux;
        while((*inicio) != NULL){
            aux = *inicio;
            *inicio = (*inicio)->prox;
            free(aux);
        }
        free(inicio);
    }
}








