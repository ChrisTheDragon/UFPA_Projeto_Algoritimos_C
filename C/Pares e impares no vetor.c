#include <stdio.h>

int main(void)
{
    int vet1[20], vet2[20], vet3[20], i=0;
    printf("VETOR 1\n");
    for (i = 0; i < 20; i++)
    {
        printf("Digite o %dº valor: ", i+1);
        scanf("%d", &vet1[i]);
    }

    printf("VETOR 2\n");
    for (i = 0; i < 20; i++)
    {
        printf("Digite o %dº valor: ", i+1);
        scanf("%d", &vet2[i]);
    }
    
    for (i = 0; i < 20; i++)
    {
        if (i % 2 == 0)
        {
            vet3[i] = vet1[i];
        } else {
            vet3[i] = vet2[i];
        }
    }
    
    printf("\nVetor com par e impar:\n");
    for (i = 0; i < 20; i++)
    {
        printf("[%d]", vet3[i]);
    }
    return 0;
}
