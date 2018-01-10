#include "StdAfx.h"
#include "ImprimeInfos.h"

ImprimeInfos::ImprimeInfos()
{
}

ImprimeInfos::~ImprimeInfos()
{
}

ImprimeInfos::ImprimeVidas::ImprimeVidas()
{
}

ImprimeInfos::ImprimeVidas::~ImprimeVidas()
{
}

ImprimeInfos::ImprimePontuacao::ImprimePontuacao()
{
}

ImprimeInfos::ImprimePontuacao::~ImprimePontuacao()
{
}

void ImprimeInfos::ImprimeVidas::setbuffer(BITMAP *B){ buffer = B; }

void ImprimeInfos::ImprimeVidas::setJogador(Jogador *pJ, Jogador *pJ2){ J = pJ; J2 = pJ2; }

Jogador* ImprimeInfos::ImprimeVidas::getJ(){ return J;}

void ImprimeInfos::ImprimeVidas::Inicicializar()
{
	cor = makecol(255, 251, 255);
	fonte = load_font("Arquivos//fontes//pont.pcx", NULL, NULL);
}

void ImprimeInfos::ImprimeVidas::Imprime()
{
	textprintf_ex(buffer, fonte, 0, 0, cor, makecol(0,0,0), "Scout %d ", J->getQvidas());
}

void ImprimeInfos::ImprimeVidas::Imprime(int jog)
{
	if(jog == 1)
		textprintf_ex(buffer, fonte, 0, 0, cor, makecol(149,28,2), " Scout1 %d ", J->getQvidas());
	else
		textprintf_right_ex(buffer, fonte, 800, 0, cor, makecol(51,2,149), " Scout2 %d ", J2->getQvidas());
}

void ImprimeInfos::ImprimePontuacao::setbuffer(BITMAP *B){ buffer = B; }

void ImprimeInfos::ImprimePontuacao::setUsuario(Usuario *pU){ U = pU; }

void ImprimeInfos::ImprimePontuacao::Inicicializar()
{
	cor = makecol(255, 251, 255);
	fonte = load_font("Arquivos//fontes//pont.pcx", NULL, NULL);
}

void ImprimeInfos::ImprimePontuacao::Imprime()
{
	textprintf_ex(buffer, fonte, 0, 22, cor, makecol(0,0,0), "%d ", U->getPontuacao());

}

