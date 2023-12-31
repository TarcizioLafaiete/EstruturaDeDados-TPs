#include "../include/celula.hpp"
//===================================================================================================
//                                  CONSTRUTOR DE CLASSE
//===================================================================================================
celulaJogador::celulaJogador(){
    prox = NULL;
    player  = new jogador();
};
//===================================================================================================
//                                  METODO GET JOGADOR
//===================================================================================================
jogador* celulaJogador::getJogador(){
    return this->player;
};
//===================================================================================================
//                                 METODO SET JOGADOR
//===================================================================================================
void celulaJogador::setJogador(jogador *player){
    this->player = player;
};
