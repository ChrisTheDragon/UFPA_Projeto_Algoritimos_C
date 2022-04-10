#include <stdio.h>
#include <stdlib.h>

int teste (int *pnt_int){
  *pnt_int = 100;
  return (*pnt_int);
}

void trocar( int *p1_int, int *p2_int ) {
  int tmp;
  tmp = *p1_int;
  *p1_int = *p2_int;
  *p2_int = tmp;
}

int main() {
  char c = 'U';
  char *pont_char = &c;
  int a = 10, b = 20, i1 = NULL, i2 = NULL, *p1 = NULL, *p2 = NULL;
  
  printf("%c - %c \n", c , *pont_char);
  
  c = 'F';
  
  printf("%c - %c \n", c , *pont_char);
  
  *pont_char = 'P';
  
  printf("%c - %c \n", c , *pont_char);

  printf("Digite: ");
  scanf("%c", &*pont_char);
  
  printf("%c - %c \n\n", c , *pont_char);

  printf("O endereço da variavél 'c' = %p\n",(void*)&c);

  printf("a = %p\n",(void*)&a);
  printf("b = %p\n\n",(void*)&b);

  i1 = 5;
  p1 = &i1;
  i2 = *p1 / 2 + 10;
  p2 = p1;

  printf("i1 = %i, i2 = %i, *p1 = %i, *p2 = %i \n\n", i1, i2, *p1, *p2);

  printf("Antes = %i\n", i1);
  teste(p1);
  printf("Depois = %i\n\n", i1);

  p2 = &i2;
  printf("i1 = %i, i2 = %i \n", i1, i2);
  trocar(p1, p2);
  printf("i1 = %i, i2 = %i \n", i1, i2);
  trocar(&i1, &i2);
  printf("i1 = %i, i2 = %i \n", i1, i2);
}