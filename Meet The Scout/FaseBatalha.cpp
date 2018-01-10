#include "StdAfx.h"
#include "FaseBatalha.h"
#include "MenuPausar.h"


FaseBatalha::FaseBatalha(void)
{
}


FaseBatalha::~FaseBatalha(void)
{
}

void FaseBatalha::Inicializar()
{
	NovoJogo = true;

	C1->setMP(MP);
	C1->setTimerFPS(T);
	C1->setJogador(J,J2);
	C1->setbuffer(buffer);
	C1->Inicializar();

	C2->setMP(MP);
	C2->setTimerFPS(T);
	C2->setJogador(J,J2);
	C2->setbuffer(buffer);
	C2->Inicializar();

	C3->setMP(MP);
	C3->setTimerFPS(T);
	C3->setJogador(J,J2);
	C3->setbuffer(buffer);
	C3->Inicializar();
}

void FaseBatalha::Entrar(int modo)	
{									
	T->ResC();			// reseta o timer pro inicio da fase ser mostrado na tela de maneira fluida
	
	C1->setfase(4);
	C2->setfase(4);
	C3->setfase(4);

	if(NovoJogo == true)	// Se não for a primeira vez que os jogadores entram nesta tela...
    {
		C1->Inicializar();
		J->setQvidas(5);
		J2->setQvidas(5);
    }						
	NovoJogo = false;

	C1->Executar();	

	Sair();
}

void FaseBatalha::Sair()
{
	C1->setfase(0);
	C2->setfase(0);
	C3->setfase(0);

	//C1->EncerrarEntidades();
	//C2->EncerrarEntidades();
	//C3->EncerrarEntidades();

	J->setativo(1);
	J2->setativo(1);
	MP->setSair(false);
	NovoJogo = true;
	// Reseta os atributos dos jogadores
	// isso evita bugs que ocorreriam caso 
	// o usuario clique novamente em 'Jogar' 
	// (no menu) iniciando uma nova partida 
    // sem reiniciar o jogo.
}