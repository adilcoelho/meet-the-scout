#pragma once
#include "fase.h"
#include "Fase3.h"

class Fase2 : public Fase
{
private:
	Fase3 *F3;

public:
	Fase2();
	~Fase2();

	void Inicializar();
	void Entrar(int modo);
	void Entrar(int modo, int cenario);
	void Sair();

	void setFase3(Fase3 *pF3);
};

