#include <stdio.h>

int main(void) {
  float valor, valT, valL, valA, valH;
  char codigo;

  printf("Digite o valor e a categoria dos produtos:\n");
  printf("Categorias: \n");
  printf("[L] - limpeza [A] - alimentacao [H]- higiene\n");
  printf("Digite 0 no valor para encerrar\n\n");

  while (valor != 0) {
    printf("Digite o valor da Mercadoria: ");
    scanf("%f", &valor);

    valT += valor;
    
    if (valor == 0){
      break;
    }
    
    printf("Digite o codigo da mercadoria: ");
    scanf(" %c", &codigo);
    
    switch (codigo){
      case 'l': valL += valor; break;
      case 'a': valA += valor; break;
      case 'h': valH += valor; break;
    }
  }

  printf("\nO total de vendas foi: R$%.2f\n\n", valT);
  printf("O total de vendas de cada produto foi de:\n");
  printf("Limpesa     : %.2f\n", valL);
  printf("Alimentação : %.2f\n", valA);
  printf("Higiene     : %.2f\n", valH);

  return 0;
}