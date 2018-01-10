#pragma once
class Entidade
{
protected:
	BITMAP* img;		// Imagem.
	BITMAP* buffer;		// buffer para que o jogador possa se desenhar na tela.
	short int x;		// Posição em x.
	short int y;		// Posição em y.
	short int h;		// Altura da imagem.
	short int l;		// Largura da imagem.
	int posanterior;	// Posição Relativa ao Personagem [0: C, 1: B, 2: E, 3: D]
	int ativo;
	int ehinimigo;

public:
	Entidade();
	~Entidade();

	// Sets //

	void setbuffer( BITMAP* B);
	void setimg( BITMAP* I );
	void setx( const short int X );
	void sety( const short int Y );
	void seth( const short int H );
	void setl( const short int L );	
	void setRelPos(int PA);
	void setativo(int at);

	// Gets //

	BITMAP* getimg();
	const short int getx();
	const short int gety();
	const short int geth();
	const short int getl();
	const short int getehinimigo();
	int getRelPos();
	int getativo();
	// Método Virtual Puro //

	virtual void Desenhar() = 0;
};

