#ifndef EMAIL_HPP
#define EMAIL_HPP
#include <iostream>
#include <string>
class email{
    public:
        email(int destinarario,int idEmail,int numPalavras,std::string mensagem);
        email();
        //Metodos Set
        void setIdEmail(int id);
        void setNumPalavras(int num);
        void setMensagem(std::string msg);
        void setDestinatario(int destinatario);
        //Metodos Get
        int getIdEmail();
        int getNumPalavras();
        std::string getMensagem();
        int getDestinatario();
    private:
        int destinatario;
        int idEmail;
        int numPalavras;
        std::string mensagem;
};
#endif