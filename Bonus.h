#pragma once
#include "Robos.h"
#include <iostream>
#include <ctime>

class Bonus :public Robos
{
public:
	Bonus();
	~Bonus();

	void criar_bonus();
	const char* gerar();
	void ativar_bonus(Robos* r, Bonus* b);
	void efeito_bonus(Robos* r, Bonus* b, const char* nome);

	const char* get_bonus1();
	const char* get_bonus2();
	const char* get_bonus3();

protected:
	const char* bonus1;
	const char* bonus2;
	const char* bonus3;
	int n;
	Robos *r[2];
	Bonus *b[2];

};

