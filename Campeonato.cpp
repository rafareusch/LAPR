#include "Campeonato.h"
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;
using std::ifstream;


Campeonato::Campeonato()
{
    Clube();

}

void Campeonato::LeArquivo(){
    int i=1,gol1,gol2;
    ifstream arq;
    string linha,time1,time2;
    arq.open("Jogos.txt", ios::in);
    while (!arq.eof()){
        getline(arq,linha,'\t');
        if (i==5)
            time1 = linha;
        if (i==6)
            gol1 = atoi(linha.c_str());
        if (i==8)
            gol2 = atoi(linha.c_str());
        if (i==9)
            time2 = linha;
        if (i==11){
            Vencedor(time1,time2,gol1,gol2);
            i=0;
        }
        i++;
    }
    arq.close();
}

void Campeonato::Vencedor(string time1, string time2, int gol1, int gol2){
    if( gol1 > gol2 ){
        cout << "1Vencedor: " << time1 << endl;
        Atribuir(time1,gol1,gol2,1);
        Atribuir(time2,gol2,gol1,-1);
    }
    if( gol1 < gol2 ){
        cout << "2Vencedor: " << time2 << endl;
        Atribuir(time2,gol2,gol1,1);
        Atribuir(time1,gol1,gol2,-1);
    }
    if( gol1 == gol2 ){
        Atribuir(time1,gol1,gol2,0);
        Atribuir(time2,gol2,gol1,0);
        cout << "Empate!" << endl;
    }

}

void Campeonato::Atribuir(string nome,int golfeito, int goltomado, int vitoria){
    int i;
    i = Pesquisar(nome);
    if (vitoria == 1)
        Clubes[i].AdicionarJogo(nome,golfeito,goltomado,1);
    if (vitoria == 0)
        Clubes[i].AdicionarJogo(nome,golfeito,goltomado,0);
    if (vitoria == -1)
        Clubes[i].AdicionarJogo(nome,golfeito,goltomado,-1);

    return;
}
int Campeonato::Pesquisar(string nome){
    int i=0;

    while (i<20){
        if (nome == Clubes[i].GetNome() || Clubes[i].GetEstado() == false){
            cout << i << " retornado" << endl;
            Clubes[i].TrocaEstado();
            return i;
        }
        i++;
    }
    cout << "Sem espaço"; // nunca deve chegar aqui
    return 0;
}

void Campeonato::Exibe(){
    int i=0;
    while (i<20){
        Clubes[i].Exibir();
        cout << endl;
        i++;
    }
    return;
}


