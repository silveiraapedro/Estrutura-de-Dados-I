#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno
{
    char nome[50], curso[50], pront[30], end[50], telefone1[20], telefone2[20];
    int ano_ingre, ano_final;
}ALUNO;

typedef struct cell
{
    ALUNO info;
    struct cell *next;
}CELULA;

CELULA* init(CELULA *lista)
{
    lista=NULL;
    return lista;
}

int empty(CELULA *q)
{
    if(q == NULL)
        return 1;
    return 0;
}

CELULA* getnode()
{
    return (CELULA *) malloc(sizeof(CELULA));
}

void freenode(CELULA *q)
{
    free(q);
}

ALUNO inserir()
{
    ALUNO a;

    printf("Insira o nome: ");
    scanf("%[^\n]s", a.nome);
    fflush(stdin);

    printf("Insira o seu curso: ");
    scanf("%[^\n]s", a.curso);
    fflush(stdin);

    printf("Insira o prontuario: ");
    scanf("%[^\n]s", a.pront);
    fflush(stdin);

    printf("Insira o endereco: ");
    scanf("%[^\n]s", a.end);
    fflush(stdin);

    printf("Insira o ano ingresso: ");
    scanf("%d", &a.ano_ingre);
    fflush(stdin);

    printf("Insira o ano que vai se formar: ");
    scanf("%d", &a.ano_final);
    fflush(stdin);

    printf("Insira o telefone 1: ");
    scanf("%[^\n]s", a.telefone1);
    fflush(stdin);

    printf("Insira o telefone 2: ");
    scanf("%[^\n]s", a.telefone2);
    fflush(stdin);

    return a;
}

CELULA* put_end(CELULA *lista, ALUNO a)
{
    CELULA *q;
    CELULA *aux;

    q = getnode();
    if(q != NULL)
    {
        strcpy(q->info.nome, a.nome);
        strcpy(q->info.curso, a.curso);
        strcpy(q->info.pront, a.pront);
        strcpy(q->info.end, a.end);
        q->info.ano_ingre = a.ano_ingre;
        q->info.ano_final = a.ano_final;
        strcpy(q->info.telefone1, a.telefone1);
        strcpy(q->info.telefone2, a.telefone2);
        q->next = NULL;

        if(empty(lista))
        {
            lista = q;
        }
        else
        {
            aux = lista;
            while(aux->next != NULL)
            {
                aux = aux->next;
            }
            aux->next = q;

        }
        return lista;
    }

}

void listar_formados(CELULA *lista)
{
    CELULA *q = lista;

    if(!empty(lista))
    {
        while(q != NULL)
        {
            if(q->info.ano_final > 2025)
            {
            printf("Nome: %s\n", q->info.nome);
            printf("Prontuario: %s\n", q->info.pront);            
            printf("Curso: %s\n", q->info.curso);            
            printf("Endereco: %s\n", q->info.end);            
            printf("Ano Ingresso: %d\n", q->info.ano_ingre);            
            printf("Ano Formado: %d\n", q->info.ano_final);            
            printf("Telefone 1: %s\n", q->info.telefone1);            
            printf("Telefone 2: %s\n", q->info.telefone2);
            
            }
            q = q->next;

        }
    }
}

void listar_not_yet(CELULA *lista)
{
    CELULA *q = lista;

    if(!empty(lista))
    {
        while(q != NULL)
        {
            if(q->info.ano_final < 2025)
            {
            printf("Nome: %s\n", q->info.nome);
            printf("Prontuario: %s\n", q->info.pront);            
            printf("Curso: %s\n", q->info.curso);            
            printf("Endereco: %s\n", q->info.end);            
            printf("Ano Ingresso: %d\n", q->info.ano_ingre);            
            printf("Ano Formado: %d\n", q->info.ano_final);            
            printf("Telefone 1: %s\n", q->info.telefone1);            
            printf("Telefone 2: %s\n", q->info.telefone2);
            
            }
            q = q->next;

        }
    }
}


void main()
{
    CELULA *l;
    ALUNO a;

    l = init(l);
    a = inserir();
    l = put_end(l,a); 

    a = inserir();
    l = put_end(l,a);

    a = inserir();
    l = put_end(l,a);

    a = inserir();
    l = put_end(l,a);
    listar_not_yet(l);
    listar_formados(l);

}



