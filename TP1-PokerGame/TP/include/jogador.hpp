#ifndef JOGADOR_HPP
#define JOGADOR_HPP
#include <iostream>
#include <string>

#define TAMANHO_MAO 5
#define Royal_Straigth_Flush 10
#define Straigth_Flush 9
#define Four_Kind 8
#define Full_House 7
#define Flush 6
#define Straigth 5
#define Three_Kind 4
#define Two_pair 3
#define One_Pair 2
#define High_Card 1

class jogador{
    public:
    //Construtores
    jogador(std::string nome,int dinheiro,std::string mao[TAMANHO_MAO]);
    jogador();
    //Metodos Get
    std::string getNome();
    int getDinheiro();
    int getCartaJogada();
    //Metodos Set
    void setNome(std::string nome);
    void setDinheiro(int dinheiro);
    void setMao(std::string *mao);
    //Metodos comuns da classe
    void pagamento(int dinheiro);
    void ganho(int dinheiro);
    int jogada();
    int cartaMaisForte(int jogada_);
    int cartaDesempate(int jogada_);
    private:
    //Variaveis da classe
    std::string nome;
    int dinheiro;
    std::string mao[TAMANHO_MAO];
    int numeros[TAMANHO_MAO];
    std::string naipes[TAMANHO_MAO];
    int cartaJogada;
    //Metodos privados
    void numeroCartas();
    void naipeCartas();
    std::string cartasMesmoValor();
    std::string cartasSequencia();
    bool cartasMesmoNaipe();
    int verificaAs();
};
#endif