#include "stdafx.h"
#include "Fase2.h"
#include "MenuPausar.h"

Fase2::Fase2()
{
}

Fase2::~Fase2()
{
}

void Fase2::Inicializar()
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

void Fase2::Entrar(int modo, int cenario)				
{									
	T->ResC();						// reseta o timer pro inicio da fase ser mostrado na tela de maneira fluida

	C1->setfase(2);
	C2->setfase(2);			// Informa �s telas a fase atual
	C3->setfase(2);
	
	if(NovoJogo == true)	// Se n�o for a primeira vez que os jogadores entram nesta tela...
    {
		C1->Inicializar();	
		C2->Inicializar();
		C3->Inicializar();
    }						
	NovoJogo = false;

	switch(cenario)
	{
		case 1: C1->Executar();
				break;
		case 2: C2->Executar();
				break;
		case 3: C3->Executar();
				break;
	}
	
							

	switch (modo)
	{
		case ESCOLHERFASE:	Sair();
							break;

		case JOGONORMAL:	if(MP->getSair())			// Se Jogador Escolheu Sair
								Sair();
							else if(J->getativo() == 1)	// Se Jogador Ainda vivo
								{
									C1->setfase(0);
									C2->setfase(0);			
									C3->setfase(0);
									MP->setSair(false);
									NovoJogo = true;
									F3->Entrar(JOGONORMAL);
								}
							else						// Se Jogador Morreu ou ESC
								Sair();
							break;
	}
}


void Fase2::Entrar(int modo)	
{								
	T->ResC();					// reseta o timer pro inicio da fase ser mostrado na tela de maneira fluida
	
	C1->setfase(2);
	C2->setfase(2);			// Informa �s telas a fase atual
	C3->setfase(2);

	if(NovoJogo == true)	// Se n�o for a primeira vez que os jogadores entram nesta tela...
    {
		C1->Inicializar();	
		C2->Inicializar();
		C3->Inicializar();
		if(modo != JOGONORMAL)
			J->setQvidas(5);
    }						
	NovoJogo = false;

	C1->Executar();			
							

	switch (modo)
	{
		case ESCOLHERFASE:	Sair();
							break;

		case JOGONORMAL:	if(MP->getSair())			// Se Jogador Escolheu Sair
								Sair();
							else if(J->getativo() == 1)	// Se Jogador Ainda vivo
								{
									C1->setfase(0);
									C2->setfase(0);			
									C3->setfase(0);
									MP->setSair(false);
									NovoJogo = true;
									F3->Entrar(JOGONORMAL);
								}
							else						// Se Jogador Morreu ou ESC
								Sair();
							break;
	}
}

void Fase2::Sair()
{
	C1->setfase(0);
	C2->setfase(0);			
	C3->setfase(0);

	//C1->EncerrarEntidades();
	//C2->EncerrarEntidades();
	//C3->EncerrarEntidades();

	J->setativo(1);
	J->setQvidas(5);
	MP->setSair(false);
	NovoJogo = true;
	system("cls");
	// Reseta os atributos dos jogadores
	// isso evita bugs que ocorreriam caso 
	// o usuario clique novamente em 'Jogar' 
	// (no menu) iniciando uma nova partida 
    // sem reiniciar o jogo.
}

void Fase2::setFase3(Fase3 *pF3)
{
	F3 = pF3;
}