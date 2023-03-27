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

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1, s2;
    char c1, c2;
    int op, pos, tam, count;

    do
    {
        cout << "MENU:\n";
        cout << "1. Ler uma string S1\n";
        cout << "2. Imprimir o tamanho da string S1\n";
        cout << "3. Comparar a string S1 com uma nova string S2\n";
        cout << "4. Concatenar a string S1 com uma nova string S2\n";
        cout << "5. Imprimir a string S1 de forma reversa\n";
        cout << "6. Contar quantas vezes um dado caractere aparece na string S1\n";
        cout << "7. Substituir a primeira ocorrência do caractere C1 da string S1 pelo caractere C2\n";
        cout << "8. Verificar se uma string S2 é substring de S1\n";
        cout << "9. Retornar uma substring da string S1\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> op;

        switch (op)
        {
        case 1:
            cout << "Digite a string S1 (tamanho máximo 20 caracteres): ";
            cin >> s1;
            break;
        case 2:
            cout << "Tamanho da string S1: " << s1.size() << endl;
            break;
        case 3:
            cout << "Digite a nova string S2: ";
            cin >> s2;
            if (s1 == s2)
            {
                cout << "As strings S1 e S2 são iguais.\n";
            }
            else
            {
                cout << "As strings S1 e S2 são diferentes.\n";
            }
            break;
        case 4:
            cout << "Digite a nova string S2: ";
            cin >> s2;
            s1 += s2;
            cout << "String concatenada: " << s1 << endl;
            break;
        case 5:
            cout << "String S1 em ordem reversa: ";
            for (int i = s1.size() - 1; i >= 0; i--)
            {
                cout << s1[i];
            }
            cout << endl;
            break;
        case 6:
            cout << "Digite o caractere a ser contado: ";
            cin >> c1;
            count = 0;
            for (int i = 0; i < s1.size(); i++)
            {
                if (s1[i] == c1)
                {
                    count++;
                }
            }
            cout << "O caractere '" << c1 << "' aparece " << count << " vezes na string S1.\n";
            break;
        case 7:
            cout << "Digite o caractere a ser substituído: ";
            cin >> c1;
            cout << "Digite o novo caractere: ";
            cin >> c2;
            pos = s1.find(c1);
            if (pos != string::npos)
            {
                s1[pos] = c2;
                cout << "String após substituição: " << s1 << endl;
            }
            else
            {
                cout << "Caractere não encontrado na string S1.\n";
            }
            break;
        case 8:
            cout << "Digite a string S2 a ser verificada: ";
            cin >> s2;
            if (s1.find(s2) != string::npos)
            {
                cout << "A string S2 é uma substring de S1.\n";
            }
            else
            {
                cout << "A string S2 não é uma substring de S1.\n";
            }
            break;
        case 9:
            cout << "Digite a posição inicial da substring: ";
            cin >> pos;
            cout << "Digite o tamanho da substring: ";
            cin >> tam;
            if (pos + tam <= s1.size())
            {
                string sub = s1.substr(pos, tam);
                cout << "Substring: " << sub << endl;
            }
            else
            {
                cout << "A substring ultrapassa o tamanho da string S1.\n";
            }
            break;
        case 0:
            cout << "Saindo...\n";
            break;
        default:
            cout << "Opção inválida. Tente novamente.\n";
            break;
        }
    } while (op != 0);

    return 0;
}