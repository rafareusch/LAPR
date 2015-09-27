#ifndef CLUBE_H
#define CLUBE_H
#include<iostream>

#include<string.h>
using namespace std;


class Clube
{
		string nome;
		int jogos,pontos,vitorias,empates,derrotas,saldo,gols,golstomados;
        bool estado;
	public:
		Clube();
		void AdicionarPontos(int p);
		void AdicionarVitoria();
		void ModificarSaldo(int gol);
		void AdicionarGol(int gol);
		void AdicionarGolTomado(int gol);
		void AdicionarJogo();
		void AdicionarDerrota();
		void AdicionarEmpate();
		void Exibir();
		void TrocaEstado();
		bool GetEstado();



};
#endif

