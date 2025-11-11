#ifndef CITY_STRATEGY_H
#define CITY_STRATEGY_H

#include <iostream>
#include <string>

using namespace std;

const int MAX_CIDADES = 100; // Define um numero maximo de cidades

// Estrutura para armazenar os dados de cada cidade
struct Cidade {
    int id;
    string nome;
    bool temCentroPokemon;
};

// Vetor global para armazenar as cidades e contador
Cidade cidades[MAX_CIDADES];
int numCidades = 0;

// Funcao para listar cidades existentes para facilitar a escolha do usuario
void listarCidades() {
    cout << "\n--- Cidades Cadastradas ---" << endl;
    if (numCidades == 0) {
        cout << "Nenhuma cidade cadastrada." << endl;
    } else {
        for (int i = 0; i < numCidades; ++i) {
            cout << "ID: " << cidades[i].id << " | Nome: " << cidades[i].nome;
            if (cidades[i].temCentroPokemon) {
                cout << " (Possui Centro Pokemon)";
            }
            cout << endl;
        }
    }
    cout << "---------------------------\n" << endl;
}


// Funcao para cadastrar uma nova cidade
void cadastrarCidade() {
    if (numCidades >= MAX_CIDADES) {
        cout << "Erro: Numero maximo de cidades atingido." << endl;
        return;
    }

    Cidade novaCidade;
    novaCidade.id = numCidades;

    cout << "Digite o nome da nova cidade: ";
    cin.ignore();
    getline(cin >> ws, novaCidade.nome);


    char resposta;
    cout << "A cidade '" << novaCidade.nome << "' possui um centro Pokemon? (s/n): ";
    cin >> resposta;
    novaCidade.temCentroPokemon = (resposta == 's' || resposta == 'S');

    cidades[numCidades] = novaCidade;
    numCidades++;

    cout << "\nCidade '" << novaCidade.nome << "' cadastrada com sucesso com o ID " << novaCidade.id << "!" << endl;
}

#endif