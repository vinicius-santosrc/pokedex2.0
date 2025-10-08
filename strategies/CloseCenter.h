#ifndef CLOSE_CENTER_H
#define CLOSE_CENTER_H

#include <iostream>
#include <list>
#include "StreetStrategy.h"

using namespace std;

const int INFINITO = 999;

// Funcao auxiliar para imprimir o caminho encontrado
void imprimirCaminho(int pred[], int destino) {
    if (pred[destino] == -1) { // chegou na origem 
        cout << cidades[destino].nome;
        return;
    }
    imprimirCaminho(pred, pred[destino]);
    cout << " -> " << cidades[destino].nome;
}

// Funcao principal que busca o centro mais próximo usando Dijkstra
void CentroProximo() {
    if (numCidades == 0) {
        cout << "Nenhuma cidade cadastrada." << endl;
        return;
    }

    int idOrigem;
    cout << "Abaixo estão as cidades disponiveis:" << endl;
    listarCidades();
    cout << "Digite o ID da sua cidade atual: ";
    cin >> idOrigem;

    if (idOrigem < 0 || idOrigem >= numCidades) {
        cout << "Erro: ID de cidade invalido." << endl;
        return;
    }
    
    if (cidades[idOrigem].temCentroPokemon) {
        cout << "Voce ja esta em uma cidade com um Centro Pokedex!" << endl;
        return;
    }

    int dist[MAX_CIDADES];
    int pred[MAX_CIDADES];
    bool visitado[MAX_CIDADES];

    // 1. Inicialização
    for (int i = 0; i < numCidades; ++i) {
        dist[i] = INFINITO;
        pred[i] = -1;
        visitado[i] = false;
    }
    dist[idOrigem] = 0;

    // 2. Algoritmo de Dijkstra
    for (int count = 0; count < numCidades - 1; ++count) {
        int u = -1;
        int min_dist = INFINITO;
        for (int i = 0; i < numCidades; i++) {
            if (!visitado[i] && dist[i] <= min_dist) {
                min_dist = dist[i];
                u = i;
            }
        }
        
        if (u == -1) break; // sse não há mais vértices alcançáveis

        visitado[u] = true;

        // Atualiza a distância dos vértices adjacentes
        for (list<Aresta>::const_iterator it = lista_adj[u].begin(); it != lista_adj[u].end(); ++it) {
            const Aresta& aresta = *it;
            int v = aresta.destino;
            int peso = aresta.peso;
            if (!visitado[v] && dist[u] != INFINITO && dist[u] + peso < dist[v]) {
                dist[v] = dist[u] + peso;
                pred[v] = u;
            }
        }
    }

    // 3. Encontra o centro mais próximo entre os alcançados
    int menorDistancia = INFINITO;
    int idCentroMaisProximo = -1;

    for (int i = 0; i < numCidades; ++i) {
        if (cidades[i].temCentroPokemon && dist[i] < menorDistancia) {
            menorDistancia = dist[i];
            idCentroMaisProximo = i;
        }
    }

    // 4. Exibe o resultado
    if (idCentroMaisProximo != -1) {
        cout << "\n--- Resultado ---" << endl;
        cout << "O Centro Pokemon mais proximo esta em: " << cidades[idCentroMaisProximo].nome << endl;
        cout << "Distancia total: " << menorDistancia << " kilometros" << endl;
        cout << "Rota a ser seguida: ";
        imprimirCaminho(pred, idCentroMaisProximo);
        cout << "\n-----------------" << endl;
    } else {
        cout << "\nNao foi encontrado um Centro Pokemon alcancavel a partir da sua localizacao." << endl;
    }
}

#endif