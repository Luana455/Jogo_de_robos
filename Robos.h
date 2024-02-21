#pragma once
#include <iostream>
#include <ctime>
using namespace std;

class Robos
{
public:
	Robos();
	~Robos();

	void criar_robo();

	void set_vida(int vida);
	void set_defesa(int defesa);
	void set_PA(int PA);
	void set_DAM(int DAM);
	void set_vitorias(int vitorias);

	int get_vida();
	int get_defesa();
	int get_PA();
	int get_DAM();
	int get_vitorias();
	


protected:
	int vida;
	int defesa;
	int PA;
	int DAM;
	int vitorias;
	


};

