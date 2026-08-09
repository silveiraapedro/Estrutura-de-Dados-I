#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arq
{
    char nome[30], data[10];
}ARQ;

typedef struct cell
{
    ARQ info;
    struct cell *esq;
    struct cell *dir;
}NO;

void init(NO **tree)
{
    *tree = NULL;
}

ARQ inserir()
{
    ARQ a;
    printf("Insira o nome do arquivo: ");
    scanf("%[^\n]s", a.nome);
    fflush(stdin);

    printf("Insira a data: ");
    scanf("%[^\n]s", a.data);
    fflush(stdin);

    return a;
}

void put(NO **tree, ARQ a)
{
    NO *new;
    if(*tree == NULL)
    {
        *tree = (NO*)malloc(sizeof(NO));
        strcpy((*tree)->info.nome, a.nome);
        strcpy((*tree)->info.data, a.data);
        (*tree)->dir = NULL;
        (*tree)->esq = NULL;
    }
    else if(strcmp((*tree)->info.nome,a.nome)<0)
    {
        put(&(*tree)->esq, a);
    }
    else if(strcmp((*tree)->info.nome,a.nome)>0)
    {
        put(&(*tree)->dir, a);
    }

}

NO* pesquisar(NO *tree, char x[10])
{
    NO *aux;
    aux = tree;
    if(aux != NULL)
    {
        return NULL;
    }
    else if(strcmp(aux->info.data, x) < 0)
    {
        return pesquisar(aux->esq, x); 
    }
    else if(strcmp(aux->info.data, x) > 0)
    {
        return pesquisar(aux->dir, x);
    }
    else
    {
        return aux;
    }
}

NO *pesquisar(NO *tree, char x[10]) {
    if (tree == NULL) return NULL;

    if (strcmp(tree->info.data, x) < 0) {
        return pesquisar(tree->esq, x);
    } else if (strcmp(tree->info.data, x) > 0) {
        return pesquisar(tree->dir, x);
    } else {
        return tree;
    }
}

NO *remover(NO *tree, char x[10]) {
    if (tree == NULL) return NULL;

    if (strcmp(x, tree->info.data) < 0) {
        tree->esq = remover(tree->esq, x);
    } else if (strcmp(x, tree->info.data) > 0) {
        tree->dir = remover(tree->dir, x);
    } else {
        // Achou o nó pra remover
        if (tree->esq == NULL && tree->dir == NULL) {
            free(tree);
            return NULL;
        } else if (tree->esq == NULL) {
            NO *temp = tree->dir;
            free(tree);
            return temp;
        } else if (tree->dir == NULL) {
            NO *temp = tree->esq;
            free(tree);
            return temp;
        } else {
            // Dois filhos: pega o maior da esquerda
            NO *temp = tree->esq;
            while (temp->dir != NULL)
                temp = temp->dir;

            tree->info = temp->info;
            tree->esq = remover(tree->esq, temp->info.data);
        }
    }
    return tree;
}

NO* listar_em_ordem(NO *tree)
{
    if(tree == NULL)
    {
        return NULL;
    }
    else
    {
        printf("%s\n", tree->info.nome);
        listar_em_ordem(tree->esq);
        listar_em_ordem(tree->dir);

    }
}

void main()
{
    NO *tree;
    ARQ a;
    init(&tree);

    a = inserir();
    put(&tree, a);

    listar_em_ordem(tree);
}



