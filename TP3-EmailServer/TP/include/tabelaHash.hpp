#ifndef TABELAHASH_HPP
#define TABELAHASH_HPP
#define TAM_HASH 1000
#include "arvore.hpp"
class tabelaHash{
    public:
        tabelaHash(int M);
        tabelaHash();
        email pesquisa(int usuario,int id);
        void insere(email novo);
        bool remove(int usuario,int id);
    private:
        int tam;
        arvoreEmail *tabela;
        int hash(int id);
};
#endif