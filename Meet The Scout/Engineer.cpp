#include "StdAfx.h"
#include "Engineer.h"


Engineer::Engineer(void)
{
}


Engineer::~Engineer(void)
{
}

Engineer :: Engineer(int posx, int posy, BITMAP* img)
{
	ehinimigo = 1;
	if(posx <= SCREEN_W)
	x = posx;
	else
		x = 750;
	y = -50; this->img = img;
	h = this->img->h;
	l = this->img->w;
	vx = 4;
	vy = 1;
}