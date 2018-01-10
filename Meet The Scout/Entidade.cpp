#include "stdafx.h"
#include "Entidade.h"


Entidade::Entidade()
{
	img = NULL;
	buffer = NULL;
	ativo = 1;
	ehinimigo = 0;
}

Entidade::~Entidade()
{
	buffer = NULL;   
	destroy_bitmap(img);  // Destrói a imagem;                   
}

// Sets //

void Entidade::setbuffer(BITMAP* B){ buffer = B; }

void Entidade::setimg( BITMAP* I ){	img = I; }

void Entidade::setx( const short int X ){ x = X; }

void Entidade::sety( const short int Y ){ y = Y; }

void Entidade::seth( const short int H ){ h = H; }

void Entidade::setl( const short int L ){ l = L; }

void Entidade :: setRelPos(int posant) { posanterior = posant;}

void Entidade::setativo( int at ){ ativo = at; }

// Gets //

BITMAP* Entidade::getimg(){ return img; }

const short int Entidade::getx(){ return x; }

const short int Entidade::gety(){ return y; }

const short int Entidade::geth(){ return h; }

const short int Entidade::getl(){ return l; }

int Entidade :: getRelPos() { return posanterior; }

const short int Entidade::getehinimigo(){ return ehinimigo; }

int Entidade::getativo(){ return ativo; }