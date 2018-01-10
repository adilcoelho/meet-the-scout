#pragma once
#include "Caixa.h"

class FabricaObstaculo
{

public:
	FabricaObstaculo();
	virtual ~FabricaObstaculo();

	virtual Obstaculo* CriarObstaculo(int px, int py) = 0;
};
