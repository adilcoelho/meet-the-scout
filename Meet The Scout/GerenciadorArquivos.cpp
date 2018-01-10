#include "stdafx.h"
#include "GerenciadorArquivos.h"
#include <fstream>
using namespace std;
#include <string>
#include <stdexcept>
using namespace std;

GerenciadorArquivos::GerenciadorArquivos()
{
}

GerenciadorArquivos::~GerenciadorArquivos()
{
}

void GerenciadorArquivos :: Ver_Record()
{
    int i, njog, aux, pontuacao[5];
    char nome[5][11];
    FILE *fp;

    BITMAP* buffer = create_bitmap(SCREEN_W,SCREEN_H);
    BITMAP* imagem = load_bitmap("Arquivos/Imagens/MenuRecordes.bmp", NULL);
    FONT* fmenu = load_font("Arquivos/fontes/fontemenu.pcx", NULL, NULL);

    if((fp=fopen("Recordes.txt","r"))==NULL)
    {
        printf("Erro na abertura do arquivo");
        exit(1);
    }

    if (fscanf(fp, "%i\n", &njog)==EOF)
        njog = 0;

	
    Tec->keyboard_input();
    int yrefmenu = SCREEN_H*0.450;
    int xrefmenu = SCREEN_W/15;
    int cor = makecol(0,0x27,0x3f);
    int bgcolor = makecol(0,0x27,0x3f);
    clear_to_color(buffer, bgcolor);
    draw_sprite(buffer, imagem, 0, 0);

    if(njog == 0)
    {
        textprintf_ex(buffer, fmenu, xrefmenu, yrefmenu, cor, -1, "Ainda nao existem recordes, seja o primeiro!!!");
    }

    for(i=0; (i<njog)&&(feof(fp)==0); i++)
    {
        fgets(nome[i],100, fp);
        aux = (strlen(nome[i]) - 1);
        nome[i][aux] =  '\0';
        fscanf(fp, "%i\n", &pontuacao[i]);
    }

    for(i=0; i<njog; i++)
    {
        textprintf_ex(buffer, fmenu, xrefmenu, yrefmenu + i*45, cor, -1, "%d- %s fez %d pts", i+1, nome[i], pontuacao[i]);
    }

    draw_sprite(screen, buffer, 0, 0);

    while(!key[KEY_ESC]);		// Tava Assim: while(!exit_program && !apertou(KEY_ESC));
	while(key[KEY_ESC]);
}

