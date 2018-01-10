#include "StdAfx.h"
#include "Heavy.h"


Heavy::Heavy(void)
{
	ehinimigo = 1;
	vx = 1; vy = 1;
}


Heavy::~Heavy(void)
{
}

Heavy :: Heavy(int posx, int posy, BITMAP* img)
{
	ehinimigo = 1;
	x = posx; y = -50; 
	this->img = img;
	h = this->img->h;
	l = this->img->w;
	vx = 4;
	vy = 1;
}