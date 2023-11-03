#include <iostream>
#include <string>
#include <fstream>
#include "../include/jogador.hpp"
#include "../include/celula.hpp"
#include "../include/lista.hpp"
#include "../include/rodada.hpp"
#include "../include/jogo.hpp"
bool confirmaNumeroRodadas(int numero){
    if(numero<=0){
        return false;
    }
    return true;
}
bool confirmaDinheiro(int dinheiro){
    if(dinheiro < 50 || dinheiro % 50 != 0){
        return false;
    }
    return true;
}
int main(){
    //Declaracao de variaveis
    //Obs: indice 10 utilizado em apostaJogadores e nomeSalvos pois 52/5 = 10 jogadores no max
    //Obs2: Validade = 1 -> Sanidade ok, = 0 ->Sanidade nok, = 2 -> nao precisa mais ser testado
    std::ifstream arquivo;
    jogo jogoPoker;
    int numeroRodadas,dinheiroInicial,numeroParticipantes,pingoRodada,apostas;
    int apostasJogadores[12];
    std::string nome;
    std::string nomeSalvos[12];
    std::string maoJogador[5];
    int validade = 1; 
    bool rodadaValidada = true;
    //Inicio do processo de leitura dos arquivos
    arquivo.open("../Entrada.txt");
    arquivo>>numeroRodadas;
    arquivo>>dinheiroInicial;
    if(confirmaNumeroRodadas(numeroRodadas) == false){
        arquivo.close();
        return 0;
    }
    else if(confirmaDinheiro(dinheiroInicial)==false){
        arquivo.close();
        return 0;
    }
    //loop para ler os dados de cada rodada
    for(int k = 0;k < numeroRodadas;k++){
        arquivo>>numeroParticipantes;
        arquivo>>pingoRodada;
        if(confirmaDinheiro(pingoRodada) == false){
            rodadaValidada = false;
        }
        else{
            rodadaValidada = true;
        }
        jogoPoker.criaRodada(numeroParticipantes,pingoRodada);
        //loop para ler os dados de cada jogador
        for(int i = 0;i<numeroParticipantes;i++){
            arquivo>>nome;
            nomeSalvos[i] = nome;
            arquivo>>apostas;
            apostasJogadores[i] = apostas;
            for(int j = 0;j<5;j++){
                arquivo>>maoJogador[j];
            }
            jogoPoker.criaJogador(dinheiroInicial,nome,maoJogador);
            //Caso ainda seja necessario testar a sanidade da rodada
            if(validade != 2 && rodadaValidada == true){
                validade = jogoPoker.testeSanidade(apostas+pingoRodada,nome);
            }
            if(validade == 1 && rodadaValidada == true){
                jogoPoker.atualizaAposta(apostas+pingoRodada,nome);
            }
            else if(validade == 0 || rodadaValidada == false){
                jogoPoker.restituiJogadores(i,apostasJogadores,pingoRodada,nomeSalvos);
                validade = 2;
            }
            }
        //Jogasse a rodada
        if(validade == 1){
            jogoPoker.preparaPote(apostasJogadores);
            jogoPoker.pagaGanhadores();
            jogoPoker.imprimePartida();
        }
        else{
            jogoPoker.imprimeRodadaInvalida();
        }
        validade = 1;
    }
    jogoPoker.imprimeResultado();
    arquivo.close();
    return 0;
}