#pragma once
#include "Jogo.h"

class Menu
{
protected:
	BITMAP* buffer;
    BITMAP* fundoM;	// Fundo do Menu
	Jogo* J;

public:
	Menu();
	virtual ~Menu();

	virtual void Iniciar() = 0;

	void setbuffer(BITMAP* B);
	void setfundoM(BITMAP* M);
	void setJogo(Jogo* J);
};
