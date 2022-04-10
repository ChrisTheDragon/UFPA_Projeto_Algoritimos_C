#include <stdio.h>

void dec_bin (int num) {
  int rest, i = 0, j = 0;
  int baseC[30];
  
  while ( num > 0){
      rest = num%2;
      num = num/2;
      baseC[i] = rest;
      i++;
  }
  
  for (j=i-1; j>=0; j--) {
    printf("%i", baseC[j]);
  }
  printf("\n\n");
}

void dec_oct (int num) {
  int rest, i = 0, j = 0;
  int baseC[30];
  
  while ( num > 0){
      rest = num%8;
      num = num/8;
      baseC[i] = rest;
      i++;
  }
  
  for (j=i-1; j>=0; j--) {
    printf("%i", baseC[j]);
  }
  printf("\n\n");
}

void dec_hex (int num) {
  int rest, i = 0, j = 0;
  int baseC[30];
  
  while ( num > 0){
    rest = num%16;
    num = num/16;
    baseC[i] = rest;
    i++;
  }
    
  for (j=i-1; j>=0; j--) {
    if (baseC[j] >= 10){
      switch (baseC[j]) {
        case 10 : printf ( "A" ); break; 		
        case 11 : printf ( "B" ); break;
        case 12 : printf ( "C" ); break;
        case 13 : printf ( "D" ); break;
        case 14 : printf ( "E" ); break;
        case 15 : printf ( "F" ); break;
      }
    }else{
      printf("%i", baseC[j]);
    }
  }
  printf("\n\n");
}

int main(void) {
  int num, base = 0, teste = 1;

  while (teste > 0) {
    base = 0;
    //Entrada do numero
    printf("\nDigite um numero: ");
    scanf("%i",&num);

    //Escolha uma base
    while (base != 2 && base != 8 && base != 16) {
      printf("Digite uma das Bases: \n");
      printf("[2] / [8] / [16]\n");
      printf("-> ");
      scanf("%i", &base);
    }
    switch (base){
      case 2: dec_bin(num); break;
      case 8: dec_oct(num); break;
      case 16: dec_hex(num); break;
    }

    //Conitnuar?
    printf("Deseja continuar? \n");
    printf("1-[S] / 0-[N]");
    printf("-> ");
    scanf("%i", &teste);
  }
  return 0;
}