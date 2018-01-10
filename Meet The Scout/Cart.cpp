#include "StdAfx.h"
#include "Cart.h"


Cart::Cart(void)
{
}

Cart::Cart(int px, int py)
{
	 img = load_bitmap("Arquivos//Imagens//Cart.bmp", NULL);
	h = this->img->h;
	l = this->img->w;
	x = px; y = py;
}

Cart::Cart(int px, int py, int ph, int pl)
{
	img = NULL;
	x = px; y = py; 
	h = ph;
	l = pl;
}


Cart::~Cart(void)
{
}
