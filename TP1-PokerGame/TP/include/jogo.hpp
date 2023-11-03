#ifndef JOGO_HPP
#define JOGO_HPP
#include <iostream>
#include <string>
#include <fstream>
#include "lista.hpp"
#include "rodada.hpp"
#include "jogador.hpp"

class jogo{
    public:
    jogo();
    void criaJogador(int dinheiroInicial,std::string nome,std::string *mao);
    void criaRodada(int numeroParticipantes,int pingo);
    void atualizaAposta(int aposta,std::string nome);
    void pagaGanhadores();
    void preparaPote(int *apostas);
    int testeSanidade(int dinheiro,std::string nome);
    void restituiJogadores(int pos,int *aposta,int pingo,std::string *nomes);
    void imprimePartida();
    void imprimeResultado();
    void imprimeRodadaInvalida();
    private:
    listaJogadores todosJogadores;
    rodada rodadaAtual;
    std::ofstream arquivoSaida;
};
#endif