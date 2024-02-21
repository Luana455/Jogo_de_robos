#pragma once
#include "Robos.h"
#include "Bonus.h"
#include <fstream>
#include <ctime>

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void combate(Robos *r1, Robos *r2,Bonus *b1, Bonus *b2);

	void set_turno(int turno);

	void salvar_jogo();
	void carregar_jogo();

	int get_turno();



protected:
	int turno, vitoria_robo1=0, vitoria_robo2=0;
	int n1, n2, opcao, PA1, PA2, DEF1, DEF2, DAM1, DAM2;
	Robos *r[2];
	Bonus *b[2];
	

};

