#pragma once
#include "Inimigo.h"

class Soldier : public Inimigo
{
private:

public:
	Soldier();
	Soldier :: Soldier(int posx, int posy, BITMAP* img);
	~Soldier();

	void Mover();

};

