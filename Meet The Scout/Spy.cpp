#include "StdAfx.h"
#include "Spy.h"


Spy::Spy()
{
	ehinimigo = 1;
	vx = 1; vy = 1;
}


Spy::~Spy()
{
}

void Spy :: Desenhar ()
{
	if(ativo == 1 && (x - J->getx() <= 250))
		draw_sprite(buffer, img, x, y);
}

/*void Spy :: setjogador (Jogador* J)
{
	this->J = J;
}*/

Spy :: Spy(int posx, int posy, BITMAP* img, Jogador* J)
{
	ehinimigo = 1;
	x = posx; y = -50;
	this->img = img;
	h = this->img->h;
	l = this->img->w;
	vx = 1;
	vy = 1;
	this->J = J;
}