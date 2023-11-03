#ifndef PALAVRA_HPP
#define PALAVRA_HPP
#include <iostream>
#include <string>
class palavra{
    public:
    palavra(std::string id);
    palavra();
    //~palavra();
    void incrementaValor();
    std::string getPalavra();
    void setPalavra(std::string);
    int getValor();
    void setValor(int valor_);
    private:
    std::string id;
    int valor;
};
#endif
