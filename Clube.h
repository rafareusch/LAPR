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
		void AdicionarJogo(string time,int gols,int golst, int controle);
		void Exibir();
		void TrocaEstado();
		bool GetEstado();
		string GetNome();
		int GetPontos();
		void SetNome(string n);
		int GetJogos();
		int GetVitorias();
	        int GetEmpates();
		int GetDerrota();
		int GetSaldo();
		int GetGols()
		int GetGolsTomados();
        	void SetJogos(int x);
        	void SetVitorias(int x);
        	void SetEmpates(int x);
        	void SetDerrota(int x);
        	void SetSaldo(int x);
        	void SetGols(int x);
        	void SetGolsTomados(int x);
        	void SetPontos(int x);
};
#endif

