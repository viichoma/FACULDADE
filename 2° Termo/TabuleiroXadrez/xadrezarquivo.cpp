#include <iostream>
#include <fstream>

using namespace std;
int main() {
    // Tamanho do quadrado e da grau de cor do cinza
    int n, g;
    cin >> n >> g;
    if ( n > 0 && n < 21 && g > 0 && g < 256) {
        int larg = 8 * n, alt = 8 * n;
        //Definir matrizes que sao os quadrados
        int preto[larg][alt], branco[larg][alt];
        //Variaveis auxiliares
        int i, j, k
        //Adicionar  cor aos quadrados
        for (int i = 0; i < larg; i++) {
            for (int j = 0; j < alt; j++) {
                preto[i][j] = 0;
                branco[i][j] = g;
            }
        }
        // Criar Arquivo
        ofstream xadrez("xadrez.pgm");
        //Escrever no arquivo
        xadrez << "P2" << endl;
        xadrez << larg << "\t"<< alt << endl;
        xadrez << g << endl;
        //For para imprimir as cores
        for (i = 0; i < alt; i++)
        {
            for (j = 0; j < larg; j++)
            {
                for (k = 0; k < n; k++) // Laço para o tamanho dos cubos
                {
                    if ((i + j) % 2 == 0) // Se par = branco, senao preto
                    {
                        xadrez << branco[i][j] << "\t";
                    } else
                    {
                        xadrez << preto[i][j] << "\t";
                    }
                }
            }


        }
        xadrez.close(); // fechar arquivo
        return 0;
    } else return 1;
}