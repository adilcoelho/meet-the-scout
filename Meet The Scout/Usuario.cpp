#include "stdafx.h"
#include "Usuario.h"
//#define WHITE makecol(255, 255, 255)


Usuario::Usuario()
{
	Nome = "Unnamed";
	Pontuacao = 0;
}

Usuario::~Usuario()
{
}

void Usuario::CadastrarUsuario()
{
/*
	BITMAP* buffer = create_bitmap(320, 240);	// initialize the double buffer

	string nome;
	string::iterator iter = nome.begin();		// string iterator
	int     caret  = 0;							// tracks the text caret
	bool    insert = true;						// true if text should be inserted 
	
	clear_keybuf();  
	
	do
	{
		while(keypressed())
		{
			int  newkey   = readkey();
			char ASCII    = ( newkey & 0xff );
			char scancode = newkey >> 8;
			// a character key was pressed; add it to the string

			if(ASCII >= 32 && ASCII <= 126)
			{
				if( (insert || iter == nome.end()))		// add the new char, inserting or replacing as need be
					iter = nome.insert(iter, ASCII);	

				else
					nome.replace(caret, 1, 1, ASCII), cout<<caret;

				caret++;	// increment both the caret and the iterator
				iter++;
			}
			else
			{
				switch(scancode)
				{
				case KEY_DEL:		if(iter != nome.end()) iter = nome.erase(iter);
									break;

				case KEY_BACKSPACE:	if(iter != nome.begin())
									{
										caret--;
										iter--;
										iter = nome.erase(iter);
									}
									break;

				case KEY_RIGHT:		if(iter != nome.end())   caret++, iter++;
									break;

				case KEY_LEFT:		if(iter != nome.begin()) caret--, iter--;
									break;

				case KEY_INSERT:	insert = !insert;
									break;
				}
			}
		}
		
		clear(buffer);
		textout(buffer, font, nome.c_str(), 0, 10, makecol(255, 255, 255));
		blit(buffer, screen, 0, 0, 0, 0, 320, 240);
	}while(!key[KEY_ENTER]); // end of game loop

	Nome = nome;
*/
	char nome[11];
	int cor = makecol(0x98,0x98,0xBE);
	int c;
	int i = 0;	
	BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);

	clear_to_color(buffer, makecol(0,0x27,0x3f));
	textout_centre_ex(buffer, font, "DIGITE O SEU NOME:", SCREEN_W/2, SCREEN_H/2, cor, -1);
	draw_sprite(screen, buffer, 0, 0);

	do
	{
		clear_to_color(buffer, makecol(0,0x27,0x3f));
		textout_centre_ex(buffer, font, "DIGITE O SEU NOME:", SCREEN_W/2, SCREEN_H/2, cor, -1);
		clear_keybuf();
		c = readkey();

		if((((c >> 8) == KEY_ENTER) || ((c >> 8) == KEY_ENTER_PAD)) && i > 0)
			break;
		else if((((c >> 8) == KEY_ENTER) || ((c >> 8) == KEY_ENTER_PAD)) && i == 0)
			c = ( KEY_BACKSPACE << 8 );

		if((c >> 8) == KEY_BACKSPACE && i == 0)			
			nome[i] = '\0';
		else if((c >> 8) == KEY_BACKSPACE && i > 0)	
			nome[--i] = '\0';
		else if(i<10)
		{
			nome[i] = (c & 0xff);
			nome[++i] = '\0';
		}

		textprintf_centre_ex(buffer, font, SCREEN_W/2, SCREEN_H/2 + font->height, makecol(233, 208, 39), -1, "%s", nome);
		draw_sprite(screen, buffer, 0, 0);

	}while(((c >> 8) != KEY_ENTER) && ((c >> 8) != KEY_ENTER_PAD));

	while( key[KEY_ENTER] || key[KEY_ENTER_PAD] );

	destroy_bitmap(buffer);

	Nome = nome;
}

void Usuario::setNome (string N) { Nome = N; }

void Usuario::setPontuacao(const int Pont) { Pontuacao = Pont; }

string Usuario::getNome() { return Nome; }

const int Usuario::getPontuacao() { return Pontuacao; }

void Usuario::operator++()
{
	Pontuacao = Pontuacao + 100;
}

void Usuario::operator++(int)
{
	Pontuacao = Pontuacao + 100;
}
