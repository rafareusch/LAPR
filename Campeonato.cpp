#include "Campeonato.h"
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;
using std::ifstream;


Campeonato::Campeonato()
{

}

void Campeonato::LeArquivo(){// string 19 = primeiro time
    int i=0,gol1,gol2,ex=0;
    ifstream arq;
    string linha, time1,time2,lixo;

    arq.open("Jogos.txt", ios::in);

    if (!arq){
      cout << "Problemas na abertura do arquivo" << endl;
      return;
    }
    while (!arq.eof()){
        getline(arq,linha,' ');
        if (i == 18){
            if (linha == "Sao"){
                linha = "Sao Paulo";
                ex=1;
            }
            if (linha == "Ponte"){
                linha = "Ponte Preta";
                ex=1;
            }
            time1 = linha;
        }
        if ( i == (22 + ex)){
            gol1 = atoi(linha.c_str());
        }
        if ( i == (30 + ex)){
            gol2 = atoi(linha.c_str());
        }
        if ( i == (34 + ex)){
            if (linha == "Sao"){
                linha = "Sao Paulo";
                getline(arq,lixo,' ');
            }
            if (linha == "Ponte"){
                linha = "Ponte Preta";
                getline(arq,lixo,' ');
            }
            time2 = linha;
            Vencedor(time1,time2,gol1,gol2);
            i=0;
            ex=0;
        }
        i++;
   }
    arq.close();
}

void Campeonato::Vencedor(string time1, string time2, int gol1, int gol2){
    if( gol1 > gol2 ){
        cout << "1Vencedor: " << time1 << endl;
        Atribuir(time1,gol1,gol2,1);
    }
    if( gol1 < gol2 ){
        cout << "2Vencedor: " << time2 << endl;
    }
    if( gol1 == gol2 ){
        cout << "Empate!" << endl;
    }

}

void Campeonato::Atribuir(string nome,int golfeito, int goltomado, int vitoria){
    int i = Pesquisar(nome), saldo = (golfeito-goltomado);

    if (vitoria == 1){
        Clubes[i].AdicionarGol(golfeito);
        Clubes[i].AdicionarPontos(3);
        Clubes[i].ModificarSaldo(saldo);
        Clubes[i].AdicionarVitoria();
        Clubes[i].AdicionarJogo();
        Clubes[i].AdicionarGolTomado(goltomado);
    return;
    }
    if (vitoria == 0){
        Clubes[i].AdicionarEmpate();
        Clubes[i].AdicionarGol(golfeito);
        Clubes[i].AdicionarGolTomado(goltomado);
        Clubes[i].ModificarSaldo(saldo);
        Clubes[i].AdicionarJogo();
        Clubes[i].AdicionarPontos(1);
        return;
    }
    if (vitoria == -1){
        Clubes[i].AdicionarGol(golfeito);
        Clubes[i].ModificarSaldo(saldo);
        Clubes[i].AdicionarDerrota();
        Clubes[i].AdicionarJogo();
        Clubes[i].AdicionarGolTomado(goltomado);
        return;
    }

}
int Campeonato::Pesquisar(string nome){
    int i=0;
    bool found=false;

    while (!found){
        if (!Clubes[i].GetEstado())
            return i;
        i++;
    }
    return -1;
}

