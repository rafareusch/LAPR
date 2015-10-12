#include "Campeonato.h"
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include <iomanip> //setprecision
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
         //cout << linha << " | " << i << endl;
        if (i==5)
            time1 = linha;
        if (i==6)
            gol1 = atoi(linha.c_str());
        if (i==8)
            gol2 = atoi(linha.c_str());
        if (i==9)
            time2 = linha;
        if (i==11){
            Clubes[Pesquisar(time1)].AdicionarJogo(time1,gol1,gol2);
            Clubes[Pesquisar(time2)].AdicionarJogo(time2,gol2,gol1);
            i=0;
        }
        i++;
    }
    arq.close();
}

int Campeonato::Pesquisar(string nome){
    int i=0;

    while (i<20){
        if (nome == Clubes[i].GetNome() || Clubes[i].GetEstado() == false){
            Clubes[i].TrocaEstado();
            return i;
        }
        i++;
    }

    cout << "Sem espaço: " << nome; // nunca deve chegar aqui
    return 0;
}



void Campeonato::Exibe(){
    int i=0;
    cout << endl;
    while (i<20){
        Clubes[i].Exibir();
        cout << endl;
        i++;
    }
    return;
}




void Campeonato::Ordena(){
    Clube aux;
    for(int x = 0; x < 20; x++ )
        for(int y = x + 1; y < 20; y++ ){
            if ( Clubes[y].GetPontos() > Clubes[x].GetPontos() )
                goto troca;
            if( Clubes[y].GetPontos() == Clubes[x].GetPontos() && Clubes[y].GetVitorias() > Clubes[x].GetVitorias())
                goto troca;
            if( Clubes[y].GetPontos() == Clubes[x].GetPontos() && Clubes[y].GetVitorias() == Clubes[x].GetVitorias() && Clubes[y].GetSaldo() > Clubes[x].GetSaldo()){
                troca:
                aux = Clubes[y];
                Clubes[y] = Clubes[x];
                Clubes[x] = aux;
            }
        }
}

void Campeonato::EscreveArquivo(){
    ofstream arq;
    arq.open( "Tabela.txt" , ios::out );
    float percent = 0;
    arq << "                        P	J	V	E	D	SG	G	GC	%"<< endl;
    for (int i=0;i<20;i++){
        percent = (float)((Clubes[i].GetVitorias() + ((float)Clubes[i].GetEmpates()/3)) * 100) / (float)Clubes[i].GetJogos();
        if (Clubes[i].GetNome() == "Sport" || Clubes[i].GetNome() == "Avai" || Clubes[i].GetNome() == "Vasco" || Clubes[i].GetNome() == "Goias"){
            arq << Clubes[i].GetNome() << "    \t\t" << Clubes[i].GetPontos() << "\t" << Clubes[i].GetJogos() << "\t" << Clubes[i].GetVitorias() << "\t" << Clubes[i].GetEmpates() << "\t" << Clubes[i].GetDerrota();
            arq << "\t" << Clubes[i].GetSaldo() << "\t" << Clubes[i].GetGols() << "\t" << Clubes[i].GetGolsTomados() << "\t" << setprecision(3) << percent << endl;
        }else{
            arq << Clubes[i].GetNome() << "  \t\t" << Clubes[i].GetPontos() << "\t" << Clubes[i].GetJogos() << "\t" << Clubes[i].GetVitorias() << "\t" << Clubes[i].GetEmpates() << "\t" << Clubes[i].GetDerrota();
            arq << "\t" << Clubes[i].GetSaldo() << "\t" << Clubes[i].GetGols() << "\t" << Clubes[i].GetGolsTomados() << "\t" << setprecision(3) << percent << endl;
        }
    }arq.close();
}




