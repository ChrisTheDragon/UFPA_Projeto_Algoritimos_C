#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *proxno;
}NO;

typedef struct lista{
    NO *inicio;
    NO *fim;
    int tam;
}Lista;

void cirar_lista(Lista *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->tam = 0;
}

void mostrar_lista(Lista l){
    NO *p1 = l.inicio;
    printf("Lista tam: %d\n", l.tam);
    if (p1){
        do{
            printf("[%d] ", p1->dado);
            p1 = p1->proxno;
        }while(p1 != l.inicio);
    }
    printf("\n");
}

void add_no(Lista *l, int val){
    NO *p1 = malloc(sizeof(NO));
    p1->dado = val;

    if (l->inicio == NULL){
        l->inicio = p1;
        l->fim = p1;
        l->fim->proxno = l->inicio;
    } else {
        l->fim->proxno = p1;
        l->fim = p1;
        p1->proxno = l->inicio;
    }
    l->tam += 1;
}

int main(){
    Lista l;

    cirar_lista(&l);
    add_no(&l, 2);
    add_no(&l, 5);
    add_no(&l, 7);
    add_no(&l, 9);
    add_no(&l, 2);
    add_no(&l, 6);
    add_no(&l, 4);
    add_no(&l, 3);

    mostrar_lista(l);
    return 0;
}
