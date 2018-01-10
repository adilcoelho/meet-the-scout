#include "stdafx.h"
#include "Tecs.h"
namespace NTeclas
{

	int TecNull :: apertou(int TECLA)
	{
		//poll_keyboard();
		return 0;

	}

	int TecNull :: segurou(int TECLA)
	{
		//poll_keyboard();
		return 0;
	}

	int TecNull :: soltou(int TECLA)
	{
		//poll_keyboard();
		return 0;
	}

	int TecSeta :: apertou(int TECLA)
	{
		//poll_keyboard();
		return(teclas_anteriores[TECLA] == 0 && key[TECLA] != 0);

	}

	int TecSeta :: segurou(int TECLA)
	{
		//poll_keyboard();
		return(teclas_anteriores[TECLA] != 0 && key[TECLA] != 0);
	}

	int TecSeta :: soltou(int TECLA)
	{
		//poll_keyboard();
		return(teclas_anteriores[TECLA] != 0 && key[TECLA] == 0);
	}

	int TecWASD :: apertou(int TECLA)
	{
		//poll_keyboard();
		return(teclas_anteriores[TECLA] == 0 && key[TECLA] != 0);

	}

	int TecWASD :: segurou(int TECLA)
	{
		//poll_keyboard();
		return(teclas_anteriores[TECLA] != 0 && key[TECLA] != 0);
	}

	int TecWASD :: soltou(int TECLA)
	{
		//poll_keyboard();
		return(teclas_anteriores[TECLA] != 0 && key[TECLA] == 0);
	}

}