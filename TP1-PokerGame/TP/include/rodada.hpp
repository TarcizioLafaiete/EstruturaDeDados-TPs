#ifndef RODADA_HPP
#define RODADA_HPP
#include <iostream>
#include <string>
#include "jogador.hpp"
#include "celula.hpp"
#include "lista.hpp"
class rodada{
    public:
    rodada(int participantes,int pingo);
    rodada();
    void montaPote(int *apostaJogadores);
    void insereJogadorRodada(jogador *j1);
    std::string jogadaVencedora();
    int numeroVencedores();
    listaJogadores Vencedores();
    int valorGanho();
    void limpaVencedores();
    private:
    //Metodos privados
    void decideGanhador();
    void criteriosDesempateCartaJogada(int jogada_);
    void criteriosDesempateCartaForte(int jogada_);
    void criteriosDesempateCarteFinal(int jogada_);
    //Variaveis privadas
    listaJogadores lj1;
    listaJogadores ljGanhadores;
    int participantes;
    int pingo;
    int pote;
    friend class jogo;
};
#endif