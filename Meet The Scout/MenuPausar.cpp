#include "stdafx.h"
#include "MenuPausar.h"

MenuPausar::MenuPausar()
{
	Sair = false;
}

MenuPausar::~MenuPausar()
{
}

void MenuPausar::Iniciar()
{
	
	Sair = false;
	MP();
}

void MenuPausar::Iniciar(int fase, int tela, Jogador* J)
{
	Jog = J;
	this->fase = fase;
	this->tela = tela;
	Sair = false;
	MP();
}

void MenuPausar::MP()
{
	while (1) // Loop principal.
	{
		draw_sprite(buffer, fundoM, 0, 0); // Desenha a imagem de fundo.

		if (key[KEY_1]) break;

		else if (key[KEY_2])
		{
			Sair = true;
			break;
		}
		else if(key[KEY_3])
		{
			GS->salve(fase, tela, Jog);
			while(key[KEY_3]);
			break;
		}
		//else if (key[KEY_ENTER]) Sair = false; // TRATAR SALVAMENTO DO JOGO

		blit(buffer, screen, 0, 0, 0, 0, 800, 600); // Desenha o buffer na tela.
		clear( buffer ); // Limpa o buffer;
	}
	while( key[KEY_1] || key[KEY_2] || key[KEY_3] );
}

void MenuPausar::setSair(const bool S){ Sair = S; }
const bool MenuPausar::getSair(){ return Sair; }

void MenuPausar::setGerSave(Gerenciador_Save* GS) { this->GS = GS;}
