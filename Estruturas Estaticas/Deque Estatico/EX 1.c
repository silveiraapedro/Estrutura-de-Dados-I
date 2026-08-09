#include <stdio.h>
#define TAM 10

typedef struct sFila 
{
    int itens[TAM];
    int inicio, fim;
}Fila;

void inicializar(Fila *f)
{
    f->inicio = TAM - 1;
    f->fim = TAM - 1; 
}

int lista_cheia(Fila *f)
{
    if(f->inicio == f->fim)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void inserir_fim(Fila *f, int elem)
{   
    if(lista_cheia(f))
    {
        printf("Lista cheia.\n");
    }
    f->fim = (f->fim + 1)% TAM;
    f->itens[f->fim] = elem;
   
}

void inserir_inicio(Fila *f, int elem)
{
    
    if(lista_cheia(f))
    {
        printf("Lista cheia.\n");
    }
    f->itens[(f->inicio - 1) % TAM] = elem;
    return 0;
}

int excluir_inicio(Fila *f)
{
    int aux = 0;
    if(!lista_cheia(f))
    {
        f->inicio = (f->inicio + 1)% TAM;
        aux = f->itens[f->inicio];
        return aux;
    }
    else
    {
        printf("ERRO - Lista vazia.\n");
        return 1;
    }
    
}

int excluir_fim(Fila *f)
{
    int aux = 0;

    if(!lista_cheia(f))
    {
        f->fim = (f->fim - 1) % TAM;
        aux = f->itens[f->fim];
        return aux;
    }
    else
    {
        printf("ERRO - Lista vazia.\n");
        return 1;
    }
    
}

void apresentar_naoclass(Fila *f)
{
    int i =(f->inicio + 1) % TAM; 
    if(!lista_cheia(f))
    {
        printf("Deque: \n");
        while(i != ((f->fim + 1)% TAM))
        {
            printf("%d\n", f->itens[i]);
            i = (i + 1) % TAM;
        }
    }
    else
    {
        printf("Fila vazia porra.\n");
    }
}

void apresentar_classica(Fila f)
{
    int quant = 0;
    int aux[TAM];

    while(!lista_cheia(&f))
    {
        aux[quant++] = excluir_inicio(&f);

    }
    printf("Fila: \n");
    for(int i = 0; i<quant; i++)
    {
        printf("%d\n", aux[i]);
    }

}

int menu()
{
    int opc;

    printf("1. Inserir elemento no fim.\n");
    printf("2. Inserir elemento no inicio.\n");
    printf("3. Excluir elemento no inicio.\n");
    printf("4. Excluir elemento no fim.\n");
    printf("5. Apresentar de maneira não classica.\n");
    printf("6. Apresentar de maneira classica.\n");
    printf("Insira uma opcao:");
    scanf("%d", &opc);

    return opc;
}


void main()
{
    int elem, opc;
    Fila f;

    inicializar(&f);
    do
    {
        opc = menu();

    switch (opc)
    {
        case 1:
        printf("Insira o elemento a ser adicionado: ");
        scanf("%d", &elem);
        inserir_fim(&f, elem);
        break;
    
        case 2:
        printf("Insira o elemento a ser adicionado: ");
        scanf("%d", &elem);
        inserir_inicio(&f, elem);
        break;

        case 3:
        excluir_inicio(&f);
        break;

        case 4:
        excluir_fim(&f);
        break;

        case 5:
        apresentar_naoclass(&f);
        break;

        case 6:
        apresentar_classica(f);
        break;

        case 0:
        printf("Encerrando o programa.\n");
        break;
        
    default:
        printf("Opcao incorreta.\n");
        break;
    
 }
} while (opc != 0);

}
