#include "../include/lista.hpp"
/*---------------------------------------------------------------------------------------------------------
                                    CONSTRUTOR DE CLASSE
-----------------------------------------------------------------------------------------------------------*/
listaPalavras::listaPalavras(){
    this->primeiro = new celulaPalavra();
    this->ultimo = primeiro;
    this->tamanho = 0;
};
/*---------------------------------------------------------------------------------------------------------
                                    METODOS DE GET 
-----------------------------------------------------------------------------------------------------------*/
int listaPalavras::getTamanho(){
    return this->tamanho;
}
//Pesquisa uma palavra por sua posicao e a retorna
palavra listaPalavras::getPalavraPosicao(int pos){
    celulaPalavra *cellNova;
    cellNova = this->primeiro;
    for(int i = 0; i <= pos;i++){
        cellNova = cellNova->prox;
    }
    return cellNova->getCelulaPalavra();
}
/*---------------------------------------------------------------------------------------------------------
                            PESQUISA PALAVRA DENTRO DA LISTA
-----------------------------------------------------------------------------------------------------------*/
palavra listaPalavras::pesquisaPalavra(std::string id){
    palavra novaPalavra;
    celulaPalavra *novaCell;
    novaCell = this->primeiro->prox;
    novaPalavra.setPalavra("#ORDEM");
    while(novaCell != NULL){
        if(novaCell->chave.getPalavra() == id){
            novaPalavra = novaCell->chave;
            break;
        }
        novaCell = novaCell->prox;
    }
    return novaPalavra;
};
/*---------------------------------------------------------------------------------------------------------
            PROCURA PALAVRA DENTRO DA LISTA E INCREMENTA 1 PARA SUAS REPETICOES
-----------------------------------------------------------------------------------------------------------*/
void listaPalavras::incrementaPalavra(std::string str){
    palavra novaPalavra;
    celulaPalavra *novaCell;
    novaCell = this->primeiro->prox;
    while(novaCell != NULL){
        if(novaCell->chave.getPalavra() == str){
            novaCell->chave.incrementaValor();
            break;
        }
        novaCell = novaCell->prox;
    }
};
/*---------------------------------------------------------------------------------------------------------
                             METODOS DE INSERCAO NO INCIO E NO FIM
-----------------------------------------------------------------------------------------------------------*/
void listaPalavras::inserePalavraInicio(palavra novaPalavra){
    celulaPalavra *novaCell;
    novaCell = new celulaPalavra();
    novaCell->setCelulaPalavra(novaPalavra);
    novaCell->prox = this->primeiro->prox;
    this->primeiro->prox = novaCell;
    tamanho ++;
    if(novaCell->prox == NULL){
        this->ultimo = novaCell;
    }
};
void listaPalavras::inserePalavraFim(palavra novaPalavra){
    celulaPalavra *novaCell;
    novaCell = new celulaPalavra();
    novaCell->setCelulaPalavra(novaPalavra);
    this->ultimo->prox = novaCell;
    this->ultimo = novaCell;
    tamanho ++;
};
/*---------------------------------------------------------------------------------------------------------
                        METODOS DE REMOCAO POR CHAVE E NO FIM DA LISTA 
-----------------------------------------------------------------------------------------------------------*/
palavra listaPalavras::removePalavra(std::string id){
    palavra novaPalavra;
    celulaPalavra *novaCell;
    celulaPalavra *anterior;
    novaCell = this->primeiro->prox;
    if(novaCell != NULL && novaCell->chave.getPalavra() == id){
        this->primeiro->prox = novaCell->prox;
        novaPalavra = novaCell->getCelulaPalavra();
        delete novaCell;
        return novaPalavra;
    }
    else{
        while(novaCell != NULL && novaCell->chave.getPalavra() != id){
            anterior = novaCell;
            novaCell = novaCell->prox;
        }
        if(novaCell == NULL){
            return novaPalavra;
        }
        else{
            novaPalavra = novaCell->chave.getPalavra();
            anterior->prox = novaCell->prox;
            delete novaCell;
            tamanho --;
            return novaPalavra;
        }
    }

};
palavra listaPalavras::removePalavraInicio(){
    palavra novaPalavra;
    celulaPalavra *novaCell;
    novaCell = primeiro->prox;
    primeiro->prox = novaCell->prox;
    tamanho--;
    if(primeiro->prox == NULL){
    ultimo = primeiro;
    }
    novaPalavra = novaCell->getCelulaPalavra();
    delete novaCell;
    return novaPalavra;
};