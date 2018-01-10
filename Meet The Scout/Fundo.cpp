#include "stdafx.h"
#include "Fundo.h"


Fundo::Fundo()
{
}

Fundo::~Fundo()
{
	//destroy_bitmap(img);
	img = NULL;
}

void Fundo::Desenhar()
{
	draw_sprite(buffer,img, x, y);
}
