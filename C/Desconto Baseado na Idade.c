#include <stdio.h>

float desconto (int id, float val){
    float desc;

    if (val > 300) {
        desc = val - (0.25*val);
    } else if (val <= 300 && val >= 100 && id > 50) {
        desc = val - (0.15*val);
    } else {
        desc = val;
    }
    return desc;
}

int main (void){
    int idade;
    float valor;

    printf("Digite a Idade: ");
    scanf("%d", &idade);
    printf("Digite o valor da compra: ");
    scanf("%f", &valor);
    printf("O valor a ser pago e R$%.2f", desconto(idade, valor));

    return 0;
}