typedef struct node {
    int dado; 
    struct node * next; 
}Lista;

Lista* cria_Lista(){
    Lista* inicio = (Lista*) malloc(sizeof(Lista));
    if(inicio != NULL)
        *inicio = NULL;
    return inicio;
}

int insere_lista(Lista* inicio, int val){
    if(inicio == NULL)
        return 0;
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    if(novo == NULL)
        return 0;
    novo->dado = val;
    novo->next = NULL;
    if((*inicio) == NULL){//iniciosta vazia: insere início
        *inicio = novo;
    }else{
        Lista *aux = *inicio;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = novo;
    }
    return 1;
}


int Busca_lista(Lista* inicio, int val){
    if(inicio == NULL)
        return 0;
    Lista *novo = *inicio;
    while(novo != NULL && novo->dado != val){
        novo = novo->next;
    }
    if(novo == NULL)
        return 0; // NÃO ENCONTROU
    else{
        return novo->dado; // ENCONTROU
    }
}

int Remove_Elemento_Lista(Lista* inicio, int val){
    if(inicio == NULL)
        return 0;
    if((*inicio) == NULL)//lista vazia
        return 0;
    Lista *ant = *inicio; 
    Lista *atual = *inicio;
    while(atual != NULL && atual->dado != val){
        ant = atual;
        atual = atual->next;
    }
    if(atual == NULL)//não encontrado
        return 0;

    if(atual == *inicio)//remover o primeiro?
        *inicio = atual->next;
    else
        ant->next = atual->next;
    free(atual);
    return 1;
}