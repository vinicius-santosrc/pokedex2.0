#include <iostream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

// 0. Disponibilizar um menu inicial que forneça as seguintes opções para o usuário : a.Cadastrar cidade;
// b.Cadastrar estrada;
// c.Buscar centro Pokémon mais próximo;
// d.Cadastrar Pokémon;
// e.Remover Pokémon;
// f.Listar Pokémons(ordem alfabética de nome);
// g.Listar Pokémons(ordem alfabética de tipo);
// h.Contar Pokémons de cada tipo;
// i.Encontrar Pokémons próximos;

enum EscolhasEnum
{
    CadastrarCidade = 'a',
    CadastrarEstrada = 'b',
    BuscarCentroProximo = 'c',
    CadastrarDino = 'd',
    RemoverDino = 'e',
    ListarDinoPorNome = 'f',
    ListarDinoPorTipo = 'g',
    ContarDinos = 'h',
    EncontrarDinoPorTipo = 'i',
    Sair = 'j'
};

void cadastrarCidade()
{
    cout << "Cadastrar cidade em desenvolvimento" << endl;
};

void cadastrarEstrada()
{
    cout << "Cadastrar estrada em desenvolvimento" << endl;
};

void buscarCentroProximo()
{
    cout << "Buscar dinos em desenvolvimento" << endl;
};

void cadastrarDino()
{
    cout << "Cadastrar dinos em desenvolvimento" << endl;
};

void removerDino()
{
    cout << "Remoção de dinos em desenvolvimento" << endl;
};

void listarDinos(string filtragem)
{
    if (filtragem == "nome")
    {
        // Pelo Nome
        cout << "Filtragem por nome em desenvolvimento" << endl;
    }
    else
    {
        // Pelo Tipo
        cout << "Filtragem por tipo em desenvolvimento" << endl;
    }
};

void contarDinos()
{
    cout << "Contagem de dinos em desenvolvimento" << endl;
};

void encontrarDinosProximos()
{
    cout << "Encontrar dinos proximos em desenvolvimento" << endl;
};

void sair()
{
    exit(0);
}

void limparTela()
{
    #ifdef _WIN32
        system("pause");
        system("cls");
    #else
        cout << "Pressione ENTER para continuar...";
        cin.ignore();
        cin.get();
        system("clear");
        system("clear");
    #endif
}

void menu()
{
    char choice; // Escolha

    while (true)
    {
        cout << "Escolha uma dentre as opções abaixo:" << endl;
        cout << "" << endl;
        cout << "a.Cadastrar cidade" << endl;
        cout << "b.Cadastrar estrada" << endl;
        cout << "c.Buscar centro arqueológico mais próximo" << endl;
        cout << "d.Cadastrar Dinossauro" << endl;
        cout << "e.Remover Dinossauro" << endl;
        cout << "f.Listar Dinossauro(ordem alfabética de nome)" << endl;
        cout << "g.Listar Dinossauro(ordem alfabética de tipo)" << endl;
        cout << "h.Contar Dinossauro de cada tipo" << endl;
        cout << "i.Encontrar Dinossauro próximos" << endl;
        cout << "j. Sair" << endl;
        cout << "" << endl;

        cin >> choice; // Pega escolha do usuário

        switch (choice) // Switch de acordo com a escolha do usuário
        {
        case CadastrarCidade:
            cadastrarCidade();
            break;
        case CadastrarEstrada:
            cadastrarEstrada();
            break;
        case BuscarCentroProximo:
            buscarCentroProximo();
            break;
        case CadastrarDino:
            cadastrarDino();
            break;
        case RemoverDino:
            removerDino();
            break;
        case ListarDinoPorNome:
            listarDinos("nome");
            break;
        case ListarDinoPorTipo:
            listarDinos("tipo");
            break;
        case ContarDinos:
            contarDinos();
            break;
        case EncontrarDinoPorTipo:
            encontrarDinosProximos();
            break;
        case Sair:
            sair();
            break;
        }

        limparTela();
    }
};

int main()
{
    menu(); // Inicializar o menu
};
