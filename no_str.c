#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    char let;
    struct no *proxno;
}NO;

void mostra(NO *p){
    while (p != NULL){
        printf("[%c]", p->let);
        p = p->proxno;
    }
}

void add_no(NO **p, char val){
    NO *p1=NULL, *p2=NULL;
    p1 = *p;

    if (p1 == NULL){
        p1 = malloc(sizeof(NO));
        p1->let = val;
        p1->proxno = NULL;
        *p = p1;
    } else {
        while (p1->proxno != NULL){
            p1 = p1->proxno;
        }
        p2 = malloc(sizeof(NO));
        p2->let = val;
        p2->proxno = NULL;
        p1->proxno = p2;
    }
}

int no_len(NO *p1){
    int a = 0;
    while (p1 != NULL){
        a += 1;
        p1 = p1->proxno;
    }
    return a;
}

int no_cmp(NO *p1, NO *p2){
    int a = 0;
    if (no_len(p1) < no_len(p2)){
        return -1;
    } else if (no_len(p1) > no_len(p2)) {
        return 1;
    } else {
        return 0;
    }
}

void no_cat(NO *p1, NO *p2){
    while(p1->proxno != NULL){
        p1 = p1->proxno;
    }
    p1->proxno = p2;
}

int main(){
    NO *no1 = NULL, *no2 = NULL;

    add_no(&no1, 'A');
    add_no(&no1, 'B');
    add_no(&no1, 'C');
    add_no(&no1, 'D');
    add_no(&no1, 'E');
    add_no(&no1, 'F');
    mostra(no1);

    add_no(&no2, 'T');

    printf("\n\n");
    printf("tamanho = %i", no_len(no1));

    printf("\n\n");
    printf("comparando = %i", no_cmp(no1, no2));

    printf("\n\n");
    no_cat(no1, no2);
    mostra(no1);

    printf("\n\n");
    

    return 0;
}
