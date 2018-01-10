#pragma once
#include "abs_GerenciadorColisao.h"
#include "Usuario.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include <vector>
using namespace std;
class Cenario;

class GerenciadorColisao
{
private:
	Entidade *E;
	Personagem* P;
	Jogador* J1;
	Jogador* J2;
	Usuario *U;
	Cenario *C;
	vector<Obstaculo*> Conj_Obst;
	vector<Obstaculo*> obsts;
	vector<Inimigo*> inimigos;
public:
	GerenciadorColisao();
	~GerenciadorColisao();

	bool bounding_box_collision();
	bool bounding_box_collisionB();
	void updRelPosJ();
	void updRelPosI();
	void updRelPosB();
	void colisaodetectada();
	void testecolisao();
	void colisaodetectadaB();
	void testecolisaoB();
	void Colisao(Jogador* J, Entidade* E);
	void Colisao(Jogador* J, Jogador* J2);
	void Colisao(Inimigo* I, Entidade* E);
	void GerenciaColisao();
	void GerenciaColisao2J();
	//void Colisao(Personagem* P, Entidade* E);

	void setUsuario(Usuario *pU);
	void setCenario(Cenario *pC);
	void Iniciar();

	//void setCol();
};

