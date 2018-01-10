#include "StdAfx.h"
#include "GerenciadorColisao.h"
#include "Cenario.h"

GerenciadorColisao::GerenciadorColisao()
{
}

GerenciadorColisao::~GerenciadorColisao()
{
}

bool GerenciadorColisao :: bounding_box_collision()
{
    if ((P->getx() > E->getx() + E->getl() - 1) || // is b1 on the right side of b2?
        (P->gety() > E->gety() + E->geth() - 1) || // is b1 under b2?
        (E->getx() > P->getx() + P->getl() - 1) || // is b2 on the right side of b1?
        (E->gety() > P->gety() + P->geth() - 1))   // is b2 under b1?
    {
        // no collision
        return false;
    }
	if (E->getativo() == 1 && P->getativo() == 1)
    return true;
	else return false;
}

void GerenciadorColisao :: updRelPosI()		// As alturas tem prioridade (Cima e Baixo)
{
    
	if(P->gety() + P->geth() - 11 < E->gety())  //acima
		E->setRelPos(102);

    else if(P->gety() +10> (E->gety() + E->geth())) //abaixo
        E->setRelPos(101);

    else if(P->getx() + P->getl() - 5 < E->getx()) // esquerda
        E->setRelPos(104);

    else if(P->getx() + 5 > (E->getx() + E->getl())) // direita
        E->setRelPos(103);
}

void GerenciadorColisao :: updRelPosJ()		// Os lados têm prioridade (esquerda e direita)
{
    if(P->getx() + P->getl() - 5 < E->getx()) // esquerda
        E->setRelPos(104);

    else if(P->getx() + 5 > (E->getx() + E->getl())) // direita
        E->setRelPos(103);

	else if(P->gety() + P->geth() - 11 < E->gety())  //acima
		E->setRelPos(102);

    else if(P->gety() +10> (E->gety() + E->geth())) //abaixo
        E->setRelPos(101);    
}

void GerenciadorColisao :: colisaodetectada()
{
    switch(E->getRelPos())
        {
			case 101:	//P->setCol('C');
						if(E->getehinimigo() == 1)		//Entre se personagem for jogador e entidade inimigo
						{
							//std::cout << "Mata Jogador\n"; 
							P->setativo(0); // mata o Jogador
						}
						P->setC(1);
						//std::cout << "Colidiu por cima\n";
						
						break;
			case 102:   if(E->getehinimigo() == 1)		//Entre se personagem for jogador e entidade inimigo
						{
							//std::cout << "Mata Inimigo\n"; 
							E->setativo(0); // mata o inimigo
							P->setvy(-15);
							P->setpulou(1);
							P->Matou = true;
							(*U)++;			//U->setPontuacao(U->getPontuacao()+100); // Incrementa Pontuação para cada inimigo morto
						}
						else if (P->getehinimigo() != 1)
						{
							//P->setCol('B');
							P->setB(1);
							if(P->gety() + P->geth() > E->gety()) P->sety(E->gety()-P->geth()+1); //nao fica mais afundado nos blocos
						}
						else	// Entra se personagem for Inimigo e entidade obstaculo
						{
							P->setB(1);
							if(P->gety() + P->geth() > E->gety()) P->sety(E->gety()-P->geth()+1);
						}
						//std::cout << "Colidiu por baixo\n";
						break;
            case 103:	//P->setCol('E');
						if(E->getehinimigo() == 1)		//Entre se personagem for jogador e entidade inimigo
						{
							//std::cout << "Mata Jogador\n"; 
							P->setativo(0); // mata o inimigo
						}
						P->setE(1);
						//std::cout << "Colidiu pela esquerda\n";
						break;
            case 104:   //P->setCol('D');
						if(E->getehinimigo() == 1)		//Entre se personagem for jogador e entidade inimigo
						{
							//std::cout << "Mata Jogador\n"; 
							P->setativo(0); // mata o Jogador
						}
						P->setD(1);
						//std::cout << "Coildiu pela direita\n";
                        break;
			default:   ;
        }
    
}

void GerenciadorColisao :: testecolisao()
{
	int k;
	if (k = bounding_box_collision())
	{
		colisaodetectada();
	}

}

void GerenciadorColisao::Colisao(Jogador* J, Entidade* E)
{
	P = J;				//Polimorfismo: P "vê" a parte Personagem de Jogador
	this->E = E;
	updRelPosJ();
	testecolisao();
}

void GerenciadorColisao::Colisao(Inimigo* I, Entidade* E)
{
	P = I;				//Idem, mas para Inimigo
	this->E = E;
	updRelPosI();
	testecolisao();
}

