#include "../include/email.hpp"
/********************************************************************************
 *                          CONSTRUTORES DE CLASSE
 ********************************************************************************/
email::email(int destinatario,int idEmail,int numPalavras,std::string mensagem){
    this->idEmail = idEmail;
    this->numPalavras = numPalavras;
    this->mensagem = mensagem;
    this->destinatario = destinatario;
};
email::email(){};
/********************************************************************************
 *                          METODOS DE SET
 ********************************************************************************/
void email::setIdEmail(int id){
    this->idEmail = id;
};
void email::setNumPalavras(int num){
    this->numPalavras = num;
};
void email::setMensagem(std::string msg){
    this->mensagem = msg;
};
void email::setDestinatario(int destinatario){
    this->destinatario = destinatario;
}
/********************************************************************************
 *                          METODOS DE GET
 ********************************************************************************/
int email::getIdEmail(){
    return this->idEmail;
};
int email::getNumPalavras(){
    return this->numPalavras;
}
std::string email::getMensagem(){
    return this->mensagem;
};
int email::getDestinatario(){
    return this->destinatario;
}