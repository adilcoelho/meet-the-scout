#pragma once
#include "TimerFPS.h"
#include "GerenciadorColisao.h"
#include "Jogador.h"
#include "Fase1.h"
#include "Fase2.h"
#include "Fase3.h"
#include "FaseBatalha.h"
#include "Cenario1.h"
#include "Cenario2.h"
#include "Cenario3.h"
#include "Usuario.h"
#include "GerenciadorArquivos.h"
#include "ImprimeInfos.h"
#include "Gerenciador_Save.h"
//#include "MenuPausar.h"

class Jogo
{
private:
	BITMAP* buffer;		// Bitmap de buffer para desenhar todas as imagens nele
						// e logo em seguida jogá-lo inteiro na tela, isso evita
						// que a tela ou as imagens fiquem piscando.
	Usuario* U;
	GerenciadorArquivos *GArq;
	Gerenciador_Save* GS;

	Jogador* J;
	Jogador* J2;

	Fase1 F1;
	Fase2 F2;
	Fase3 F3;
	FaseBatalha FB;

	Cenario1 C1;
	Cenario2 C2;
	Cenario3 C3;

	TimerFPS T;

	GerenciadorColisao GC;

public:

	Jogo();
    ~Jogo();
	void Inicializar();
	void Iniciar();
	void IniciarC();

	void IniciarFase1();
	void IniciarFase2();
	void IniciarFase3();
	void IniciarFaseBatalha();
    
    BITMAP* getbuffer();

	void setjogadores(Jogador* P, Jogador* PP);

	void Associa_F1_MP (MenuPausar* pMP);

	void Associa_F2_MP (MenuPausar* pMP);

	void Associa_F3_MP (MenuPausar* pMP);

	void Associa_FB_MP (MenuPausar* pMP);

	void setUsuario(Usuario* Us);

	void setGerenciadorArquivo(GerenciadorArquivos *pGArq);

	void setGerenciadorSave(Gerenciador_Save *GS);

	void Associa_GC_U(Usuario *pU);

	void Associa_Cenarios_MostraInfos(ImprimeInfos::ImprimeVidas *pIV, ImprimeInfos::ImprimePontuacao *pIP);
};

