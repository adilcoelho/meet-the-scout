#include "StdAfx.h"
#include "Sentry.h"


Sentry::Sentry(void)
{
}

Sentry::Sentry(int px, int py)
{
	img = load_bitmap("Arquivos//Imagens//Sentry.bmp", NULL);
	h = this->img->h;
	l = this->img->w;
	x = px; y = py; 
}

Sentry::Sentry(int px, int py, int ph, int pl)
{
	img = NULL;
	x = px; y = py; 
	h = ph;
	l = pl;
}


Sentry::~Sentry(void)
{
}
