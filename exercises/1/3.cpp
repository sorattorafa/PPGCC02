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

int main() {
    // declaração da matriz 12x4
    int vendas[12][4];

    // preenchimento da matriz e cálculo dos totais
    int totalMes[12] = {0};
    int totalSemana[4] = {0};
    int totalAno = 0;
    for (int i = 0; i < 12*4; i++) {
        int mes = i / 4;
        int semana = i % 4;
        cout << "Informe as vendas do mes " << mes+1 << " semana " << semana+1 << ": ";
        cin >> vendas[mes][semana];
        totalMes[mes] += vendas[mes][semana];
        totalSemana[semana] += vendas[mes][semana];
        totalAno += vendas[mes][semana];
    }

    // impressão dos totais
    cout << "Total vendido em cada mes do ano:" << endl;
    for (int i = 0; i < 12; i++) {
        cout << "Mes " << i+1 << ": R$ " << totalMes[i] << endl;
    }

    cout << "Total vendido em cada semana durante todo o ano:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Semana " << i+1 << ": R$ " << totalSemana[i] << endl;
    }

    cout << "Total vendido no ano: R$ " << totalAno << endl;

    return 0;
}