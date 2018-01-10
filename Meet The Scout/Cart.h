#pragma once
#include "obstaculo.h"
class Cart :
	public Obstaculo
{
public:
	Cart(void);
	Cart(int px, int py = 0);
	Cart(int px, int py, int ph, int pl);
	virtual ~Cart(void);
};

