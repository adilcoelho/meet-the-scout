#ifndef TIMERFPS_H
#define TIMERFPS_H

namespace TFPS
{
	class TimerFPS
	{
	public:
		TimerFPS();
		virtual ~TimerFPS();
		void Init();
		volatile long mcounter; // counter acessível de fora
		void SubC();
		void UpdmC();
		void ResC();
		void operator--();
		void operator--(int);	//Para evitar os warnings
		//void Increment();
	protected:
	private:
	};
}
#endif // TIMERFPS_H
