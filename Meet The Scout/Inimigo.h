#pragma once
#include "personagem.h"

class Inimigo : public Personagem
{
private:
	static int Quantidade;

public:
	Inimigo();
	Inimigo(int posx, int posy, BITMAP* img);
	~Inimigo();

	static void setQuantidade(int Q);
	static int getQuantidade();
	
	virtual void Mover();
};

