#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
    char nome[30];
    int mat;
    float nota1, nota2, nota3, media;
    struct No *proxno;
}No;

void mostrar (No *p) {
    printf("ALUNOS CADASTRADOS:\n");
    printf("_______________________\n");
    while (p != NULL) {
        printf("NOME:      %s\n", p->nome);
        printf("MATRICULA: %d\n", p->mat);
        printf("NOTA 1:     %.2f\n", p->nota1);
        printf("NOTA 2:     %.2f\n", p->nota2);
        printf("NOTA 2:     %.2f\n", p->nota3);
        printf("MÉDIA:     %.2f\n", p->media);
        printf("==========================\n");
        p = p->proxno;
    }
}

void add_no (No **p){
    No *p1 = NULL, *p2 = NULL;
    float med;
    p1 = malloc(sizeof(No));
    if (*p == NULL) {
        printf("Nome: ");
        scanf(" %[^\n]", p1->nome);
        getchar();
        printf("Matricula: ");
        scanf("%d", &p1->mat);
        printf("Nota 1: ");
        scanf("%f", &p1->nota1);
        printf("Nota 2: ");
        scanf("%f", &p1->nota2);
        printf("Nota 3: ");
        scanf("%f", &p1->nota3);
        med = (p1->nota1 + p1->nota2 + p1->nota3)/3;
        p1->media = med;
        printf("MÉDIA: %.2f\n", p1->media);
        p1->proxno = NULL;
        *p = p1;
    } else {
        p2 = malloc(sizeof(No));
        p1 = *p;
        while (p1->proxno != NULL){
            p1 = p1->proxno;
        }
        printf("Nome: ");
        scanf(" %[^\n]", p2->nome);
        getchar();
        printf("MAtricula: ");
        scanf("%d", &p2->mat);
        printf("Nota 1: ");
        scanf("%f", &p2->nota1);
        printf("Nota 2: ");
        scanf("%f", &p2->nota2);
        printf("Nota 3: ");
        scanf("%f", &p2->nota3);
        med = (p2->nota1 + p2->nota2 + p2->nota3)/3;
        p2->media = med;
        printf("MÉDIA: %.2f\n", p2->media);
        p2->proxno = NULL;
        p1->proxno = p2;
    }
}

int main (void) {
    No *no1 = NULL;
    int op, con=0;

    printf("CADASTRO: \n");
    do{
        add_no(&no1);
        printf("Cadastrar mais um?\n");
        printf("[ 1 ] - SIM\n[ 2 ] - Não\n-> ");
        scanf("%d", &con);
    }while(con == 1);
    
    mostrar(no1);
        
    return 0;
}
