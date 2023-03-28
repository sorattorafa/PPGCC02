/*
Criar um programa que carregue uma matriz 12 × 4 com os valores das vendas de uma loja,
em que cada linha represente um mês do ano, e cada coluna, uma semana do mês. Para fins de
simplificação considere que cada mês possui somente 4 semanas. Calcule e imprima:
    - Total vendido em cada mês do ano;
    - Total vendido em cada semana durante todo o ano;
    - Total vendido no ano.
*/

#include <iostream>

using namespace std;

#include <stdio.h>

int main()
{ // preenchimento da matriz e cálculo dos totais
    int totalMes[12] = {0};
    int totalSemana[4] = {0};
    int totalAno = 0;
    for (int i = 0; i < 12 * 4; i++)
    {
        int mes = i / 4;
        int semana = i % 4;
        printf("Informe as vendas do mes %d semana %d: ", mes + 1, semana + 1);
        scanf("%d", &vendas[mes][semana]);
        totalMes[mes] += vendas[mes][semana];
        totalSemana[semana] += vendas[mes][semana];
        totalAno += vendas[mes][semana];
    }

    // impressão dos totais
    printf("Total vendido em cada mes do ano:\n");
    for (int i = 0; i < 12; i++)
    {
        printf("Mes %d: R$ %d\n", i + 1, totalMes[i]);
    }

    printf("Total vendido em cada semana durante todo o ano:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("Semana %d: R$ %d\n", i + 1, totalSemana[i]);
    }

    printf("Total vendido no ano: R$ %d\n", totalAno);

    return 0;
}