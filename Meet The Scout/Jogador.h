#pragma once
#include "Personagem.h"
#include "Teclado.h"

class Jogador : public Personagem
{
private:
	Teclado* Tec;
	int Qvidas;
	bool jogadorprincipal;

public:
	Jogador();
	~Jogador();

	void setQvidas(int Q);
	void setjogadorprincipal(bool JP);
	void setTec(Teclado* T);

	int getQvidas();
	bool getjogadorprincipal();

	

	virtual void Mover();

	
};