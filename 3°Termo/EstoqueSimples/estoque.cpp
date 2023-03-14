#include <iostream>
using namespace std;

struct Produto
{
    char nome[30];
    int codigo;
    double preco;
};
void printarlista(Produto x)
{
    cout << "Nome: " << x.nome << endl;
    cout << "Codigo: " << x.codigo << endl;
    cout << fixed; cout.precision(2);
    cout << "Preço: R$ " << x.preco << endl;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    Produto estoque[10];
    int tamest = 2;
    estoque[0] = {"Pé de Moleque", 13205, 0.20};
    estoque[1] = {"Cocada Baiana", 15202, 0.50};
    while(1)
    {
    printf("\nSistema de Estoque \nEscolha a Opçao Desejada\n");
    printf("\n1. Verificar Estoque (%d Produtos) \n2. Adicionar ao Estoque (Limite de 10 Produtos)\n", tamest);
    printf("3. Verificar Produto \n4. Encerrar Programa\n");

    int escolha; cin >> escolha;
    if (escolha == 1)
    {
        for(int i =0; i<tamest;i++)
        {
            cout << i+1 << ". " <<  estoque[i].nome << endl;
        }
    }
    else if (escolha == 2)
    {
        if(tamest < 10)
        {
        cout << "Insira o nome do produto:" << endl;
        Produto prod; cin >> prod.nome;
        cout << "Insira o codigo do produto:" << endl;
        cin >> prod.codigo;
        cout << "Insira o preço do produto" << endl;
        cin >> prod.preco;
        estoque[tamest++] = prod;
        
        }
        else
        cout << "Estoque cheio" << endl;
    }
    else if (escolha == 3)
    {
    cout << "Insira o numero do produto que deseja verificar" << endl;
        int verificar; cin >> verificar;
        printarlista(estoque[verificar-1]);
    }
    else if (escolha == 4)
    {
    cout << endl <<  "O Sistema está encerrando" << endl;
    break;
    }
    }
}