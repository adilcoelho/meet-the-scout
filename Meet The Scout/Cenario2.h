#pragma once
#include "Cenario.h"
#include "Cenario3.h"

class Cenario2 : public Cenario
{
private:
	Cenario3* C3;

public:
	Cenario2();
	~Cenario2();

	void Inicializar();
	void Executar();

	void setCenario3(Cenario3* Ce);
};

