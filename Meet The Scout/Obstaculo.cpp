#include "StdAfx.h"
#include "Obstaculo.h"


Obstaculo::Obstaculo()
{
}

Obstaculo::~Obstaculo()
{
}

void Obstaculo::Desenhar()
{
	
	draw_sprite(buffer, img, x, y);

}