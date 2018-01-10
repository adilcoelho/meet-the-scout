#include "stdafx.h"
#include "Cenario.h"

Cenario::Cenario()
{
}

Cenario::~Cenario()
{
}

void Cenario::setJogador( Jogador* Jo, Jogador* Jo2 ) { J = Jo; J2=Jo2; }

void Cenario::setbuffer( BITMAP* B ) { buffer = B; }

void Cenario::setMP( MenuPausar* M ){ MP = M; }

void Cenario::setTimerFPS(TimerFPS *Ti)
{
	T = Ti;
}

void Cenario::setGerenciadorColisao(GerenciadorColisao *G)
{
	GC=G;
}

void Cenario::setImprimeInfos(ImprimeInfos::ImprimeVidas *pIV, ImprimeInfos::ImprimePontuacao *pIP)
{
	ImpVidas = pIV;
	ImpPont = pIP;
}

void Cenario::setfase(int f){ fase = f; }

int Cenario::getfase(){ return fase; }

vector <Obstaculo*> Cenario::getobsts()
{
	return obsts;
}

vector <Obstaculo*> Cenario::getConj_Obst()
{
	return Conj_Obst;
}

vector <Inimigo*> Cenario::getinimigos()
{
	return inimigos;
}

Jogador* Cenario::getJogador1()
{
	return J;
}
Jogador*Cenario::getJogador2()
{
	return J2;
}