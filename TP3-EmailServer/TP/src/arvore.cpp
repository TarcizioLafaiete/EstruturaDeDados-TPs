#include "../include/arvore.hpp"
/********************************************************************************
 *                          CONSTRUTORES DE CLASSE
 ********************************************************************************/
arvoreEmail::arvoreEmail(){
    this->raiz = NULL;
};
/********************************************************************************
 *                  METODO DE INSERCAO EM AROVE BINARIA
 ********************************************************************************/
void arvoreEmail::insereEmail(email novo){
    this->insereEmailRecursivo(raiz,novo);
};
void arvoreEmail::insereEmailRecursivo(no* &pai,email novo){
    if(pai == NULL){
        pai = new no();
        pai->item = novo;
    }
    else if(pai->item.getIdEmail() == novo.getIdEmail()){
        return;
    }
    else{
        if(novo.getIdEmail() < pai->item.getIdEmail()){
            this->insereEmailRecursivo(pai->esq,novo);
        }
        else{
            this->insereEmailRecursivo(pai->dir,novo);
        }
    }
};
/********************************************************************************
 *                      METODO DE CONSULTA EM ARVORE BINARIA
 ********************************************************************************/
email arvoreEmail::consultaEmail(int usuario,int id){
    return this->consultaEmailRecursivo(raiz,usuario,id);
};
email arvoreEmail::consultaEmailRecursivo(no* &pai,int usuario,int id){
    email temp,retorno;
    if(pai == NULL){
        temp = email(0,0,0,"MENSAGEM INEXISTENTE");
        return temp;
    }
    else{
        if(id < pai->item.getIdEmail()){
            temp = this->consultaEmailRecursivo(pai->esq,usuario,id);
        }
        else if(id > pai->item.getIdEmail()){
            temp = this->consultaEmailRecursivo(pai->dir,usuario,id);
        }
        else{
            if(pai->item.getDestinatario() == usuario){
                return pai->item;
            }
            else{
                temp = email(0,0,0,"MENSAGEM INEXISTENTE");
                return temp;
            }
        }
    }
    return temp;
};
/********************************************************************************
 *                   METODO DE REMOCAO EM ARVORE BINARIA
 ********************************************************************************/
bool arvoreEmail::removeEmail(int id,int usuario){
    return removeEmailRecursivo(raiz,id,usuario);
};
bool arvoreEmail::removeEmailRecursivo(no* &pai,int id,int usuario){
    no *aux;
    if (pai == NULL) {
        return false;
    }
    if (id < pai->item.getIdEmail()){
        return removeEmailRecursivo(pai->esq,id,usuario);
    }
    else if (id >pai->item.getIdEmail()){
        return removeEmailRecursivo(pai->dir, id,usuario);
    }
    else {
        if(pai->item.getDestinatario() == usuario){
            if (pai->dir == NULL) {
            aux = pai;
            pai = pai->esq;
            delete aux;
        }
            else if(pai->esq == NULL) {
                aux = pai;
                pai = pai->dir;
                delete aux;
            }
            else{
                antecessor(pai, pai->esq);
                return true;
            }
        }
        else{
            return false;
        }
    }
};
/********************************************************************************
 *            METODO AUXILIAR PARA ACHAR O ANTECESSOR PARA TROCA
 ********************************************************************************/
void arvoreEmail::antecessor(no* q,no* &r){
    if(r->dir != NULL) {
        antecessor(q, r->dir);
        return;
    }
    q->item = r->item;
    q = r;
    r = r->esq;
    delete q;
};