#include <stdio.h>
/*struct data {
  int dia;
  int mes;
  int ano;
};*/

typedef struct DATA1 {
  int dia;
  int mes;
  int ano;
}DATA;

int teste (DATA d) {
  d.dia = 5;
  printf("%d\n", d.dia);
  if (d.dia == 2)
    return (1);
  else
    return (0);
}

int main(void) {
  DATA hoje;
  int flag;
  hoje.dia = 2;
  hoje.mes = 3;
  hoje.ano = 2013;
  
  flag  = teste(hoje);
  
  printf("%i\n\n", hoje.dia);
  
  if (flag != 1){
    printf("Erro !\n");
  }  
  
  return 0;
}