#include "stdafx.h"
#include "MenuRaiz.h"


MenuRaiz::MenuRaiz(){}

MenuRaiz::~MenuRaiz()
{
	buffer = NULL; // Aterra o ponteiro para o buffer;  
}

void MenuRaiz::Iniciar()
{
	Raiz();
}

void MenuRaiz::Raiz()
{

	while (!key[KEY_ESC]) // Loop principal.
	{
		draw_sprite(buffer, fundoM, 0, 0); // Desenha a imagem de fundo.

		if ( key[KEY_1] || key[KEY_1_PAD] ) // Opção 1 (jogar).
		{
			while( key[KEY_1] || key[KEY_1_PAD] );
			printf("OP1\n");
			MJ->Iniciar();
		}
		else if ( key[KEY_2] || key[KEY_2_PAD] ) // Opção 2 (Instruções).
		{
			printf("OP2\n");
			Instrucoes();
		}
		else if ( key[KEY_3] || key[KEY_3_PAD] ) // Opção 3 (Records).
		{
			Garq->Ver_Record();
			printf("OP3\n"); 
		}
		else if ( key[KEY_4] || key[KEY_4_PAD] ) // Opção 4 (Sair).
		{
			break;
		}

		blit(buffer, screen, 0, 0, 0, 0, 800, 600); // Desenha o buffer na tela.
		clear( buffer ); // Limpa o buffer;
	}
}

void MenuRaiz::Instrucoes()
{
	while (!key[KEY_ESC]) //loop principal.
	{
		draw_sprite(buffer, fundoI, 0, 0); // Desenha a imagem de fundo.

		if(key[KEY_ENTER])
			break;

		blit(buffer, screen, 0, 0, 0, 0, 800, 600); // Desenha o buffer na tela.
		clear( buffer ); // Limpa o buffer;
	} 
	while (key[KEY_ESC]);
}

/* Sets */

void MenuRaiz::setfundoinstrucoes( BITMAP* I)
{
	fundoI = I;
}

void MenuRaiz::setMenuJogar( MenuJogar* M )
{
	MJ = M;
}

void MenuRaiz::setGerenciadorArquivos(GerenciadorArquivos *pGarq)
{
	Garq = pGarq;
}
