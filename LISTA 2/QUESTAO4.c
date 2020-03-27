int insere_lista_ordenada(Lista* inicio, int val){
    if(inicio == NULL)
        return 0;
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    if(novo == NULL)
        return 0;
    novo->dado = val;
    if((*inicio) == NULL){//lista vazia: insere início
        novo->next = NULL;
        *inicio = novo;
        return 1;
    }
    else{
        Lista *ant = *inicio;
        Lista *atual = *inicio;
        while(atual != NULL && atual->dado < val){
            ant = atual;
            atual = atual->next;
        }
        if(atual == *inicio){ //insere início
            novo->next = *inicio;
            *inicio = novo;
        }else{
            novo->next = atual;
            ant->next = novo;
        }
        return 1;
    }
}