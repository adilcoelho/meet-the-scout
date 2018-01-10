#include "stdafx.h"
#include "Personagem.h"
#include <iostream>

Personagem::Personagem()
{
	C = false;
    B = false;
    D = false;
    E = false;
	Matou = false;
}

Personagem::~Personagem(){}


void Personagem::setvx( const int VX ){ vx = VX; }

void Personagem::setvy( const short int VY ){ vy = VY; }

void Personagem::setpulou( const int P ){ pulou = P; }


const int Personagem::getpulou(){ return pulou; }

const short int Personagem::getvx(){ return vx; }

const short int Personagem::getvy(){ return vy; }

void Personagem::Desenhar()
{
	if(ativo == 1)
	draw_sprite(buffer, img, x, y);
}

void Personagem :: setCol(char Dir)
{
	switch(toupper(Dir))
	{
	case 'C': C = 1;
		break;
	case 'B': B = 1;
		break;
	case 'E': E = 1;
		break;
	case 'D': D = 1;
		break;
	default: return;
	}
}

void Personagem::setC(int c){C=c;}

void Personagem::setB(int b){B=b;}

void Personagem::setD(int d){D=d;}

void Personagem::setE(int e){E=e;}

void Personagem :: resetCol()
{
	C = 0;
	B = 0;
	E = 0;
	D = 0;
	
}

int Personagem :: getCol(char Dir)
{
	switch(toupper(Dir))
	{
	case 'C': return C;
	case 'B': return B;
	case 'E': return E;
	case 'D': return D;
	default: return 0;
	}
}