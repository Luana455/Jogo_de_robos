#include "Robos.h"
    



Robos::Robos()
{
	
	srand(time(0));
}


Robos::~Robos()
{
}

void Robos::criar_robo()
{ //cria um robo com 30 de vida e atributos aleatorios 
		vida = 30;
		vitorias = 0;
		defesa = rand() % 9 + 1;
		PA = rand() % 9 + 1;
		DAM = rand() % 9 + 1;
		
}

void Robos::set_vida(int vida)
{
	this->vida = vida;
}

void Robos::set_defesa(int defesa)
{
	this->defesa = defesa;
}

void Robos::set_PA(int PA)
{
	this->PA = PA;
}

void Robos::set_DAM(int DAM)
{
	this->DAM = DAM;
}

void Robos::set_vitorias(int vitorias)
{
	this->vitorias = vitorias;
}

int Robos::get_vida()
{
	return this->vida;
}

int Robos::get_defesa()
{
	return this->defesa;
}

int Robos::get_PA()
{
	return this->PA;
}

int Robos::get_DAM()
{
	
	return this->DAM;
}

int Robos::get_vitorias()
{
	return this->vitorias;
}

