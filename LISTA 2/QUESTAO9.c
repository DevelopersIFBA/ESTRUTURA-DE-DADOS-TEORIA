typedef struct elementoFila{
    struct elementoFila next;
    int valor;
}ElementoFila;

typedef struct fila{
    struct elementoFila *inicio;
    struct elementoFila *final;
    int qtd;
}Fila;

int main(){

	Fila *fiMaiorPrioridade = (Fila*) malloc(sizeof(Fila));
	Fila *fiMenorPrioridade = (Fila*) malloc(sizeof(Fila));
	int opcao;
	int valor;

	scanf("%d", &valor);
	scanf("%d", &opcao); // QUAL LISTA DESEJA INSERIR? 1- ALTA 2- BAIXA

	Enqueue(fiMaiorPrioridade, fiMenorPrioridade, opcao, valor);

	Dequeue(fiMaiorPrioridade, fioMenorPrioridade);
}

int Enqueue(Fila* fioMaioPrioridade, Fila* fiMenorPrioridade, int opcao, int valor){
    
    if(opcao == 1){
    	if(fiMaiorPrioridade == NULL)
        	return 0;  // FILA NAO EXISTE
       	ElementoFila *novoMaior = (ElementoFila*) malloc(sizeof(ElementoFila));
       	if(novoMaior == NULL)
        	return 0;
        novoMaior->valor = valor;
    	novoMaior->next = NULL;
    	if(fiMaiorPrioridade->final == NULL) //fila vazia
        	fiMaiorPrioridade->inicio = novoMaior;
	    else
	        fiMaiorPrioridade->final->next = novoMaior;
	    fiMaiorPrioridade->final = novoMaior;
	    fiMaiorPrioridade->qtd++;
	    return 1;
    }
    else if(opcao == 2){
    	if(fiMenorPrioridade == NULL)
        	return 0;  // FILA NÃO EXISTE
        ElementoFila *novoMenor = (ElementoFila*) malloc(sizeof(ElementoFila));
        if(novoMenor == NULL)
        	return 0;
        novoMenor->valor = valor;
    	novoMenor->next = NULL;
    	if(fiMenorPrioridade->final == NULL) //fila vazia
        	fiMenorPrioridade->inicio = novoMenor;
	    else
	        fiMenorPrioridade->final->next = novoMenor;
	    fiMenorPrioridade->final = novoMenor;
	    fiMenorPrioridade->qtd++;
	    return 1;
    }
    else{
    	return 0;
    }
}

int Dequeue(Fila* fiMaiorPrioridade, Fila* fiMenorPrioridade){
    
    if(fiMaiorPrioridade == NULL)
        return 0;
    if(fiMaiorPrioridade->inicio == NULL){ //Fila Alta Prioridade vazia
    	if(fiMenorPrioridade == NULL)
        	return 0;
    	if(fiMenorPrioridade->inicio == NULL)// Fila Baixa Prioridade Vazia
        	return 0; 
    	ElementoFila *noMenor = fiMenorPrioridade->inicio;
	    fiMenorPrioridade->inicio = fiMenorPrioridade->inicio->next;
	    if(fiMenorPrioridade->inicio == NULL) //fila ficou vazia
	        fiMenorPrioridade->final = NULL;
	    free(noMenor);
	    fiMenorPrioridade->qtd--;
	    return 1;
    }
    else{
    	ElementoFila *noMaior = fiMaiorPrioridade->inicio;
	    fiMaiorPrioridade->inicio = fiMaiorPrioridade->inicio->next;
	    if(fiMaiorPrioridade->inicio == NULL) //fila ficou vazia
	        fiMaiorPrioridade->final = NULL;
	    free(noMaior);
	    fiMaiorPrioridade->qtd--;
	    return 1;
    }
}