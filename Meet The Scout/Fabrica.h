#pragma once
#include "FabricaObstaculo.h"

template <class T>
class Fabrica : public FabricaObstaculo
{
public:
	Fabrica(){}
	~Fabrica(){}

	Obstaculo* CriarObstaculo(int px, int py){return new T(px, py);}
};