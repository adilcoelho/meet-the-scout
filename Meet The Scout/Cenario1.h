#pragma once
#include "Cenario.h"
#include "Cenario2.h"

class Cenario1 : public Cenario
{
private:
	Cenario2* C2;

public:
	Cenario1();
	~Cenario1();
	
	void Inicializar();

	void Executar();

	void setCenario2(Cenario2* Ce);
};

