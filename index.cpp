#include <iostream>
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

void menu()
{
    char choice; //Escolha

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
    cout << "" << endl;

    cin >> choice; //Pega escolha do usuário

    switch (choice) //Switch de acordo com a escolha do usuário
    {
    case 'a':
        break;
    case 'b':
        break;
    case 'c':
        break;
    case 'd':
        break;
    case 'e':
        break;
    case 'f':
        break;
    case 'g':
        break;
    case 'h':
        break;
    case 'i':
        break;
    };
};

int main()
{
    menu(); // Inicializar o menu
};
