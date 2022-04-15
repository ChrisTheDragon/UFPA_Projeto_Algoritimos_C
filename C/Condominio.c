#include <stdio.h>

typedef struct dados
{
    char nome[20];
    unsigned int numero;
    float area;
    unsigned int moradores;
    float valor;
}dados;

int tam = 4;

void cadastrar (dados condominio[tam]){
    for (int i = 0; i < tam; i++)
    {
        printf("Digite os seguintes dados:\n");
        printf("Nome do responsavel: ");
        scanf(" %[^\n]", &condominio[i].nome);
        getchar();
        printf("Numero do apartamento: ");
        scanf("%d", &condominio[i].numero);
        printf("Area [m2]: ");
        scanf("%f", &condominio[i].area);
        printf("Quantidade de moradores: ");
        scanf("%d", &condominio[i].moradores);
        system("cls");
    }
}

float areaTotal (dados *condominio) {
    float areat = 0;
    for (int i = 0; i < tam; i++)
    {
        areat += condominio[i].area;
    }
    return areat;
}

float despesas (dados *condominio, float total) {
    float area, taxa;
    area = areaTotal(condominio);
    taxa = total/area;
    return taxa;
}

void MaisPessoas (dados *condominio) {
    int maior, morador;
    maior = condominio[0].moradores;
    for (int i = 0; i < tam; i++)
    {
        if (maior < condominio[i].moradores) {
            maior = condominio[i].moradores;
            morador = i;
        }
    }
    printf("O apartamento com maior numero e moradores é:\n");
    printf("Responsavel = %s\nN. Apartamento = %d\nArea = %.2f\nQuant. Moradores = %d\n", condominio[morador].nome, condominio[morador].numero, condominio[morador].area, condominio[morador].moradores);
    system("pause");
}

int main(void)
{
    dados condominio[tam];
    int op=6;
    float total;

    while (op != 0)
    {
        printf("====== MENU ======\n");
        printf("[ 1 ] - Cadastrar\n");
        printf("[ 2 ] - Area Total\n");
        printf("[ 3 ] - Valor po Mes\n");
        printf("[ 4 ] - Apartamento mais Populoso\n");
        printf("[ 0 ] - Finalizar\n");
        printf("-> ");
        scanf("%d", &op);

        switch (op)
        {
        case 1: 
            cadastrar(condominio); 
            break;
        case 2: 
            printf("A area total do condominio é: %.2f m2\n", areaTotal(condominio));
            system("pause"); 
            break;
        case 3:
            printf("Digite o total de despesas do condominio: R$");
            scanf("%f", &total);
            printf("A taxa do condiminio será: %.2f", despesas(condominio, total));
        case 4:
            MaisPessoas(condominio);
            break;
        case 0:
            printf("Finalizando Sistema!");
            op = 0;
        default:
            printf("Opcao invalida!");
            break;
        }
    }
    return 0;
}
