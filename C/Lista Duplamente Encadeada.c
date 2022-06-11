#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct NO *proxno;
    struct NO *antno;
}NO;

void mostrar_lista(NO *p, int dir){
	if (dir == 1) {
        while (p != NULL){
            printf("[%d]->", p->dado);
            p = p->proxno;
        }
    } else if (dir == 2) {
        while (p->proxno != NULL){
            p = p->proxno;
        }
        while (p->antno != NULL){
            printf("[%d]<-", p->dado);
            p = p->antno;
        }
    }
}

void add_no(NO **p, int val){
    NO *p1 = NULL, *p2 = NULL;

    if (*p == NULL){
        p1 = malloc(sizeof(NO));
        p1->dado = val;
        p1->antno = NULL;
        p1->proxno = NULL;
        *p = p1;
    } else {
        p2 = malloc(sizeof(NO));
        p1 = *p;
        while (p1->proxno != NULL){
            p1 = p1->proxno;
        }
        p2->dado = val;
        p2->antno = p1;
        p2->proxno = NULL;
        p1->proxno = p2;
    }
}

int main(){
    NO *p = NULL;

    add_no(&p, 10);
    add_no(&p, 20);
    add_no(&p, 40);
    add_no(&p, 80);
    add_no(&p, 100);
    add_no(&p, 220);
    mostrar_lista(p, 2);
    printf("\n");
    mostrar_lista(p, 1);

    
    return 0;
}