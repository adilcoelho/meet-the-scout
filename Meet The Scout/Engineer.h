#pragma once
#include "inimigo.h"
class Engineer :
	public Inimigo
{
public:
	Engineer(void);
	Engineer(int posx, int posy, BITMAP* img);
	virtual ~Engineer(void);
};

