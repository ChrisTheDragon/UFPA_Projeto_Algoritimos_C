#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int dado;
	char letra;
	struct testeno *proxno;
}NO;

void mostrar_lista(NO *p){
	while (p != NULL){
		printf("O dado é: %i \n",p->dado);
		printf("A letra é: %c\n",p->letra);
		p = p->proxno;
	}
}

int num_no(NO *p){
	int i=0;
	while (p != NULL){
		i++;
		p = p->proxno;
	}
	return i;
}

void add_noinicio(NO **p, int val, char let){
	NO *p1;
	p1 = malloc(sizeof(NO));
	if (*p == NULL){
		p1->dado = val;
		p1->letra = let;
		p1->proxno = NULL;
		*p = p1;
	} else if (p1 != NULL){
		p1->dado = val;
		p1->letra = let;
		p1->proxno = *p;
		*p = p1;
	}
}

void add_nofinal(NO *p, int val, char let){
	NO *p1;
	p1 = malloc(sizeof(NO));
	p1->dado = val;
	p1->letra = let;
	while (p->proxno != NULL){
		p = p->proxno;
	}
	p->proxno = p1;
	p1->proxno = NULL;
}

void add_nomeio (NO *p, int val, int posi){
	NO *p1 = NULL;
	int i=0;
	int j = num_no(p);
	
	p1 = malloc(sizeof(NO));
	if (posi >= j){
		printf("Error\n");
	} else {
		while (i != posi){
		p = p->proxno;
		i++;
		}
	}
	p1->proxno = p->proxno;
	p1->dado = val;
	p->proxno = p1;
}

void rmv_noinicio(NO **p){
	NO *p1 = NULL;
	p1 = *p;

	if (p1 != NULL){
		p1 = p1->proxno;
		free(*p);
	}
	*p = p1;
}

void rmv_nofinal(NO *p){
	NO *p1 = NULL, *p2 = NULL;
	p1 = p;

	while (p1->proxno != NULL){
		p2 = p1;
		p1 = p1->proxno;
	}
	free(p1);
	p2->proxno = NULL;
}

void conc_no(NO *l1, NO *l2){
	while (l1->proxno != NULL){
		l1 = l1->proxno;
	}
	l1->proxno = l2;
}

int main(void) {
  NO *no1 = NULL;

	add_noinicio(&no1, 5, 'A');
	mostrar_lista(no1);
  return 0;
}