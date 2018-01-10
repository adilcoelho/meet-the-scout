#pragma once
#include "obstaculo.h"
class Sentry :
	public Obstaculo
{
public:
	Sentry(void);
	Sentry(int px, int py = 0);
	Sentry(int px, int py, int ph, int pl);
	virtual ~Sentry(void);
};

