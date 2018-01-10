#pragma once
#include "GerenciadorGrafico.h"
#include "Jogo.h"
#include "MenuRaiz.h"
#include "MenuJogar.h"
#include "MenuEscolherFase.h"
#include "MenuPausar.h"
#include "Fase1.h"
#include "Tecs.h"
using namespace NTeclas;
#include "GerenciadorArquivos.h"
#include "Gerenciador_Save.h"
#include "ImprimeInfos.h"

class Principal
{
private:
	GerenciadorGrafico Allegro; // Gerenciador do Allegro.
    MenuRaiz MR;				// Menu principal do jogo.
	MenuJogar MJ;				// Submenu Jogar
	MenuEscolherFase MEF;		// Submenu Escolher Fase
	MenuPausar MP;
	Jogo J;						// O Jogo em si.
	Jogador Jo;
	Jogador Jo2;
	Teclado* Tec1;
	Teclado* Tec2;
	Teclado *Tec3;
	Usuario U;					// Usuario do Jogo
	GerenciadorArquivos GArq;
	Gerenciador_Save GS;

	ImprimeInfos::ImprimePontuacao ImpPont;
	ImprimeInfos::ImprimeVidas ImpVidas;


public:
	Principal();
	~Principal();
	void Executar();      
	void Inicializar();
};

