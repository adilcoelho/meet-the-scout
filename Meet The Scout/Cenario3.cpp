#include "stdafx.h"
#include "Cenario3.h"
#include "MenuPausar.h"

Cenario3::Cenario3()
{
	fase = 0;
}

Cenario3::~Cenario3()
{
	for(int i=0; i < obsts.size(); i++)
		if(obsts[i])
			delete obsts[i];
}

void Cenario3::Inicializar()
{
	srand (time(NULL));
		int i;
		int N;
	if(fase == 1)
	{
		
		if(obsts.size() != 0)
			obsts.clear();
		if(inimigos.size() != 0)
			inimigos.clear();
		if(Conj_Obst.size() != 0)
			Conj_Obst.clear();
		J->setx(0);						// Posição inicial em x.
		J->sety(250);					// Posição icial em y.


		fundo.setbuffer(buffer);
		fundo.setimg(load_bitmap("Arquivos//Imagens//FundoTela3.bmp", NULL));
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
			auxobst = new Caixa(370, 500 - HCaixa*(1+i));
			obsts.push_back(auxobst);
			obsts[i]->setbuffer(buffer);
		}

		auxobst = new Sentry(150,SCREEN_H - HChao - HSentry);
		obsts.push_back(auxobst);
		obsts[i++]->setbuffer(buffer);

		auxobst = new Caixa(175,325);
		obsts.push_back(auxobst);
		obsts[i++]->setbuffer(buffer);

		auxobst = new Cart(310,500);
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
		N = rand() % 2 + 1;
		for(i = 0; i < N; i++)
		{
			auxinimigo = new Spy(250 + 150*i, 90, load_bitmap("Arquivos//Imagens//Spy.bmp", NULL), J);

			inimigos.push_back(auxinimigo);
			inimigos[i]->setbuffer(buffer);

		}

		N = rand() % 2 + 1;
		int min = i;
		for(i; i < min+N; i++)
		{
			auxinimigo = new Pyro(250 + 50*i, 90, load_bitmap("Arquivos//Imagens//Pyro.bmp", NULL));

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
		J->sety(67);					// Posição icial em y.

		

		fundo.setbuffer(buffer);
		fundo.setimg(load_bitmap("Arquivos//Imagens//FundoTela3.bmp", NULL));
		fundo.setx(0);  
		fundo.sety(0);


		N = rand() % 4 + 1;
		Obstaculo* auxobst;
		for(i = 0; i < N; i++)
		{
			auxobst = new Sentry(LCaixa + (LSentry + 50)*i, 180);
			obsts.push_back(auxobst);
			obsts[i]->setbuffer(buffer);
		}

		auxobst = new Caixa(0,150);
		obsts.push_back(auxobst);
		obsts[i++]->setbuffer(buffer);

		auxobst = new Caixa(444,180);
		obsts.push_back(auxobst);
		obsts[i++]->setbuffer(buffer);

		auxobst = new Caixa(467,426);
		obsts.push_back(auxobst);
		obsts[i++]->setbuffer(buffer);

		int res = i;
		N = rand() % 5 + 1;
		for(i = 0; i < N; i++)
		{
			auxobst = new Cart(700,0 + HCart * i);
			obsts.push_back(auxobst);
			obsts[i+res]->setbuffer(buffer);
		}

		res = i + res;
		N = rand() % 3 + 1;
		for(i = 0; i < N; i++)
		{
			auxobst = new Dispenser( 467 + LCaixa , SCREEN_H - HDispenser*(1+i));
			obsts.push_back(auxobst);
			obsts[i+res]->setbuffer(buffer);
		}

		Inimigo* auxinimigo;
		N = rand() % 2 + 1;
		for(i = 0; i < N; i++)
		{
			auxinimigo = new Spy(250 + 150*i, 90, load_bitmap("Arquivos//Imagens//Spy.bmp", NULL), J);

			inimigos.push_back(auxinimigo);
			inimigos[i]->setbuffer(buffer);

		}

		N = rand() % 2 + 1;
		int min = i;
		for(i; i < min+N; i++)
		{
			auxinimigo = new Pyro(250 + 50*i, 90, load_bitmap("Arquivos//Imagens//Pyro.bmp", NULL));

			inimigos.push_back(auxinimigo);
			inimigos[i]->setbuffer(buffer);
		}
	}
	else if (fase == 3)
	{
		srand (time(NULL));
		int i;
		int N;
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

		F0 = new Fabrica<Caixa>();		//Fabrica Template Implementada: <Caixa> ou <Cart> ou <Dispenser>

		Conj_Obst.push_back( F0->CriarObstaculo(0, 200));
		Conj_Obst[0]->setbuffer(buffer);

		Conj_Obst.push_back( F0->CriarObstaculo(720, 200));
		Conj_Obst[1]->setbuffer(buffer);

		inimigos.push_back(new Heavy(150, 90, load_bitmap("Arquivos//Imagens//Heavy.bmp", NULL)));
		inimigos[0]->setbuffer(buffer);

		//IMPLEMENTAR TELA 1 DA FASE 3 AQUI
	}

}

void Cenario3::Executar()
{
	int i = 0, j = 0, VidasBoss = 4;
	int QInimigos = inimigos.size();
	inimigos[0]->setQuantidade(inimigos.size());
	system("cls");
	printf("Fase %i\n", fase);
	printf("Cenario 3\n");
	printf("Inimigos: %i", inimigos[0]->getQuantidade());
	GC->setCenario(this);
	GC->Iniciar();
	while (1)	//loop principal.
	{

		while(T->mcounter > 0)
		{
			GC->GerenciaColisao();
			
			if( (fase == 3) && (inimigos[0]->getativo() == 0) && (VidasBoss !=0) )
			{
				inimigos[0]->setativo(1);
				VidasBoss--;
			}

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
				printf("Cenario 3\n");
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

		if (fase != 3 && J->getx() >= 800)		// Se o jogador sair da tela pela direita
		{

			break; // venceu
		}
		if (fase == 3 && VidasBoss <= 0)		// Se o jogador sair da tela pela direita
		{
			ImpPont->Imprime();
			blit(buffer, screen, 0, 0, 0, 0, 800, 600);		// Desenha o buffer na tela.
			FONT* f = load_font("Arquivos//fontes//pont.pcx",NULL,NULL);
			textout_centre_ex(screen,f,"Voce VENCEU", SCREEN_W/2, SCREEN_H/2, 0Xf6ff00,-1);
			destroy_font(f);
			rest(3000);
			break; // venceu
		}

		if (key[KEY_ESC])			// Se esc for pressionado...
		{
			MP->Iniciar(fase, 3, ImpVidas->getJ());
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
				J->sety(50);					
				J->setativo(1);
			}
		}

		blit(buffer, screen, 0, 0, 0, 0, 800, 600);		// Desenha o buffer na tela.
		clear( buffer );								// Limpa o buffer;
		T->UpdmC();
	}
}
