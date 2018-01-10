#include "StdAfx.h"
#include "Jog1.h"


Jog1::Jog1(void)
{
}


Jog1::~Jog1(void)
{
}

void Jog1::Mover()
{
	 if(B == 0 && y < 600 - h - HChao)
    {
        if(pulou == 0)
        {
            pulou = 1;
        }
        if(vy == 10) vy--;
        vy++;
    }
    else if (B == 1 && y < 600 - h - HChao)
    {
        pulou = 0;
        vy = 0;
    }
    else
    {
        pulou = 0;
        vy = 0;
    }

    if(y + h >= 600 - HChao) y = 600 - h - HChao;

    if ((Tec->apertou(KEY_UP)) && pulou <= 1)
    {
        vy = -15;
        pulou++;
    }
    if (C == 1)
    {
        vy = 1;
        pulou = 2;
    }

    if ((Tec->apertou(KEY_RIGHT) || Tec->segurou (KEY_RIGHT))&&( (x+l) < 850)&&(D == 0)) x = x + vx;
    if ((Tec->apertou(KEY_LEFT) || Tec->segurou (KEY_LEFT))&&( x > 0)&&(E == 0)) x = x - vx;

    y = y + vy;
    Tec->keyboard_input();
}