void GerenciadorColisao::Colisao(Jogador* J, Jogador* J2)
{
	this->J1 = J;				//Polimorfismo: P "vê" a parte Personagem de Jogador
	this->J2 = J2;
	updRelPosB();
	testecolisaoB();
}

void GerenciadorColisao::setUsuario(Usuario *pU)
{
	U = pU;
}

void GerenciadorColisao :: colisaodetectadaB()
{
    switch(J2->getRelPos())
        {
			case 101:	//J1->setCol('C');
						
						J1->setativo(0); // mata o Jogador
						J2->setvy(-15);
						J2->setpulou(1);
						J2->Matou = true;
						break;

			case 102:   J2->setativo(0); // mata o inimigo
						J1->setvy(-15);
						J1->setpulou(1);
						J1->Matou = true;
						(*U)++;			//U->setPontuacao(U->getPontuacao()+100); // Incrementa Pontuação para cada inimigo morto
						break;

            case 103:	J1->setE(1);
						break;

            case 104:   J1->setD(1);
                        break;
			default:   ;
        }
    
}

void GerenciadorColisao :: testecolisaoB()
{
	int k;
	if (k = bounding_box_collisionB())
	{
		colisaodetectadaB();
	}

}

void GerenciadorColisao :: updRelPosB()		// Os lados têm prioridade (esquerda e direita)
{
    if(J1->getx() + J1->getl() - 5 < J2->getx()) // esquerda
        J2->setRelPos(104);

    else if(J1->getx() + 5 > (J2->getx() + J2->getl())) // direita
        J2->setRelPos(103);

	else if(J1->gety() + J1->geth() - 11 < J2->gety())  //acima
		J2->setRelPos(102);

    else if(J1->gety() +10> (J2->gety() + J2->geth())) //abaixo
        J2->setRelPos(101);    
}

bool GerenciadorColisao :: bounding_box_collisionB()
{
    if ((J1->getx() > J2->getx() + J2->getl() - 1) || // is b1 on the right side of b2?
        (J1->gety() > J2->gety() + J2->geth() - 1) || // is b1 under b2?
        (J2->getx() > J1->getx() + J1->getl() - 1) || // is b2 on the right side of b1?
        (J2->gety() > J1->gety() + J1->geth() - 1))   // is b2 under b1?
    {
        // no collision
        return false;
    }
	if (J2->getativo() == 1 && J1->getativo() == 1)
    return true;
	else return false;
}

void GerenciadorColisao::GerenciaColisao()
{
	int i = 0, j = 0;

	// Reseta Colisões
	J1->resetCol();
	for(i=0; i < inimigos.size(); i++)
	{
		inimigos[i]->resetCol();
	}

	// Verifica Colisões com o Jogador
	for(i=0; i < obsts.size(); i++)
		Colisao(J1,obsts[i]);

	for(i=0; i < Conj_Obst.size(); i++)
		Colisao(J1,Conj_Obst[i]);

	for(i=0; i < inimigos.size(); i++)
		Colisao(J1,inimigos[i]);

	for(i=0; i < inimigos.size(); i++)
	{
		Colisao(inimigos[i],J1);
		for(j=0; j < obsts.size(); j++)
			Colisao(inimigos[i],obsts[j]);
		for(j=0; j < Conj_Obst.size(); j++)
			Colisao(inimigos[i],Conj_Obst[j]);
	}
}

void GerenciadorColisao::GerenciaColisao2J()
{
	int i = 0;
	// Reseta Colisões
	J1->resetCol();
	J2->resetCol();

	for(i=0; i < inimigos.size(); i++)
	{
		inimigos[i]->resetCol();
	}

	// Verifica Colisões dos obstaculos com os Jogadores
	for(i=0; i < obsts.size(); i++)
		Colisao(J1,obsts[i]);

	for(i=0; i < Conj_Obst.size(); i++)
		Colisao(J1,Conj_Obst[i]);

	for(i=0; i < obsts.size(); i++)
		Colisao(J2,obsts[i]);

	for(i=0; i < Conj_Obst.size(); i++)
		Colisao(J2,Conj_Obst[i]);

	Colisao(J1,J2);
	Colisao(J2,J1);
}

void GerenciadorColisao::setCenario(Cenario *pC)
{
	C = pC;
}

void GerenciadorColisao::Iniciar()
{
	J1 = C->getJogador1();
	J2 = C->getJogador2();
	Conj_Obst = C->getConj_Obst();
	obsts = C->getobsts();
	inimigos = C->getinimigos();
}