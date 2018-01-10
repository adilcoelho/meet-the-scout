#pragma once
#include "Jogo.h"
#include "Menu.h"
#include "MenuJogar.h"
#include "GerenciadorArquivos.h"

class MenuRaiz : public Menu
{
private:
    BITMAP* fundoI; // Fundo do menu de Instrução.
	MenuJogar* MJ;
	GerenciadorArquivos *Garq;
    // Bitmap de buffer para desenhar todas as imagens nele
    // e logo em seguida jogá-lo inteiro na tela, isso evita
    // que a tela ou as imagens fiquem piscando.
           
public:
	MenuRaiz();
    ~MenuRaiz();
           
    void Iniciar();
    void Raiz();			// Menu Principal.
	void Instrucoes();		// Tela de Instrução.
           
    void setfundoinstrucoes( BITMAP* I);
	void setMenuJogar( MenuJogar* M );
	void setGerenciadorArquivos(GerenciadorArquivos *pGarq);

};

