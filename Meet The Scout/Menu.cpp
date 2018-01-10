#include "stdafx.h"
#include "Menu.h"

Menu::Menu()
{
	buffer = NULL;
	fundoM = NULL;
	J = NULL;
}

Menu::~Menu()
{
}

void Menu::setbuffer(BITMAP* B)
{	
	buffer = B;
}

void Menu::setfundoM(BITMAP* M)
{	
	fundoM = M;
}

void Menu::setJogo(Jogo* J)
{
	this->J=J;
}
