#ifndef CAMPEONATO_H
#define CAMPEONATO_H
#include<iostream>

#include "Clube.h"
using namespace std;


class Campeonato
{
        Clube Clubes[20];
	public:
		Campeonato();
		void LeArquivo();
		void Vencedor(string time1, string time2, int gol1, int gol2);
		int Pesquisar(string nome);
		void Atribuir(string nome,int golfeito, int goltomado, int vitoria);
		void Exibe();
		void Ordena();
		void EscreveArquivo();


};

#endif
