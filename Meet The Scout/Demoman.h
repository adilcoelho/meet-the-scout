#pragma once
#include "inimigo.h"
class Demoman :
	public Inimigo
{
public:
	Demoman(void);
	Demoman(int posx, int posy, BITMAP* img);
	virtual ~Demoman(void);
};

