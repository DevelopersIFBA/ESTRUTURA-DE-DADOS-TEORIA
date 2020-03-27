typedef struct fila{
    int inicioFilaUm
    int finalFilaUm;
    int inicioFilaDois;
    int finalFilaDois;
    int qtdFila1;
    int qtdFila2;
    int dados[20];
}Fila;

Fila* cria_Fila(){
    Fila *fi;
    fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->inicioFilaUm = 0;
        fi->finalFilaUm = 0;
        fi->inicioFilaDois = 10;
        fi->finalFilaDois = 10;
        fi->qtdFila1 = 0;
        fi->qtdFila2 = 0;
    }
    return fi;
}


int insere_Fila(Fila* fi, int valor, int opcao){

    if(opcao == 1){
        if(fi == NULL)
            return 0;
        if(Fila_cheia(fi, opcao))
            return 0;
        fi->dados[fi->finalFilaUm] = valor;
        fi->finalFilaUm = (fi->finalFilaUm+1)%10;
        fi->qtdFila1++;
        return 1;
    }
    else if(opcao == 2){
        if(fi == NULL)
            return 0;
        if(Fila_cheia(fi, opcao))
            return 0;
        fi->dados[fi->finalFilaDois] = valor;
        fi->finalFilaDois = ((fi->finalFilaDois+1)%10)+10;
        fi->qtdFila2++;
        return 1;
    }
    else{
        return 0;
    }
    
}


int Fila_cheia(Fila* fi, int opcao){
    if(fi == NULL)
        return -1;
    if(opcao == 1){
        if (fi->qtdFila1 == 10)
            return 1;
    }
    else if (opcao == 2){
        if (fi->qtdFila2 == 10)
            return 1;
    }
    return 0;
}

int consulta_Fila(Fila* fi, int *valor, int opcao){
    if(fi == NULL || Fila_vazia(fi, opcao))
        return 0;
    if(opcao == 1){
        *valor = fi->dados[fi->inicioFilaUm];
        return 1;
    }
    else if(opcao == 2){
        *valor = fi->dados[fi->inicioFilaDois];
        return 1;
    }
    else
        return 0;
}

int remove_Fila(Fila* fi, int opcao){

    if(opcao == 1){
        if(fi == NULL || Fila_vazia(fi, opcao))
            return 0;
        fi->inicio = (fi->inicioFilaUm+1)%10;
        fi->qtdFila1--;
        return 1;
    }
    else if(opcao == 2){
        if(fi == NULL || Fila_vazia(fi, opcao))
            return 0;
        fi->inicio = ((fi->inicioFilaDois+1)%10)+10;
        fi->qtdFila2--;
        return 1;

    }
    else{
        return 0; // OPCAO DE FILA INVÁLIDA
    }
}

int Fila_vazia(Fila* fi, int opcao){
    if(fi == NULL)
        return -1;
    if(opcao == 1){
        if (fi->qtdFila1 == 0)
            return 1;
    }
    else if (opcao == 2){
        if (fi->qtdFila2 == 0)
            return 1;
    }
    return 0;
}
