#include <stdio.h>
#define TAM 10

typedef struct sLista
{
    int valor[TAM];
    int n;
} LISTA;

void lista_inicializar(LISTA *L)
{
    L->n = -1;  /// Vai servir para determinar como nada os elementos que ainda n�o foram              /// inseridos dentro do vetor.
}

int lista_cheia(LISTA *L)
{
    if(L->n+1 == TAM) /// Analisar se a variavel 'n' ja foi preenchida com todos o seu devido tamanho
                           /// assim n�o permetindo que seja preenchido
    {
        printf("Esta cheio.\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

int lista_vazia(LISTA *L)
{
    if(L -> n == -1) /// Verificar se a lista esta vazia analisando se 'n' esta em -1
    {
        printf("Esta vazio.\n");
        return 1;
    }
    else
    {
        return 0;
    }

}

int inserir_elementopos(LISTA *L, int pos, int elem)
{
    if(lista_cheia(L))
    {
        printf("A lista ja esta cheia.\n");
        return 1;
    }

    if(pos < 0 || pos > L->n+1) /// vai verificar se a posi��o inserida � conrresponde as que
        /// tem dentro do vetor, nunca ultrapassando os limites.
    {
        printf("A posicao inserida esta fora dos limites da array.\n");
        return 1;
    }

    for(int i =(L->n+1); i > pos; i--) /// O valor na posi��o desejada ira ser inserido a partir do/// for percorrendo a partir do fim at� o inicio
    {
        L->valor[i] = L->valor[i-1];
    }

    L->valor[pos] = elem; /// Apos percorrer no for at� o valor de 'pos' ira receber o valor inserido
    /// desejado.
    L->n = L->n+1; /// aumenta mais uma posicao
    return 0;
}

int remover_elementopos(LISTA *L, int pos)
{
    int i;
    if(pos < 0 || pos > L->n)
    {
        printf("A posicao inserida esta fora dos limites da array.\n");
        return 1;
    }

    for(i = pos; i < (L->n); i++) /// Esta percorrendo do inicio do vetor at� a posicao escolhida lendo at�
    /// final

    {
        L->valor[i] = L->valor[i+1];
    }

        L->n = L->n-1; /// Vair excluir na posi��o achada, diminuindo o tamanho
    return 0;

}

int acessar_elementopos(LISTA *L, int pos)
{
    if(pos < 0 || pos > L->n)
    {
        printf("A posicao inserida esta fora dos limites da array.\n");
        return 1;
    }

    return L->valor[pos];
}

int mostrar_vetor(LISTA *L)
{
    if (lista_vazia(L)) {
        printf("Lista vazia.\n");
    } else {
        for (int i = 0; i <= L->n; i++) {
            printf("[pos %d]-- val %d\n", i, L->valor[i]);
        }
    }
}

int inserir_elementofim(LISTA *L, int elem){
    if(lista_cheia(L) == 1){//verifica se a lista esta cheia
        printf("Erro, a lista esta cheia");
        return 1; //se tiver, abandona a operacao
    }
    L->valor[L->n+1] = elem; //caso o contrario, atribui elemento no valor na posicao n+1;
    L->n = L->n+1;//apos isso, aumenta o fim da fila

    return 0; //retorna 0 pra conferir, mas pode ser void
}

int main()
{
    LISTA *lista;
    int pos = -1, elem;
    char op;

    lista_inicializar(&lista);

    printf("a. inserir elemento no vetor em posicao especifica.\n");
    printf("b. mostrar vetor.\n");
    printf("c. remover elemento de posicao especifica.\n");
    printf("d. acessar elemento em posicao especifica.\n");
    printf("e. inserir elemento no vetor.\n");

    while(op != 'e')
    {
    printf("Insira a opcao: ");
    scanf(" %c", &op);

        switch(op)
        {
        case 'a':
            printf("Insira a posicao que sera inserido: ");
            scanf("%d", &pos);
            printf("Insira o que vai ser inserido: ");
            scanf("%d", &elem);
            inserir_elementopos(&lista, pos, elem);
            break;

        case 'b':
            mostrar_vetor(&lista);
            break;

        case 'c':
            printf("Insira a posicao a ser removida: ");
            scanf("%d", &pos);
            remover_elementopos(&lista, pos);
            break;

        case 'd':
            printf("Insira a posicao a ser acessada: ");
            scanf("%d", &pos);
            acessar_elementopos(&lista, pos);
            break;
        }

    }

}
