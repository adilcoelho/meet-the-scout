#include "stdafx.h"
#include "Cenario1.h"
#include "MenuPausar.h"

#define HPadrao 0


Cenario1::Cenario1()
{
	fase = 0;
}

Cenario1::~Cenario1()
{
	for(int i=0; i < obsts.size(); i++)
		if(obsts[i])
			delete obsts[i];

	for(int i=0; i < inimigos.size(); i++)
		if(inimigos[i])
			delete inimigos[i];

	for(int i=0; i < Conj_Obst.size(); i++)
		if(Conj_Obst[i])
			delete Conj_Obst[i];
}

void Cenario1::Inicializar()
{
	int i;
	int N;
	int aux;
	srand (time(NULL));

	if (fase == 1)
	{
		
		
		if(obsts.size() != 0)
			obsts.clear();
		if(inimigos.size() != 0)
			inimigos.clear();
		if(Conj_Obst.size() != 0)
			Conj_Obst.clear();
		J->setx(0);						// Posição inicial em x.
		J->sety(250);					// Posição icial em y.

		J2->setx(400);					// Posição inicial em x.
		J2->sety(250);					// Posição icial em y.

		fundo.setbuffer(buffer);
		fundo.setimg(load_bitmap("Arquivos//Imagens//FundoTela1.bmp", NULL));
		fundo.setx(0);  
		fundo.sety(0);

		//chao.setbuffer(buffer);
		//chao.setimg(load_bitmap("Arquivos//Imagens//chaoFase1.bmp", NULL));
		//chao.setx(0);  
		//chao.sety(0);

		/*Obstaculo* auxobst = new Caixa(0, SCREEN_H-50, SCREEN_W, 50);
		obsts.push_back(auxobst);
		obsts[0]->setbuffer(buffer);*/

		//******************************* Implementação do Factory Method para obstáculos ***********************************//



		F0 = new Fabrica<Sentry>();		//Fabrica Template Implementada: <Caixa> ou <Cart> ou <Dispenser>

		Conj_Obst.push_back( F0->CriarObstaculo(400, 20));
		Conj_Obst[0]->setbuffer(buffer);


		//******************************* Implementação do Factory Method para obstáculos ***********************************//

		N = rand() % 3 + 1;
		Obstaculo* auxobst;
		for(i = 0; i < N; i++)
		{
			auxobst = new Caixa(200 + 80*i, SCREEN_H - HChao - HCaixa*(1+i));
			obsts.push_back(auxobst);
			obsts[i]->setbuffer(buffer);
		}

		auxobst = new Caixa(550-LCaixa, SCREEN_H - 149);
		obsts.push_back(auxobst);
		obsts[i++]->setbuffer(buffer);
		int res = i;
		N = rand() % 3 + 1;
		for(i = 0; i < N; i++)
		{
			auxobst = new Dispenser(550, SCREEN_H - HChao - HDispenser*(1+i));
			obsts.push_back(auxobst);
			obsts[i + res]->setbuffer(buffer);
		}

		/*auxobst = new Sentry(100, 500);
		obsts.push_back(auxobst);
		obsts[i++]->setbuffer(buffer);*/

		/*auxobst = new Caixa(420, 400, load_bitmap("Arquivos//Imagens//Objeto2.bmp", NULL));
		obsts.push_back(auxobst);
		obsts[2]->setbuffer(buffer);*/

		Inimigo* auxinimigo;
		N = rand() % 3 + 1;
		for(i = 0; i < N; i++)
		{
			auxinimigo = new Spy(150 + 150*i, 90, load_bitmap("Arquivos//Imagens//Spy.bmp", NULL), J);
			inimigos.push_back(auxinimigo);
			inimigos[i]->setbuffer(buffer);

		}
		N = rand() % 2 + 1;
		int min = i;
		for(i; i < min+N; i++)
		{
			auxinimigo = new Demoman(200 + 80*i, 90, load_bitmap("Arquivos//Imagens//Demoman.bmp", NULL));

			inimigos.push_back(auxinimigo);
			inimigos[i]->setbuffer(buffer);
		}


		/*
		auxinimigo = new Inimigo(250, 610, load_bitmap("Arquivos//Imagens//Spy.bmp", NULL));
		inimigos.push_back(auxinimigo);
		inimigos[0]->setbuffer(buffer);

		auxinimigo = new Inimigo(430, 90, load_bitmap("Arquivos//Imagens//Spy.bmp", NULL));
		inimigos.push_back(auxinimigo);
		inimigos[2]->setbuffer(buffer);*/
	}
	else if(fase == 2)
	{
		
		if(obsts.size() != 0)
			obsts.clear();
		if(inimigos.size() != 0)
			inimigos.clear();
		if(Conj_Obst.size() != 0)
			Conj_Obst.clear();

		J->setx(0);						// Posição inicial em x.
		J->sety(250);					// Posição icial em y.

		J2->setx(400);					// Posição inicial em x.
		J2->sety(250);					// Posição icial em y.			VERIFICAR INFLUÊNCIA DISSO COM A TELA 2

		fundo.setbuffer(buffer);
		fundo.setimg(load_bitmap("Arquivos//Imagens//FundoTela1.bmp", NULL));
		fundo.setx(0);  
		fundo.sety(0);

		//chao.setbuffer(buffer);
		//chao.setimg(load_bitmap("Arquivos//Imagens//chaoFase1.bmp", NULL));
		//chao.setx(0);  
		//chao.sety(0);

		/*Obstaculo* auxobst = new Caixa(0, SCREEN_H-50, SCREEN_W, 50);
		obsts.push_back(auxobst);
		obsts[0]->setbuffer(buffer);*/

		//******************************* Implementação do Factory Method para obstáculos ***********************************//



		F0 = new Fabrica<Sentry>();		//Fabrica Template Implementada: <Caixa> ou <Cart> ou <Dispenser>

		Conj_Obst.push_back( F0->CriarObstaculo(400, 20));
		Conj_Obst[0]->setbuffer(buffer);


		//******************************* Implementação do Factory Method para obstáculos ***********************************//

		N = rand() % 3 + 1;
		Obstaculo* auxobst;
		i=0;

		auxobst = new Caixa(430, SCREEN_H - HChao - HCaixa);
		obsts.push_back(auxobst);
		obsts[i++]->setbuffer(buffer);

		auxobst = new Caixa(430, 200);
		obsts.push_back(auxobst);
		obsts[i++]->setbuffer(buffer);

		auxobst = new Caixa(233, 386);
		obsts.push_back(auxobst);
		obsts[i++]->setbuffer(buffer);

		int res = i;
		N = rand() % 6 + 1;
		for(i = 0; i < N; i++)
		{
			auxobst = new Dispenser(511, SCREEN_H - HChao - HDispenser*(1+i));
			obsts.push_back(auxobst);
			obsts[i + res]->setbuffer(buffer);
		}

		

		Inimigo* auxinimigo;
		N = rand() % 3 + 1;
		for(i = 0; i < N; i++)
		{
			auxinimigo = new Spy(150 + 150*i, 90, load_bitmap("Arquivos//Imagens//Spy.bmp", NULL), J);
			inimigos.push_back(auxinimigo);
			inimigos[i]->setbuffer(buffer);

		}
		N = rand() % 2 + 1;
		int min = i;
		for(i; i < min+N; i++)
		{
			auxinimigo = new Demoman(200 + 80*i, 90, load_bitmap("Arquivos//Imagens//Demoman.bmp", NULL));

			inimigos.push_back(auxinimigo);
			inimigos[i]->setbuffer(buffer);
		}
													//IMPLEMENTAR TELA 1 DA FASE 2 AQUI
	}
	else if(fase == 3)
	{
		
		if(obsts.size() != 0)
			obsts.clear();
		if(inimigos.size() != 0)
			inimigos.clear();
		if(Conj_Obst.size() != 0)
			Conj_Obst.clear();

		J->setx(0);						// Posição inicial em x.
		J->sety(250);					// Posição icial em y.

		J2->setx(400);					// Posição inicial em x.
		J2->sety(250);					// Posição icial em y.			VERIFICAR INFLUÊNCIA DISSO COM A TELA 2

		fundo.setbuffer(buffer);
		fundo.setimg(load_bitmap("Arquivos//Imagens//FundoTela1.bmp", NULL));
		fundo.setx(0);  
		fundo.sety(0);

		//******************************* Implementação do Factory Method para obstáculos ***********************************//



		FabricaObstaculo *F0 = new Fabrica<Caixa>();		//Fabrica Template Implementada: <Caixa> ou <Cart> ou <Dispenser>
		FabricaObstaculo *F1 = new Fabrica<Sentry>();		//Fabrica Template Implementada: <Caixa> ou <Cart> ou <Dispenser>
		FabricaObstaculo *F2 = new Fabrica<Cart>();		//Fabrica Template Implementada: <Caixa> ou <Cart> ou <Dispenser>
		FabricaObstaculo *F3 = new Fabrica<Dispenser>();		//Fabrica Template Implementada: <Caixa> ou <Cart> ou <Dispenser>


		//******************************* Implementação do Factory Method para obstáculos ***********************************//

		N = rand() % 3 + 1;
		Obstaculo* auxobst;
		i=0;

		Conj_Obst.push_back( F0->CriarObstaculo(260, SCREEN_H - HChao - HCaixa));
		aux = Conj_Obst.size() - 1;
		Conj_Obst[aux]->setbuffer(buffer);

		Conj_Obst.push_back( F0->CriarObstaculo(430, 350));
		aux = Conj_Obst.size() - 1;
		Conj_Obst[aux]->setbuffer(buffer);

		Conj_Obst.push_back( F0->CriarObstaculo(260, 270));
		aux = Conj_Obst.size() - 1;
		Conj_Obst[aux]->setbuffer(buffer);

		for(i = 0; i < 3; i++)
		{
			Conj_Obst.push_back( F1->CriarObstaculo(90 + (LSentry + 15) * i, 280 - 2*i));
			aux = Conj_Obst.size() - 1;
			Conj_Obst[aux]->setbuffer(buffer);
		}

		for(i = 0; i < 3; i++)
		{
			Conj_Obst.push_back( F2->CriarObstaculo(210 + (LCart + 15) * i, 100 + 2*i));
			aux = Conj_Obst.size() - 1;
			Conj_Obst[aux]->setbuffer(buffer);
		}
		N = rand() % 2;
		for(i = 0; i < N; i++)
		{
			Conj_Obst.push_back( F3->CriarObstaculo(440, 422 + HDispenser * i));
			aux = Conj_Obst.size() - 1;
			Conj_Obst[aux]->setbuffer(buffer);
		}
		N = rand() % 5;
		for(i = 0; i < N; i++)
		{
			Conj_Obst.push_back( F1->CriarObstaculo(523, 180 + HSentry * i));
			aux = Conj_Obst.size() - 1;
			Conj_Obst[aux]->setbuffer(buffer);
		}
		for(i = 0; i < 4; i++)
		{
			Conj_Obst.push_back( F3->CriarObstaculo(740, 140 + HDispenser * i));
			aux = Conj_Obst.size() - 1;
			Conj_Obst[aux]->setbuffer(buffer);
		}

		Inimigo* auxinimigo;
		N = rand() % 3 + 1;
		for(i = 0; i < N; i++)
		{
			auxinimigo = new Spy(150 + 150*i, 90, load_bitmap("Arquivos//Imagens//Spy.bmp", NULL), J);
			inimigos.push_back(auxinimigo);
			inimigos[i]->setbuffer(buffer);

		}
		N = rand() % 2 + 1;
		int min = i;
		for(i; i < min+N; i++)
		{
			auxinimigo = new Demoman(200 + 50*i, 90, load_bitmap("Arquivos//Imagens//Demoman.bmp", NULL));

			inimigos.push_back(auxinimigo);
			inimigos[i]->setbuffer(buffer);
		}
													//IMPLEMENTAR TELA 1 DA FASE 2 AQUI
	}
	else if(fase == 4)
	{
		if(obsts.size() != 0)
			obsts.clear();
		if(inimigos.size() != 0)
			inimigos.clear();
		if(Conj_Obst.size() != 0)
			Conj_Obst.clear();

		J->setx(0);						// Posição inicial em x.
		J->sety(0);					// Posição icial em y.

		J2->setx(800 - J2->getl());					// Posição inicial em x.
		J2->sety(0);					// Posição icial em y.			VERIFICAR INFLUÊNCIA DISSO COM A TELA 2

		fundo.setbuffer(buffer);
		fundo.setimg(load_bitmap("Arquivos//Imagens//FundoTela1.bmp", NULL));
		fundo.setx(0);  
		fundo.sety(0);

		//******************************* Implementação do Factory Method para obstáculos ***********************************//



		FabricaObstaculo *F0 = new Fabrica<Caixa>();		//Fabrica Template Implementada: <Caixa> ou <Cart> ou <Dispenser>
		FabricaObstaculo *F1 = new Fabrica<Sentry>();		//Fabrica Template Implementada: <Caixa> ou <Cart> ou <Dispenser>
		FabricaObstaculo *F2 = new Fabrica<Cart>();		//Fabrica Template Implementada: <Caixa> ou <Cart> ou <Dispenser>
		FabricaObstaculo *F3 = new Fabrica<Dispenser>();		//Fabrica Template Implementada: <Caixa> ou <Cart> ou <Dispenser>


		//******************************* Implementação do Factory Method para obstáculos ***********************************//

		N = rand() % 3 + 1;
		Obstaculo* auxobst;
		i=0;

		Conj_Obst.push_back( F0->CriarObstaculo(260, SCREEN_H - HChao - HCaixa));
		aux = Conj_Obst.size() - 1;
		Conj_Obst[aux]->setbuffer(buffer);

		Conj_Obst.push_back( F0->CriarObstaculo(430, 350));
		aux = Conj_Obst.size() - 1;
		Conj_Obst[aux]->setbuffer(buffer);

		Conj_Obst.push_back( F0->CriarObstaculo(260, 270));
		aux = Conj_Obst.size() - 1;
		Conj_Obst[aux]->setbuffer(buffer);

		for(i = 0; i < 3; i++)
		{
			Conj_Obst.push_back( F1->CriarObstaculo(90 + (LSentry + 15) * i, 280 - 2*i));
			aux = Conj_Obst.size() - 1;
			Conj_Obst[aux]->setbuffer(buffer);
		}

		for(i = 0; i < 3; i++)
		{
			Conj_Obst.push_back( F2->CriarObstaculo(210 + (LCart + 15) * i, 100 + 2*i));
			aux = Conj_Obst.size() - 1;
			Conj_Obst[aux]->setbuffer(buffer);
		}
		N = rand() % 2;
		for(i = 0; i < N; i++)
		{
			Conj_Obst.push_back( F3->CriarObstaculo(440, 422 + HDispenser * i));
			aux = Conj_Obst.size() - 1;
			Conj_Obst[aux]->setbuffer(buffer);
		}
		N = rand() % 5;
		for(i = 0; i < N; i++)
		{
			Conj_Obst.push_back( F1->CriarObstaculo(523, 180 + HSentry * i));
			aux = Conj_Obst.size() - 1;
			Conj_Obst[aux]->setbuffer(buffer);
		}
		for(i = 0; i < 4; i++)
		{
			Conj_Obst.push_back( F3->CriarObstaculo(740, 140 + HDispenser * i));
			aux = Conj_Obst.size() - 1;
			Conj_Obst[aux]->setbuffer(buffer);
		}

		Inimigo* auxinimigo;
		N = rand() % 3 + 1;
		for(i = 0; i < N; i++)
		{
			auxinimigo = new Spy(150 + 150*i, 90, load_bitmap("Arquivos//Imagens//Spy.bmp", NULL), J);
			inimigos.push_back(auxinimigo);
			inimigos[i]->setbuffer(buffer);

		}
		N = rand() % 2 + 1;
		int min = i;
		for(i; i < min+N; i++)
		{
			auxinimigo = new Demoman(200 + 120*i, 90, load_bitmap("Arquivos//Imagens//Demoman.bmp", NULL));

			inimigos.push_back(auxinimigo);
			inimigos[i]->setbuffer(buffer);
		}
	}
}

