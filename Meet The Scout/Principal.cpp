#include "stdafx.h"
#include "Principal.h"

Principal::Principal()
{
    Executar();                      
}

Principal::~Principal()
{
    Allegro.deinit();                   
}

void Principal::Executar()
{
    Inicializar();  // método que inicializa os jogadores.
    MR.Iniciar();	// Executa o menu principal.
}

void Principal::Inicializar()
{
    Allegro.init();
	J.Associa_F1_MP(&MP);			//Associa o Menu Pausar à Fase 1
	J.Associa_F2_MP(&MP);			//Associa o Menu Pausar à Fase 2
	J.Associa_F3_MP(&MP);			//Associa o Menu Pausar à Fase 3
	J.Associa_FB_MP(&MP);
	J.Associa_GC_U(&U);
	J.Associa_Cenarios_MostraInfos(&ImpVidas, &ImpPont);
	J.setjogadores(&Jo, &Jo2);		// Associa os jogadores ao jogo.
    J.Inicializar();
	J.setUsuario(&U);
	J.setGerenciadorArquivo(&GArq);
	J.setGerenciadorSave(&GS);
	
	BITMAP *aux;

	Jo.setimg(load_bitmap("Arquivos//Imagens//Objeto1.bmp", NULL));  //carrega a imagem a partir da pasta onde ela está.
    aux = Jo.getimg();
    Jo.setbuffer(J.getbuffer());	// Associa o buffer ao jogador para que possa se desenhar na tela.
    Jo.seth(aux->h);				// inicializa a altura da imagem/personagem.
    Jo.setl(aux->w);				// inicializa a largura da imagem/personagem.
    Jo.setx(0);						// Posição inicial em x.
    Jo.sety(250);					// Posição icial em y.
    Jo.setvx(3);					// Velocidade icial do objeto em x.
    Jo.setvy(0);					// Velocidade icial do objeto em y.
    Jo.setpulou(0);
    Tec1 = new TecSeta();
    Jo.setTec(Tec1);
	Jo.setjogadorprincipal(true);
	
    Jo2.setimg(load_bitmap("Arquivos//Imagens//Objeto2.bmp", NULL));
    aux = Jo2.getimg();
    Jo2.setbuffer(J.getbuffer());
	Jo2.seth((Jo2.getimg())->h);
    Jo2.setl((Jo2.getimg())->w);
    Jo2.setx(450);
    Jo2.sety(250);
    Jo2.setvx(3);
    Jo2.setvy(0);
    Tec2 = new TecSeta();
    Jo2.setTec(Tec2);
	Jo2.setjogadorprincipal(false);

	//destroy_bitmap(aux);

    


	//Inicia Menu Principal

    MR.setbuffer(J.getbuffer());
    MR.setfundoM(load_bitmap("Arquivos//Imagens//MenuRaiz.bmp", NULL));  
    MR.setfundoinstrucoes(load_bitmap("Arquivos//Imagens//MenuInstrucoes.bmp", NULL)); 
	MR.setMenuJogar(&MJ);
	MR.setGerenciadorArquivos(&GArq);
    MR.setJogo(&J); // Associa o Jogo ao Menu para que se possa usar o buffer do jogo.

	//Inicia Menu Jogar

	MJ.setbuffer(J.getbuffer());
    MJ.setfundoM(load_bitmap("Arquivos//Imagens//MenuJogar.bmp", NULL));
	MJ.setMenuEscolherFase(&MEF);
    MJ.setJogo(&J); 
	MJ.setGerSave(&GS);

	//Inicia Menu Escolher Fase

	MEF.setbuffer(J.getbuffer());
	MEF.setfundoM(load_bitmap("Arquivos//Imagens//MenuEscolherFase.bmp", NULL));
	MEF.setJogo(&J);

	//Inicia Menu Pausar
	MP.setbuffer(J.getbuffer());
	MP.setfundoM(load_bitmap("Arquivos//Imagens//MenuPausar.bmp", NULL));
	MP.setJogo(&J);
	MP.setGerSave(&GS);

	// Inicia Gerenciador Arquivos
	Tec3 = new TecNull();
    GArq.setTec(Tec2);

	// Inicia Gerenciador de Save
	GS.setBuffer(J.getbuffer());
	GS.setJogador(&Jo);
	GS.setUsuario(&U);
	GS.setTeclado(Tec1); 

	// Inicia MostraInfos
	ImpVidas.setbuffer(J.getbuffer());
	ImpVidas.setJogador(&Jo, &Jo2);
	ImpVidas.Inicicializar();
	ImpPont.setbuffer(J.getbuffer());
	ImpPont.setUsuario(&U);
	ImpPont.Inicicializar();
}