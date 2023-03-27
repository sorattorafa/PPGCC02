/*
Faça um programa em c++ que:
- Leia um inteiro n(2 ≤n ≤3), crie e leia uma estrutura que é uma matriz quadrada de
ordem n, contendo sua dimensão e seus elementos.
- Crie a matriz adjunta da matriz lida. A matriz adjunta é composta pelos cofatores da matriz
geradora. O cofator do elemento Aijé o determinante da matriz que se obtém eliminando-se
as linhas ie jda matriz original. Exemplo de cálculo do cofator do elemento
*/
#include <iostream>
#include <cmath>

using namespace std;

// Função que calcula o determinante de uma matriz quadrada de ordem n
float determinante(int n, float **matriz)
{
    float det = 0;
    int sinal = 1;
    if (n == 1)
    {
        det = matriz[0][0];
    }
    else
    {
        for (int k = 0; k < n; k++)
        {
            float **submatriz = new float *[n - 1];
            for (int i = 0; i < n - 1; i++)
            {
                submatriz[i] = new float[n - 1];
            }
            for (int i = 1; i < n; i++)
            {
                int j_aux = 0;
                for (int j = 0; j < n; j++)
                {
                    if (j != k)
                    {
                        submatriz[i - 1][j_aux] = matriz[i][j];
                        j_aux++;
                    }
                }
            }
            det += sinal * matriz[0][k] * determinante(n - 1, submatriz);
            sinal *= -1;
            for (int i = 0; i < n - 1; i++)
            {
                delete[] submatriz[i];
            }
            delete[] submatriz;
        }
    }
    return det;
}

// Função que calcula o cofator de um elemento A[i][j] de uma matriz quadrada de ordem n
float cofator(int n, float **matriz, int i, int j)
{
    float **submatriz = new float *[n - 1];
    for (int k = 0; k < n - 1; k++)
    {
        submatriz[k] = new float[n - 1];
    }
    int i_aux = 0;
    for (int k = 0; k < n; k++)
    {
        if (k != i)
        {
            int j_aux = 0;
            for (int l = 0; l < n; l++)
            {
                if (l != j)
                {
                    submatriz[i_aux][j_aux] = matriz[k][l];
                    j_aux++;
                }
            }
            i_aux++;
        }
    }
    float cof = pow(-1, i + j) * determinante(n - 1, submatriz);
    for (int k = 0; k < n - 1; k++)
    {
        delete[] submatriz[k];
    }
    delete[] submatriz;
    return cof;
}

// Função que imprime a matriz adjunta de uma matriz quadrada de ordem n
void matriz_adjunta(int n, float **matriz)
{
    float **adj = new float *[n];
    for (int i = 0; i < n; i++)
    {
        adj[i] = new float[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj[j][i] = cofator(n, matriz, i, j);
        }
    }
    cout << "Matriz adjunta:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] adj[i];
    }
    delete[] adj;
}

int main()
{
    int n;
    cout << "Digite a ordem da matriz (entre 2 e 3): ";
    cin >> n;
    float *matriz = new float[n];
    for (int i = 0; i < n; i++)
    {
        matriz[i] = new float[n];
    }
    cout << "Digite os elementos da matriz:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matriz[i][j];
        }
    }
    matriz_adjunta(n, matriz);
    for (int i = 0; i < n; i++)
    {
        delete[] matriz[i];
    }
    delete[] matriz;
    return 0;
}