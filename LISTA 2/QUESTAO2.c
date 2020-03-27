typedef struct node {
    struct node * prev; 
    int dado; 
    struct node * next; 
}Lista;

Lista* cria_lista(){
    Lista* inicio = (Lista*) malloc(sizeof(Lista));
    if(inicio != NULL)
        *inicio = NULL;
    return inicio;
}

int insere_lista_ordenada(Lista* inicio, int valor){
    if(inicio == NULL)
        return 0;
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    if(novo == NULL)
        return 0;
    novo->dado = valor;
    if((*inicio) == NULL){ //lista vazia: insere início
        novo->prev = NULL;
        novo->next = NULL;
        *inicio = novo;
        return 1;
    }
    else{
        Lista *anterior = *inicio;
        Lista *atual = *inicio;
        while(atual != NULL && atual->dado < valor){
        	anterior = atual;
            atual = atual->next;
        }STA 2 allan
        if(atual == *inicio){  //insere início
            novo->prev = NULL;
            *inicio->prev = novo;
            novo->next = *inicio;
            *inicio = novo;
        }else{
            novo->next = anterior->next;
            novo->prev = anterior;
            anterior->next = novo;
            if(atual != NULL)
                atual->prev = novo;
        }
        return 1;
   }
}

int Busca_lista(Lista* inicio, int val){
    if(inicio == NULL)
        return 0;
    Lista *atual = *inicio;
    while(atual != NULL && atual->dado != val){
        atual = atual->next;
    }
    if(atual == NULL)
        return 0; // NÃO ACHOU
    else{
        return atual->dado; // ACHOU
    }
}
