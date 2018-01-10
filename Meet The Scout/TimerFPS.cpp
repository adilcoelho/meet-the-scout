#include "stdafx.h"
#include "TimerFPS.h"
using namespace TFPS;
#include <allegro.h>
//#include <iostream>

volatile long counter = 0; // counter para incremento do timer do allegro
void Increment()
{

    counter++; 
}
END_OF_FUNCTION(Increment)


TimerFPS::TimerFPS()
{
    mcounter = 0;
}

TimerFPS::~TimerFPS()
{
    //dtor
}

void TimerFPS :: Init()
{
	LOCK_VARIABLE(counter);
    LOCK_FUNCTION(Increment);
    install_int_ex(Increment, BPS_TO_TIMER(60));
}

void TimerFPS :: UpdmC()
{
	mcounter = counter;
	//std::cout << mcounter << std::endl;
}

void TimerFPS :: operator--()
{
	mcounter--;
	counter--;
}

void TimerFPS :: operator--(int)
{
	mcounter--;
	counter--;
}

void TimerFPS :: ResC()
{
	counter = 0;
}

