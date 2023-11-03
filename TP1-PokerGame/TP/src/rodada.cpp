#include "../include/rodada.hpp"
//===================================================================================================
//                              CONSTRUTORES DE CLASSE
//===================================================================================================
//Construtor de classe completo
rodada::rodada(int participantes,int pingo){
    this->participantes = participantes;
    this->pingo = pingo;
    this->lj1 = listaJogadores();
    this->ljGanhadores = listaJogadores();
    this->pote = 0;
};
//Construtor vazio
rodada::rodada(){
    this->lj1 = listaJogadores();
    this->ljGanhadores = listaJogadores();
    this->pote = 0;
};
//===================================================================================================
//              I               MONTA O POTE DA PARTIDA
//===================================================================================================
void rodada::montaPote(int *apostaJogadores){
    for(int i = 0; i < this->participantes; i++){
        this->pote += apostaJogadores[i] + this->pingo;
    }
};
//===================================================================================================
//                     INSERE OS JOGADORES QUE IRAM PARTICIPAR DA RODADA
//===================================================================================================
void rodada::insereJogadorRodada(jogador *j1){
    this->lj1.insereJogador(j1);
};
//===================================================================================================
//                          CONVERTE O VALOR DA JOGADA NA SUA SIGLA 
//===================================================================================================
std::string rodada::jogadaVencedora(){
    jogador *ganhador;
    ganhador = this->ljGanhadores.getJogador(1);
    int jogada_ = ganhador->jogada();
    switch (jogada_)
    {
    case 10: 
        return "RSF";
    case 9: 
        return "SF";
    case 8: 
        return "FK";
    case 7: 
        return "FH";
    case 6: 
        return "F";
    case 5: 
        return "S";
    case 4: 
        return "TK";
    case 3: 
        return "TP";
    case 2: 
        return "OP";
    case 1: 
        return "HC";
    default:
        return "ERRO";
        break;
    }
};
//===================================================================================================
//                         RETORNA O NUMERO DE GANHADORES DA RODADA
//===================================================================================================
int rodada::numeroVencedores(){
    return this->ljGanhadores.getTamanho();
};
//===================================================================================================
//                          RETORNA A LISTA DE GANHADORES DA RODADA
//===================================================================================================
listaJogadores rodada::Vencedores(){
    this->decideGanhador();
    return this->ljGanhadores;
};
//===================================================================================================
//                            RETORNA O VALOR GANHO PELO VENCEDOR
//===================================================================================================
int rodada::valorGanho(){
    return (int) this->pote/this->ljGanhadores.getTamanho();
};
//===================================================================================================
//                         METODO QUE LIMPA A LISTA DE GANHADORES
//===================================================================================================
void rodada::limpaVencedores(){
    this->ljGanhadores.limpa();
}
/**************************************************************************************************
                               
                                     METODOS PRIVADOS

**************************************************************************************************/
//===================================================================================================
//                     COMPARA AS JOGADAS E ANALISE QUEM TEM AS MAIORES
//===================================================================================================
void rodada::decideGanhador(){
    jogador *j1,*j2;
    j1 = this->lj1.getJogador(1);
    for(int i = 2;i <= participantes;i++){
        j2 = this->lj1.getJogador(i);
        if(j2->jogada() > j1->jogada()){
            j1 = j2;
            this->ljGanhadores.limpa();
        }
        else if(j2->jogada() == j1->jogada()){
            this->ljGanhadores.insereJogador(j2);
        }
    }
    this->ljGanhadores.insereJogador(j1);
    if(this->ljGanhadores.getTamanho() > 1){
        this->criteriosDesempateCartaJogada(j1->jogada());
    }
};
//===================================================================================================
//            COMPARA AS CARTAS MAIS VALIOSAS DA MAO DOS JOGADORES DE JOGADAS IGUAIS
//===================================================================================================
void rodada::criteriosDesempateCartaJogada(int jogada_){
   jogador *j1,*j2;
   listaJogadores ljaux;
   ljaux = listaJogadores();
    j1 = this->ljGanhadores.getJogador(1);
    for(int i = 2;i <= ljGanhadores.getTamanho();i++){
        j2 = this->ljGanhadores.getJogador(i);
        if(j2->getCartaJogada() > j1->getCartaJogada()){
            j1 = j2;
            ljaux.limpa();
        }
        else if(j2->getCartaJogada() == j1->getCartaJogada()){
            ljaux.insereJogador(j2);
        }
    }
    ljaux.insereJogador(j1);
    this->ljGanhadores.limpa();
    ljGanhadores = ljaux;
    if(this->ljGanhadores.getTamanho() > 1){
        this->criteriosDesempateCartaForte(jogada_);
    }
};
//===================================================================================================
//             COMPARA A CARTA MAIS VALIOSA FORA DA JOGADA EM CASA DE MAIS UM EMPATE
//===================================================================================================
void rodada::criteriosDesempateCartaForte(int jogada_){
   jogador *j1,*j2;
   listaJogadores ljaux;
   ljaux = listaJogadores();
   j1 = this->ljGanhadores.getJogador(1);
   for(int i = 2;i <= ljGanhadores.getTamanho();i++){
        j2 = this->ljGanhadores.getJogador(i);
        if(j2->cartaMaisForte(jogada_) > j1->cartaMaisForte(jogada_)){
            j1 = j2;
            ljaux.limpa();
        }
        else if(j2->cartaMaisForte(jogada_) == j1->cartaMaisForte(jogada_)){
            ljaux.insereJogador(j2);
        }
    }
    ljaux.insereJogador(j1);
    this->ljGanhadores.limpa();
    ljGanhadores = ljaux;
    if(this->ljGanhadores.getTamanho() > 1){
        this->criteriosDesempateCarteFinal(jogada_);
    }
};
//===================================================================================================
//          COMPARA A SEGUNDA CARTA MAIS VALIOSA FORA DA JOGADA EM CASA DE MAIS UM EMPATE
//===================================================================================================
void rodada::criteriosDesempateCarteFinal(int jogada_){
   jogador *j1,*j2;
   listaJogadores ljaux;
   ljaux = listaJogadores();
   j1 = this->ljGanhadores.getJogador(1);
   for(int i = 2;i <= ljGanhadores.getTamanho();i++){
        j2 = this->ljGanhadores.getJogador(i);
        if(j2->cartaDesempate(jogada_) > j1->cartaDesempate(jogada_)){
            j1 = j2;
            ljaux.limpa();
        }
        else if(j2->cartaDesempate(jogada_) == j1->cartaDesempate(jogada_)){
            ljaux.insereJogador(j2);
        }
    }
    ljaux.insereJogador(j1);
    this->ljGanhadores.limpa();
    ljGanhadores = ljaux;
};