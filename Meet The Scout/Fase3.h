#pragma once
#include "fase.h"

class Fase3 : public Fase
{
public:
	Fase3();
	~Fase3();

	void Inicializar();
	void Entrar(int modo);
	void Entrar(int modo, int cenario);
	void Sair();
};

