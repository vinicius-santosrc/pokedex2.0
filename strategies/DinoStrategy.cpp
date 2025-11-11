#include "DinoStrategy.h"

node * criarNo(Pokemon p) {
    node* novoNo = new node;
    novoNo->dados = p;
    novoNo->esquerda = nullptr;
    novoNo->direita = nullptr;
    return novoNo;
}