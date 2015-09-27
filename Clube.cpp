#include "Clube.h"
#include<iostream>
using namespace std;

Clube::Clube()
{
    pontos = 0;
    vitorias = 0;
    saldo = 0;
    gols = 0;
    estado=false;
}

void Clube::AdicionarJogo(){
    jogos += 1;
}

void Clube::AdicionarPontos(int p){
    pontos += p;
}

void Clube::AdicionarVitoria(){
    vitorias += 1;
}

void Clube::AdicionarEmpate(){
    empates += 1;
}

void Clube::AdicionarDerrota(){
    derrotas += 1;
}

void Clube::ModificarSaldo(int s){
    saldo += s;
}

void Clube::AdicionarGol(int gol){
    gols += gol;
}

void Clube::AdicionarGolTomado(int gol){
    golstomados += gol;
}

void Clube::Exibir(){
    cout << "Time: " << nome << endl;
    cout << "Vitorias: " << vitorias << endl;
    cout << "Saldo: " << saldo << endl;
    cout << "Gols: " << gols << endl;
}

void Clube::TrocaEstado(){
    estado = !estado;
}

bool Clube::GetEstado(){
    return estado;
}




