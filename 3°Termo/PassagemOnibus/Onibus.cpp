#include <iostream>
#include<string.h>
#include <experimental/random>
using namespace std;

struct Passagem
{
    int poltrona;
    int diaida, mesida, diavolta, mesvolta;
    string horárioida, horáriovolta;
    string origem, destino;
    double valor;
};

struct Cliente
{
    Passagem passagem;
    string nome;
    int idade;
};

void listacidades() //Imprimir tabela de cidades
{
    string cidades[8] = {"Ourinhos", "São Paulo", "Assis", "Santa Cruz do Rio Pardo", "Curitiba", "Londrina", "Marília", "Maringá"};
    for(int i=0; i<8; i++)
    {
    cout << i+1 << ". " << cidades[i] << "\t" << i+2 << ". " << cidades[i+1] << endl;
    i++;
    }
}

void listahorarios() //Imprimir tabela de horarios
{
    string horarios[8] = {"06:00", "08:00", "09:30", "11:00", "14:00", "15:00", "18:00", "20:30"};
    for(int i=0; i<8; i++)
    {
    cout << i+1 << ". " << horarios[i] << "\t" << i+2 << ". " << horarios[i+1] << endl;
    i++;
    }
}

int main()
{
    //Arrays para usar como escolhas
    string horarios[8] = {"06:00", "08:00", "09:30", "11:00", "14:00", "15:00", "18:00", "20:30"};
    string cidades[8] = {"Ourinhos", "São Paulo", "Assis", "Santa Cruz do Rio Pardo", "Curitiba", "Londrina", "Marília", "Maringá"};

    Cliente pessoa;

    //while true para confirmar os dados
    while(true)
{
    cout << "Sistema de Compra de Passagem" << endl;
    cout << "\n1. Insira seus dados pessoais" << endl;

    cout << "Digite seu nome completo:" << endl; getline(cin, pessoa.nome);

    while(true)
    {
    cout << "Digite sua idade:" << endl; cin >> pessoa.idade;
    if(pessoa.idade > 6 and pessoa.idade < 110) break;
    else cout << "Idade invalida"  << endl;
    }

    //N° poltrona é gerada aleatoriamente com uma bilbioteca
    pessoa.passagem.poltrona = experimental::randint(1,50);

    while(true)
    {
    cout << "\nQual seu ponto de origem?" << endl;
    listacidades();
    int org; cin >> org;
    if(org < 1 or org > 8)
    {
    cout << "\nEscolha invalida" << endl;
    }
    else
    {
        pessoa.passagem.origem = cidades[org-1];

        cout << "\nQual seu ponto de destino?" << endl;
        listacidades();
        int dest; cin >> dest;
        pessoa.passagem.destino = cidades[dest-1];
        if(dest < 1 or dest > 8)
        {
        cout << "\nEscolha invalida" << endl;
        }
        else
        {
            pessoa.passagem.destino = cidades[dest-1];
        }

        if (pessoa.passagem.origem != pessoa.passagem.destino)
        {
            break;
        }
        else
        {
            cout << "\nOrigem e Destino não podem ser os mesmos" << endl;
        }

    }
    }


    cout << "\nOs dados estão corretos?" << endl;
    cout << "Nome: " << pessoa.nome << endl; 
    cout << "Idade: " << pessoa.idade << " anos" <<  endl; 
    cout << "Origem: " << pessoa.passagem.origem << endl;
    cout << "Destino: " << pessoa.passagem.destino << endl;
    cout << "S / N" << endl;
    string escolha; cin >> escolha; 
    if (escolha == "S" or escolha == "s") break; // Se os dados estiverem corretos prosseguir com o codigo
}

    while(true)
    {
    cout << "\nInsira o dia de partida (dd)" << endl;
    cin >> pessoa.passagem.diaida;
    cout << "\nInsira o mes de partida (mm)" << endl;
    cout << pessoa.passagem.diaida << "/";
    cin >> pessoa.passagem.mesida;
    if(pessoa.passagem.diaida > 0 and pessoa.passagem.diaida <= 31 and pessoa.passagem.mesida > 0 and pessoa.passagem.mesida <= 12)
    break;
    else cout << "Data Invalida" << endl;
    }

    cout << "\nEscolha o horário da sua partida?" << endl;  
    while(true) // Apresentado uma tabela de horarios e o usuario escolhe o horario preferido
    {
    listahorarios();
    int ida; cin >> ida;
    if(ida > 0 and ida <=8)
    {
    pessoa.passagem.horárioida = horarios[ida-1];
    break;
    }
    else cout << "Horario Invalido" << endl;
    }

    cout << "\nAgendar data de retorno?\nS / N" << endl;
    //Se o usuario optar por já comprar a passagem de retorno, será coletado mais informações
    string retorno; cin >> retorno;
    if (retorno == "S" or retorno == "s")
    {
    
    while(true)
    {
    cout << "\nInsira o dia de retorno (dd)" << endl;
    cin >> pessoa.passagem.diavolta;
    cout << "\nInsira o dia de retorno (mm)" << endl;
    cout << pessoa.passagem.diavolta << "/";
    cin >> pessoa.passagem.mesvolta;
    if((pessoa.passagem.diavolta > 0 and pessoa.passagem.diavolta <= 31) and (pessoa.passagem.mesvolta > 0 and pessoa.passagem.mesvolta <= 12))
    {
        if(pessoa.passagem.mesvolta == pessoa.passagem.mesida)
        {
            if(pessoa.passagem.diavolta > pessoa.passagem.diaida)
            {
                break;
            }
            else cout << "\nData Invalida" << endl;
        }
        else if(pessoa.passagem.mesvolta < pessoa.passagem.mesida)
        {
            cout << "\nData Invalida" << endl;
        }
        else break;
    }
    else cout << "\nData Invalida" << endl;
    }
    
    cout << "\nInsira o horário da sua volta?" << endl;
    while(true)
    {
    listahorarios();
    int volta; cin >> volta;
    if(volta > 0 and volta <=8)
    {
    pessoa.passagem.horáriovolta = horarios[volta-1];
    break;
    }
    else cout << "Horario Invalido" << endl;
    }
    }

    //Valor da passagem gerado aleatoriamente, se for ida e volta o valor é dobrado
    pessoa.passagem.valor = experimental::randint(15,100) ;
    if (retorno == "S" or retorno == "s")
    {
    pessoa.passagem.valor *= 2;
    }
    
    //Imprimir as informações da passagem
    cout << "\n-----Sua Passagem-----" << endl;
    cout << "Nome: " << pessoa.nome << endl;
    cout << "Idade: " << pessoa.idade << " anos" << endl;
    cout << "Origem: " << pessoa.passagem.origem << endl;
    cout << "Destino: " << pessoa.passagem.destino << endl;
    cout << "N° de poltrona: " << pessoa.passagem.poltrona << endl;
    cout << "Data de partida: " << pessoa.passagem.diaida << "/" << pessoa.passagem.mesida << endl;
    cout << "Horario de partida: " << pessoa.passagem.horárioida << endl;

    if (retorno == "S" or retorno == "s")
    {
    cout << "Data de volta: " << pessoa.passagem.diavolta << "/" << pessoa.passagem.mesvolta << endl;
    cout << "Horario de volta: " << pessoa.passagem.horáriovolta << endl;
    }

    cout << "Valor da Viagem: R$ " << pessoa.passagem.valor << endl;
}