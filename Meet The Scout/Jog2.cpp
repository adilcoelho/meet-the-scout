#include "StdAfx.h"
#include "Jog2.h"


Jog2::Jog2(void)
{
}


Jog2::~Jog2(void)
{
}

void Jog2::Mover()
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

    if ((Tec->apertou(KEY_W)) && pulou <= 1)
    {
        vy = -15;
        pulou++;
    }
    if (C == 1)
    {
        vy = 1;
        pulou = 2;
    }

    if ((Tec->apertou(KEY_D) || Tec->segurou (KEY_D))&&( (x+l) < 850)&&(D == 0)) x = x + vx;
    if ((Tec->apertou(KEY_A) || Tec->segurou (KEY_A))&&( x > 0)&&(E == 0)) x = x - vx;

    y = y + vy;
    Tec->keyboard_input();
}




