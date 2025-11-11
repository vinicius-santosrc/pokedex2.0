#ifndef DINOSTRATEGY_H
#define DINOSTRATEGY_H
#include <iostream>
#include <string>
#include <list>
#include <cmath>
#include <complex>
using namespace std;

struct Pokemon {
    string nome;
    string tipo;
    int numero;
    int x, y;
};

struct node {
    Pokemon dados;
    node *esquerda = nullptr;  //cidade anterior
    node *direita = nullptr; //proxima cidade
};

node * raiz = nullptr;

node * criarNo(Pokemon p);

node * inserirNaArvore(node *no, Pokemon p){
    if(no == NULL){
        return criarNo(p);
    }
    if((p.nome < no -> dados.nome)){
        no -> esquerda = inserirNaArvore(no -> esquerda, p);
    }else if(p.nome > no -> dados.nome) {
        no -> direita = inserirNaArvore (no -> direita, p);
    }else {
        cout << "Erro: Pokemon com o nome '" << p.nome << "' ja existe." << endl;
    }

    return no;
}

void listarPorNomeEmOrdem(node* no) {
    if(no != NULL) {
        listarPorNomeEmOrdem(no->esquerda);
        cout << " - Nome: " << no->dados.nome << ", Tipo: " << no->dados.tipo << ", Numero: " << no->dados.numero<< ", Coordenadas: (" << no->dados.x << ", " << no->dados.y << ")" << endl;
        listarPorNomeEmOrdem(no->direita);
    }
}

node* encontrarMenor(node* no) {
    while(no && no->esquerda != NULL) {
        no = no->esquerda;
    }
    return no;
}

node* removerDaArvore(node* no, string nome) {
    if (no == NULL) {
        cout << "Erro: Pokemon com o nome '" << nome << "' nao encontrado." << endl;
        return no;
    }

    if (nome < no->dados.nome) {
        no->esquerda = removerDaArvore(no->esquerda, nome);
    } else if (nome > no->dados.nome) {
        no->direita = removerDaArvore(no->direita, nome);
    } else {
        // No encontrado
        if (no->esquerda == NULL) {
            node* temp = no->direita;
            delete no;
            return temp;
        } else if (no->direita == NULL) {
            node* temp = no->esquerda;
            delete no;
            return temp;
        }

        // No com dois filhos
        node* temp = encontrarMenor(no->direita);
        no->dados = temp->dados;
        no->direita = removerDaArvore(no->direita, temp->dados.nome);
    }
}

void coletarTodos(node *no, list<Pokemon>& lista){
    if( no != NULL) {
        coletarTodos(no -> esquerda, lista);
        lista.push_back(no -> dados);
        coletarTodos(no -> direita, lista);
    }
}

void cadastrarPokemon() {
    Pokemon p;
    cout << "Digite o nome do Pokemon: ";
    cin.ignore();
    getline(cin >> ws, p.nome);
    cout << "Digite o tipo do Pokemon: ";
    getline(cin >> ws, p.tipo);
    cout << "Digite o numero do Pokemon: ";
    cin >> p.numero;
    cout << "Digite a coordenada X do Pokemon: ";
    cin >> p.x;
    cout << "Digite a coordenada Y do Pokemon: ";
    cin >> p.y;

    raiz = inserirNaArvore(raiz, p);
    cout << "Pokemon '" << p.nome << "' cadastrado com sucesso!" << endl;
}

void listarPokemonsPeloNome() {
    cout << "--- Lista de Pokemons (Ordenados por Nome) ---" << endl;
    if (raiz == NULL) {
        cout << "Nenhum Pokemon cadastrado." << endl;
    } else {
        listarPorNomeEmOrdem(raiz);
    }
    cout << "-----------------------------------------------" << endl;
}

bool compararPorTipo(const Pokemon &a, const Pokemon &b) {
    return a.tipo < b.tipo;
}

void listarPokemonsPorTipo() {
    if (raiz == NULL) {
        cout << "Nenhum Pokemon cadastrado." << endl;
        return;
    }

    list<Pokemon> listaPokemons;
    coletarTodos(raiz, listaPokemons);
    listaPokemons.sort(compararPorTipo);

    cout << "\n--- Lista de Pokemons por Tipo ---" << endl;
    for (const auto &p : listaPokemons) {
        cout << " - Nome: " << p.nome
             << ", Tipo: " << p.tipo
             << ", Numero: " << p.numero
             << ", Coordenadas: (" << p.x << ", " << p.y << ")" << endl;
    }
    cout << "----------------------------------\n" << endl;
}

void contarPokemons() {
    cout << "--- Contagem de Pokemons por Tipo---" << endl;
    if(raiz == nullptr)
    {
    cout << "Nenhum Pokemon cadastrado." << endl;
    return;
    }
    
    list<Pokemon> todosPokemons;
    
    coletarTodos(raiz, todosPokemons);
    
    todosPokemons.sort(compararPorTipo);

    string tipoAtual = todosPokemons.front().tipo;
    int contador = 0;

    for(list<Pokemon>::const_iterator it = todosPokemons.begin(); it != todosPokemons.end(); ++it) {
        if(it->tipo == tipoAtual) {
            contador++;
        } else {
            cout << "Tipo: " << tipoAtual << " | quantidade" << contador << endl;
            tipoAtual = it->tipo;
            contador = 1;
        }
    }
    cout << "Tipo: " << tipoAtual << " | quantidade: " << contador << endl;
    cout << "-----------------------------------\n" << endl;
}
    void encontrarPokemonsProximos() {
    
    if (raiz == NULL) {
        cout << "Nenhum Pokemon cadastrado." << endl;
        return;
    }

    int x, y , raio;
    cout << "--- Encontrar Pokemons Proximos ---" << endl;
    cout << "Digite sua localizacao (X): ";
    cin >> x;
    cout << "Digite sua localizacao (Y): ";
    cin >> y;
    cout << "Digite o raio de busca (ex: 50): ";
    cin >> raio;

    list<Pokemon> todosPokemons;
    coletarTodos(raiz, todosPokemons);

    cout << "\nPokemons encontrados dentro do raio de " << raio << "Km" << endl;
    bool encontrado = false;

    for(list<Pokemon>::const_iterator it = todosPokemons.begin(); it != todosPokemons.end(); ++it) {
        double dist = sqrt(pow(it->x - x, 2) + pow(it->y - y, 2));
        if (dist <= raio) {
            cout << " - " << it->nome << " (Tipo: " << it->tipo << ") a " << dist << " unidades." << endl;
            encontrado = true;
        }
    }
    if(!encontrado) {
        cout << "Nenhum Pokemon encontrado dentro do raio especificado." << endl;
        cout << "-----------------------------------\n" << endl;
    }
}

void removerPokemon() {
    string nome;
    cout << "--- Remover Pokemon ---" << endl;
    cout << "Digite o nome do Pokemon a ser removido: ";
    cin.ignore();
    getline(cin >> ws, nome);

    
    raiz = removerDaArvore(raiz, nome);
    cout << "\nPokemon '" << nome << "' removido (se existia)." << endl;
}


#endif