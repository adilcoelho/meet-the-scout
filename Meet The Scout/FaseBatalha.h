#pragma once
#include "fase.h"
class FaseBatalha :
	public Fase
{
public:
	FaseBatalha(void);
	virtual ~FaseBatalha(void);

	void Inicializar();
	void Entrar(int modo);
	void Sair();
};

