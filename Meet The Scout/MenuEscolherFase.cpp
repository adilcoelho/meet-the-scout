#include "stdafx.h"
#include "MenuEscolherFase.h"

MenuEscolherFase::MenuEscolherFase()
{
}

MenuEscolherFase::~MenuEscolherFase()
{
}

void MenuEscolherFase::Iniciar()
{
	MEF();
}

void MenuEscolherFase::MEF()
{
	while (!key[KEY_ESC]) // Loop principal.
    {
        draw_sprite(buffer, fundoM, 0, 0); // Desenha a imagem de fundo.

        if ( key[KEY_1] || key[KEY_1_PAD] ) // Opção 1 (Fase 1).
        {
			printf("OP1_3\n");
			J->IniciarFase1();
        }
        else if ( key[KEY_2] || key[KEY_2_PAD] ) // Opção 2 (Fase 2).
        {
			printf("OP2_3\n");
			J->IniciarFase2();
        }
        else if ( key[KEY_3] || key[KEY_3_PAD] ) // Opção 3 (Fase 3).
        {
			printf("OP3_3\n"); 
			J->IniciarFase3();
        }
		else if ( key[KEY_B] ) // Opção 3 (Fase 3).
        {
			printf("OPB_3\n"); 
			J->IniciarFaseBatalha();
        }
		else if ( key[KEY_4] || key[KEY_4_PAD] ) // Opção 4 (Voltar).
        {
			while( key[KEY_4] || key[KEY_4_PAD] );	//O Jogador volta assim que soltar a tecla, para que não saia do jogo.
			break;
        }
		
        blit(buffer, screen, 0, 0, 0, 0, 800, 600); // Desenha o buffer na tela.
        clear( buffer ); // Limpa o buffer;
    }
}
