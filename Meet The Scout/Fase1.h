#pragma once
#include "Fase.h"
#include "TimerFPS.h"
#include "Caixa.h"
#include "Fase2.h"

class Fase1 : public Fase
{
private:
	Fase2 *F2;

public:
	Fase1();
	~Fase1();

	void Inicializar();
	void Entrar(int modo);
	void Entrar(int modo, int cenario);
	void Sair();

	void setFase2(Fase2 *pF2);

};

