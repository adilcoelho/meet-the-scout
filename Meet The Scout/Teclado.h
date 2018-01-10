#ifndef TECLADO_H
#define TECLADO_H
#include <allegro.h>

class Teclado
{
    public:
        Teclado();
        virtual ~Teclado();
        void keyboard_input();
        virtual int apertou(int TECLA) = 0;
        virtual int segurou(int TECLA) = 0;
        virtual int soltou(int TECLA) = 0;
    protected:
        int teclas_anteriores[KEY_MAX];
    private:
};



#endif // TECLADO_H
