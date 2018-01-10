#include "stdafx.h"
#include "Jogador.h"


Jogador::Jogador()
{
	Qvidas = 3;
}

Jogador::~Jogador()
{
	img = NULL;
	//destroy_bitmap(img);  // Destrói a imagem;
}

void Jogador::setTec(Teclado* T)
{
	Tec = T;
}

void Jogador::setQvidas(int Q){ Qvidas = Q; }
	
int Jogador::getQvidas(){ return Qvidas; }

void Jogador::Mover()
{
	 if(B == 0 && y < 600 - h - HChao)
    {
        if(pulou == 0)
        {
            pulou = 1;
        }
        if(vy == 10) vy--;
        vy++;
    }
    else if (B == 1 && y < 600 - h - HChao)
    {
        pulou = 0;
        vy = 0;
    }
    else
    {
        pulou = 0;
        vy = 0;
    }

    if(y + h >= 600 - HChao) y = 600 - h - HChao;

	if(jogadorprincipal)
	{
		if ((Tec->apertou(KEY_UP)) && pulou <= 1)
		{
			vy = -15;
			pulou++;
		}
	}
	else
	{
		if ((Tec->apertou(KEY_W)) && pulou <= 1)
		{
			vy = -15;
			pulou++;
		}
	}
    if (C == 1)
    {
        vy = 1;
        pulou = 2;
    }


	if(jogadorprincipal)
	{
		if ((Tec->apertou(KEY_RIGHT) || Tec->segurou (KEY_RIGHT))&&( (x+l) < 850)&&(D == 0)) x = x + vx;
		if ((Tec->apertou(KEY_LEFT) || Tec->segurou (KEY_LEFT))&&( x > 0)&&(E == 0)) x = x - vx;
	}
	else
	{
		if ((Tec->apertou(KEY_D) || Tec->segurou (KEY_D))&&( (x+l) < 850)&&(D == 0)) x = x + vx;
		if ((Tec->apertou(KEY_A) || Tec->segurou (KEY_A))&&( x > 0)&&(E == 0)) x = x - vx;
	}

    y = y + vy;
    Tec->keyboard_input();
}




void Jogador :: setjogadorprincipal(bool JP)
{
	jogadorprincipal = JP;
}

bool Jogador :: getjogadorprincipal()
{
	return jogadorprincipal;
}