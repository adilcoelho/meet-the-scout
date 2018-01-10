#pragma once
#include "obstaculo.h"


class Caixa : public Obstaculo
{
public:
	Caixa();
	Caixa(int px, int py = 0);
	Caixa(int px, int py, int ph, int pl);
	virtual ~Caixa();
};

