#include <stdio.h>

#define tam 100

int tamanho(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        i += 1;
    }
    return i;
}

void conc_cadeia(char strg1[], char strg2[], char strg3[])
{
    int i = 0, j = 0;
    while (strg1[i] != '\0')
    {
        strg3[j] = strg1[i];
        i += 1;
        j += 1;
    }

    i = 0;

    while (strg2[i] != '\0')
    {
        strg3[j] = strg2[i];
        i += 1;
        j += 1;
    }

    strg3[j] = '\0';
    printf("%s", strg3);
}

void rmv_cadeia(char F[], char R[], int inicio, int numcar)
{
    int i = 0, j = 0, s;
    while (F[i] != '\0')
    {
        if (i == inicio)
        {
            j = i;
            while (j != (i + numcar) - 1)
            {
                j++;
            }
            j = j + 1;
        }
        R[i] = F[j];
        i++;
        j++;
    }
    R[i] = '\0';
    //printf("%s", R);
}

void ins_cadeia(char strA[], char strB[], char strC[], int posi)
{
    int i = 0, j = 0;

    while (i < posi)
    {
        strC[i] = strA[i];
        i++;
    }

    while (strB[j] != '\0')
    {
        strC[i] = strB[j];
        i++;
        j++;
    }

    while (strA[posi] != '\0')
    {
        strC[i] = strA[posi];
        posi++;
        i++;
    }

    strA[i] = '\0';

    //printf("%s", strC);
}

void comp_cadeia(char str1[], char str2[])
{
    int i = 0, cont = 0;

    if (tamanho(str1) != tamanho(str2))
    {
        printf("Cadeias diferentes");
    }
    else
    {
        for (i = 0; i <= tamanho(str1); i++)
        {
            if (str1[i] == str2[i])
            {
                cont++;
            }
        }
        if (cont == tamanho(str1))
        {
            printf("Cadeias Diferentes");
        }
        else
        {
            printf("Cadeias Iguas");
        }
    }
}

void sub_cadeia(char inteiro[], int ind, int numcar, char corte[])
{
    int i = 0, j = 0, k = 0;
    while (inteiro[i] != '\0')
    {
        if (i == ind)
        {
            k = ind;
            for (j = 0; j < numcar; j++)
            {
                corte[j] = inteiro[k];
                k++;
            }
        }
        i++;
    }
    corte[j] = '\0';
    printf("%s\n", corte);
}

void subst_cadeia(char fonte[], char s1[], char s2[])
{
    rmv_cadeia(fonte, s2, 4, 5);
    printf("%s\n", s2);
    ins_cadeia(fonte, s1, s2, 4);
    printf("%s\n", s2);

}

int main(void)
{
    int op = 99, a, b;
    char str1[tam], str2[tam], str3[tam];

    while (op != 0)
    {
        printf("\n\n---ESCOLHA UMA OPÇÃO---\n");
        printf("[ 1 ] - Concatenar Cadeia\n");
        printf("[ 2 ] - Remover Cadeia\n");
        printf("[ 3 ] - Inserir Cadeia\n");
        printf("[ 4 ] - Comparar Cadeia\n");
        printf("[ 5 ] - Retirar Subcadeia\n");
        printf("[ 6 ] - Substituir Cadeia\n");
        printf("[ 0 ] - Sair\n");
        printf("-> ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Digite uma frase: ");
            scanf(" %[^\n]", str1);
            setbuf(stdin, NULL);
            printf("Digite outra frase: ");
            scanf(" %[^\n]", str2);
            setbuf(stdin, NULL);
            printf("\n");
            conc_cadeia(str1, str2, str3);
            break;
        case 2:
            printf("Digite uma frase: ");
            scanf(" %[^\n]", str1);
            setbuf(stdin, NULL);
            printf("Digite o ponto de corte: ");
            scanf(" %d", &a);
            printf("Digite a quantidade a ser cortada: ");
            scanf(" %d", &b);
            printf("\n");
            rmv_cadeia(str1, str2, a, b);
            break;
        case 3:
            printf("Digite uma frase: ");
            scanf(" %[^\n]", str1);
            setbuf(stdin, NULL);
            printf("Digite outra frase: ");
            scanf(" %[^\n]", str2);
            setbuf(stdin, NULL);
            printf("Digite o ponto de inserção: ");
            scanf(" %d", &a);
            printf("\n");
            ins_cadeia(str1, str2, str3, a);
            break;
        case 4:
            printf("Digite uma frase: ");
            scanf(" %[^\n]", str1);
            setbuf(stdin, NULL);
            printf("Digite outra frase: ");
            scanf(" %[^\n]", str2);
            setbuf(stdin, NULL);
            printf("\n");
            comp_cadeia(str1, str2);
            break;
        case 5:
            printf("Digite uma frase: ");
            scanf(" %[^\n]", str1);
            setbuf(stdin, NULL);
            printf("Digite o ponto de corte: ");
            scanf(" %d", &a);
            printf("Digite a quantidade a ser cortada: ");
            scanf(" %d", &b);
            printf("\n");
            sub_cadeia(str1, a, b, str2);
            break;
        case 6:
            printf("Digite uma frase: ");
            scanf(" %[^\n]", str1);
            setbuf(stdin, NULL);
            printf("Digite outra frase: ");
            scanf(" %[^\n]", str2);
            setbuf(stdin, NULL);

            subst_cadeia(str1, str2, str3);

        case 0:
            printf("Programa Finalizado\n");
            break;
        default:
            printf("Opção Inválida\nTente Novamente\n");
            printf("-> ");
            scanf("%d", &op);
            break;
        }
    }
    return 0;
}