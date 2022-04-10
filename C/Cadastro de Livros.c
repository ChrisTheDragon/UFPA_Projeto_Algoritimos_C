#include <stdio.h>

typedef struct dados{
    char nome[20];
    char autor[30];
    unsigned int isbn;
    float preco;
}dados;

void cadastrar (dados livros[10]){
    int op=0;
    printf("CADASTRO\n");
    printf("Digite os seguintes dados: \n");
    for (int i=0; i<10; i++){

        printf("Livro %iº\n", i+1);

        printf("NOME = ");
        scanf(" %[^\n]", &livros[i].nome);
        getchar();

        printf("AUTOR = ");
        scanf(" %[^\n]", &livros[i].autor);
        getchar();

        printf("ISBN = ");
        scanf(" %i", &livros[i].isbn);

        printf("PREÇO = ");
        scanf(" %f", &livros[i].preco);
    }
}

int pesquisa (unsigned int isbn, dados livros[10], int *a) 
{
    for (int i = 0; i < 10; i++)
    {
        if (isbn == livros[i].isbn)
        {
            *a = i;
            return 1;
        }
    }
    return 0;
}

int main(void) {
    dados livros[10];
    unsigned int isbn;
    int i;
    
    cadastrar(livros);

    printf("Digite o ISBN do livro: ");
    scanf("%d", &isbn);
    if (pesquisa(isbn, livros, &i))
    {
        printf("Livro encontrado!\n");
        printf("Nome = %s\nAutor = %s", livros[i].nome, livros[i].autor);
    } else {
        printf("Livro não encontrado");
    }
    return 0;
}
