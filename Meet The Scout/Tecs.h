#ifndef TECS_H
#define TECS_H


namespace NTeclas
{
	#include "Teclado.h"
	class TecSeta : public Teclado
	{
	public:
		TecSeta() {}
		virtual ~TecSeta() {}

		int apertou(int TECLA);
		int segurou(int TECLA);
		int soltou(int TECLA);
	protected:

	private:
	};

	class TecNull : public Teclado
	{
	public:
		TecNull() {}
		virtual ~TecNull() {}

		int apertou(int TECLA);
		int segurou(int TECLA);
		int soltou(int TECLA);
	protected:

	private:
	};

	class TecWASD : public Teclado
	{
	public:
		TecWASD() {}
		virtual ~TecWASD() {}

		int apertou(int TECLA);
		int segurou(int TECLA);
		int soltou(int TECLA);
	protected:

	private:
	};
}
#endif // TECNULL_H
