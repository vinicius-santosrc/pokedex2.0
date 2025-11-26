#ifndef STREET_STRATEGY_H
#define STREET_STRATEGY_H

#include <iostream>
#include <list>
#include "CityStrategy.h"

using namespace std;

struct Aresta {
    int destino;
    int peso;
};

list<Aresta> lista_adj[MAX_CIDADES];

void cadastrarEstrada() {
    if (numCidades < 2) {
        cout << "E necessario ter pelo menos duas cidades cadastradas para criar uma estrada." << endl;
        return;
    }

    int idOrigem, idDestino, peso;

    cout << "Abaixo estao as cidades disponiveis:" << endl;
    listarCidades();

    cout << "Digite o ID da cidade de origem: ";
    cin >> idOrigem;
    cout << "Digite o ID da cidade de destino: ";
    cin >> idDestino;
    cout << "Digite a distancia (peso) da estrada: ";
    cin >> peso;

    if (idOrigem >= numCidades || idDestino >= numCidades || idOrigem < 0 || idDestino < 0) {
        cout << "Erro: ID de cidade invalido." << endl;
        return;
    }

    Aresta arestaOrigem;
    arestaOrigem.destino = idDestino;
    arestaOrigem.peso = peso;
    lista_adj[idOrigem].push_back(arestaOrigem);
    
    Aresta arestaDestino;
    arestaDestino.destino = idOrigem;
    arestaDestino.peso = peso;
    lista_adj[idDestino].push_back(arestaDestino);

    cout << "\nEstrada entre '" << cidades[idOrigem].nome << "' e '" << cidades[idDestino].nome << "' cadastrada com sucesso!" << endl;
}

#endif