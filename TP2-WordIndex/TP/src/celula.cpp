#include "../include/celula.hpp"
/*---------------------------------------------------------------------------------------------------------
                                    CONSTRUTOR DE CLASSE
-----------------------------------------------------------------------------------------------------------*/
celulaPalavra::celulaPalavra(){
    this->prox = NULL;
    this->chave = palavra();
};
/*---------------------------------------------------------------------------------------------------------
                                    METODOS GET E SET
-----------------------------------------------------------------------------------------------------------*/
palavra celulaPalavra::getCelulaPalavra(){
    return this->chave;
};
void celulaPalavra::setCelulaPalavra(palavra novaPalavra){
    this->chave = novaPalavra;
};
