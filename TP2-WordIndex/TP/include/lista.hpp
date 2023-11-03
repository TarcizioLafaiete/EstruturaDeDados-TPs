#ifndef LISTA_HPP
#define LISTA_HPP
#include <iostream>
#include <string>
#include "palavra.hpp"
#include "celula.hpp"

class listaPalavras{
    public:
    listaPalavras();
    int getTamanho();
    palavra getPalavraPosicao(int pos);
    palavra pesquisaPalavra(std::string id);
    void incrementaPalavra(std::string id);
    void inserePalavraInicio(palavra novaPalavra);
    void inserePalavraFim(palavra novaPalavra);
    palavra removePalavra(std::string id);
    palavra removePalavraInicio();
    private:
    celulaPalavra *primeiro;
    celulaPalavra *ultimo;
    int tamanho;
};
#endif