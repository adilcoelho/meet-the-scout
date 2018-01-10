#pragma once
#include "Jogador.h"
#include "Usuario.h"

class ImprimeInfos
{
public:
	ImprimeInfos();
	~ImprimeInfos();

	class ImprimeVidas
	{
	private:
		Jogador* J;
		Jogador* J2;
		BITMAP* buffer;
		int cor;
		FONT *fonte;
	public:
		ImprimeVidas();
		~ImprimeVidas();

		void setJogador(Jogador *pJ, Jogador*pJ2);
		void setbuffer( BITMAP* B);
		void Inicicializar();
		void Imprime();
		void Imprime(int jog);

		Jogador* getJ();
	};

	class ImprimePontuacao
	{
	private:
		Usuario* U;
		BITMAP* buffer;
		int cor;
		FONT *fonte;
	public:
		ImprimePontuacao();
		~ImprimePontuacao();

		void setbuffer( BITMAP* B);
		void setUsuario( Usuario *pU );
		void Inicicializar();
		void Imprime();
	};
};

