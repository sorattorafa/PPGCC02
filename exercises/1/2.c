#include <stdio.h>

int main() {
    int n;
    printf("Digite a dimensao dos vetores: ");
    scanf("%d", &n);

    int v1[n], v2[n], v3[2*n];

    // leitura dos elementos do primeiro vetor
    printf("Digite os elementos do primeiro vetor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &v1[i]);
    }

    // leitura dos elementos do segundo vetor
    printf("Digite os elementos do segundo vetor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &v2[i]);
    }

    // intercalação dos vetores
    for (int i = 0, j = 0; i < n; i++, j += 2) {
        v3[j] = v1[i];
        v3[j+1] = v2[i];
    }

    // impressão dos vetores
    printf("Vetor 1: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v1[i]);
    }
    printf("\n");

    printf("Vetor 2: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v2[i]);
    }
    printf("\n");

    printf("Vetor 3: ");
    for (int i = 0; i < 2*n; i++) {
        printf("%d ", v3[i]);
    }
    printf("\n");

    return 0;
}