/*
Criar um programa que carregue uma matriz 12 × 4 com os valores das vendas de uma loja,
em que cada linha represente um mês do ano, e cada coluna, uma semana do mês. Para fins de
simplificação considere que cada mês possui somente 4 semanas. Calcule e imprima:
    - Total vendido em cada mês do ano;
    - Total vendido em cada semana durante todo o ano;
    - Total vendido no ano.
*/

#include <stdio.h>

int main() {
    int vendas[12][4]; // matriz 12x4 para armazenar as vendas
    int total_mes[12] = {0}; // vetor para armazenar o total vendido em cada mês
    int total_semana[4] = {0}; // vetor para armazenar o total vendido em cada semana
    int total_ano = 0; // variável para armazenar o total vendido no ano
    int i, j;

    // Laço para ler as vendas de cada mês e semana
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 4; j++) {
            printf("Digite o valor vendido na semana %d do mês %d: ", j+1, i+1);
            scanf("%d", &vendas[i][j]);
            total_mes[i] += vendas[i][j]; // acumula o total vendido no mês
            total_semana[j] += vendas[i][j]; // acumula o total vendido na semana
            total_ano += vendas[i][j]; // acumula o total vendido no ano
        }
    }

    // Imprime o total vendido em cada mês
    printf("Total vendido em cada mês:\n");
    for (i = 0; i < 12; i++) {
        printf("Mês %d: R$ %d\n", i+1, total_mes[i]);
    }

    // Imprime o total vendido em cada semana
    printf("Total vendido em cada semana:\n");
    for (j = 0; j < 4; j++) {
        printf("Semana %d: R$ %d\n", j+1, total_semana[j]);
    }

    // Imprime o total vendido no ano
    printf("Total vendido no ano: R$ %d\n", total_ano);

    return 0;
}