#include <stdio.h>

int main(void) {
    int vet[12], x=13, y=13;

    for (int i=0; i<12; i++){
        printf("Digite o %dº valor: ", i+1);
        scanf("%d", &vet[i]);
    }

    printf("Numeros / Posição");
    for (int i=0; i<12; i++){
        printf("[%d / %d]", vet[i], i);
    }
    
    while (x > 11 || y > 11)
    {
        printf("\nDigite uma posição do vetor: ");
        scanf("%d", &x);
        printf("Digite outra posição do vetor: ");
        scanf("%d", &y);
        if (x > 11 || y > 11) {
            printf("Valor inválido! Digite novamente!\n");
        }
    }
    
    printf("Soma: %d + %d = %d", vet[x], vet[y], vet[x]+vet[y]);


    return 0;
}
