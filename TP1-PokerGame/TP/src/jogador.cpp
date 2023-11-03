#include "../include/jogador.hpp"
//===================================================================================================
//                                  CONSTRUTORES DE CLASSE
//===================================================================================================
//Costrutor completo da classe jogador
jogador::jogador(std::string nome,int dinheiro,std::string *mao){
    this->nome = nome;
    this->dinheiro = dinheiro;
    this->cartaJogada = 0;
    for(int i = 0; i<TAMANHO_MAO;i++)
    {
        this->mao[i] = mao[i];
    }
};
//Construtor vazio
jogador::jogador(){};
//===================================================================================================
//                                      METODOS GETTERS
//===================================================================================================
//Metodo que retorna o nome do jogador
std::string jogador::getNome(){
    return this->nome;
};
//Metodo que retorna o dinheiro atual do jogador
int jogador::getDinheiro(){
    return this->dinheiro;
};
//Metodo que retorna a Carta da jogada que jogador tem na mao
int jogador::getCartaJogada(){
    if(this->cartaJogada == 1){
        return 14;
    }
    else{
    return this->cartaJogada;
    }
};
//===================================================================================================
//                                      METODOS SETTERS
//===================================================================================================
//Metodo que insere um nome em um jogador
void jogador::setNome(std::string nome){
    this->nome = nome;
};
//Metodo que insere um dinheiro em um jogador
void jogador::setDinheiro(int dinheiro){
    this->dinheiro = dinheiro;
};
//Metodo que insere a mao em um jogador 
void jogador::setMao(std::string *mao){
    for(int i = 0; i<TAMANHO_MAO;i++)
    {
        this->mao[i] = mao[i];
    }
};
//===================================================================================================
//                  METODOS RELACIONADOS A MOVIMENTACAO DE DINHEIRO DO JOGADOR
//===================================================================================================
 //Metodo que retira o valor da aposta da rodada do dinheiro do jogador
 void jogador::pagamento(int dinheiro){
    if(this->dinheiro > dinheiro){
    this->dinheiro -=dinheiro;
    }
 };
 //Metodo que adiciona o valor ganho na rodada do dinheiro do jogador
 void jogador::ganho(int dinheiro){
     this->dinheiro += dinheiro;
 };
//===================================================================================================
//                      METODOS QUE SEPARA OS NAIPES E OS NUMEROS DAS CARTAS
//===================================================================================================
//Metodo que insere na string numeros o numero das cartas da mao do jogador
void jogador::numeroCartas(){
    int i = 0;
    std::string aux;
    std::string::iterator it;
    //Loop passa por cada carta na mao
    for(int j = 0;j < TAMANHO_MAO; j++){
        //Loop para separar o numero do naipe das cartas
        for(it = this->mao[j].begin();it !=this->mao[j].end();++it){
            //Isere na string auxiliar o valor da carta
            if(*it >= '0' && *it <= '9'){
                aux.insert(aux.end(),*it);
            }
            else{
                //Converte a string do numero da carta em um inteiro
                 this->numeros[i] = std::stoi(aux);
                 //Limpa a string auxiliar para analisar a proxima carta
                 aux.clear();
                 i ++;
             }
        }
    }
};
 //Metodo para achar o naipe das cartas
void jogador::naipeCartas(){
    std::string* cartas;
    std::string::iterator it;
    int i = 0;
    cartas = this->mao;
    //Loop que percorre o array de cartas e retira os naipes da carta
    for(int j = 0;j<TAMANHO_MAO;j++){
        for(it = cartas[j].begin();it !=cartas[j].end();++it){
             if(*it >= 'A' && *it <= 'Z'){
                this->naipes[i] = *it;
                i++;
             }   
         }
    }
};
//===================================================================================================
//                  METODO QUE ANALISA SE A MAO DO JOGADOR POSSUI ALGUMA CARTA IGUAL
//===================================================================================================
std::string jogador::cartasMesmoValor(){
    int qtdDupla = 0;
    int situacaoAs = verificaAs();
    int rep = 0;
    bool tripla;
    bool quarta;
         for(int i = 0;i<TAMANHO_MAO-1;i++){
             if(numeros[i]==numeros[i+1]){
                 rep++;
             }
             else{
                 rep = 0;
             }
             if(rep == 1){
                 qtdDupla++;
                if(tripla == false){ 
                    if(this->cartaJogada != 1)
                    this->cartaJogada = this->numeros[i];
                }
             }
             else if(rep == 2){
                 tripla = true;
                 qtdDupla --;
                this->cartaJogada = this->numeros[i];
             }
             else if(rep == 3){
                 quarta = true;
                 tripla = false;
                 this->cartaJogada = this->numeros[i];
             }
         }
     if(quarta == true){
         return "Quarta";
     }
     else if(qtdDupla == 1 && tripla == true){
         return "Full House";
     }
     else if(tripla == true){
         return "Tripla";
     }
     else if(qtdDupla == 2){
         return "Dois pares";
     }
     else if(qtdDupla == 1){
         return "Um par";
     }
     else{
         if(situacaoAs != 2){
             this->cartaJogada = this->numeros[4];
         }
         else{
             this->cartaJogada = 1;
         }
         return "Carta mais alta";
     }
};
//Metodo que verifica se há uma sequencia na mão
std::string jogador::cartasSequencia(){
    int i, j,p;
    int qtd = 0;
    int aux;
    for(i = 0; i < TAMANHO_MAO-1; i++){
        for(j = 1; j < TAMANHO_MAO-i; j++){
            if (this->numeros[j] < this->numeros[j-1]){
                aux = this->numeros[j];
                this->numeros[j] = this->numeros[j-1];
                this->numeros[j-1] = aux;
            }
        }      
    }
    for(p = 0;p < TAMANHO_MAO-1;p++){
        if(this->numeros[p]== this->numeros[p+1]-1){
            qtd++;
        }
    }   
    if(this->numeros[0] == 1 && this->numeros[1]== 10 && this->numeros[2]== 11 &&
        this->numeros[3] == 12 && this->numeros[4]==13){
        return "Royal";
    }  
    else if(qtd == TAMANHO_MAO-1){
        return "Straigth";
    }
    else{
        return "Nothing";
    }
};
//Metodo que verifica se as cartas tem o mesmo naipe
bool jogador::cartasMesmoNaipe(){
    int qtd = 0;
     for(int l = 1;l < TAMANHO_MAO;l++)
     {
         if(this->naipes[0] == this->naipes[l]){
            qtd++;
         }
     }
     if(qtd == TAMANHO_MAO-1){
         return true;
     }
     else{
         return false;
     }
};
//===================================================================================================
//                        METODOS DEFINE QUAL JOGADA O JOGADOR POSSUI
//===================================================================================================
 //Metodo que define a mao do jogador
 int jogador::jogada(){
    std::string situacaoValor;
    std::string situacaoSequencia;
     bool situacaoNaipe;
     this->numeroCartas();
     this->naipeCartas();
     situacaoSequencia = cartasSequencia();
     situacaoValor = cartasMesmoValor();
     situacaoNaipe = cartasMesmoNaipe();
     if(situacaoSequencia == "Royal" && situacaoNaipe == true){
         return Royal_Straigth_Flush;
     }
     else if(situacaoSequencia != "Nothing" && situacaoNaipe == true){
        return Straigth_Flush;
     }
     else if(situacaoValor == "Quarta"){
         return Four_Kind;
     }
     else if(situacaoValor == "Full House"){
         return Full_House;
     }
     else if(situacaoNaipe == true){
         return Flush;
     }
     else if(situacaoSequencia != "Nothing"){
         return Straigth;
     }
     else if(situacaoValor == "Tripla"){
         return Three_Kind;
     }
     else if(situacaoValor == "Dois pares"){
         return Two_pair;
     }
     else if(situacaoValor == "Um par"){
         return One_Pair;
     }
     else if(situacaoValor == "Carta mais alta"){
         return High_Card;
     }
     else{
         return 0;
     }
 };
