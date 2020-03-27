typedef struct pilha{
    int qtdPilha1;
    int qtdPilha2;
    int dados[100];
}Pilha;

Pilha* cria_Pilha(){
    Pilha *pilha;
    pilha = (Pilha*) malloc(sizeof(Pilha));
    if(pilha != NULL)
        pilha->qtdPilha1 = 0;
    pilha->qtdPilha1 = 0;
    pilha->qtdPilha2 = 0;
    return pilha;
}

int Push(Pilha* pilha, int valor, int PilhaUmOuDois){
    if(pilha == NULL)
        return 0;

    if(PilhaUmOuDois == 1){
    	if(pilha->qtdPilha1 == 50) //PILHA UM CHEIA
        	return 0;
        pilha->dados[pilha->qtdPilha1] = valor;
    	pilha->qtdPilha1++;
    	return 1;
    }
    else if (PilhaUmOuDois == 2){
    	if(pilha->qtdPilha2 == 50) //PILHA DOIS CHEIA
        	return 0;
        pilha->dados[pilha->qtdPilha2] = valor;
    	pilha->qtdPilha2++;
    	return 1;

    }
    else
    	return 0; // OPCAO INVALIDA
}

int Pop(Pilha* pilha, int PilhaUmOuDois){
    if(pilha == NULL)
        return 0;  // PILHA NÃO EXISTE

    if(PilhaUmOuDois == 1){
    	if(pilha->qtdPilha1 == 0) //PILHA VAZIA
        	return 0;
    	pilha->qtdPilha1--;
    	return 1;
    }
    else if (PilhaUmOuDois == 2){
    	if(pilha->qtdPilha2 == 0) //PILHA VAZIA
        	return 0;
    	pilha->qtdPilha2--;
    	return 1;

    }
    else
    	return 0; //  OPCAO INVALIDA
}