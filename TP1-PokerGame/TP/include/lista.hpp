#ifndef LISTA_HPP
#define LISTA_HPP
#include "celula.hpp"
#include "jogador.hpp"
#define pagamentoAposta false
#define ganhoRodada true
class listaJogadores{
    public:
    listaJogadores();
    int getTamanho();
    jogador* getJogador(int pos);
    bool existeJogador(std::string nome);
    void insereJogador(jogador *j1);
    jogador* pesquisaJogador(std::string nome);
    jogador* removeJogadorNome(std::string nome);
    jogador* removeJogador();
    void debitaJogador(std::string nome,int valor,bool movimento);
    jogador* achaMaisRico();
    void limpa();
    private:
    celulaJogador *primeiro;
    celulaJogador *ultimo;
    int tamanho;
    friend class rodada;
};
#endif