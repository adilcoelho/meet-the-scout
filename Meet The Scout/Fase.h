#pragma once
#include "Jogador.h"
#include "Fundo.h"
#include "Obstaculo.h"
#include "Inimigo.h"
//#include "MenuPausar.h"
#include <vector>
#include "Cenario1.h"
#include "Cenario2.h"
#include "Cenario3.h"
using namespace std;
class MenuPausar;
using namespace TFPS;

class Fase
{
protected:
	BITMAP* buffer;			// Bitmap de buffer para desenhar todas as imagens nele
							// e logo em seguida jogá-lo inteiro na tela, isso evita
							// que a tela ou as imagens fiquem piscando.	
	TimerFPS *T;

	Jogador* J;
	Jogador* J2;

	Cenario1* C1;
	Cenario2* C2;
	Cenario3* C3;

	//vector<Obstaculo*> obsts;
	//vector<Inimigo*> inimigos;
  
	//Fundo fundo;	

	MenuPausar* MP;

	bool NovoJogo;

public:
	Fase();
	virtual ~Fase();

	virtual void Inicializar() = 0;
	virtual void Entrar(int modo) = 0;
	
	virtual void Sair() = 0;

	void setTimerFPS(TimerFPS *Ti);
	void setJogador( Jogador* Jo, Jogador* Jo2 );
	void setbuffer( BITMAP* B );
	void setMP( MenuPausar* M );
	void setCenario1( Cenario1* Te);
	void setCenario2( Cenario2* Te);
	void setCenario3( Cenario3* Te);

	BITMAP* getbuffer();
};

