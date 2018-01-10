#include "StdAfx.h"
#include "Dispenser.h"


Dispenser::Dispenser(void)
{
}

Dispenser::Dispenser(int px, int py)
{
	img = load_bitmap("Arquivos//Imagens//Dispenser.bmp", NULL);
	h = this->img->h;
	l = this->img->w;
	x = px; y = py; 
}

Dispenser::Dispenser(int px, int py, int ph, int pl)
{
	img = NULL;
	x = px; y = py; 
	h = ph;
	l = pl;
}


Dispenser::~Dispenser(void)
{
}

