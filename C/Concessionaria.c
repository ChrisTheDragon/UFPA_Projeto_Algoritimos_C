#include <stdio.h>
#include <string.h>

typedef struct carros  
{
    char marca[15];
    int ano;
    char cor[10];
    float preco;
}carros;

int tam = 4;

void cadastrar (carros vetcarros[tam]){
    for (int i = 0; i < tam; i++)
    {
        printf("CARRO N%i:\n", i+1);
        printf("MARCA: ");
        scanf(" %[^\n]", &vetcarros[i].marca);
        getchar();
        printf("ANO: ");
        scanf("%d", &vetcarros[i].ano);
        printf("COR: ");
        scanf(" %[^\n]", &vetcarros[i].cor);
        printf("PRECO: ");
        scanf("%f", &vetcarros[i].preco);
    }
}

void PesquisaPreco (carros vetcarros[tam]) {
    float preco;
    printf("Digite um valor: R$ ");
    scanf("%f", &preco);

    printf("Carros encontrados: \n");
    for (int i = 0; i < tam; i++)
    {
        if (preco >= vetcarros[i].preco) {
            printf("MARCA = %s\nANO = %i\nCOR = %s\n", vetcarros[i].marca, vetcarros[i].ano, vetcarros[i].cor);
            printf("\n================\n");
        }
    }
    
}

void PesquisaMarca (carros vetcarros[tam]){
    char marca[15];
    printf("Digite uma Marca: ");
    scanf(" %s", marca);
    getchar();
    
    for (int i = 0; i < tam; i++)
    {
        if (strcmp(marca, vetcarros[i].marca) == 0){
            printf("\n PRECO : %.2f\n ANO: %i\n COR: %s", vetcarros[i].preco, vetcarros[i].ano, vetcarros[i].cor);
            printf("\n================\n");
        }
    }
    

}

void PesquisaCarac (carros vetcarros[tam]){
    int ano, cont = 0;
    char marca[15], cor[10];

    printf("Digite as Caracteristicas: \n");
    printf("MARCA = ");
    scanf(" %s", &marca);
    printf("ANO = ");
    scanf("%d", &ano);
    printf("COR = ");
    scanf("%s", &cor);

    for (int i = 0; i < tam; i++)
    {
        if ((strcmp(marca, vetcarros[i].marca) ==0) && (ano == vetcarros[i].ano) && (strcmp(cor, vetcarros[i].cor))) {
            printf("Carro Encontrado\n");
            printf("PRECO %.2f\n", vetcarros[i].preco);
        } else {
            cont =1;
        }
    }
    if cont == 1{
        printf("\nCarro nao encontrado\n");
    }
}

int main(void)
{
    int op = 6;
    carros vetcarros[tam];

    while (op != 0)
    {
        printf("\n===== MENU =====\n");
        printf("[ 1 ] - Cadastrar Carros\n");
        printf("[ 2 ] - Pesquisa por Preco\n");
        printf("[ 3 ] - Pesquisa por Marca\n");
        printf("[ 4 ] - Pesquisa por Caracteristicas\n");
        printf("[ 0 ] - Sair\n");
        printf("-> ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            cadastrar(vetcarros);
            break;
        case 2:
            PesquisaPreco(vetcarros);
            break;
        case 3:
            PesquisaMarca(vetcarros);
            break;
        case 4:
            PesquisaCarac(vetcarros);
            break;
        case 0:
            printf("\nFinalizando Programa!\n");
            op = 0;
            break;
        default:
            printf("\nOpcao invalida\n");
            break;
        }
    }
    
    return 0;
}
