#include <stdio.h>
typedef struct Cadastro
{
    char sexo;
    char nome[20];
    int idade;
}Cadastro;

int main(void)
{
    Cadastro cad[10];
    int i, idF=0, idM=0;

    for (i = 0;  i < 10; i++)
    {
        system("cls");
        printf("CADASTRO\n");
        printf("Pessoa Nº%i\n", i+1);
        printf("Digite o Nome: ");
        scanf(" %[^\n]", cad[i].nome);
        getchar();
        printf("Digite o sexo [m/f]: ");
        scanf("%c", &cad[i].sexo);
        printf("Digite a idade: ");
        scanf(" %d", &cad[i].idade);
        if (cad[i].sexo == 'f')
        {
            idF += 1;
        } 
        else 
        {
            idM += 1;
        }
    }
    
    for (i = 0; i < 10; i++)
    {
        printf("[Nome: %s] [Sexo: %c] [idade: %d]\n", cad[i].nome, cad[i].sexo, cad[i].idade);
    }

    printf("\nForam inseridos %d individuos do sexo Masculino e %d do sexo Feminino\n", idM, idF);
    
    system("pause");
    return 0;
}
