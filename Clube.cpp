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



void Clube::AdicionarJogo(string time,int golsf,int golst){
    nome = time;
    saldo = saldo + (golsf - golst);
    jogos += 1;
    gols += golsf;
    golstomados += golst;
    if (golsf > golst){
        pontos += 3;
        vitorias += 1;
    }
    if (golsf == golst){
        pontos += 1;
        empates += 1;
    }
    if (golst > golsf)
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

int Clube::GetPontos(){
    return pontos;
}

void Clube::SetNome(string n){
    nome = n;
}

int Clube::GetJogos(){
    return jogos;
}
int Clube::GetVitorias(){
    return vitorias;
}
int Clube::GetEmpates(){
    return empates;
}
int Clube::GetDerrota(){
    return derrotas;
}
int Clube::GetSaldo(){
    return saldo;
}
int Clube::GetGols(){
    return gols;
}
int Clube::GetGolsTomados(){
    return golstomados;
}
void Clube::SetJogos(int x){
    jogos = x;
}
void Clube::SetVitorias(int x){
    vitorias = x;
}
void Clube::SetEmpates(int x){
     empates = x;
}
void Clube::SetDerrota(int x){
     derrotas = x;
}
void Clube::SetSaldo(int x){
     saldo = x;
}
void Clube::SetGols(int x){
     gols = x;
}
void Clube::SetGolsTomados(int x){
    golstomados = x;
}
void Clube::SetPontos(int x){
    pontos = x;
}

