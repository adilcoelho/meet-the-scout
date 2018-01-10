#pragma once
#include "Jogador.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Fundo.h"
#include "TimerFPS.h"
#include "Spy.h"
#include "Demoman.h"
#include "Engineer.h"
#include "Heavy.h"
#include "Soldier.h"
#include "Pyro.h"
#include "Caixa.h"
#include "Dispenser.h"
#include "Cart.h"
#include "Sentry.h"
#include "GerenciadorColisao.h"
#include "Fabrica.h"
#include "ImprimeInfos.h"
using namespace TFPS;

#define HDispenser 79
#define LDispenser 60
#define HCaixa 80
#define LCaixa 80
#define HCart 76
#define LCart 100
#define HSentry 47
#define LSentry 50


//#include "MenuPausar.h"
#include <vector>
using namespace std;
class MenuPausar;

class Cenario
{
protected:
	BITMAP* buffer;			// Bitmap de buffer para desenhar todas as imagens nele
							// e logo em seguida jogá-lo inteiro na tela, isso evita
							// que a tela ou as imagens fiquem piscando.
	TimerFPS *T;

	GerenciadorColisao *GC;

	Jogador* J;
	Jogador* J2;

	vector<Obstaculo*> Conj_Obst;
	vector<Obstaculo*> obsts;
	vector<Inimigo*> inimigos;

	
	FabricaObstaculo *F0;		
	FabricaObstaculo *F1;		
	FabricaObstaculo *F2;		
	FabricaObstaculo *F3;
  
	Fundo fundo;	

	MenuPausar* MP;

	ImprimeInfos::ImprimeVidas *ImpVidas;
	ImprimeInfos::ImprimePontuacao *ImpPont;

	int fase;

public:
	Cenario();
	virtual ~Cenario();

	virtual void Inicializar()=0;

	virtual void Executar()=0;

	void setJogador( Jogador* Jo, Jogador* Jo2 );
	void setbuffer( BITMAP* B );
	void setMP( MenuPausar* M );
	void setTimerFPS(TimerFPS *Ti);
	void setGerenciadorColisao(GerenciadorColisao *G);
	void setImprimeInfos(ImprimeInfos::ImprimeVidas *pIV, ImprimeInfos::ImprimePontuacao *pIP);
	void setfase(int f);
	int getfase();
	vector <Obstaculo*> getobsts();
	vector <Obstaculo*> getConj_Obst();
	vector <Inimigo*> getinimigos();
	Jogador* getJogador1();
	Jogador* getJogador2();
};

