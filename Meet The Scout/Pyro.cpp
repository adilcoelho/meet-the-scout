#include "StdAfx.h"
#include "Pyro.h"


Pyro::Pyro(void)
{
}


Pyro::~Pyro(void)
{
}

Pyro :: Pyro(int posx, int posy, BITMAP* img)
{
	ehinimigo = 1;
	x = posx; y = -50; this->img = img;
	h = this->img->h;
	l = this->img->w;
	vx = 2;
	vy = 1;
}

void Pyro::Mover()
{
	if(ativo == 1)
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
		/*else if (B == 1 && y < 600 - h - HChao)
		{
			pulou = 0;
			vy = 0;
		}*/
		else
		{
			pulou = 0;
			vy = 0;
		}

		if(y + h >= 600 - HChao){ y = 600 - h - HChao; }

    
		if (C == 1)
		{
			vy = 1;
			pulou = 2;
		}

		//if(E==0 && D==0) 
		if(E==1 || D==1) vx = -vx;
		x = x + vx;
		if(x<=0 || x + l >= SCREEN_W) vx = -vx;

		y = y + vy;
	}
}
