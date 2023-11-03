#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../include/palavra.hpp"
#include "../include/celula.hpp"
#include "../include/lista.hpp"
#include "../include/controleLista.hpp"
#include "time.h"
//linha de exemplo :./tp2.out -i|I in.txt -m|M pivo -s|S tamanho -o|O out.txt
void parseArgs(int argc,char* argv[],std::string *entrada,std::string *saida,
            int *pivo,int *tamanho){
    //Pula o nome do executavel
    int i = 1;
    std::string arg;
    std::stringstream aux;
    //Caso esses parametros nao sejam passados por padrao eles sao 0
    *pivo = 0;
    *tamanho = 0;
    while(i<argc){
        arg = argv[i];
        if(arg == "-i" || arg == "-I"){
            *entrada = argv[i+1];
        }
        else if(arg == "-m" || arg == "-M"){
            *pivo = atoi(argv[i+1]);
        }
        else if(arg == "-s" || arg == "-S"){
            aux << argv[i+1];
            aux >> *tamanho;
        }
        else if(arg == "-o" || arg == "-O"){
            *saida = argv[i+1];
        }
        i++;
    }
};
//Funcao normaliza as palavras para a forma minuscula
void normalizaString(std::string *str){
    std::string::iterator it;
    for(it = str->begin();it != str->end();++it){
        if(*it >= 'A' && *it <= 'Z'){
            *it = *it + 32;
        }
    }
}
//Retira pontuacao do final das palavras
void limpaAcentuacao(std::string *str){
    std::string::iterator it;
    it = str->end() -1;
     if(*it < 'a' || *it  > 'z'){
         if(*it < '0' || *it > '9'){
              str->erase(str->size()-1,1);
         }
    }
}
int main(int argc,char* argv[]){
    std::string entrada;
    std::string saida;
    std::string str;
    std::string tipo;
    int tamanho;
    int pivo;
    std::ifstream arquivoEntrada;
    parseArgs(argc,argv,&entrada,&saida,&pivo,&tamanho);
    //Caso os nomes dos arquivos de entrada e saida nao tenham sido passados apresenta falha
    if(entrada.empty()){
        std::cout<<"não foi passado um argumento para o arquivo de entrada"<<std::endl;
        return 0;
    }
    if(saida.empty()){
        std::cout<<"não foi passado um argumento para o arquivo de saida"<<std::endl;
    }
    controleLista control = controleLista(saida);
    arquivoEntrada.open(entrada);
    arquivoEntrada>>tipo;
    //Loop de leitura do arquivo de entrada
    while(arquivoEntrada >> str){
        //Monta lista com a nova ordem lexicografica
        if(tipo == "#ORDEM"){
            if(str == "#TEXTO"){
                tipo = "#TEXTO";
            }
            else{
                normalizaString(&str);
                control.montaOrdem(str);
            }
        }
        //Monta lista com as palavras do texto
        else if(tipo == "#TEXTO"){
            if(str == "#ORDEM"){
                tipo = "#ORDEM";
            }
            else{
                normalizaString(&str);
                limpaAcentuacao(&str);
                control.montaTexto(str);
            }
        }
    }
    //Ordena palavras do texto
    control.ordena(tamanho,pivo);
    arquivoEntrada.close();
    return 0;
}