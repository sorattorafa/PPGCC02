/*
 Escrever um programa em c++ que leia dois vetores de mesma dimensão (n). 
 Para isso, o programa lê a dimensão dos vetores e seus elementos, uma a um.
  O programa gera um terceiro vetor de dimensão 2n, cujos elementos são resultantes da intercalação dos vetores originais. 
  O programa imprime todos os vetores. Por exemplo, considerando V1 e V2, obtemos V3:
v1: 1 3 5 7 9 11
v2: 2 4 6 8 10 12
v3: 1 2 3 4 5 6 7 8 9 10 11 12
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Digite a dimensao dos vetores: ";
    cin >> n;

    int v1[n], v2[n], v3[2*n];

    // leitura dos elementos do primeiro vetor
    cout << "Digite os elementos do primeiro vetor:\n";
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }

    // leitura dos elementos do segundo vetor
    cout << "Digite os elementos do segundo vetor:\n";
    for (int i = 0; i < n; i++) {
        cin >> v2[i];
    }

    // intercalação dos vetores
    for (int i = 0, j = 0; i < n; i++, j += 2) {
        v3[j] = v1[i];
        v3[j+1] = v2[i];
    }

    // impressão dos vetores
    cout << "Vetor 1: ";
    for (int i = 0; i < n; i++) {
        cout << v1[i] << " ";
    }
    cout << endl;

    cout << "Vetor 2: ";
    for (int i = 0; i < n; i++) {
        cout << v2[i] << " ";
    }
    cout << endl;

    cout << "Vetor 3: ";
    for (int i = 0; i < 2*n; i++) {
        cout << v3[i] << " ";
    }
    cout << endl;

    return 0;
}
