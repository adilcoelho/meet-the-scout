#pragma once
#include "Entidade.h"


#define HChao 24

class Personagem : public Entidade
{
protected:
	int vx;
	short int vy;
	int pulou;
	int C,B,D,E; // Variáveis para detectar o sentido das colisões.

public:
	bool Matou;
	Personagem();
	virtual ~Personagem();

	void setvx( const int VX );
	void setvy( const short int VY );
	void setpulou( const int P );
	void setCol(char Dir);
	void setC(int c);
	void setB(int b);
	void setD(int d);
	void setE(int e);
	void resetCol();

	const int getpulou();
	const short int getvx();
	const short int getvy();
	int getCol(char Dir);

	virtual void Desenhar();
	/*void Colisao(Entidade* Ent);
	void testecolisao(Entidade* P2);
	void colisaodetectada(Entidade* Ent);
	void updRelPos(Entidade* Ent);
	bool bounding_box_collision(Entidade* Ent);*/

	virtual void Mover() = 0;
};

