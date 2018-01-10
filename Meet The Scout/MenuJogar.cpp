#include "stdafx.h"
#include "MenuJogar.h"

MenuJogar::MenuJogar()
{
}

MenuJogar::~MenuJogar()
{
}

void MenuJogar::Iniciar()
{
	MJ();
}

void MenuJogar::MJ()
{
	while (1) // Loop principal.
    {
        draw_sprite(buffer, fundoM, 0, 0); // Desenha a imagem de fundo.

        if ( key[KEY_1] || key[KEY_1_PAD] ) // Opção 1 (Novo Jogo).
        {
			printf("OP1_2\n");
			J->Iniciar();
        }
        else if ( key[KEY_2] || key[KEY_2_PAD] ) // Opção 2 (Escolher Fase).
        {
			while( key[KEY_2] || key[KEY_2_PAD] );
			printf("OP2_2\n");
			MEF->Iniciar();
        }
        else if ( key[KEY_3] || key[KEY_3_PAD] ) // Opção 3 (Carregar Jogo).
        {
			GS->loade();
			J->IniciarC();
			while(key[KEY_3] || key[KEY_3_PAD]);
        }
		else if ( key[KEY_4] || key[KEY_4_PAD] || key[KEY_ESC] ) // Opção 4 (Voltar).
        {
			while( key[KEY_4] || key[KEY_4_PAD] || key[KEY_ESC] );	//O Jogador volta assim que soltar a tecla, para que não saia do jogo.
			break;
        }
		
        blit(buffer, screen, 0, 0, 0, 0, 800, 600); // Desenha o buffer na tela.
        clear( buffer ); // Limpa o buffer;
    }
}

void MenuJogar::setMenuEscolherFase(MenuEscolherFase* ME)
{
	MEF = ME;
}

void MenuJogar::setGerSave(Gerenciador_Save* GS)
{
	this->GS = GS;
}