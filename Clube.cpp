#include "Clube.h"
#include<iostream>
using namespace std;

Clube::Clube()
{
    pontos = 0;
    vitorias = 0;
    saldo = 0;
    gols = 0;
    golstomados = 0;
    jogos = 0;
    empates = 0;
    derrotas =0;
    estado=false;
}


void Clube::AdicionarJogo(string time,int golsf,int golst, int controle){
    saldo = saldo + (golsf - golst);
    nome = time;
    jogos += 1;
    gols += golsf;
    golstomados += golst;
    if (controle == 1){
        pontos += 3;
        vitorias += 1;
    }
    if (controle == 0){
        pontos += 1;
        empates += 1;
    }
    if (controle == -1)
        derrotas += 1;
}






void Clube::Exibir(){
    cout << "Time: " << nome << endl;
    cout << "Pontos: " << pontos << endl;
    cout << "Jogos: " << jogos << endl;
     cout << "Vitorias " << vitorias << endl;
    cout << "Empates:" << empates << endl;
    cout << "Derrotas: "  << derrotas << endl;
    cout << "Saldo: " << saldo << endl;
    cout << "Gols: " << gols << endl;
    cout << "Gols tomados: " << golstomados << endl;
}

void Clube::TrocaEstado(){
    estado = true;
}

bool Clube::GetEstado(){
    return estado;
}

string Clube::GetNome(){
    return nome;
}




