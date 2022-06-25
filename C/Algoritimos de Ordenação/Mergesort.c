#include <stdio.h>

//Faz a Ordenação com a intercalação
void merge(int vetor[], int aux[], int esq, int meio, int dir){
    int i, esq_fim, pos_aux, num_elem;

    esq_fim = meio-1; //Divide o vetor no meio, onde esq_fim pega a ultima posição do subvetor da esquerda
    pos_aux = esq; //Posição auxiliar pega a primeira posição da esquerda
    num_elem = dir - esq + 1; // numero de elementos do vetor

    while ((esq <= esq_fim) && (meio <=dir)){ //varre os dois subvetores [inicio até o meio]|[meio até o final]
        if (vetor[esq] <= vetor[meio]){ // Testa de o valor do vetor da esquerda é menor que o valor do vetor da direita
            aux[pos_aux] = vetor[esq]; // Se for menor, ele vai para o vetor auxiliar
            pos_aux += 1; // E o vetor auxiliar e da esqeurda andam uma casa
            esq += 1;  
        } else { // Se o valor do vetor da direita é menor, ele vai para a auxiliar
            aux[pos_aux] = vetor[meio];
            pos_aux += 1; // e ambos os vetors andam uma casa
            meio += 1;
        }
    }

    // Se restar valores não testados no vetor, eles vão para o auxliar
    while (esq <= esq_fim){ 
        aux[pos_aux] = vetor[esq];
        esq += 1;
        pos_aux += 1;
    }
    while (meio <= dir){
        aux[pos_aux] = vetor[meio];
        meio += 1;
        pos_aux += 1;
    }

    //Apos a ordenação, o vetor original pega os numeros ordenados do vetor auxiliar
    for (i=0; i < num_elem; i++){ 
        vetor[dir] = aux[dir];
        dir -= 1;
    }
}

//Faz a divisão do vetor e a chamada por recursividade
void ordenar (int vetor[], int aux[], int esq, int dir){
    int meio;
    if (dir > esq) { 
        meio = (dir+esq) / 2; // tira o meio do vetor
        ordenar(vetor, aux, esq, meio); // Recursividade que vai dividindo o vetor varias vezes no meio criando subvetores na parte esquerda
        ordenar(vetor, aux, meio+1, dir); //Mesma recursividade pra parte direita
        merge(vetor, aux, esq, meio+1, dir); //chamada pra ordenar a parte que foi dividida no meio
    }
}

//Função que vai ser chamada na Função main
void mergeSort (int vetor[], int aux[], int tam){
    ordenar(vetor, aux, 0, tam-1); //Passa o vetor e o auxiliar que o usuario informa
                                   //Passa o indice esquerdo como 0, por ser o primeiro indice
                                   //Passa o indice direito como o tamanho do vetor menos 1, já que começa em 0
}

int main(void){

    int tam = 10;
    int vet[10] = {5, 9, 4, 7, 6, 2, 3, 8, 1, 3}; 
    int aux[tam];

    system("cls");
    
    //Print do vetor desodernado
    for(int i=0; i<tam; i++){
        printf("[%d]", vet[i]);
    }

    mergeSort(vet, aux, tam);
    printf("\n");

    //Print do vetor Ordenado
    for(int i=0; i<tam; i++){
        printf("[%d]", vet[i]);
    }

    return 0;
}