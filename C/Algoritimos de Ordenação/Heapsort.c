#include <stdio.h>

//Cria a arovore e define os pais e filhos
void criaHeap(int vetor[], int inicio, int fim) {
    int aux = vetor[inicio];  //Variavel auxiliar inicia com o valor da primeira posição do vetor e se torna o pai
    int filho = inicio*2+1;  //Primieiro filho dessa posição
    while (filho <= fim) { //Enquando o filho for menor que o fim do vetor
        if (filho < fim){
            if (vetor[filho] < vetor[filho+1]){  //Se o segundo filho for maior
                filho += 1;
            }
        }
        if (aux < vetor[filho]){ //Se o pai for maior que o filho
            vetor[inicio] = vetor[filho]; //O valor do filho vai para a posição do pai
            inicio = filho; //O filho se torna o pai
            filho = (2 * inicio) + 1; //Primeiro filho do novo pai
        } else {
            filho = fim + 1; //Se não houver mais filhos maiores que o pai
        }
    }
    vetor[inicio] = aux; //A ultima posição analisada pega o valor do primeiro pai
}

//Ordena a arvore criada
void heapSort (int vetor[], int N){
    int i, aux;
    for (i = (N-1)/2; i >= 0; i--){ //Cria a Heap da metade do vetor até a primeira posição
        criaHeap(vetor, i, N-1);
    }
    for (i = N-1; i >= 1; i--){ //Pega o elemento do topo da arvore e coloca na ultima posição
        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        criaHeap(vetor, 0, i-1); //Recosntroi a Heap
    }
}

int main(void) {
    int tam = 10;
    int vet[10] = {5, 9, 4, 7, 6, 2, 3, 8, 1, 3};

    system("cls");

    //Print do vetor desodernado
    for(int i=0; i<tam; i++){
        printf("[%d]", vet[i]);
    }

    heapSort(vet, 10);
    printf("\n");

    //Print do vetor Ordenado
    for(int i=0; i<tam; i++){
        printf("[%d]", vet[i]);
    }
    return 0;
}