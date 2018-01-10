#include "stdafx.h"
#include "Gerenciador_Save.h"
#include <fstream>


Gerenciador_Save::Gerenciador_Save(void)
{
}


Gerenciador_Save::~Gerenciador_Save(void)
{
}

void Gerenciador_Save::salve(int fase, int tela, Jogador* J)
{
	
	int pont = U->getPontuacao();
	string nome = U->getNome();
    std::ofstream Save("salvar.dat", std::ios::binary);
	Save.write(reinterpret_cast<const char *>(&fase), sizeof(int));
	Save.write(reinterpret_cast<const char *>(&tela), sizeof(int));
	Save.write(reinterpret_cast<const char *>(&pont), sizeof(int));
	Save.write(reinterpret_cast<const char *>(&*J), sizeof(*J));
	//Save.write(reinterpret_cast<const char *>(&nome), sizeof(string));
	Save << nome;
	

	std::cout << "Dados Salvos com sucesso!\n";
	Save.close();
}

void Gerenciador_Save::loade()
{
  
    
    std::ifstream Load("salvar.dat",std::ios::binary);
    
    Load.read(reinterpret_cast<char *>(&fase), sizeof(int));
	Load.read(reinterpret_cast<char *>(&tela), sizeof(int));
	Load.read(reinterpret_cast<char *>(&pontuacao), sizeof(int));
	Load.read(reinterpret_cast<char *>(&Jo), sizeof(*J));
	string auxnome;
	//Load.read(reinterpret_cast<char *>(&auxnome), sizeof(string));
	Load >> auxnome;
	nome = auxnome;
	

	
	std::cout << "Dados carregados com sucesso!\n";
	std::cout << "Dados carregados:\n";
	std::cout << "Posicao do jogador: X = "<<Jo.getx() << " Y = " << Jo.gety() << std::endl;
	std::cout << "Nome: " << nome << std::endl;
	std::cout << "Num de vidas: " << Jo.getQvidas() << std::endl;
	std::cout << "Pontuacao: " << pontuacao << std::endl;
	std::cout << "Fase: " << fase << std::endl;
	std::cout << "Cenario: " << tela << std::endl;
	//system("pause");
	/**J = Jo;
	J->setbuffer(buffer);
	J->setimg(load_bitmap("Arquivos//Imagens//Objeto1.bmp", NULL));
    J->setTec(Tec);*/

	Load.close();
  
}

void Gerenciador_Save::setBuffer(BITMAP* buf){buffer = buf;}
void Gerenciador_Save::setJogador(Jogador* J){this->J = J;}

void Gerenciador_Save::setTeclado(Teclado* Tec) {this->Tec = Tec;}
void Gerenciador_Save::setUsuario(Usuario* U) {this->U = U;}

int Gerenciador_Save::getfase(){ return fase;}
int Gerenciador_Save::gettela() {return tela;}
int Gerenciador_Save::getpont(){return pontuacao;}
string Gerenciador_Save::getnome(){return nome;}
Jogador* Gerenciador_Save::getJo(){return &Jo;}