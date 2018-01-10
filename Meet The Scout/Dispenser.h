#pragma once
#include "obstaculo.h"
class Dispenser :
	public Obstaculo
{
public:
	Dispenser(void);
	Dispenser(int px, int py = 0);
	Dispenser(int px, int py, int ph, int pl);
	~Dispenser(void);
};

