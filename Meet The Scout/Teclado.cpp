#include "stdafx.h"
#include "Teclado.h"

Teclado::Teclado()
{
    //ctor
}

Teclado::~Teclado()
{
    //dtor
}


void Teclado :: keyboard_input()
{
    int i;
    //poll_keyboard();
    for(i = 0; i < KEY_MAX; i++)
        teclas_anteriores[i] = key[i];
}


