#pragma once
#include "Jogo.h"
#include "Menu.h"
#include "MenuEscolherFase.h"
#include "Gerenciador_Save.h"

class MenuJogar : public Menu
{
private:
	MenuEscolherFase* MEF;
	Gerenciador_Save* GS;

public:
	MenuJogar();
	~MenuJogar();

	void Iniciar();
    void MJ();

	void setMenuEscolherFase(MenuEscolherFase* ME);
	void setGerSave(Gerenciador_Save* GS);
	
};

