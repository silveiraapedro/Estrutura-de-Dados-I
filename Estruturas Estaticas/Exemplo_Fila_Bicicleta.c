/// 1. Fa�a um programa que seja capaz de armazenar
/// at� 10 bicicletas, organizadas em uma fila,
/// contendo as seguintes informa��es: cor e quantidade
/// de marchas. O programa deve permitir incluir e
/// remover bicicletas da fila.
#include <stdio.h>
#include <string.h>
#define TAMF 11

typedef struct sBicicleta{
    char cor[20];
    int qtde_marchas;
}BICICLETA;

typedef struct sFila{
    BICICLETA vetor[TAMF];
    int inicio, fim;
}FILA;

void inicializar(FILA *fila){
    fila->inicio = TAMF - 1;
    fila->fim = TAMF -1;
}

int cheia(FILA *fila){
    if(fila->inicio == fila->fim)
        return 1;
    else
        return 0;
}

int vazia(FILA *fila){
    if(fila->inicio == fila->fim)
        return 1;
    else
        return 0;
}

void inserir_fila(FILA *fila,BICICLETA b){
    fila->fim = (fila->fim + 1) % TAMF;
    if (cheia(fila)){
        printf("\nFila cheia!!!");
        fila->fim = fila->fim--;
        if (fila->fim == -1)
            fila->fim = TAMF - 1;
    } else {
        strcpy(fila->vetor[fila->fim].cor,b.cor);
        fila->vetor[fila->fim].qtde_marchas = b.qtde_marchas;
    }
}

BICICLETA remover_fila(FILA *fila){
    BICICLETA b;
    if (! vazia(fila)){
        fila->inicio = (fila->inicio + 1) % TAMF;
        strcpy(b.cor,fila->vetor[fila->inicio].cor);
        b.qtde_marchas = fila->vetor[fila->inicio].qtde_marchas;
    }else{
        printf("\nErro. Fila vazia! ");
        b.qtde_marchas = 0;
    }
    return b;
}

int menu(){
    int op;
    printf("\nMenu: ");
    printf("\n0 - Encerrar programa.");
    printf("\n1 - Inserir bicileta");
    printf("\n2 - Remover bicileta");
    printf("\nEscolha uma das opcoes: ");
    scanf("%d",&op);
    return op;
}

BICICLETA ler_bicicleta(){
    BICICLETA b;

    fflush(stdin);
    printf("\n\nQual a cor da bicicleta?R: ");
    scanf("%[^\n]s",b.cor);
    fflush(stdin);
    printf("\nQual a quantidade de marchas? R: ");
    scanf("%d",&b.qtde_marchas);

    return b;
}

void main(){
    int opc;
    FILA fila;
    BICICLETA byke;
    inicializar(&fila);
    do{
        opc = menu();
        switch (opc) {
            case 0: printf("\nPrograma encerrado!!!");
                    break;
            case 1: printf("\nInserir bicicleta: ");
                    byke = ler_bicicleta();
                    inserir_fila(&fila,byke);

                    printf("\nCor: %s, marchas: %d",
                           fila.vetor[fila.fim].cor,
                           fila.vetor[fila.fim].qtde_marchas);

                    break;
            case 2: printf("\nRetirar bicicleta: ");
                    byke = remover_fila(&fila);

                    printf("\nCor: %s, marchas: %d",
                           byke.cor, byke.qtde_marchas);

                    break;
            default:
                printf("Opcao invalida");
        }
    }while (opc != 0);

}
