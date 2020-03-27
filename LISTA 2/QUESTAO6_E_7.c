typedef struct pilha{
    int dado;
    struct pilha *prox;
}Pilha;


Pilha* cria_P3(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}/ 


int pushPilha3(Pilha* iniP3, Lista* inicio){
	if(iniP3 == NULL)
        return 0;
    if(inicio == NULL)
        return 0;

    Pilha* novo = (Pilha*) malloc(sizeof(Pilha));
    if(novo == NULL)
        return 0;

    Lista *atual = *inicio;

    while(atual != NULL){
    	novo->dados = atual-> dados;
    	novo->prox = (*iniP3);
    	*iniP3 = novo;
        atual = atual->next;
    }

    return 1;
}


int inserePilhaEmListaEncadeadaOrdenada(Lista* inicio, Pilha* ini){ // INSERE NA LISTA ENCADEADA AS PILHAS 1 E 2

	if(inicio == NULL)
        return 0;
    if(ini == NULL)
        return 0;

    Lista *novo = (Lista*) malloc(sizeof(Lista));
    if(novo == NULL)
        return 0;

    Pilha *atual = *ini;

    while(*atual != NULL){

	    novo->dado = atual->dado;
	    if((*inicio) == NULL){ //lista vazia: insere início
	        novo->next = NULL;
	        *inicio = novo;
	    }
	    else{
	        Lista *ant = *inicio;
	        Lista *atl = *inicio;
	        while(atl != NULL && atl->dado < atual->dado){
	            ant = atl;
	            atl = atl->next;
	        }
	        if(atl == *inicio){ //insere início
	            novo->next = *inicio;
	            *inicio = novo;
	        }else{
	            novo->next = atl;
	            ant->next = novo;
	        }
	    }
	    atual = atual->prox
    }
    pop_Pilha(ini);
    return 1;
}

void pop_Pilha(Pilha* ini){
    if(ini != NULL){
        Pilha* no;
        while((*ini) != NULL){
            no = *ini;
            *ini = (*ini)->prox;
            free(no);
        }
        free(ini);
    }
}