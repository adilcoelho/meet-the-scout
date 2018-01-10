#include "StdAfx.h"
#include "Demoman.h"


Demoman::Demoman(void)
{
}


Demoman::~Demoman(void)
{
}

Demoman :: Demoman(int posx, int posy, BITMAP* img)
{
	ehinimigo = 1;
	x = posx; y = -50; this->img = img;
	h = this->img->h;
	l = this->img->w;
	vx = 3;
	vy = 1;
}