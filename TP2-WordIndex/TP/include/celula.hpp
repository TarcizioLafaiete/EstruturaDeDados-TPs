#ifndef CELULA_HPP
#define CELULA_HPP
#include <iostream>
#include <string>
#include "palavra.hpp"
class celulaPalavra{
    public:
    celulaPalavra();
    palavra getCelulaPalavra();
    void setCelulaPalavra(palavra novaPalavra);
    private:
    palavra chave;
    celulaPalavra *prox;
    friend class listaPalavras;
};
#endif