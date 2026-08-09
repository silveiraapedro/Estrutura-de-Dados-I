#include <stdio.h>
#include <string.h>
#define TAM 50

typedef struct sPassage
{
    char nome[50];
    int idade;
}Passageiro;

typedef struct sFila
{
    Passageiro itens[TAM]; /// Armazena uma array de informações da outra estrutura
    int inicio, fim;
}Fila;

void inicializar(Fila *f)
{
    f->inicio = TAM - 1;
    f->fim = TAM - 1;
}

int lista_vazia(Fila *f)
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

int lista_cheia(Fila *f)
{
    if((f->fim)%TAM == f->inicio) /// Pelo jeito tem que ser f->fim visto que geralmente colocamos valores no
                                  /// fim da fila, mas nesse caso depende.
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

void adicionar_fim(Fila *f, char nome[], int idade)
{
   
    if(lista_cheia(f))
    {
        printf("A lista esta cheia.\n");
    }
    f->fim = (f->fim + 1)% TAM;
    strcpy(f->itens[f->fim].nome, nome);
    f->itens[f->fim].idade = idade;
}

void adicionar_inicio(Fila *f, char nome[], int idade)
{
    f->inicio = (f->inicio - 1)% TAM;
    if(lista_cheia(f))
    {
        printf("A lista esta cheia.\n");
    }
    
    strcpy(f->itens[f->inicio].nome, nome);
    f->itens[f->inicio].idade = idade;
}

void remover(Fila *f)
{
    if(!lista_vazia(f))
    {
        f->inicio = (f->inicio + 1)% TAM;
    }
    else
    {
        printf("Lista vazia.\n");
    }
}

void inserir_passageiro(Fila *f)
{
    char nome[TAM];
    char opc, des;
    int idade;

    do
{
    fflush(stdin);

    printf("Insira o nome do passageiro: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = 0;

    printf("Insira a idade do passageiro: ");
    scanf("%d", &idade);
    while (getchar() != '\n'); 

    printf("Este crioulo vai ir no fim ou inicio?");
    scanf(" %c", &des);
    while (getchar() != '\n');

    if(des == 'fim')
    {
        adicionar_fim(f, nome, idade);
    }
    else
    {
        adicionar_inicio(f, nome, idade);
    }

    if(!lista_cheia(f))
    {
        printf("Deseja inserir mais um passageiro: ");
        scanf(" %c", &opc);
        while (getchar() != '\n');
    }
}while(!lista_cheia(f) && (opc == 's' || opc == 'S'));
}

void apresentar_passageiros(Fila f)
{
    int i = 0;

    if(!lista_vazia(&f))
    {
        while(!lista_vazia(&f))
        {
            printf("\nPassageiro[%d]\n nome: %s\n idade: %d\n", i+1, f.itens[(f.inicio+1)%TAM].nome, 
                                                                f.itens[(f.inicio+1)%TAM].idade);
            remover(&f);
            i++;
        }
    }
    else
    {
        printf("Lista vazia.\n");
    }
}

int menu()
{
    int opc;
    printf("1. Adicionar passageiro.\n");
    printf("2. Remover passageiro.\n");
    printf("3. Apresentar passageiro registrados.\n");
    printf("0. encerrar.\n");
    printf("Insira a opcao.");
    scanf("%d", &opc);
    return opc;
}

int main()
{
    Fila f; 
    int opc;
    

    inicializar(&f);
    do
    {
        opc = menu();

        switch (opc)
        {
            case 1:
            inserir_passageiro(&f);
            break;
            
            case 2:
            remover(&f);
            break;

            case 3:
            apresentar_passageiros(f);
            break;

            case 0:
            printf("Encerrando programa.\n");
            break;

        default:
        printf("opcao incorreta.\n");
            break;
        }
    } while (opc != 0);
    
}