//===================================================================================================
//                METODO PARA VERIFICAR A SITUACAO DO AS NA MAO DO JOGADOR
//===================================================================================================
 int jogador::verificaAs(){
     if(this->numeros[0] == 1 && this->numeros[4]==5){
          return 1;
      }
      else if(this->numeros[0] == 1 && this->numeros[4]!=5){
          return 2;
      }
      else{
          return 0;
      }
 };
//===================================================================================================
//                   DEFINE A CARTA MAIS VALIOSA FORA DA JOGADA PRINCIPAL
//===================================================================================================
 int jogador::cartaMaisForte(int jogada_){
     int situacaoAs = verificaAs();
     if(jogada_ == Four_Kind || jogada_ == Full_House){
        for(int i = 0;i<TAMANHO_MAO;i++){
            if(this->numeros[i]!= this->cartaJogada){
                return this->numeros[i];
            }
        }
     }
     else if(jogada_ == Flush){
        if(situacaoAs == 2){
            return this->numeros[4];
        }
        else{
            return this->numeros[3];
        }
     }
     else if(jogada_ == Three_Kind){
        if(this->numeros[0] != this->cartaJogada &&
           situacaoAs == 2){
                return 14;
        }
        else if(this->numeros[4] == this->cartaJogada){
            return this->numeros[1];
        }
        else if(this->numeros[4] != this->cartaJogada){
            return this->numeros[4];
        }
     }
     else if(jogada_ == Two_pair){
         for(int k = 0;k<TAMANHO_MAO;k++){
             if(this->numeros[k]!=this->cartaJogada &&
                this->numeros[k]==this->numeros[k+1]){
                    return this->numeros[k];
             }
         }
     }
     else if(jogada_ == One_Pair){
         if(this->numeros[0] != this->cartaJogada &&
           situacaoAs == 2){
                return 14;
        }
        else if(this->numeros[4] == this->cartaJogada){
            return this->numeros[2];
        }
        else if(this->numeros[4] != this->cartaJogada){
            return this->numeros[4];
        }
     }
     else if(jogada_ == High_Card){
         if(situacaoAs == 2){
             return this->numeros[4];
         }
         else{
            return this->numeros[3];
         }
     }
     return 0;
 };
//===================================================================================================
//                          DEFINE ULTIMA CARTA PARA DESEMPATE
//===================================================================================================
 int jogador::cartaDesempate(int jogada_){
     int cartaForte = cartaMaisForte(jogada_);  
     if(jogada_ == Flush){
         if(cartaForte == this->numeros[4]){
             return this->numeros[3];
         }
         else{
             return this->numeros[2];
         }
     }
     else if( jogada_ == Three_Kind || jogada_ == One_Pair){
         for(int i = 4;i>=0;i--){
             if(this->numeros[i] != this->cartaJogada &&
             this->numeros[i] != cartaForte &&
             this->numeros[i] != 1){
                 return this->numeros[i];
             }
         }
     }
      else if(jogada_ == Two_pair){
         for(int i = 4;i>=0;i--){
             if(this->numeros[i] != this->cartaJogada &&
             this->numeros[i] != cartaForte){
                 return this->numeros[i];
             }
         }
     }
     else if(jogada_ == High_Card){
         if(cartaForte == 14){
             return this->numeros[4];
         }
         else{
             return this->numeros[3];
         }
     }
         return 0;
 };
