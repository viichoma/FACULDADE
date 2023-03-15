#include <iostream>
using namespace std;
int main() {
    int i, j, g, n;
    cin >> n >> g;

    if ( n > 0 && n < 21 && g > 0 && g < 256) // Regras
    {
        int alt = 8 * n, larg = 8 * n, aux;
        int xadrex[alt][larg]; // Matriz da board com os tamanhos

        cout << "P2" << endl << alt << "\t" << larg << endl << g << endl; // Regras pro pgm
        for (i = 0; i < (alt / n); i++) // Mudar posição da matriz, divido por n pq é a escala dos quadrados
        {
            for (int k = 0; k < n; k++) // fazer duas linhas iguais
            {
                for (j = 0; j < (larg / n); j++) // Mudar posição da matriz, divido por n pq é a escala dos quadrados
                {
                    if ((i + j) % 2 == 0) { // se a posição for par, o quadrado é branco
                        for (aux = 0; aux < n; aux++) // for para printar a cor n vezes do tamanho
                        {
                            xadrex[i][j] = g;
                            cout << xadrex[i][j] << "\t";
                        }
                    } else
                    {
                        for (aux = 0; aux < n; aux++) // for para printar a cor n vezes do tamanho
                        {
                            xadrex[i][j] = 0;
                            cout << xadrex[i][j] << "\t";
                        }
                    }
                }
                cout << "\t" << endl; // tab e quebra de linha após fim da linha
            }
        }
    }
}