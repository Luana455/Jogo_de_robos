#include "Bonus.h"



Bonus::Bonus()
{
	srand(time(0));
}


Bonus::~Bonus()
{
}

const char* Bonus::gerar() //M�todo para gerar um b�nus aleat�rio entre os 5 dispon�veis
{
	n = rand() % 4 + 1;

	switch (n)
	{
	case 1:
		return "Strength Armor";
		break;

	case 2:
		return "Precision Arms";
		break;

	case 3:
		return "Bomb Punch";
		break;

	case 4:
		return "Energy Shield";
		break;

	case 5:
		return "Plasma Bazooka";
		break;

	default:
		break;
	}
}
void Bonus::criar_bonus() //Cria e seta os 3 b�nus utilizando o m�todo gerar() para deixar aleat�rio
{
	bonus1 = gerar();
	bonus2 = gerar();
	bonus3 = gerar();
}

void Bonus::efeito_bonus(Robos* r, Bonus* b, const char* nome) //M�todo para aplicar os efeitos dos b�nus no rob� espec�fico (caso ele tenha algum desses b�nus)
{
	if (nome == "Strength Armor")
	{
		n = 1;
	}
	else if (nome == "Precision Arms")
	{
		n = 2;
	}
	else if (nome == "Bomb Punch")
	{
		n = 3;
	}
	else if (nome == "Energy Shield")
	{
		n = 4;
	}
	else
	{
		n = 5;
	}

	switch (n)
	{
	case 1:
		r->set_defesa(r->get_defesa() + 2);
		break;

	case 2:
		r->set_PA(r->get_PA() + 1);
		break;

	case 3:
		r->set_PA(r->get_PA() + 1);
		r->set_DAM(r->get_DAM() + 2);
		break;

	case 4:
		r->set_defesa(r->get_defesa() + 1);
		r->set_DAM(r->get_DAM() + 1);
		break;

	case 5:
		r->set_PA(r->get_PA() + 1);
		r->set_defesa(r->get_defesa() - 2);
		r->set_DAM(r->get_DAM() + 2);
		break;

	default:
		break;
	}
}

void Bonus::ativar_bonus(Robos* r, Bonus* b) //Ativa aleatoriamente um dos 3 b�nus dispon�veis e usa o m�todo efeito_bonus() para aplicar os efeitos
{
	n = rand() % 2 + 1;

	switch (n)
	{
	case 1:
		efeito_bonus(r, b, get_bonus1());
		break;
	case 2:
		efeito_bonus(r, b, get_bonus2());
		break;
	case 3:
		efeito_bonus(r, b, get_bonus3());
		break;
	default:
		break;
	}
}

const char* Bonus::get_bonus1()
{
	return this->bonus1;
}

const char* Bonus::get_bonus2()
{
	return this->bonus2;
}

const char* Bonus::get_bonus3()
{
	return this->bonus3;
}
