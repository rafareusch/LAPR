#include "Campeonato.h"
#include<iostream>
#include<fstream>
#include<string.h>

using std::ifstream;
using namespace std;

Campeonato::Campeonato()
{
	cout<< "teste construtor";
}

void Campeonato::LeArquivo(){// string 19 = primeiro time
    int i=0,gol1,gol2;
    ifstream arq;
    string linha, time1,time2;

    arq.open("Jogos.txt", ios::in);

    if (!arq){
      cout << "Problemas na abertura do arquivo" << endl;
      return;
    }

    while (!arq.eof()){
        getline(arq,linha,' ');
       // cout << linha << "/";
        if (i == 18){
            time1 = linha;
          //  cout << time1 << endl;
          //  cout << "i =" << i <<"  ";
        }
        if ( i == 22){
            gol1 = atoi(linha.c_str());
           // cout << gol1 << endl;
           // cout << "i =" << i <<"  ";
        }
        if ( i == 30){
            gol2 = atoi(linha.c_str());
           // cout << gol2 << endl;
           // cout << "i =" << i <<"  ";
        }
        if ( i == 34){
            time2 = linha;
           // cout << time2 << endl;
           //cout << "i =" << i <<"  ";
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
    }
    if( gol1 < gol2 ){
        cout << "2Vencedor: " << time2 << endl;
    }
    if( gol1 == gol2 ){
        cout << "Empate!" << endl;
    }

}

