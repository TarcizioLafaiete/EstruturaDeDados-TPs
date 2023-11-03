#include "../include/controleLista.hpp"
/*---------------------------------------------------------------------------------------------------------
                                    CONSTRUTOR DE CLASSE
-----------------------------------------------------------------------------------------------------------*/
controleLista::controleLista(std::string saida){
    this->ordem = listaPalavras();
    this->texto = listaPalavras();
    this->valorOrdem = 65;
    this->arquivoSaida.open(saida);
};
/*---------------------------------------------------------------------------------------------------------
                                    MONTA UMA LISTA COM A NOVA ORDEM LEXICOGRAFICA
-----------------------------------------------------------------------------------------------------------*/
void controleLista::montaOrdem(std::string str){
    palavra novaPalavra;
    if(valorOrdem <= 90){
        novaPalavra.setPalavra(str);
        novaPalavra.setValor(this->valorOrdem);
        this->ordem.inserePalavraInicio(novaPalavra);
        this->valorOrdem ++;
    }
};
/*---------------------------------------------------------------------------------------------------------
                                    MONTA A LISTA DE PALAVRAS CONTIDAS NO TEXTO
-----------------------------------------------------------------------------------------------------------*/
void controleLista::montaTexto(std::string str){
    palavra paux = palavra();
    paux = texto.pesquisaPalavra(str);
    if(paux.getPalavra() ==  "#ORDEM"){
        paux.setPalavra(str);
        this->texto.inserePalavraFim(paux);
    }
    else{
        this->texto.incrementaPalavra(str);
    }
};
/*---------------------------------------------------------------------------------------------------------
                                   CHAMA O METODO PARA ORDENAR A LISTA
-----------------------------------------------------------------------------------------------------------*/
void controleLista::ordena(int melhoria,int grupoPivo){
    if(ordem.getTamanho() == 0 || texto.getTamanho() == 0){
        std::cout<<"falha na analise do arquivo de entrada"<<std::endl;
        return;
    }
    int tamanho = texto.getTamanho();
    palavra vetorPalavras[tamanho];
    for(int i = 0;i < tamanho;i++){
        vetorPalavras[i] = texto.getPalavraPosicao(i);
    }
    this->quicksort(0,tamanho - 1,vetorPalavras,melhoria,grupoPivo);
    this->imprimiVetor(vetorPalavras);
};
/*---------------------------------------------------------------------------------------------------------
                                    PROCESSO DE ORDENACAO
-----------------------------------------------------------------------------------------------------------*/
void controleLista::quicksort(int esq,int dir,palavra *vetor,int melhoria,int grupoPivo){
    int i,j;
    if(melhoria > dir - esq){
        this->selecao(vetor,esq,dir);
    }
    else{
        this->particao(esq,dir,&i,&j,vetor,grupoPivo);
        if(esq < j){
            this->quicksort(esq,j,vetor,melhoria,grupoPivo);
        }
        if(i < dir){
            this->quicksort(i,dir,vetor,melhoria,grupoPivo);
        }
    }
};
palavra controleLista::escolhePivo(palavra *vetor,int grupoPivo,int pontoMedio){
    palavra vetorAuxiliar[grupoPivo];
    int esq = pontoMedio - grupoPivo/2;
    int dir = pontoMedio +  grupoPivo/2;
    int j = 0;
    for(int i = esq;i <  dir;i++){
        vetorAuxiliar[j] = vetor[i];
        j++;
    }
    this->selecao(vetorAuxiliar,0,j-1);
    return vetorAuxiliar[grupoPivo/2];
};
void controleLista::particao(int esq,int dir,int *i,int *j,palavra *vetor,int grupoPivo){
    palavra paux,ppivo;
    *i = esq;*j = dir;
    if(grupoPivo > dir - esq || grupoPivo == 0){
        ppivo = vetor[(dir + esq)/2];
    }
    else{
        ppivo = this->escolhePivo(vetor,grupoPivo,(dir + esq)/2);
    }
    do{
        while(this->comparaPalavrasNovaOrdem(ppivo.getPalavra(),vetor[*i].getPalavra())) (*i)++;
        while(this->comparaPalavrasNovaOrdem(vetor[*j].getPalavra(),ppivo.getPalavra())) (*j)--;
        if(*i <= *j){
            paux = vetor[*i];
            vetor[*i] = vetor[*j];
            vetor[*j] = paux;
            (*i)++;(*j)--;
        }
    } while(*i<=*j);
};
void controleLista::selecao(palavra *vetor,int esq,int dir){
    int minimo;
    palavra paux;
    for(int i = esq;i < dir;i++){
        minimo = i;
        for(int j = i + 1;j < dir + 1;j++){
            if(comparaPalavrasNovaOrdem(vetor[minimo].getPalavra(),vetor[j].getPalavra())){
                minimo = j;
            }
        }
        paux = vetor[i];
        vetor[i] = vetor[minimo];
        vetor[minimo] = paux;
    }
}
void controleLista::imprimiVetor(palavra *vetor){
    for(int i = 0;i < texto.getTamanho();i++){
        arquivoSaida<<vetor[i].getPalavra()<<" "<<vetor[i].getValor()<<std::endl;
    }
    arquivoSaida <<"#FIM";
    arquivoSaida.close();
}
/*---------------------------------------------------------------------------------------------------------
                            COMPARADOR DE PALAVRAS SEGUINDO A NOVA ORDEM LEXICOGRAFICA
-----------------------------------------------------------------------------------------------------------*/
bool controleLista::comparaPalavrasNovaOrdem(std::string palavra1,std::string palavra2){
    int valorPalavra1,valorPalavra2;
    std::string::iterator itPalavra1 = palavra1.begin();
    std::string::iterator itPalavra2 = palavra2.begin();
    std::string letraPalavra1,letraPalavra2;
    bool maior;
    if(palavra1.size() > palavra2.size()){
        maior = true;
    }
    else{
        maior = false;
    }
    palavra paux1 = palavra();
    palavra paux2 = palavra();
    while(itPalavra1 != palavra1.end() && itPalavra2 != palavra2.end()){
        letraPalavra1 = *itPalavra1;
        paux1 = ordem.pesquisaPalavra(letraPalavra1);
        letraPalavra2 = *itPalavra2;
        paux2 = ordem.pesquisaPalavra(letraPalavra2);
        if(paux1.getPalavra() == "#ORDEM"){
            valorPalavra1 = *itPalavra1;
        }
        else{
            valorPalavra1 = paux1.getValor();
        }
        if(paux2.getPalavra() == "#ORDEM"){
            valorPalavra2 = *itPalavra2;
        }
        else{
            valorPalavra2 = paux2.getValor();
        }
        if(valorPalavra1 > valorPalavra2){
            return true;
        }
        else if(valorPalavra1<valorPalavra2){
            return false;
        }
        ++itPalavra2;
        ++itPalavra1;
    }
    return maior;
};