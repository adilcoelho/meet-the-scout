#include "stdafx.h"
#include "Cenario2.h"
#include "MenuPausar.h"

Cenario2::Cenario2()
{
	fase = 0;
}

Cenario2::~Cenario2()
{
	for(int i=0; i < obsts.size(); i++)
		if(obsts[i])
			delete obsts[i];
}

void Cenario2::Inicializar()
{
	srand (time(NULL));
	int i;
	int N;
	int aux;

	F0 = new Fabrica<Caixa>();		//Fabrica Template Implementada: <Caixa> ou <Cart> ou <Dispenser>
	F1 = new Fabrica<Sentry>();		//Fabrica Template Implementada: <Caixa> ou <Cart> ou <Dispenser>
	F2 = new Fabrica<Cart>();		//Fabrica Template Implementada: <Caixa> ou <Cart> ou <Dispenser>
	F3 = new Fabrica<Dispenser>();		//Fabrica Template Implementada: <Caixa> ou <Cart> ou <Dispenser>
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
		fundo.setimg(load_bitmap("Arquivos//Imagens//FundoTela2.bmp", NULL));
		fundo.setx(0);  
		fundo.sety(0);

		//chao.setbuffer(buffer);
		//chao.setimg(load_bitmap("Arquivos//Imagens//chaoFase1.bmp", NULL));
		//chao.setx(0);  
		//chao.sety(0);


		N = rand() % 3 + 1;
		Obstaculo* auxobst;
		for(i = 0; i < N; i++)
		{
			auxobst = new Caixa(200, SCREEN_H - HChao - HCaixa*(1+i));
			obsts.push_back(auxobst);
			obsts[i]->setbuffer(buffer);
		}


		auxobst = new Sentry(90,SCREEN_H - HChao - HSentry);
		obsts.push_back(auxobst);
		obsts[i++]->setbuffer(buffer);

		auxobst = new Dispenser(300,275);
		obsts.push_back(auxobst);
		obsts[i++]->setbuffer(buffer);
		int res = i;
		N = rand() % 2 + 1;
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
			auxinimigo = new Engineer(250 + 150*i, 90, load_bitmap("Arquivos//Imagens//Engineer.bmp", NULL));

			inimigos.push_back(auxinimigo);
			inimigos[i]->setbuffer(buffer);

		}
		N = rand() % 4 + 3;
		int min = i;
		for(i; i < min+N; i++)
		{
			auxinimigo = new Soldier(200 + 50*i, 90, load_bitmap("Arquivos//Imagens//Soldier.bmp", NULL));

			inimigos.push_back(auxinimigo);
			inimigos[i]->setbuffer(buffer);
		}
	}
	else if (fase == 2)
	{
		if(obsts.size() != 0)
			obsts.clear();
		if(inimigos.size() != 0)
			inimigos.clear();
		if(Conj_Obst.size() != 0)
			Conj_Obst.clear();
		J->setx(0);						// Posição inicial em x.
		J->sety(500);					// Posição icial em y.

	

		fundo.setbuffer(buffer);
		fundo.setimg(load_bitmap("Arquivos//Imagens//FundoTela2.bmp", NULL));
		fundo.setx(0);  
		fundo.sety(0);

		//chao.setbuffer(buffer);
		//chao.setimg(load_bitmap("Arquivos//Imagens//chaoFase1.bmp", NULL));
		//chao.setx(0);  
		//chao.sety(0);


		N = rand() % 3 + 1;
		Obstaculo* auxobst;
		i=0;
		int res = i;
		N = rand() % 3 + 1;
		for(i = 0; i < N; i++)
		{
			auxobst = new Dispenser(748, 377 - HDispenser*(1+i));
			obsts.push_back(auxobst);
			obsts[i + res]->setbuffer(buffer);
		}

		auxobst = new Caixa(107, 448);
		obsts.push_back(auxobst);
		obsts[i++]->setbuffer(buffer);

		auxobst = new Caixa(0, 290);
		obsts.push_back(auxobst);
		obsts[i++]->setbuffer(buffer);

		res = i;
		N = 4;
		for(i = 0; i < N; i++)
		{
			auxobst = new Caixa(106 + 170*i, 125);
			obsts.push_back(auxobst);
			obsts[i + res]->setbuffer(buffer);
		}

		auxobst = new Dispenser(300,275);
		obsts.push_back(auxobst);
		obsts[res + i++]->setbuffer(buffer);
		
		res = i + res;
		N = 4;
		for(i = 0; i < N; i++)
		{
			auxobst = new Sentry(748, SCREEN_H - HChao - HSentry*(1+i));
			obsts.push_back(auxobst);
			obsts[i + res]->setbuffer(buffer);
		}


		Inimigo* auxinimigo;
		N = rand() % 2 + 2;
		for(i = 0; i < N; i++)
		{
			auxinimigo = new Engineer(250 + 150*i, 90, load_bitmap("Arquivos//Imagens//Engineer.bmp", NULL));

			inimigos.push_back(auxinimigo);
			inimigos[i]->setbuffer(buffer);

		}
		N = rand() % 3 + 4;
		int min = i;
		for(i; i < min+N; i++)
		{
			auxinimigo = new Soldier(200 + 50*i, 90, load_bitmap("Arquivos//Imagens//Soldier.bmp", NULL));

			inimigos.push_back(auxinimigo);
			inimigos[i]->setbuffer(buffer);
		}
	}
	else if (fase == 3)
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

		Conj_Obst.push_back( F0->CriarObstaculo(140, SCREEN_H - HChao - HCaixa));
		aux = Conj_Obst.size() - 1;
		Conj_Obst[aux]->setbuffer(buffer);


		for(i = 0; i < 1; i++)
		{
			Conj_Obst.push_back( F3->CriarObstaculo(620 + (LDispenser) * i, SCREEN_H - HChao - HDispenser*(1+i)));
			aux = Conj_Obst.size() - 1;
			Conj_Obst[aux]->setbuffer(buffer);
		}

		Inimigo* auxinimigo;
		int paux;
		N = rand() % 2 + 1;
		for(i = 0; i < N; i++)
		{
			auxinimigo = new Spy(150 + 150*i, 90, load_bitmap("Arquivos//Imagens//Spy.bmp", NULL), J);
			inimigos.push_back(auxinimigo);
			paux = inimigos.size() - 1;
			inimigos[paux]->setbuffer(buffer);

		}
		N = rand() % 2 + 1;
		for(i = 0; i < N; i++)
		{
			auxinimigo = new Demoman(200 + 120*i, 90, load_bitmap("Arquivos//Imagens//Demoman.bmp", NULL));
			inimigos.push_back(auxinimigo);
			paux = inimigos.size() - 1;
			inimigos[paux]->setbuffer(buffer);
		}
		N = rand() % 2 + 1;
		for(i = 0; i < N; i++)
		{
			auxinimigo = new Engineer(225 + 120*i, 90, load_bitmap("Arquivos//Imagens//Engineer.bmp", NULL));
			inimigos.push_back(auxinimigo);
			paux = inimigos.size() - 1;
			inimigos[paux]->setbuffer(buffer);
		}
		N = rand() % 2 + 1;
		for(i = 0; i < N; i++)
		{
			auxinimigo = new Pyro(350 + 120*i, 90, load_bitmap("Arquivos//Imagens//Pyro.bmp", NULL));
			inimigos.push_back(auxinimigo);
			paux = inimigos.size() - 1;
			inimigos[paux]->setbuffer(buffer);
		}
		N = rand() % 2 + 1;
		for(i = 0; i < N; i++)
		{
			auxinimigo = new Soldier(310 + 120*i, 90, load_bitmap("Arquivos//Imagens//Soldier.bmp", NULL));
			inimigos.push_back(auxinimigo);
			paux = inimigos.size() - 1;
			inimigos[paux]->setbuffer(buffer);
		}
	}

}

void Cenario2::Executar()
{
	int i = 0, j = 0;
	int QInimigos = inimigos.size();
	inimigos[0]->setQuantidade(inimigos.size());
	system("cls");
	printf("Fase %i\n", fase);
	printf("Cenario 2\n");
	printf("Inimigos: %i", inimigos[0]->getQuantidade());
	GC->setCenario(this);
	GC->Iniciar();
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
				printf("Cenario 2\n");
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
			C3->Executar();			// Vai para a tela2.
			break;
		}

		if (key[KEY_ESC])			// Se esc for pressionado...
		{
			MP->Iniciar(fase, 2, ImpVidas->getJ());
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
				J->sety(100);					
				J->setativo(1);
			}
		}

		blit(buffer, screen, 0, 0, 0, 0, 800, 600);		// Desenha o buffer na tela.
		clear( buffer );								// Limpa o buffer;
		T->UpdmC();
	}
}

void Cenario2::setCenario3( Cenario3* Ce ){ C3 = Ce; }
