#include "stdafx.h"
#include "Jogo.h"

Jogo::Jogo(){}

Jogo::~Jogo()
{
   destroy_bitmap(buffer);  // Destrói a imagem;       
}

void Jogo::Inicializar()
{
	buffer = create_bitmap(800, 600);  
	T.Init();
	C1.setCenario2(&C2);
	C2.setCenario3(&C3);

	C1.setGerenciadorColisao(&GC);
	C2.setGerenciadorColisao(&GC);
	C3.setGerenciadorColisao(&GC);
	
	F1.setbuffer(buffer);
	F1.setTimerFPS(&T);
	F1.setJogador(J,J2);		// Associa os jogadores à Fase
	F1.setFase2(&F2);			// Associa a Fase 1 à Fase 2
	F1.setCenario1(&C1);			
	F1.setCenario2(&C2);			// Agrega as Telas 1,2 e 3 fracamente
	F1.setCenario3(&C3);
	F1.Inicializar();

	F2.setbuffer(buffer);
	F2.setTimerFPS(&T);
	F2.setJogador(J,J2);		// Associa os jogadores à Fase
	F2.setFase3(&F3);			// Associa a Fase 2 à Fase 3
	F2.setCenario1(&C1);			
	F2.setCenario2(&C2);			// Agrega as Telas 1,2 e 3 fracamente
	F2.setCenario3(&C3);
	F2.Inicializar();

	F3.setbuffer(buffer);
	F3.setTimerFPS(&T);
	F3.setJogador(J,J2);		// Associa os jogadores à Fase
	F3.setCenario1(&C1);			
	F3.setCenario2(&C2);			// Agrega as Telas 1,2 e 3 fracamente
	F3.setCenario3(&C3);
	F3.Inicializar();

	FB.setbuffer(buffer);
	FB.setTimerFPS(&T);
	FB.setJogador(J,J2);		// Associa os jogadores à Fase
	FB.setCenario1(&C1);			
	FB.setCenario2(&C2);			// Agrega as Telas 1,2 e 3 fracamente
	FB.setCenario3(&C3);
	FB.Inicializar();



	/* As funções foram colocardas nesse método "Inicializar",
	porque, caso colocadas na construtora, causam um erro no programa.
	Esse erro ocorre porque a Biblioteca Gráfica está sendo inicializada
	na classe Principal, sendo assim, os objetos agregados nessa classe
	têm suas construtoras 'lidas' antes da inicialização da biblioteca,
	portanto o programa não reconhece as funções e ocorre o erro.
	Desta forma, os objetos são inicializados depois da biblioteca gráfica
	portanto, não há problemas. */          
}

void Jogo::Iniciar()
{
	U->CadastrarUsuario();
	U->setPontuacao(0);
	 
    F1.Entrar(JOGONORMAL);          // 'entra' na área da Fase

	GArq->Atualiza_Ranking(U->getNome(),U->getPontuacao());

	U->setPontuacao(0);				// Zera Pontuação
	system("cls");
}

void Jogo::IniciarC()
{
	U->setNome(GS->getnome());
	U->setPontuacao(GS->getpont());
	J->setQvidas(GS->getJo()->getQvidas());
	J->setx(GS->getJo()->getx());
	J->sety(GS->getJo()->gety());
	 
	if(U->getNome() == "Unnamed")
	{
		switch(GS->getfase())
		{
		case 1: F1.Entrar(ESCOLHERFASE, GS->gettela());
				break;
		case 2: F2.Entrar(ESCOLHERFASE, GS->gettela());
				break;
		case 3: F3.Entrar(ESCOLHERFASE, GS->gettela());
				break;
		}
	}
	else
	{
		switch(GS->getfase())
		{
		case 1: F1.Entrar(JOGONORMAL, GS->gettela());
				break;
		case 2: F2.Entrar(JOGONORMAL, GS->gettela());
				break;
		case 3: F3.Entrar(JOGONORMAL, GS->gettela());
				break;
		}
		GArq->Atualiza_Ranking(U->getNome(),U->getPontuacao());
	}


	

	U->setPontuacao(0);				// Zera Pontuação
	system("cls");
}

void Jogo::IniciarFase1()
{
	F1.Entrar(ESCOLHERFASE);
	U->setPontuacao(0);		
}

void Jogo::IniciarFase2()
{
	F2.Entrar(ESCOLHERFASE);
	U->setPontuacao(0);		
}

void Jogo::IniciarFase3()
{
	F3.Entrar(ESCOLHERFASE);
	U->setPontuacao(0);		
}

void Jogo::IniciarFaseBatalha()
{
	FB.Entrar(ESCOLHERFASE);
	U->setPontuacao(0);
}

void Jogo::setjogadores(Jogador* P, Jogador* PP)
{
	J = P;
	J2 = PP;
}

BITMAP* Jogo::getbuffer()
{
    return buffer;        
}

void Jogo::Associa_F1_MP(MenuPausar* pMP)
{
	F1.setMP(pMP);
}

void Jogo::Associa_F2_MP (MenuPausar* pMP)
{
	F2.setMP(pMP);
}

void Jogo::Associa_F3_MP (MenuPausar* pMP)
{
	F3.setMP(pMP);
}

void Jogo::Associa_FB_MP (MenuPausar* pMP)
{
	FB.setMP(pMP);
}

void Jogo::setUsuario(Usuario* Us)
{
	U = Us;
}

void Jogo::setGerenciadorArquivo(GerenciadorArquivos *pGArq)
{
	GArq = pGArq;
}

void Jogo::setGerenciadorSave(Gerenciador_Save *GS)
{
	this->GS = GS;
}

void Jogo::Associa_GC_U(Usuario *pU)
{
	GC.setUsuario(pU);
}

void Jogo::Associa_Cenarios_MostraInfos(ImprimeInfos::ImprimeVidas *pIV, ImprimeInfos::ImprimePontuacao *pIP)
{
	C1.setImprimeInfos(pIV, pIP);
	C2.setImprimeInfos(pIV, pIP);
	C3.setImprimeInfos(pIV, pIP);
}