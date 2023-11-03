#include "../include/tabelaHash.hpp"
/********************************************************************************
 *                          CONSTRUTORES DE CLASSE
 ********************************************************************************/
tabelaHash::tabelaHash(int M){
    this->tam = M;
    this->tabela = new arvoreEmail[tam];
};
tabelaHash::tabelaHash(){};
/********************************************************************************
 *                          PESQUISA EM TABELA HASH
 ********************************************************************************/
email tabelaHash::pesquisa(int usuario,int id){
    int posicao;
    email temp;
    posicao = this->hash(usuario);
    temp = tabela[posicao].consultaEmail(usuario,id);
    return temp;
};
/********************************************************************************
 *                          INSERCAO EM TABELA HASH
 ********************************************************************************/
void tabelaHash::insere(email novo){
    int posicao;
    email temp;
    temp = this->pesquisa(novo.getDestinatario(),novo.getIdEmail());
    if(temp.getMensagem() != "MENSAGEM INEXISTENTE"){
        return;
    }
    posicao = hash(novo.getDestinatario());
    this->tabela[posicao].insereEmail(novo);
};
/********************************************************************************
 *                          REMOCAO EM TABELA HASH
 ********************************************************************************/
bool tabelaHash::remove(int usuario,int id){
    email temp;
    int posicao;
    posicao = this->hash(usuario);
    return this->tabela[posicao].removeEmail(id,usuario);
};
/********************************************************************************
 *                          FUNCAO HASH
 ********************************************************************************/
int tabelaHash::hash(int id){
    return id%this->tam;
};