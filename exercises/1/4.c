/*
 Faça um programa em c++ que contenha um menu com as seguintes opções:
A. Ler uma string S1 (tamanho máximo 20 caracteres);
B. Imprimir o tamanho da string S1;
C. Comparar a string S1 com uma nova string S2 fornecida pelo usuário e imprimir o resultado
da comparação;
D. Concatenar a string S1 com uma nova string S2 e imprimir na tela o resultado da
concatenação;
E. Imprimir a string S1 de forma reversa;
F. Contar quantas vezes um dado caractere aparece na string S1. Esse caractere desse ser
informado pelo usuário;
G. Substituir a primeira ocorrência do caractere C1 da string S1 pelo caractere C2. Os caracteres
C1 e C2 serão digitados pelo usuário;
H. Verificar se uma string S2 e substring de S1. A string S2 deve ser informada pelo usuário;
I. 9. Retornar uma substring da string S1. Para isso o usuário deve informar a partir de qual
posição deve ser criada a substring e qual é o tamanho da substring
*/
#include <stdio.h>
#include <string.h>

#define MAX_LEN 20

int main()
{
    char s1[MAX_LEN + 1], s2[MAX_LEN + 1], c1, c2;
    int option, pos, len, count;

    do
    {
        printf("\n\nMENU\n");
        printf("1. Ler uma string S1 (tamanho maximo 20 caracteres)\n");
        printf("2. Imprimir o tamanho da string S1\n");
        printf("3. Comparar a string S1 com uma nova string S2 fornecida pelo usuario e imprimir o resultado da comparacao\n");
        printf("4. Concatenar a string S1 com uma nova string S2 e imprimir na tela o resultado da concatenacao\n");
        printf("5. Imprimir a string S1 de forma reversa\n");
        printf("6. Contar quantas vezes um dado caractere aparece na string S1\n");
        printf("7. Substituir a primeira ocorrencia do caractere C1 da string S1 pelo caractere C2\n");
        printf("8. Verificar se uma string S2 e substring de S1\n");
        printf("9. Retornar uma substring da string S1\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\nDigite a string S1: ");
            scanf("%s", s1);
            break;
        case 2:
            printf("\nTamanho de S1: %ld\n", strlen(s1));
            break;
        case 3:
            printf("\nDigite a string S2: ");
            scanf("%s", s2);
            if (strcmp(s1, s2) == 0)
            {
                printf("As strings sao iguais\n");
            }
            else
            {
                printf("As strings sao diferentes\n");
            }
            break;
        case 4:
            printf("\nDigite a string S2: ");
            scanf("%s", s2);
            strcat(s1, s2);
            printf("String concatenada: %s\n", s1);
            break;
        case 5:
            printf("\nString S1 em ordem reversa: ");
            for (int i = strlen(s1) - 1; i >= 0; i--)
            {
                printf("%c", s1[i]);
            }
            printf("\n");
            break;
        case 6:
            printf("\nDigite um caractere: ");
            scanf(" %c", &c1);
            count = 0;
            for (int i = 0; i < strlen(s1); i++)
            {
                if (s1[i] == c1)
                {
                    count++;
                }
            }
            printf("O caractere %c aparece %d vez(es) na string S1\n", c1, count);
            break;
        case 7:
            printf("\nDigite o caractere C1: ");
            scanf(" %c", &c1);
            printf("Digite o caractere C2: ");
            scanf(" %c", &c2);
            for (int i = 0; i < strlen(s1); i++)
            {
                if (s1[i] == c1)
                {
                    s1[i] = c2;
                    break;
                }
            }
            printf("Nova string: %s\n", s1);
            break;
        case 8:
            printf("\nDigite a string S2: ");
            scanf("%s", s2);
            if (strstr(s1, s2) != NULL)
            {
                printf("A string S2 e uma substring de S1\n");
            }
            else
            {
                printf("A string S2 nao e uma substring de S1\n");
            }
            break;
        case 9:
            printf("\nDigite a posicao inicial: ");
            scanf("%d", &pos);
            printf("Digite o tamanho da substring: ");
            scanf("%d", &len);
            if (pos < 0 || pos >= strlen(s1) || len < 0 || len > strlen(s1) - pos)
            {
                printf("Erro: posicao ou tamanho invalidos\n");
            }
            else
            {
                char substring[MAX_LEN + 1];
                strncpy(substring, s1 + pos, len);
                substring[len] = '\0';
                printf("Substring: %s\n", substring);
            }
            break;
        case 0:
            printf("\nEncerrando o programa...\n");
            break;
        default:
            printf("\nOpcao invalida. Tente novamente.\n");
        }
    } while (option != 0);

    return 0;
}