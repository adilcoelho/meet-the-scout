#pragma once
#include "inimigo.h"
class Pyro :
	public Inimigo
{
public:
	Pyro(void);
	Pyro(int posx, int posy, BITMAP* img);

	void Mover();
	virtual ~Pyro(void);
};

