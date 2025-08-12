#include <iostream>
#include <stdlib.h>
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

void menu()
{
    char choice; // Escolha
    cout << "Escolha uma dentre as opções abaixo:" << endl;
    cout << "" << endl;
    cout << "a.Cadastrar cidade" << endl;
    cout << "b.Cadastrar estrada" << endl;
    cout << "c.Buscar centro Pokémon mais próximo" << endl;
    cout << "d.Cadastrar Pokémon" << endl;
    cout << "e.Remover Pokémon" << endl;
    cout << "f.Listar Pokémons(ordem alfabética de nome)" << endl;
    cout << "g.Listar Pokémons(ordem alfabética de tipo)" << endl;
    cout << "h.Contar Pokémons de cada tipo" << endl;
    cout << "i.Encontrar Pokémons próximos" << endl;
    cout << "j. Sair" << endl;
    cout << "" << endl;

    while (true)
    {
        cin >> choice; // Pega escolha do usuário

        switch (choice) // Switch de acordo com a escolha do usuário
        {
        case 'a':
            cadastrarCidade();
            break;
        case 'b':
            cadastrarEstrada();
            break;
        case 'c':
            buscarCentroProximo();
            break;
        case 'd':
            cadastrarDino();
            break;
        case 'e':
            removerDino();
            break;
        case 'f':
            listarDinos("nome");
            break;
        case 'g':
            listarDinos("tipo");
            break;
        case 'h':
            contarDinos();
            break;
        case 'i':
            encontrarDinosProximos();
            break;
        case 'j':
            sair();
            break;
        }
    }
};

int main()
{
    menu(); // Inicializar o menu
};
