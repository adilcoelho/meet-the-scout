#pragma once
#include "Jogador.h"
#include "Usuario.h"

class Gerenciador_Save
{
private:
	BITMAP* buffer;
	Usuario* U;
	Usuario Us;
	Jogador* J;
	Jogador Jo;
	Teclado* Tec;
	int fase, tela, pontuacao;
	string nome;

public:
	
	Gerenciador_Save(void);
	Gerenciador_Save(BITMAP* buf);
	
	void salve(int fase, int tela, Jogador* J);
	void loade();

	void setBuffer(BITMAP* buffer);
	void setJogador(Jogador* J);
	void setTeclado(Teclado* Tec);
	void setUsuario(Usuario* U);

	int getfase();
	int gettela();
	int getpont();
	string getnome();
	Jogador* getJo();

	virtual ~Gerenciador_Save(void);
};



