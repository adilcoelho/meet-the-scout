
#include "inimigo.h"
#include "Jogador.h"
class Spy : public Inimigo
{
private:
	Jogador* J;
public:
	Spy(void);
	Spy(int posx, int posy, BITMAP* img, Jogador* J);
	virtual ~Spy(void);

	//void setjogador);
	virtual void Desenhar();
};
