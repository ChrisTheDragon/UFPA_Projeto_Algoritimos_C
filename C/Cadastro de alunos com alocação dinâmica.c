#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
    char nome[30];
	int mat;
	float nota1, nota2, nota3, media;
	struct Aluno *proxno;
}Aluno;

void cadastrar(Aluno **p){
	Aluno *p1 = NULL, *p2 = NULL;
    float m = 0;
    if (*p == NULL){
        p1 = malloc(sizeof(Aluno));
        printf("NOME: ");
        scanf(" %[^\n]", p1->nome);
        getchar();
        printf("MATRICULA: ");
        scanf("%d", &p1->mat);
        printf("NOTA 1: ");
        scanf("%f", &p1->nota1);
        printf("NOTA 2: ");
        scanf("%f", &p1->nota2);
        printf("NOTA 3: ");
        scanf("%f", &p1->nota3);
        m = (p1->nota1 + p1->nota2 + p1->nota3)/3;
        p1->media = m;
        printf("MÉDIA: %.2f\n", p1->media);
        p1->proxno = NULL;
        *p = p1;
    } else {
        p2 = malloc(sizeof(Aluno));
        p1 = *p;
        while (p1->proxno != NULL){
            p1 = p1->proxno;
        }
        printf("NOME: ");
        scanf(" %[^\n]", p2->nome);
        printf("MATRICULA: ");
        scanf("%d", &p2->mat);
        printf("NOTA 1: ");
        scanf("%f", &p2->nota1);
        printf("NOTA 2: ");
        scanf("%f", &p2->nota2);
        printf("NOTA 3: ");
        scanf("%f", &p2->nota3);
        m = (p2->nota1 + p2->nota2 + p2->nota3)/3;
        p2->media = m;
        printf("MÉDIA: %.2f\n", p2->media);
        p2->proxno = NULL;
        p1->proxno = p2;
    }
}

void mostrar(Aluno *p) {
    while (p != NULL){
        printf("NOME:      %s\n", p->nome);
        printf("MATRICULA: %i\n", p->mat);
        printf("NOTA 1:    %.2f\n", p->nota1);
        printf("NOTA 2:    %.2f\n", p->nota2);
        printf("NOTA 3:    %.2f\n", p->nota3);
        printf("MÉDIA:     %.2f\n", p->media);
        printf("========================");
        p = p->proxno;
    }
}

int main(void) {
    int op;
    int con = 1;
    Aluno *no1 = NULL;

    printf("=====MENU=====\n");
    printf("[ 1 ] - Cadastrar\n");
    printf("[ 2 ] - Mostrar\n");
    printf("-> ");
	scanf("%i", &op);

    if (op == 1) {
        while (con == 1) {
            cadastrar(&no1);
            printf("Cadastrar mais um?\n");
            printf("[ 1 ] - SIM\n[ 2 ] - Não\n-> ");
            scanf("%d", &con);
            if (con == 2) {
                main();
            }
        }
    } else if (op == 2) {
        mostrar(no1);
    }
  return 0;
}