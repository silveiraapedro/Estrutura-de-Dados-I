#include <stdio.h>
#include <string.h>
#define TAM 50

typedef struct sMusica
{
    char nome[TAM], genero[TAM];
}Musica;

typedef struct sFila
{
    Musica itens[TAM];
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
    if((f->fim + 1) % TAM == f->inicio) /// Se caso o proximo elemento calculado pelo indice seja igual ao inicio
                                        /// significa que ele estara na proxima posicao do inicio, não podendo
                                        /// inserir na proxima posição.
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enfileirar(Fila *f, char nome[], char genero[])
{

    if(lista_cheia(f))
    {
        printf("ERRO - A fila esta cheia.\n");
    }
    f->fim = (f->fim + 1) % TAM; /// Ele vai criar um condição onde se f->fim chegar no final da fila
                                 /// não vai adicionar mais nenhum numero, tirando assim a condição do
                                 /// if que antes existia.   
    strcpy(f->itens[f->fim].nome, nome);
    strcpy(f->itens[f->fim].genero, genero);

}

void desenfileirar(Fila *f)
{

    if(!lista_vazia(f))
    {
        f->inicio = (f->inicio + 1) % TAM; /// Mesmo contexto, ele vai retirar e passar pra frente o proximo 
                                           /// numero, fazendo assim a condição anterior imposta no if. 
    }

    else
    {
        printf("ERRO - Lista Vazia.\n");
    }
}

void adicionar_musica(Fila *f)
{
    char nome[TAM], genero[TAM];
    char opc;

    do
    {
        fflush(stdin);

        printf("Insira o nome da musica: ");
        fgets(nome, 50, stdin);
        fflush(stdin);

        printf("Insira o genero da musica: ");
        fgets(genero, 50, stdin);
        fflush(stdin);

        enfileirar(f, nome, genero);

        if(!lista_cheia(f)) /// Antes havia erro porque ele ja comparava antes de aplicar a adição, logo ele estaria
                            /// f->inicio e f->fim = 0, logo dando erro de lista cheia sem ter enserido nada.
        {
            printf("Deseja inserir uma nova musica: ");
            scanf("%c", &opc);
            fflush(stdin);
        }

    } while (!lista_cheia(f) && (opc == 'S'|| opc == 's' ));
    
}

void apresentar_musicas(Fila f)
{
    int i = 0;

    if(!lista_vazia(&f))
    {
        while(!lista_vazia(&f))
        {
            printf("\nMusica[%d]\n Nome: %s Genero: %s", i+1, f.itens[(f.inicio+1)%TAM].nome, 
            f.itens[(f.inicio+1)%TAM].genero);  /// Porque (f->inicio+1) % TAM, se pa seja pq ele vai percorrer do inicio
                                                /// e indo adiante ao decorrer do vetor com o looping e pegando o que armazena em cada posicao.
            desenfileirar(&f);
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

printf("1. Adicionar musica.\n");
printf("2. Remover muscia.\n");
printf("3. Apresentar musicas registradas.\n");
printf("0. encerrar.\n");
printf("Insira a opcao.");
scanf("%d", &opc);
return opc;
}

void main()
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
        adicionar_musica(&f);
            break;
        
            case 2:
            desenfileirar(&f);
            break;
    
            case 3:
            apresentar_musicas(f);
            break;
        default:
        printf("invalida.\n");
            break;
        }
    } while (opc != 0);
    

    
    


}