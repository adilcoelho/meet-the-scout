#include "stdafx.h"
#include "Caixa.h"


Caixa::Caixa()
{
}

Caixa::Caixa(int px, int py)
{
	img = load_bitmap("Arquivos//Imagens//Caixa.bmp", NULL);
	h = this->img->h;
	l = this->img->w;
	x = px; y = py; 
}

Caixa::Caixa(int px, int py, int ph, int pl)
{
	img = NULL;
	x = px; y = py; 
	h = ph;
	l = pl;
}

Caixa::~Caixa()
{
}
