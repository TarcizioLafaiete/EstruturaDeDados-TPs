#include <iostream>
#include <string>
#include <fstream>
#include "../include/tabelaHash.hpp"
#define MAXIMO 1000000
#define MINIMO 0
#define MAXIMO_PALAVRAS 200
//ParseArgs -> -i entrada.txt -o saida.txt
void parseArgs(int argc,char* argv[],std::string *entrada,std::string *saida){
    //Pula no nome do executavel
    int i = 1;
     std::string arg;
    while(i < argc){
        arg = argv[i];
        //armazena o nome do arquivo de entrada
        if(arg == "-i"){
            *entrada = argv[i+1];
        }
        //aramazena o nome do arquvio de saida
        else if(arg == "-o"){
            *saida = argv[i+1];
        }
        i++;
    }
}
int main(int argc,char* argv[]){
    std::string entrada,saida,comando,msg,str;
    std::ifstream arquivoEntrada;
    std::ofstream arquivoSaida;
    int tamanhoTabela,idUsuario,idEmail,numPalavras;
    email novo;
    tabelaHash tabela;
    parseArgs(argc,argv,&entrada,&saida);
    //Verifica se algum arquivo foi passado como parametro
    if(entrada.empty()){
        std::cout<<"Nao foi passado arquivo de entrada nos parametros"<<std::endl;
        return 0;
    }
    if(saida.empty()){
        std::cout<<"Nao foi passado arquivo de saida nos parametros"<<std::endl;
        return 0;
    }
    arquivoEntrada.open(entrada);
    arquivoSaida.open(saida);
    arquivoEntrada>>tamanhoTabela;
    tabela = tabelaHash(tamanhoTabela);
    while(arquivoEntrada>>comando){
        //Realiza a insercao de um e-mail no servidor
        if(comando == "ENTREGA"){ 
            arquivoEntrada>>idUsuario;
            arquivoEntrada>>idEmail;
            arquivoEntrada>>numPalavras;
            //Loop para formar a mensagem
            for(int i = 0;i < numPalavras;i++){
                arquivoEntrada>>str;
                msg.append(str);
                msg.append(" ");
            }
            novo = email(idUsuario,idEmail,numPalavras,msg);
            msg.erase(msg.begin(),msg.end());
            //Verifica se parametros estao na faixa desejada
            if(idUsuario >= MINIMO && idUsuario <=  MAXIMO && idEmail >= MINIMO && idEmail <= MAXIMO
            && numPalavras >= MINIMO && numPalavras <= MAXIMO_PALAVRAS){
                tabela.insere(novo);  
                arquivoSaida<<"OK: "<<"MENSAGEM "<<novo.getIdEmail()<<" PARA "<<novo.getDestinatario()
                <<" ARMAZENADA EM "<<novo.getDestinatario()%tamanhoTabela<<std::endl;
            }
        }
        //Consulta e-mail no servidor
        else if(comando == "CONSULTA"){
            arquivoEntrada>>idUsuario;
            arquivoEntrada>>idEmail;
            //Verifica se parametros estao na faixa desejada
            if(idUsuario >= MINIMO && idUsuario <=  MAXIMO && idEmail >= MINIMO && idEmail <= MAXIMO){
                novo = tabela.pesquisa(idUsuario,idEmail);
                arquivoSaida<<"CONSULTA "<<idUsuario<<" "<<idEmail<<": "<<novo.getMensagem()<<std::endl;
            }
        }
        //Remove e-mail do servidor
        else if(comando == "APAGA"){
              arquivoEntrada>>idUsuario;
            arquivoEntrada>>idEmail;
            //Verifica se parametros estao na faixa desejada
             if(idUsuario >= MINIMO && idUsuario <=  MAXIMO && idEmail >= MINIMO && idEmail <= MAXIMO){
                if(tabela.remove(idUsuario,idEmail) ==  1){
                    arquivoSaida<<"OK: MENSAGEM APAGADA"<<std::endl;
                }
                else{
                    arquivoSaida<<"ERRO: MENSAGEM INEXISTENTE"<<std::endl;
                }  
            }
        }
    }
    arquivoSaida.close();
    arquivoEntrada.close();
    return 0;
}