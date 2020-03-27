#include <stdio.h>
#include <stdlib.h>
#define LISTA_NAO_EXISTE -1
#define ERRO_AO_ALOCAR -2
#define SUCESSO -3
#define LISTA_VAZIA -4
#define NAO_ENCONTRADO -5


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
int insere_lista_inicio(Lista* inicio, Aluno alunos);
int insere_lista_ordenada(Lista* inicio, Aluno alunos);
Aluno pesquisa_aluno_por_matricula(Lista* inicio, int matricula);
int remove_lista_por_numero_matricula(Lista* inicio, int matricula);
int remove_lista_inicio(Lista* inicio);
int remove_lista_final(Lista* inicio);
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
    printf("Tamanho: %d\n\n",tamanho_lista(inicio));

    for(i=0; i < 4; i++)
        insere_lista_final(inicio,alunos[i]);

    imprime_lista(inicio);
    printf("\n\n Tamanho: %d\n\n",tamanho_lista(inicio));

    remove_lista_final(inicio);

    imprime_lista(inicio);
    printf("\n\n Tamanho: %d\n\n",tamanho_lista(inicio));

    remove_lista_inicio(inicio);

    imprime_lista(inicio);
    printf("\n\n Tamanho: %d\n\n",tamanho_lista(inicio));

    Aluno aluno = pesquisa_aluno_por_matricula(inicio, 4);
    printf("Matricula: %d\n",aluno.matricula);
    printf("Nome: %s\n",aluno.nome);
    printf("Notas: %.2f %.2f %.2f\n",aluno.n1,
                               aluno.n2,
                               aluno.n3);

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
    return SUCESSO;
}

int insere_lista_inicio(Lista* inicio, Aluno alunos){
    
    if(inicio == NULL)
        return LISTA_NAO_EXISTE;

    Elem* novo;
    novo = (Elem*) malloc(sizeof(Elem));
    if(novo == NULL)
        return ERRO_AO_ALOCAR;

    novo->dados = alunos;
    novo->prox = (*inicio);
    *inicio = novo;

    return SUCESSO;
}

int insere_lista_ordenada(Lista* inicio, Aluno alunos){ // ORDENAR PELO NUMERO DE MATRICULA DOS ALUNOS
    
    if(inicio == NULL)
        return LISTA_NAO_EXISTE;

    Elem *novo = (Elem*) malloc(sizeof(Elem));
    if(novo == NULL)
        return ERRO_AO_ALOCAR;

    novo->dados = alunos;

    if((*inicio) == NULL){ // SE A LISTA ESTIVER VAZIA, INSERE NO INICIO
        novo->prox = NULL;
        *inicio = novo;
        return SUCESSO;
    }
    else{
        Elem *anterior = *inicio;
        Elem *atual = *inicio;

        while(atual != NULL && atual->dados.matricula < alunos.matricula){
            anterior = atual;
            atual = atual->prox;  // atual SAI DO LAÇO SENDO MAIOR Q O ELEMENTO INSERIDO OU SENDO NULL
        }

        if(atual == *inicio){  // SE FOR O PRIMEIRO ELEMENTO QUE FOR O MAIOR
            novo->prox = (*inicio);
            *inicio = novo;
        }
        else{
            novo->prox = atual;
            anterior->prox = novo;
        }
        return SUCESSO;
    }
}

void imprime_lista(Lista* inicio){
    if(inicio == NULL)
        return;
    Elem* aux = *inicio;
    while(aux != NULL){
        printf("Matricula: %d\n",aux->dados.matricula);
        printf("Nome: %s\n",aux->dados.nome);
        printf("Notas: %.2f %.2f %.2f\n",aux->dados.n1,
                                   aux->dados.n2,
                                   aux->dados.n3);
        printf("-------------------------------\n");

        aux = aux->prox;
    }
}

Aluno pesquisa_aluno_por_matricula(Lista* inicio, int matricula){
    
    if(inicio == NULL)
        return (*inicio)->dados;

    Elem *aux = *inicio;

    while(aux != NULL && aux->dados.matricula != matricula){
        aux = aux->prox;
    }

    if(aux == NULL)
        return aux->dados;
    else{
        return aux->dados;
    }
}

int remove_lista_por_numero_matricula(Lista* inicio, int matricula){
    
    if(inicio == NULL)
        return LISTA_NAO_EXISTE;

    if((*inicio) == NULL)
        return LISTA_VAZIA; // NAO TEM NADA PARA EXCLUIR

    Elem *anterior =  *inicio; 
    Elem *atual = *inicio;

    while(atual != NULL && atual->dados.matricula != matricula){
        anterior = atual;
        atual = atual->prox;
    }
    if(atual == NULL) // PERCORREU A LISTA ATE O FIM
        return NAO_ENCONTRADO;

    if(atual == *inicio)  //REMOÇAO PRIMEIRO ELEMENTO
        *inicio = atual->prox;
    else
        anterior->prox = atual->prox;

    free(atual);
    
    return SUCESSO;
}

int remove_lista_inicio(Lista* inicio){
    
    if(inicio == NULL)
        return LISTA_NAO_EXISTE;

    if((*inicio) == NULL)
        return LISTA_VAZIA;

    Elem *aux = *inicio;
    *inicio = aux->prox;

    free(aux);

    return SUCESSO;
}

int remove_lista_final(Lista* inicio){
    
    if(inicio == NULL)
        return LISTA_NAO_EXISTE;

    if((*inicio) == NULL)
        return LISTA_VAZIA;

    Elem *ant = *inicio;
    Elem *atual = *inicio;

    while(atual->prox != NULL){
        ant = atual;
        atual = atual->prox;
    }

    if(atual == (*inicio)) // REMOÇAO PRIMEIRO ELEMENTO
        *inicio = atual->prox;
    else
        ant->prox = atual->prox;

    free(atual);

    return SUCESSO;
}


//#########################################
//        FUNÇÕES AUXILIARES
//#########################################

int tamanho_lista(Lista* inicio){
    int cont = 0;

    if(inicio == NULL)
        return LISTA_NAO_EXISTE;

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








