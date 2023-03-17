/* 
Uma empresa classifica seus funcionários em 3 níveis de acordo com um índice de produtividade. 
São eles: (1) Excelente, (2) Intermediário e (3) Regular. Cada nível adiciona ou subtrai uma porcentagem do funcionário, 
de acordo com a tabela abaixo ( cada item da tabela é separado por vírgula):

1, Excelente, +65% do salário base
2 , Intermediário, +20% do salário base
3, Regular, -10% do salário base


Crie um programa na linguagem C que leia o salário base e o índice de produtividade 
de um funcionário (um número inteiro de 1 a 3). Em seguida, o programa deve calcular
 e imprimir o salário com o abono, seguindo a tabela a seguir. Crie uma função para calcular o salário
*/

#include <stdio.h>

float calcularSalario(int indiceProdutividade, float salarioBase);

int main()
{
    int indiceProdutividade;
    float salarioBase, salarioFinal;

    printf("Digite o salário base: ");
    scanf("%f", &salarioBase);

    printf("Digite o índice de produtividade (1 - Excelente, 2 - Intermediário, 3 - Regular): ");
    scanf("%d", &indiceProdutividade);

    salarioFinal = calcularSalario(indiceProdutividade, salarioBase);

    printf("O salário final é R$%.2f\n", salarioFinal);

    return 0;
}

float calcularSalario(int indiceProdutividade, float salarioBase)
{
    float salarioFinal;

    switch (indiceProdutividade)
    {
        case 1:
            salarioFinal = salarioBase * 1.65;
            break;
        case 2:
            salarioFinal = salarioBase * 1.20;
            break;
        case 3:
            salarioFinal = salarioBase * 0.90;
            break;
        default:
            printf("Índice de produtividade inválido.\n");
            salarioFinal = salarioBase;
    }

    return salarioFinal;
}

