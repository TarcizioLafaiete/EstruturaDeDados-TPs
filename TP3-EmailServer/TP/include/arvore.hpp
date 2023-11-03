#ifndef ARVORE_HPP
#define ARVORE_HPP

#include "no.hpp"
class arvoreEmail{
    public:
        arvoreEmail();
        void insereEmail(email novo);
        bool removeEmail(int id,int usuario);
        email consultaEmail(int usuario,int id);
    private:
        no *raiz;
         void insereEmailRecursivo(no* &pai,email novo);
         email consultaEmailRecursivo(no* &pai,int usuario,int id);
         bool removeEmailRecursivo(no* &pai,int id,int usuario);
         void antecessor(no *q,no* &r);
};
#endif