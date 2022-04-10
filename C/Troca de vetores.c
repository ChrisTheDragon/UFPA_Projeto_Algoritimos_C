#include <stdio.h>

int main(void)
{
    int tam=11;
    while (tam > 10)
    {
        printf("Digite o tamanho dos vetores ente 1 e 10: ");
        scanf("%d", &tam);
        if (tam > 10){
            printf("Tamanho inválido, tente novamente!\n");
        }
    }
    
    int vet1[tam], vet2[tam], vet3[tam];

    printf("VETOR 1\n");
    for (int i = 0; i < tam; i++)
    {
        printf("Digite o %dº valor: ", i+1);
        scanf("%d", &vet1[i]);
    }
    
    printf("VETOR 2\n");
    for (int i = 0; i < tam; i++)
    {
        printf("Digite o %dº termo: ", i+1);
        scanf("%d", &vet2[i]);
    }

    printf("\nVETOR 1 =\n");
    for (int i = 0; i < tam; i++)
    {
        printf("[%d]", vet1[i]);
    }
    printf("\n");
    printf("VETOR 2 =\n");
    for (int i = 0; i < tam; i++)
    {
        printf("[%d]", vet2[i]);
    }

    printf("\n\nTrocando\n\n");

    for (int i = 0; i < tam; i++)
    {
        vet3[i] = vet1[i];
        vet1[i] = vet2[i];
        vet2[i] = vet3[i];
    }

    printf("VETOR 1 =\n");
    for (int i = 0; i < tam; i++)
    {
        printf("[%d]", vet1[i]);
    }
    printf("\n");
    printf("VETOR 2 =\n");
    for (int i = 0; i < tam; i++)
    {
        printf("[%d]", vet2[i]);
    }
    return 0;
}
