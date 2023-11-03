#include "../include/lista.hpp"
//===================================================================================================
//                                  CONSTRUTOR DE CLASSE
//===================================================================================================
listaJogadores::listaJogadores(){
    this->primeiro = new celulaJogador();
    ultimo = primeiro;
    tamanho = 0;
};
//===================================================================================================
//                                  METODOS GETTERS
//===================================================================================================
int listaJogadores::getTamanho(){
    return this->tamanho;
};
jogador* listaJogadores::getJogador(int pos){
    celulaJogador *cellJogador;
    if(pos > tamanho || pos <= 0){
        return cellJogador->getJogador();
    }
    cellJogador = this->primeiro;
    for(int i = 0;i<pos;i++){
        cellJogador = cellJogador->prox;
    }
    return cellJogador->getJogador();
};
//===================================================================================================
//                         METODO DE PESQUISA DO JOGADOR PELO NOME
//===================================================================================================
jogador* listaJogadores::pesquisaJogador(std::string nome){
    jogador *j1;
    celulaJogador *cj1;
    if(tamanho == 0){
        return j1;
    }
    cj1 = this->primeiro->prox;
    while(cj1 != NULL){
        if(cj1->player->getNome() == nome){
            j1 = cj1->player;
        }
        cj1 = cj1->prox;
    }
    return j1;
};
//===================================================================================================
//                       METODO VERIFICA SE HÁ O JOGADOR NA LISTA
//===================================================================================================
bool listaJogadores::existeJogador(std::string nome){
    celulaJogador *cj1;
    if(tamanho == 0){
        return false;
    }
    cj1 = this->primeiro->prox;
    while(cj1 != NULL){
        if(cj1->player->getNome() == nome){
            return true;
        }
        cj1 = cj1->prox;
    }
    return false;
};
//===================================================================================================
//             METODOS INSERCAO NA LISTA, POR PADRAO INSERCAO NO FINAL DA LISTA
//===================================================================================================
void listaJogadores::insereJogador(jogador *j1){
    celulaJogador *cj1;
    cj1 = new celulaJogador();
    cj1->player = j1;
    this->ultimo->prox = cj1;
    this->ultimo = cj1;
    tamanho++;
};
//===================================================================================================
//               METODO REMOVE DA LISTA, POR PADRAO REMOCAO NO INCIO DA LISTA
//===================================================================================================
jogador* listaJogadores::removeJogador(){
    jogador *j1;
    celulaJogador *cj1;
    if(tamanho == 0){
        return j1;
    }
    cj1 = this->primeiro->prox;
    this->primeiro->prox = cj1->prox;
    tamanho --;
    if(this->primeiro->prox == NULL){
        this->ultimo = this->primeiro;
    }
    j1 = cj1->player;
    delete cj1;
    return j1;

};
//===================================================================================================
//                        METODOS DE REMOCAO PELO NOME DO JOGADOR
//===================================================================================================
jogador* listaJogadores::removeJogadorNome(std::string nome){
    jogador *j1;
    j1 = new jogador();
    celulaJogador *cj1;
    celulaJogador *anterior;
    cj1 = this->primeiro->prox;
    tamanho --;
    if(cj1 != NULL && cj1->player->getNome()==nome){
        this->primeiro->prox = cj1->prox;
        j1 = cj1->getJogador();
        delete cj1;
        return j1;
    }
    else{
        while(cj1 != NULL && cj1->player->getNome() != nome){
            anterior = cj1;
            cj1 = cj1->prox;
        }
        if(cj1 == NULL){
            return j1;
        }
        else{
            j1 = cj1->getJogador();
            anterior->prox = cj1->prox;
            delete cj1;
            return j1;
        }
    }
};
//===================================================================================================
//                               METODO DE LIMPEZA DE LISTA
//===================================================================================================
void listaJogadores::limpa(){
    jogador *j1;
    while(tamanho != 0){
        j1 = this->removeJogador();
    }
};
//===================================================================================================
//                   METODOS QUE MOVIMENTA O DINHEIRO DO JOGADOR NA RODADA
//===================================================================================================
void listaJogadores::debitaJogador(std::string nome,int valor,bool movimento){
    celulaJogador *cj1;
    cj1 = new celulaJogador();
    cj1 = this->primeiro->prox;
    while(cj1 != NULL && cj1->player->getNome()!= nome){
        cj1 = cj1->prox;
    }
    if(movimento == ganhoRodada){
        cj1->player->ganho(valor);
    }
    else{
        cj1->player->pagamento(valor);
    }
};
//===================================================================================================
//               METODOS PARA DESCOBRIR O MAIS RICO DOS JOGADORES DA LISTA
//===================================================================================================
jogador* listaJogadores::achaMaisRico(){
    jogador *j1;
    celulaJogador *cj1;
    cj1 = new celulaJogador();
    cj1 = this->primeiro->prox;
    j1 = cj1->player;
    for(int i = 1;i < tamanho;i++){
        cj1 = cj1->prox;
        if(cj1->player->getDinheiro() > j1->getDinheiro()){
            j1 = cj1->player;
        }
    }
    return j1;
};