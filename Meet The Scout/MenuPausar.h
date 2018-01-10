#pragma once
#include "menu.h"
#include "Gerenciador_Save.h"
#include "Jogador.h"

class MenuPausar : public Menu
{
private:
	
	int fase, tela, pont;
	Jogador* Jog;
	bool Sair;
	Gerenciador_Save* GS;

public:
	MenuPausar();
	~MenuPausar();

	void Iniciar();
	void Iniciar(int fase, int tela, Jogador* J);
	void MP();

	void setSair(const bool S);
	void setGerSave(Gerenciador_Save* GS);
	const bool getSair();
};

