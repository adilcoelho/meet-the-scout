#pragma once
#include "inimigo.h"
class Heavy : public Inimigo
{
public:
	Heavy(void);
	Heavy(int posx, int posy, BITMAP* img);
	virtual ~Heavy(void);
};

