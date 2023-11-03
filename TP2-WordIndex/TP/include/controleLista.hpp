#ifndef CONTROLELISTA_HPP
#define CONTROLELISTA_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "palavra.hpp"
#include "celula.hpp"
#include "lista.hpp"
class controleLista{
    public:
    controleLista(std::string saida);
    void montaOrdem(std::string str);
    void montaTexto(std::string str);
    void ordena(int melhoria,int grupoPivo);
    private:
    listaPalavras ordem;
    listaPalavras texto;
    std::ofstream arquivoSaida;
    int valorOrdem;
    bool comparaPalavrasNovaOrdem(std::string palavra1,std::string palavra2);
    void quicksort(int esq,int dir,palavra *vetor,int melhoria,int grupoPivo);
    void particao(int esq,int dir,int *i,int *j,palavra *vetor,int grupoPivo);
    void selecao(palavra *vetor,int esq,int dir);
    palavra escolhePivo(palavra *vetor,int grupoPivo,int pontoMedio);
    void imprimiVetor(palavra *vetor);
};
#endif