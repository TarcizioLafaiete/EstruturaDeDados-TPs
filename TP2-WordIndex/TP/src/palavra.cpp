#include "../include/palavra.hpp"
/*---------------------------------------------------------------------------------------------------------
                                    CONSTRUTOR DE CLASSE
-----------------------------------------------------------------------------------------------------------*/
palavra::palavra(std::string id){
    this->valor = 0;
    this->id = id;
};
palavra::palavra(){};
/*---------------------------------------------------------------------------------------------------------
                                    METODOS COMUNS DA CLASSE PALAVRA
-----------------------------------------------------------------------------------------------------------*/
std::string palavra::getPalavra(){
    return this->id;
};
//Usado para incrementar um a cada repeticao de palavra
void palavra::incrementaValor(){
    this->valor += 1;
};
int palavra::getValor(){
    return this->valor;
};
void palavra::setPalavra(std::string id){
    this->id = id;
    this->valor = 1;
};
void palavra::setValor(int valor_){
    this->valor = valor_;
};