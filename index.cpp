/*Nomes - Matricula - Curso
    Anna Beatriz da Silva Bitencur - 753 - GES
    Vinicius da Silva Santos - 637 - GEs
    Petrus de Souza Matos Pfaffenbach - 627 - GES
    Marcelo Henrique da Silva Costa - 628 - Ges
    Maria Eduarda Constância Rocha Moreira - 710 - GES
*/

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include "strategies/CityStrategy.h"
#include "strategies/StreetStrategy.h"
#include "strategies/CloseCenter.h"
#include "strategies/DinoStrategy.h"
#include <list>

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

void cadastrarCidadeIndex()
{
    cadastrarCidade();
};

void cadastrarEstradaIndex()
{
    cadastrarEstrada();
};

void buscarCentroProximoIndex()
{
    CentroProximo();
};

void cadastrarPokemonIndex()
{
    cadastrarPokemon();
};

void removerPokemonIndex()
{
    removerPokemon();
};

void listarPokemonsIndex(string filtragem)
{
    if (filtragem == "nome")
    {
        // Pelo Nome
        listarPokemonsPeloNome();
    }
    else
    {
        // Pelo Tipo
        listarPokemonsPorTipo();
    }
};

void contarPokemonsIndex()
{
    contarPokemons();
};

void encontrarPokemonsProximosIndex()
{
    encontrarPokemonsProximos();
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
        cout << "Escolha uma dentre as opcoes abaixo:" << endl;
        cout << "" << endl;
        cout << "a.Cadastrar cidade" << endl;
        cout << "b.Cadastrar estrada" << endl;
        cout << "c.Buscar centro Pokemon mais proximo" << endl;
        cout << "d.Cadastrar Pokemon" << endl;
        cout << "e.Remover Pokemon" << endl;
        cout << "f.Listar Pokemon(ordem alfabetica de nome)" << endl;
        cout << "g.Listar Pokemo(ordem alfabetica de tipo)" << endl;
        cout << "h.Contar Pokemon de cada tipo" << endl;
        cout << "i.Encontrar Pokemon proximos" << endl;
        cout << "j. Sair" << endl;
        cout << "" << endl;

        cin >> choice; // Pega escolha do usuário

        switch (choice) // Switch de acordo com a escolha do usuário
        {
        case CadastrarCidade:
            cadastrarCidadeIndex();
            break;
        case CadastrarEstrada:
            cadastrarEstradaIndex();
            break;
        case BuscarCentroProximo:
            buscarCentroProximoIndex();
            break;
        case CadastrarDino:
            cadastrarPokemonIndex();
            break;
        case RemoverDino:
            removerPokemonIndex();
            break;
        case ListarDinoPorNome:
            listarPokemonsIndex("nome");
            break;
        case ListarDinoPorTipo:
            listarPokemonsIndex("tipo");
            break;
        case ContarDinos:
            contarPokemonsIndex();
            break;
        case EncontrarDinoPorTipo:
            encontrarPokemonsProximosIndex();
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

/*nova  entrega:
  - faz lista de adjacencia
  - dijkstra
*/