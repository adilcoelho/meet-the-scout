#pragma once
#include <string>
using namespace std;

class Usuario
{
private:
	string Nome;
	int Pontuacao;

public:
	//char* nome;					//TESTE -----------------------------------------------------------------------------------------------
	//int pontuacao;				//TESTE -----------------------------------------------------------------------------------------------

	Usuario();
	~Usuario();

	void setNome (string N);
	void setPontuacao(const int Pont);

	string getNome();
	const int getPontuacao();

	void CadastrarUsuario();

	void operator++();
	void operator++(int);

	/*void operator=(Usuario *U)	//TESTE -----------------------------------------------------------------------------------------------
	{
		this->nome = U->nome;
		this->pontuacao = U->pontuacao;
	}

	void operator=(Usuario U)	//TESTE -----------------------------------------------------------------------------------------------
	{
		this->nome = U.nome;
		this->pontuacao = U.pontuacao;
	}*/

};

