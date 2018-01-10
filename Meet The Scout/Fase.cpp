#include "stdafx.h"
#include "Fase.h"

Fase::Fase()
{
}

Fase::~Fase()
{
}

void Fase::setTimerFPS(TimerFPS *Ti){ T = Ti; }

void Fase::setJogador( Jogador* Jo, Jogador* Jo2 ) { J = Jo; J2=Jo2; }

void Fase::setbuffer( BITMAP* B ) { buffer = B; }

void Fase::setMP( MenuPausar* M ){ MP = M; }

void Fase::setCenario1(Cenario1* Ce){ C1 = Ce; }

void Fase::setCenario2(Cenario2* Ce){ C2 = Ce; }

void Fase::setCenario3(Cenario3* Ce){ C3 = Ce; }

BITMAP* Fase::getbuffer() { return buffer; }