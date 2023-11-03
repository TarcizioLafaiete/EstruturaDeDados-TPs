#ifndef CELULA_HPP
#define CELULA_HPP
#include <iostream>
#include <string>
#include "jogador.hpp"
class celulaJogador{
    public:
    celulaJogador();
    jogador* getJogador();
    void setJogador(jogador *player);
    private:
    jogador *player;
    celulaJogador *prox; //Ponteiro para o proximo da fila
    friend class listaJogadores;
};  
#endif