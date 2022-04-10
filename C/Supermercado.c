#include <stdio.h>
typedef struct estoque
{
    char nome[15];
    char setor;
    int quantidade;
    float preco;
}estoque;

int tam = 100;

void cadastro (estoque *produtos)
{
    for (int i = 0; i < tam; i++)
    {
        system("cls");
        printf("Digite os seguintes dados:\n");
        printf("Produto: ");
        scanf(" %[^\n]", produtos[i].nome);
        getchar();
        printf("Setor: ");
        scanf(" %c", &produtos[i].setor);
        printf("quantidade: ");
        scanf(" %d", &produtos[i].quantidade);
        printf("Preço: ");
        scanf(" %f", &produtos[i].preco);
    }
}

int ProdutosSetor (estoque *produtos, char setor)
{
    int prod=0;

    for (int i = 0; i < tam; i++)
    {
        if (setor == produtos[i].setor)
        {
            prod += 1;
        }
    }
    return prod;
}

float CapitalInvest (estoque *Produtos)
{
    float capital =0;

    for (int i = 0; i < tam; i++)
    {
        capital += Produtos[i].quantidade * Produtos[i].preco;
    }
    return capital;
}

int main(void)
{
    int op = 4;
    char setor;
    estoque produtos[tam];

    while (op != 0)
    {
        system("cls");
        printf("      MENU\n");
        printf("=================\n");
        printf("[ 1 ] - Cadastrar Produto\n[ 2 ] - Produtos po setor\n[ 3 ] - Capital investido\n[ 0 ] - Sair\n");
        printf("-> ");
        scanf(" %i", &op);

        switch (op)
        {
        case 1: cadastro(produtos); break;
        case 2: 
            printf("Digite o setor: ");
            scanf(" %c", &setor);
            printf("O numero de produtos do setor %c e %i\n", setor, ProdutosSetor(produtos, setor));
            system("pause");
        case 3: 
            printf("O total investido foi: R$%.2f\n", CapitalInvest(produtos));
            system("pause");
        default:
            break;
        }
    }
    return 0;
}
