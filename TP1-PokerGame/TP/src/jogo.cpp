#include "../include/jogo.hpp"
//===================================================================================================
//                          CONSTRUTOR DE CLASSE VAZIA
//===================================================================================================
jogo::jogo(){
        arquivoSaida.open("../saida.txt");
};
//===================================================================================================
//              ADICIONA OS JOGADORES NA RODADA ATUAL E CASO NÃO TENHA SIDO ADICIONADO 
//                          ADICONA NA LISTA DE TODOS OS JOGADORES
//===================================================================================================
void jogo::criaJogador(int dinheiroInicial,std::string nome,std::string *mao){
    jogador* novoJogador = new jogador(nome,dinheiroInicial,mao);
    if(!todosJogadores.existeJogador(nome)){
        todosJogadores.insereJogador(novoJogador);
        rodadaAtual.insereJogadorRodada(novoJogador);
    }
    else{
        novoJogador = todosJogadores.pesquisaJogador(nome);
        novoJogador->setMao(mao);
        rodadaAtual.insereJogadorRodada(novoJogador);
    }
};
//===================================================================================================
//                  CHAMA O CONSTRUTOR DE UMA RODADA PARA INICIAR A PARTIDA
//===================================================================================================
void jogo::criaRodada(int numeroParticipantes,int pingo){
    rodadaAtual = rodada(numeroParticipantes,pingo);
};
//===================================================================================================
//                RECECE O VALOR APOSTADO PELO JOGADOR E SUBTRAI DO SEU MONTANTE
//===================================================================================================
void jogo::atualizaAposta(int aposta,std::string nome){
    todosJogadores.debitaJogador(nome,aposta,pagamentoAposta);
};
//===================================================================================================
//                   TESTA SE HA UMA APOSTA MAIOR QUE O MONTANTE DO JOGADOR
//===================================================================================================
int jogo::testeSanidade(int dinheiro,std::string nome){
    jogador *j1;
    j1 = rodadaAtual.lj1.pesquisaJogador(nome);
    if(dinheiro > j1->getDinheiro()){
        return 0;
    }
    else{
        return 1;
    }
};
//===================================================================================================
//  RESTITUI O DINHEIRO DOS JOGADORES QUE JA HAVIAM APOSTADO ANTES DA FALHA DO TESTE DE SANIDADE
//===================================================================================================
void jogo::restituiJogadores(int pos,int *apostas,int pingo,std::string *nomes){
    if(pos == 0){
        return;
    }
    else{
        for(int i = 0;i < pos;i++){
            todosJogadores.debitaJogador(nomes[i],apostas[i]+pingo,ganhoRodada);
        }
    }
};
//===================================================================================================
//                     LEVA AS APOSTAS DOS JOGADORES PARA DENTRO DO POTE
//===================================================================================================
void jogo::preparaPote(int *apostas){
    rodadaAtual.montaPote(apostas);
};
//===================================================================================================
//               A RODADA E JOGADA E REALIZASSE O PAGAMENTO DOS GANAHDOR(ES) DA RODADA
//===================================================================================================
void jogo::pagaGanhadores(){
    listaJogadores listaAuxiliar;
    jogador *j1;
    listaAuxiliar = rodadaAtual.Vencedores();
    int ganhos = rodadaAtual.valorGanho();
    for(int i = 1;i<=listaAuxiliar.getTamanho();i++){
        j1 = listaAuxiliar.getJogador(i);
        todosJogadores.debitaJogador(j1->getNome(),ganhos,ganhoRodada);
    }
    rodadaAtual.limpaVencedores();
};
//===================================================================================================
//                          IMPRIME O RESULTADO DA PARTIDA
//===================================================================================================
void jogo::imprimePartida(){
    listaJogadores listaImpressa;
    jogador *vencedor;
    listaImpressa = rodadaAtual.Vencedores();
    arquivoSaida<<rodadaAtual.numeroVencedores()<<" "<<rodadaAtual.valorGanho()<<" "<<
    rodadaAtual.jogadaVencedora()<<std::endl;
    for(int i = 1;i <= listaImpressa.getTamanho();i++){
        vencedor = listaImpressa.getJogador(i);
         arquivoSaida<< vencedor->getNome()<< " ";
    }
     arquivoSaida<<std::endl; 
     rodadaAtual.limpaVencedores();
};
//===================================================================================================
//        IMPRIME O RESULTADO FINAL DO JOGO EM ORDEM DE MAIOR MONTANTE PARA MENOR MONTANTE
//===================================================================================================
void jogo::imprimeResultado(){
    jogador *j1,*j2;
    arquivoSaida<<"############"<<std::endl;
    while(todosJogadores.getTamanho() != 0){
        j1 = todosJogadores.achaMaisRico();
        j2 = todosJogadores.removeJogadorNome(j1->getNome());
        arquivoSaida<<j1->getNome()<<" "<<j1->getDinheiro()<<std::endl;
    }
    delete j2;
    arquivoSaida.close();
};
//===================================================================================================
//                 EM CASO DE FALHA DE SANIDADE IMPRIME O ANULAMENTO DA RODADA
//===================================================================================================
void jogo::imprimeRodadaInvalida(){
    arquivoSaida<<"0 0 I"<<std::endl;
};