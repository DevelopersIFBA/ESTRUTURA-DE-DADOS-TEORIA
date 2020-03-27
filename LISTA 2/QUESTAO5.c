#define MAX 50
int topo = -1
int inicio = 0;
int pilha[MAX];
 
int VerificaPalindromo(char palavra[])
{
    char letra;
    int i;

    for (i = 0; palavra[i] != '\0'; i++)
    {
        letra = palavra[i];
        push(letra);
    }
    for (i = 0; i < (strlen(palavra) / 2); i++)
    {
        if (pilha[topo] == pilha[inicio])
        {
            pop();
            inicio++;
        }
        else
        {
            return 0; // NAO EH PALINDROMO
        }
    }
    if ((strlen(palavra) / 2)  ==  inicio)
        return 1; // PALAVRA EH PALINDROMO
    
    inicio  =  0;
    topo  =  -1;
}
 
void push(char element)
{
    topo++;
    pilha[topo]  =  element;
}
 
void pop()
{
    topo--;
}