void GerenciadorArquivos :: Atualiza_Ranking(string nome, int pontuacao)
{
	string straux;
	int i=0, j, njog, auxint;
	//FILE *fp;
	vector<Usuario*> Conj_Usuarios;
	Usuario *aux;

	/*if ((fp = fopen("Recordes.txt","r+")) == NULL)		//Antes de usar try catch
	{
	printf("Erro na abertura do arquivo\n");
	exit(1);
	}*/

	try
	{

		ifstream RecuperaRecordes ( "Recordes.txt", ios::out );
		RecuperaRecordes.exceptions ( ifstream::eofbit | ifstream::failbit | ifstream::badbit );

		/*ifstream RecuperaRecordes ( "Recordes.txt", ios::out );
		if ( !RecuperaRecordes )
		{
		cerr << " Arquivo não pode ser aberto " << endl;
		fflush ( stdin );
		getchar( );
		system("pause");
		}*/

		//if (fscanf(fp, "%i\n", &njog)==EOF)
		//njog = 0;
		RecuperaRecordes >> njog;
		if(njog == EOF)
			njog = 0;

		cout<<njog;

		for(int i = 0; i < (njog +1); i++)
			Conj_Usuarios.push_back(new Usuario);

		for( i=0; ( i<njog ) && ( !RecuperaRecordes.eof() ); i++ )  // Lê do Arquivo
		{
			RecuperaRecordes >> straux;				//fgets(Conj_Usuarios[i]->nome,100, fp);
			Conj_Usuarios[i]->setNome(straux);		//auxint = (strlen(Conj_Usuarios[i]->nome) - 1);
			//Conj_Usuarios[i]->nome[auxint] =  '\0';
			RecuperaRecordes >> auxint;				//fscanf(fp, "%d\n", &Conj_Usuarios[i]->pontuacao);
			Conj_Usuarios[i]->setPontuacao(auxint);

			cout << Conj_Usuarios[i]->getNome();		//puts(Conj_Usuarios[i]->nome);
			cout << Conj_Usuarios[i]->getPontuacao();	//printf("%d gols\n", Conj_Usuarios[i]->pontuacao);
		}

		Conj_Usuarios[i]->setNome(nome);				//strcpy(Conj_Usuarios[i]->nome, nome);              // Lê do Jogo
		Conj_Usuarios[i]->setPontuacao(pontuacao);		//Conj_Usuarios[i]->pontuacao = pontuacao;

		for(i=0; i <= njog; i++)																	//for(i=0; i<=njog; i++)
		{																							//	{
			for(j=i+1; j <= njog; j++)																//		for(j=i+1; j<=njog; j++)
			{																						//		{
				if(Conj_Usuarios[i]->getPontuacao() > Conj_Usuarios[j]->getPontuacao())				//			if (Conj_Usuarios[i]->pontuacao > Conj_Usuarios[j]->pontuacao)
				{																					//			{
					aux = Conj_Usuarios[j];															//				aux = Conj_Usuarios[j];
					Conj_Usuarios[j] = Conj_Usuarios[i];											//				Conj_Usuarios[j] = Conj_Usuarios[i];
					Conj_Usuarios[i] = aux;															//				Conj_Usuarios[i]->pontuacao = aux.pontuacao;		//Conj_Usuarios[i] = aux;
					//				Conj_Usuarios[i]->nome = aux.nome;					// PODE TER ERRO DE STRING AKI!
				}																					//			}
			}																						//		}
		}																							//	}

		for(int k = 0; k < Conj_Usuarios.size(); k++)
		{
			cout << Conj_Usuarios[k]->getNome() << endl << Conj_Usuarios[k]->getPontuacao() << endl; // PARA TESTAR
		}

		RecuperaRecordes.close();

	}
	catch(std::exception const& e)
	{
		cout << "Erro na abertura/execução do arquivo para salvar pontuação.\n\n" << e.what() << endl;
		system("pause");
		exit(1);
	}

	ofstream GravaRecordes ("Recordes.txt",ios::out);
	if ( !GravaRecordes )
	{
		cerr << " Arquivo não pode ser aberto " << endl;
		fflush ( stdin );
		getchar( );
		system("pause");
	}

	if (njog !=5)
		GravaRecordes << (njog + 1);	//fprintf(fp, "%d\n", njog+1);
	else
		GravaRecordes << njog << "\n";			//fprintf(fp, "%d\n", njog);

	for(i=njog; i >= 0; i--)
	{
		if( (njog == 5) && (i == 0) )	//if(njog == 5 && i == 0)
			break;
		GravaRecordes << Conj_Usuarios[i]->getNome() << endl
					  << Conj_Usuarios[i]->getPontuacao() << endl;
	}

	for(int i=0; i < Conj_Usuarios.size(); i++)
		if(Conj_Usuarios[i])
			delete Conj_Usuarios[i];

	GravaRecordes.close();

	/*
    rewind(fp);

    if (njog !=5)
        fprintf(fp, "%d\n", njog+1);
    else
        fprintf(fp, "%d\n", njog);

    for(i=njog; i>=0; i--)
    {
        if(njog == 5 && i == 0)
        {
            break;
        }
        fputs(Conj_Usuarios[i]->nome, fp);
        fprintf(fp, "\n%i\n", Conj_Usuarios[i]->pontuacao);
    }

    for(int i=0; i < Conj_Usuarios.size(); i++)
		if(Conj_Usuarios[i])
			delete Conj_Usuarios[i];

    fclose(fp);*/

	/*************** Original *************//*
	int i=0, j, njog, auxint;
    FILE *fp;
    jogador *jog, aux;

    if ((fp = fopen("Recordes.txt","r+")) == NULL)
    {
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }
    if (fscanf(fp, "%i\n", &njog)==EOF)
        njog = 0;

    if ((jog = malloc ((njog+1)*sizeof(jogador))) == NULL)
    {
        printf("Erro na Alocacao\n");
        exit(1);
    }

    for(i=0; (i<njog)&&(feof(fp)==0); i++)  // Lê do Arquivo
    {
        fgets(jog[i].nome,100, fp);
        auxint = (strlen(jog[i].nome) - 1);
        jog[i].nome[auxint] =  '\0';
        fscanf(fp, "%d\n", &jog[i].pontuacao);
        puts(jog[i].nome);
        printf("%d gols\n", jog[i].pontuacao);
    }

    strcpy(jog[i].nome, nome);              // Lê do Jogo
    jog[i].pontuacao = pontuacao;

    for(i=0; i<=njog; i++)
    {
        for(j=i+1; j<=njog; j++)
        {
            if (jog[i].pontuacao > jog[j].pontuacao)
            {
                aux = jog[j];
                jog[j] = jog[i];
                jog[i] = aux;
            }
        }
    }

    rewind(fp);

    if (njog !=5)
        fprintf(fp, "%d\n", njog+1);
    else
        fprintf(fp, "%d\n", njog);

    for(i=njog; i>=0; i--)
    {
        if(njog == 5 && i == 0)
        {
            break;
        }
        fputs(jog[i].nome, fp);
        fprintf(fp, "\n%i\n", jog[i].pontuacao);
    }

    free(jog);
    fclose(fp);*/
}

void GerenciadorArquivos::setTec(Teclado* pTec)
{
	Tec = pTec;
}