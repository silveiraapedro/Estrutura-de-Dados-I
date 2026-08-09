#include <stdio.h>
#include <string.h>
#define TAM 10

typedef struct sBarraca
{
    char nome[50], cpf[50], comida[50];
    char sit;
}BARRACA;

typedef struct sLista
{
    BARRACA itens[TAM];
    int n;
}lista;

void inicializar(lista *l)
{
    l->n = -1;
}

int cheia(lista *l)
{
    if(l->n+1 == TAM)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int vazia(lista *l)
{
    if(l->n == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enfileirar(lista *l, BARRACA b)
{
    if(cheia(l))
    {
        printf("TA CHEIA PORRA.\n");
        return 1;
    }

    else
    {
        strcpy(l->itens[l->n].nome, b.nome); 
        strcpy(l->itens[l->n].cpf, b.cpf);
        strcpy(l->itens[l->n].comida, b.comida);
        l->itens[l->n].sit = b.sit;
        l->n = l->n+1;
    }
}

BARRACA inserir()
{
    BARRACA b;
    int opc;

    fflush(stdin);
    printf("Insira o nome da barraca: ");
    scanf("%[^\n]s", b.nome);

    fflush(stdin);
    printf("Insira o cpf: ");
    scanf("%[^\n]s", b.cpf);

    fflush(stdin);
    printf("Insira a opcao de comida 1-Bebidas, 2-Lanches, 3-Art. em geral: ");
    scanf("%d", &opc);
    fflush(stdin);

    switch (opc)
    {
    case 1:
        strcpy(b.comida, "Bebida");
        break;
    
    case 2:
    strcpy(b.comida, "Lanches");
    break;    

    case 3:
    strcpy(b.comida, "Art em geral");
    break; 
    }

    printf("A situação do aluguel esta paga? D: devendo, P:pago");
    scanf(" %c", &b.sit);
    fflush(stdin);

    return b;

}


void apresentar(lista l)
{
    for(int i = 0; i<l.n+1; i++)
    {
        printf("Barraca[%d]\n", i);
        printf("Nome: %s\n", l.itens[i].nome);
        printf("CPF: %s\n", l.itens[i].cpf);
        printf("Comida: %s\n", l.itens[i].comida);
        printf("Situação do aluguel: %c\n", l.itens[i].sit);
    }
}

void main()
{
    lista l;
    BARRACA b;

    b = inserir();
    enfileirar(&l, b);

    apresentar(l);

}





