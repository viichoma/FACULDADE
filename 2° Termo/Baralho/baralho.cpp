#include <iostream>
using namespace std;
int main()
{
    int p;
	cin >> p;
        if (p >=2 && p <= (2 * 100000))
		{
        int pos = 2, cont = 1; // Posição da carta já embaralhada // Contador
		while (pos != 1) // Enquanto a carta n volta a sua origem
		{
            int media = (p/2);
			if (pos <= media) 
            {pos += pos;}
			else 
            {pos -= (p - pos + 1);}
			cont++;
		}
		cout << cont << endl;
        }
	
}

//Padrao do Embaralhamento
//Se a posição da carta for menor ou igual a metade do baralho, a nova posição da carta será 2 * posicaoAtual.
//Senao: posicaoAtual – (tamanhoBaralho- posicaoAtual + 1), ou seja, 2 * posicaoAtual – 1 – tamanhoBaralho.
//Se uma carta volta a sua ordem original, todo o baralho estara em ordem.
