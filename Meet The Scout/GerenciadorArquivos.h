#pragma once
#include "Teclado.h"
#include "Usuario.h"
#include <vector>
using namespace std;

class GerenciadorArquivos
{
private:
	Teclado *Tec;
public:
	GerenciadorArquivos();
	~GerenciadorArquivos();

	void Ver_Record();
	void Atualiza_Ranking(string nome, int pontuacao);

	void setTec(Teclado* pTec);
};

