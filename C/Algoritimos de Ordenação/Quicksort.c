#include <stdio.h>

//Função para achar o pivo e separar os elementos da esquerda e direita do pivo
int particionar(int vetor[], int inicio, int fim){
    int esq, dir, pivo, aux;
    esq = inicio;  // esq pega o inicio de vetor
    dir = fim;  // dir pega o fim do vetor
    pivo = vetor[inicio];  //O pivo começa no inicio do vetor
    while (esq < dir){
        while ((esq <= fim) && (vetor[esq] <= pivo)){
            esq++; // Corre o vetor da esquerda pra direita até achar um elemnto que seja maior que o pivo
        }
        while ((dir >= 0) && (vetor[dir] > pivo)){
            dir--; // Corre o vetor da direita para esquerda até achar um elemnto que seja menor que o pivo
        }
        if (esq <= dir){ // Se a esquerda do pivo for maior que a direita do pivo
            aux = vetor[esq]; // Troca os dois de lugar
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;
        }
    }
    vetor[inicio] = vetor[dir]; // O inicio pega aonde a direita parou
    vetor[dir] = pivo; // E trca de lugar com o pivo

    return dir; // Retorna a posição do pivo
}

void quickSort(int vetor[], int inicio, int fim){
    int pivo;
    if (fim > inicio){
        pivo = particionar(vetor, inicio, fim); //Acha a posição do Pivo
        quickSort(vetor, inicio, pivo-1); //Recursividade para os valores antes do pivo
        quickSort(vetor, pivo+1, fim); //Recursividade para os valores depois do pivo
    }
}

int main(void){

    int tam = 10;
    int vet[10] = {5, 9, 4, 7, 6, 2, 3, 8, 1, 3};

    system("cls");
    
    //Print do vetor desodernado
    for(int i=0; i<tam; i++){
        printf("[%d]", vet[i]);
    }

    quickSort(vet, 0, 9);
    printf("\n");

    //Print do vetor Ordenado
    for(int i=0; i<tam; i++){
        printf("[%d]", vet[i]);
    }

    return 0;
}