void Cenario1::Executar()
{
	int i = 0, j = 0;
	int QInimigos = inimigos.size();
	inimigos[0]->setQuantidade(inimigos.size());
	clear_to_color(screen,0);
	FONT* f = load_font("Arquivos//fontes//pont.pcx",NULL,NULL);
	switch(fase)
	{
		case 1: textout_centre_ex(screen,f,"FASE 1", SCREEN_W/2, SCREEN_H/2, 0XFFFFFF,-1);
				break;
		case 2: textout_centre_ex(screen,f,"FASE 2", SCREEN_W/2, SCREEN_H/2, 0XFFFFFF,-1);
				break;
		case 3: textout_centre_ex(screen,f,"FASE 3", SCREEN_W/2, SCREEN_H/2, 0XFFFFFF,-1);
				break;
		case 4: textout_centre_ex(screen,f,"BATALHA (2 JOGADORES)", SCREEN_W/2, SCREEN_H/2, 0XFFFFFF,-1);
				break;
			
	}
	destroy_font(f);
	rest(3000);
	T->ResC();
	GC->setCenario(this);
	GC->Iniciar();
	if(fase !=4)
	{	
		system("cls");
		printf("Fase %i\n", fase);
		printf("Cenario 1\n");
		printf("Inimigos: %i", inimigos[0]->getQuantidade());
		while (1)	//loop principal.
		{

			while(T->mcounter > 0)
			{
				GC->GerenciaColisao();
				
				if(J->Matou)
				{
					J->setativo(1);
					J->Matou = false;					
					J->sety(J->gety()-11);	
					for(i=0, QInimigos = 0; i<inimigos.size(); i++)
						if (inimigos[i]->getativo() == 1)
							QInimigos++;
					inimigos[0]->setQuantidade(QInimigos);
					system("cls");
					printf("Fase %i\n", fase);
					printf("Cenario 1\n");
					printf("Inimigos: %i", inimigos[0]->getQuantidade());
				}
				J->Mover();
				for(i=0; i < inimigos.size(); i++)
				{
					inimigos[i]->Mover();
				}

				(*T)--;		// Subtrai mcounter e counter
			}

			//Desenha Entidades na Tela (buffer)
			fundo.Desenhar();
			J->Desenhar();
			for(i=0; i < obsts.size(); i++)
				obsts[i]->Desenhar();

			for(i=0; i < Conj_Obst.size(); i++)
				Conj_Obst[i]->Desenhar();

			for(i=0; i < inimigos.size(); i++)
				inimigos[i]->Desenhar();

			ImpPont->Imprime();
			ImpVidas->Imprime();

			if (J->getx() >= 800)		// Se o jogador sair da tela pela direita
			{
				J->setx(0);				// Seta as novas posições do personagem na próxima tela.
				C2->Executar();			// Vai para a tela2.
				break;
			}

			if (key[KEY_ESC])			// Se Enter for pressionado...
			{
				MP->Iniciar(fase, 1, ImpVidas->getJ());
				if (MP->getSair())		// Aciona a tela do menu de saída.
				{
					break;
				}
				T->ResC();				//Para o Personagem aparecer na posição em que parou
			}

			if (J->getativo() == 0)
			{
				if (J->getQvidas() == 0)
				{
					FONT* f = load_font("Arquivos//fontes//pont.pcx",NULL,NULL);
					textout_centre_ex(screen,f,"Voce PERDEU", SCREEN_W/2, SCREEN_H/2, 0Xbd1700,-1);
					destroy_font(f);
					rest(3000);
					MP->setSair(true);
					break;
				}
				else
				{
					J->setQvidas(J->getQvidas() - 1);
					J->setx(0);						
					J->sety(250);					
					J->setativo(1);
				}
			}

			//if(QInimigosAnterior > i

			blit(buffer, screen, 0, 0, 0, 0, 800, 600);		// Desenha o buffer na tela.
			clear( buffer );								// Limpa o buffer;
			T->UpdmC();
		}
	}
	else
	{
		while (1)	//loop principal.
		{

			while(T->mcounter > 0)
			{
				GC->GerenciaColisao2J();
				
				if(J->Matou)
				{
					J->setativo(1);
					J->Matou = false;					
					J->sety(J->gety()-11);				
				}
				J->Mover();
				J2->Mover();
				for(i=0; i < inimigos.size(); i++)
				{
					inimigos[i]->Mover();
				}

				(*T)--;		// Subtrai mcounter e counter
			}

			//Desenha Entidades na Tela (buffer)
			fundo.Desenhar();
			J->Desenhar();
			J2->Desenhar();
			for(i=0; i < obsts.size(); i++)
				obsts[i]->Desenhar();

			for(i=0; i < Conj_Obst.size(); i++)
				Conj_Obst[i]->Desenhar();

			ImpVidas->Imprime(1);
			ImpVidas->Imprime(2);

			if (J->getx() >= 800 - J->getl())		// Se o jogador sair da tela pela direita
			{

				J->setx(800 - J->getl());
			}
			if (J->getx() <= 0)		// Se o jogador sair da tela pela direita
			{

				J->setx(0);
			}

			if (key[KEY_ESC])			// Se Enter for pressionado...
			{
				MP->Iniciar(1, 1, ImpVidas->getJ());
				if (MP->getSair())		// Aciona a tela do menu de saída.
				{
					break;
				}
				T->ResC();				//Para o Personagem aparecer na posição em que parou
			}

			if (J->getativo() == 0)
			{
				if (J->getQvidas() == 0)
				{
					FONT* f = load_font("Arquivos//fontes//pont.pcx",NULL,NULL);
					textout_centre_ex(screen,f,"Jogador 2 VENCEU", SCREEN_W/2, SCREEN_H/2, 0X1700bd,0);
					destroy_font(f);
					rest(3000);
					MP->setSair(true);
					break;
				}
				else
				{
					J->setQvidas(J->getQvidas() - 1);
					J->setx(0);						
					J->sety(0);					
					J->setativo(1);
				}
			}

			if (J2->getativo() == 0)
			{
				if (J2->getQvidas() == 0)
				{
					FONT* f = load_font("Arquivos//fontes//pont.pcx",NULL,NULL);
					textout_centre_ex(screen,f,"Jogador 1 VENCEU", SCREEN_W/2, SCREEN_H/2, 0Xbd1700,0);
					destroy_font(f);
					rest(3000);
					MP->setSair(true);
					break;
				}
				else
				{
					J2->setQvidas(J2->getQvidas() - 1);
					J2->setx(800 - J2->getl());						
					J2->sety(0);					
					J2->setativo(1);
				}
			}

			blit(buffer, screen, 0, 0, 0, 0, 800, 600);		// Desenha o buffer na tela.
			clear( buffer );								// Limpa o buffer;
			T->UpdmC();
		}
	}
}

void Cenario1::setCenario2(Cenario2* Ce){ C2 = Ce; }
