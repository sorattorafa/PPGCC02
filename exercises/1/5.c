/*
Faça um programa em c++ que:
- Leia um inteiro n(2 ≤n ≤3), crie e leia uma estrutura que é uma matriz quadrada de
ordem n, contendo sua dimensão e seus elementos.
- Crie a matriz adjunta da matriz lida. A matriz adjunta é composta pelos cofatores da matriz
geradora. O cofator do elemento Aijé o determinante da matriz que se obtém eliminando-se
as linhas ie jda matriz original. Exemplo de cálculo do cofator do elemento
*/
#include <stdio.h>

#define MAX_DIM 3

typedef struct {
    int dim;
    int elements[MAX_DIM][MAX_DIM];
} Matrix;

int determinant(Matrix matrix) {
    int det = 0;
    if (matrix.dim == 2) {
        det = matrix.elements[0][0] * matrix.elements[1][1] - matrix.elements[0][1] * matrix.elements[1][0];
    } else if (matrix.dim == 3) {
        det = matrix.elements[0][0] * (matrix.elements[1][1] * matrix.elements[2][2] - matrix.elements[1][2] * matrix.elements[2][1]) -
              matrix.elements[0][1] * (matrix.elements[1][0] * matrix.elements[2][2] - matrix.elements[1][2] * matrix.elements[2][0]) +
              matrix.elements[0][2] * (matrix.elements[1][0] * matrix.elements[2][1] - matrix.elements[1][1] * matrix.elements[2][0]);
    }
    return det;
}

Matrix adjoint(Matrix matrix) {
    Matrix adj;
    adj.dim = matrix.dim;

    for (int i = 0; i < matrix.dim; i++) {
        for (int j = 0; j < matrix.dim; j++) {
            Matrix temp;
            temp.dim = matrix.dim - 1;
            int row = 0;
            for (int k = 0; k < matrix.dim; k++) {
                if (k == i) continue;
                int col = 0;
                for (int l = 0; l < matrix.dim; l++) {
                    if (l == j) continue;
                    temp.elements[row][col] = matrix.elements[k][l];
                    col++;
                }
                row++;
            }
            int sign = ((i + j) % 2 == 0 ? 1 : -1);
            adj.elements[j][i] = sign * determinant(temp);
        }
    }

    return adj;
}

int main() {
    Matrix matrix;
    printf("Enter matrix dimension (2 or 3): ");
    scanf("%d", &matrix.dim);

    printf("Enter matrix elements: \n");
    for (int i = 0; i < matrix.dim; i++) {
        for (int j = 0; j < matrix.dim; j++) {
            scanf("%d", &matrix.elements[i][j]);
        }
    }

    Matrix adj = adjoint(matrix);

    printf("Adjoint matrix: \n");
    for (int i = 0; i < matrix.dim; i++) {
        for (int j = 0; j < matrix.dim; j++) {
            printf("%d ", adj.elements[i][j]);
        }
        printf("\n");
    }

    return 0;
}