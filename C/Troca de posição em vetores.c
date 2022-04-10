#include <stdio.h>

void invet(int vet[16])
{
    int invet[16];

    for (int i = 0; i < 16; i++)
    {
        if (i >= 8){
            invet[i] = vet[i-8];
        }
        if (i < 8){
            invet[i] = vet[i+8];
        }
    }

    for (int i = 0; i < 16; i++)
    {
        printf("[%d]", vet[i]);
    }
    printf("\n");
    for (int i = 0; i < 16; i++)
    {
        printf("[%d]", invet[i]);
    }
}

int main(void)
{
    int vet[16];

    for (int i = 0; i < 16; i++)
    {
        printf("Digite o %dº valor: ", i+1);
        scanf("%d", &vet[i]);
    }

    invet(vet);

    return 0;
}
