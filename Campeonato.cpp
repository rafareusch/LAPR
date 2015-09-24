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

void Campeonato::LeArquivo(){
    ifstream arq;
    string teste, linha;

    arq.open("Jogos.txt", ios::in);

    if (!arq)
    {
      cout << "Problemas na abertura do arquivo" << endl;
      return;
    }

    while (!arq.eof())
   {
        getline(arq,linha,' ');
        cout << linha << endl;

   }
     arq.close();


}
