#include <stdio.h>

void teste (void){
  for (int i=0; i<5; i++){
    printf("Christian J. C. Marinho\n");
  }
}

void num_tri (int n) {
  int trinum = 0;
  for (int i=1; i <= n; i++) {
    trinum = trinum + i;
  }
  printf("O numero triangular %i é %i\n", n, trinum);
}

int mdc (int a, int b) {
  int tmp;
  while(b != 0) {
    tmp = a%b;
    a = b;
    b = tmp;
  }
return a;
}

int minimo (int valores[10]) {
  int valor_min;
  valor_min = valores[0];

  for (int i=0; i < 10; i++) {
    if (valores[i] < valor_min) {
      valor_min = valores[i];
    }
  }
return valor_min;
}

int main(void) {
  
  int A[10], min;
  
  printf("informe 10 valores:\n");
  for (int i=0; i<10; i++) {
    scanf("%i", &A[i]);
  }

  min = minimo(A);

  printf("O valor minimo é: %i", min);

  /*int num1, num2, x;
  printf("Digite um número: ");
  scanf("%d", &num1);
  printf("Digite um número: ");
  scanf("%d", &num2);

  x = mdc(num1, num2);
  
  printf("\nO MDC de %d e %d é: %d", num1, num2, mdc(num1, num2));
  printf("\nO MDC de %d e %d é: %d", num1, num2, x);*/
  
  //num_tri(6);
  //num_tri(50);
  
  return 0;
}