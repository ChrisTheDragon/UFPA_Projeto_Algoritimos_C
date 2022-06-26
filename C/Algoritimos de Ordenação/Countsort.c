#include <stdio.h>

#define MAX 50

void countSort(int vetor[], int tam_vet){
    int i, j, k;
    int aux[MAX]; //vetor que será usado como indice para os valores

    for (i=0; i < MAX; i++){
        aux[i] = 0; //Enche o vetor auxiliar com 0;
    }

    for (i =0; i < tam_vet; i++){
        aux[vetor[i]]++; //Trata o valor do vetor como indice do aux e incrementa toda vez que aquele valor aparecer
    }

    for (i=0, j=0; j < MAX; j++){ //Percorre os dois vetores
        for (k = aux[j]; k > 0; k--){ //pega o valor do vetor usado como indice e coloca em k
            vetor[i++] = j; //incrementa os valores de acordo com J
        }
    }
}

int main (void){
    int tam = 10;
    int vet[10] = {5, 9, 4, 7, 6, 2, 3, 8, 1, 3};

    system("cls");

    //Print do vetor desodernado
    for(int i=0; i<tam; i++){
        printf("[%d]", vet[i]);
    }

    countSort(vet, 10);
    printf("\n");

    //Print do vetor Ordenado
    for(int i=0; i<tam; i++){
        printf("[%d]", vet[i]);
    }

    return 0;
}