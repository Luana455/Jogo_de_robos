#include "Jogo.h"



Jogo::Jogo()
{
}


Jogo::~Jogo()
{
}

void Jogo::inicializar()
{ //cria dois robos com aloca��o dinamica e inicializa o combate

	r[0] = new Robos();
	r[1] = new Robos();

	r[0]->criar_robo();
	r[1]->criar_robo();

	b[0] = new Bonus();
	b[1] = new Bonus();
	

	b[0]->criar_bonus();
	b[1]->criar_bonus();
	

	combate(r[0], r[1], b[0], b[1]);

	carregar_jogo();
}

void Jogo::combate(Robos *r1, Robos *r2, Bonus *b1, Bonus *b2)
{
	
	//Mostra os atributos iniciais dos robos 
	cout << "********************************************" << endl;
	cout << "          Robo 01                           " << endl;
	cout << " Vida: "<<r1->get_vida() << endl;
	cout << " Poder de ataque: "<< r1->get_PA() << endl;
	cout << " Defesa: " << r1->get_defesa() <<  endl;
	cout << " Capacidade de dano: " << r1->get_DAM() <<  endl;
	cout << " Vitorias: " << r1->get_vitorias() << endl;
	cout << " Bonus 1: " << b1->get_bonus1() << endl;
	cout << " Bonus 2: " << b1->get_bonus2() << endl;
	cout << " Bonus 3: " << b1->get_bonus3() << endl;

	cout << "********************************************" << endl;

	cout << "********************************************" << endl;
	cout << "          Robo 02                           " << endl;
	cout << " Vida: "<<r1->get_vida()<< endl;
	cout << " Poder de ataque: " << r2->get_PA() << endl;
	cout << " Defesa: " << r2->get_defesa() << endl;
	cout << " Capacidade de dano: " << r2->get_DAM() << endl;
	cout << " Vitorias: " << r2->get_vitorias() << endl;
	cout << " Bonus 1: " << b2->get_bonus1() << endl;
	cout << " Bonus 2: " << b2->get_bonus2() << endl;
	cout << " Bonus 3: " << b2->get_bonus3() << endl;

	cout << "********************************************" << endl;

	cout << "********************************************" << endl;
	cout << "*              1 - Jogar                   *" << endl;
	cout << "*              2 - Sair                    *" << endl;
	cout << "********************************************" << endl;
	cin >> opcao;

	if (opcao == 2)
	{
		salvar_jogo();
		exit(0);
	}
	

	if(opcao==1)//inicia o combate
	{ system("CLS");
		set_turno(0);
		

	while (r1->get_vida() > 0 && r2->get_vida() > 0)
	{
		srand(time(0));


		cout << " Vitorias do Robo 01: " << r1->get_vitorias() << endl;
		cout << " Vitorias do Robo 02: " << r2->get_vitorias() << endl;
		cout << "********************************************" << endl;

		//armazena em variaveis os rands de cada atributo, mudando em cada turno
		    PA1 = rand() % r1->get_PA() + 1;	

			DEF2 = rand() % r2->get_defesa() + 1;

			PA2 = rand() % r2->get_PA() + 1;

			DEF1 = rand() % r1->get_defesa() + 1;
			
			DAM1 = rand() % r1->get_DAM() + 1;

			DAM2 = rand() % r2->get_DAM() + 1;

		if (turno % 2 == 0) // inicia com o turno do robo 1
		{
			if (PA1 > DEF2)
			{//robo 1 ataca robo 2
				n1 = r2->get_vida() - DAM1;
				r2->set_vida(n1);
				cout << " Poder de ataque do Robo 01:  " << PA1 << endl;
				cout << " Defesa do Robo 02:  " << DEF2 << endl;
				cout << "********************************************" << endl;
				cout << endl;
				cout << " Robo 01 atacou com dano de " << DAM1 << endl;
				if (n1 >= 0)
					cout << " Robo 02 perdeu vida! Vida: " << n1 << endl;
				else if (n1 < 0)
					cout << " Robo 02 perdeu vida!Vida: 0" << endl;

				cout << "********************************************" << endl;
				cout << "*              1 - Continuar               *" << endl;
				cout << "*              2 - Sair                    *" << endl;
				cout << "********************************************" << endl;
				cin >> opcao;
				system("CLS");
				if (opcao == 1)
					turno++;
				if (opcao == 2)
				{
					salvar_jogo();
					exit(0);
				}
			}	
			else
			{//caso o robo defenda
				cout << " Poder de ataque do Robo 01:  " << PA1 << endl;
				cout << " Defesa do Robo 02:  " << DEF2 << endl;
				cout << "********************************************" << endl;
				cout << endl;
				cout << " Robo 02 defendeu o ataque!" << endl;
				cout << "********************************************" << endl;
				cout << "*              1 - Continuar               *" << endl;
				cout << "*              2 - Sair                    *" << endl;
				cout << "********************************************" << endl;
				cin >> opcao;
				system("CLS");
				if (opcao == 1)
					turno++;
				if (opcao == 2)
				{
					salvar_jogo();
					exit(0);
				}
				
			}

			if (r1->get_vida() > 0 && r2->get_vida() <= 0) // salva as vitorias do robo 1
			{	
				vitoria_robo1++;
				r2 = new Robos();
				r2->criar_robo();
				r2->set_vitorias(0);
				r1->set_vitorias(vitoria_robo1);
				if (r1->get_vitorias() == 2)
				{
					cout << " Novo bonus!" << endl;
					b1->ativar_bonus(r[0], b[0]);
					r1->set_vitorias(0);
				}
				cout << endl;
				cout << " Robo 01 venceu!" << endl;
				cout << endl;
				cout << "********************************************" << endl;
				cout << "*              1 - Continuar               *" << endl;
				cout << "*              2 - Sair                    *" << endl;
				cout << "********************************************" << endl;
				cin >> opcao;
				system("CLS");
				if (opcao == 1)
					turno++;
				if (opcao == 2)
				{
					salvar_jogo();
					exit(0);
				}
				
			}

		}
		if (turno % 2 != 0) // turno do robo 2 
		{
			if (PA2 > DEF1)
			{//robo 2 ataca robo 1
				n2 = r1->get_vida() - DAM2;
				r1->set_vida(n2);
				cout << " Poder de ataque do Robo 02:  " << PA2 << endl;
				cout << " Defesa do Robo 01:  " << DEF1 << endl;
				cout << "********************************************" << endl;
				cout << endl;
				cout << " Robo 02 atacou com dano de " << DAM2 << endl;
				if (n2 >= 0)
					cout << " Robo 01 perdeu vida! Vida: " << n2 << endl;
				else if (n2 < 0)
					cout << " Robo 01 perdeu vida! Vida: 0" << endl;

				cout << "********************************************" << endl;
				cout << "*              1 - Continuar               *" << endl;
				cout << "*              2 - Sair                    *" << endl;
				cout << "********************************************" << endl;
				cin >> opcao;
				system("CLS");

				if (opcao == 1)
					turno++;
				if (opcao == 2)
				{
					salvar_jogo();
					exit(0);
				}
			}
			else
			{//caso o robo defenda
				cout << " Poder de ataque Robo 02:  " << PA2 << endl;
				cout << " Defesa do Robo 01:  " << DEF1 << endl;
				cout << "********************************************" << endl;
				cout << endl;
				cout << " Robo 01 defendeu o ataque!" << endl;
				cout << "********************************************" << endl;
				cout << "*              1 - Continuar               *" << endl;
				cout << "*              2 - Sair                    *" << endl;
				cout << "********************************************" << endl;
				cin >> opcao;
				system("CLS");
				if (opcao == 1)
					turno++;
				if (opcao == 2)
				{
					salvar_jogo();
					exit(0);
				}
				
			}
			if (r2->get_vida() > 0 && r1->get_vida() <= 0) // salva as vitoriais do robo 2 
			{
				
				vitoria_robo2++;
				delete(r[0]);
				r1 = new Robos();
				r1->criar_robo();
				r1->set_vitorias(0);
				r2->set_vitorias(vitoria_robo2);

				if (r2->get_vitorias() == 2)
				{
					cout << " Novo bonus!" << endl;
					b2->ativar_bonus(r[1], b[1]);
					r2->set_vitorias(0);
				}
				cout << endl;
				cout << " Robo 02 venceu!"<< endl;
				cout << endl;
				cout << "********************************************" << endl;
				cout << "*              1 - Continuar               *" << endl;
				cout << "*              2 - Sair                    *" << endl;
				cout << "********************************************" << endl;
				cin >> opcao;
				system("CLS");
				if (opcao == 1)
					turno++;
				if (opcao == 2)
				{
					salvar_jogo();
					exit(0);
				}
			}
		}
	}
	}

}

void Jogo::set_turno(int turno)
{
	this->turno = turno;
}

void Jogo::salvar_jogo()
{
	ofstream save("save.bin", iostream::out | iostream::trunc | ios::binary);
	int salvar_atributos;

	for (int i = 0; i < 2; i++) //robos
	{
		salvar_atributos = r[i]->get_DAM(); r[i]->get_defesa(); r[i]->get_vida(); r[i]->get_PA(); r[i]->get_vitorias(); save.write(reinterpret_cast <const char*> (&salvar_atributos), sizeof(int));

		for (int n = 0; n < 2; n++) //bonus
		{
			b[n]->criar_bonus(); save.write(reinterpret_cast <const char*> (&b[n]), sizeof(int));
			b[n]->criar_bonus(); save.write(reinterpret_cast <const char*> (&b[n]), sizeof(int));
		}
	}
	
	salvar_atributos = get_turno(); save.write(reinterpret_cast <const char*> (&salvar_atributos), sizeof(int)); //turnos
	
	save.close();
}

void Jogo::carregar_jogo()
{
	ifstream load("save.bin", ios::binary);

	int salvar_atributos;

	for (int i = 0; i < 2; i++)//carregar atributos dos robos
	{
		load.read(reinterpret_cast <char*> (&salvar_atributos), sizeof(int)); r[i]->set_DAM(salvar_atributos); r[i]->set_PA(salvar_atributos); r[i]->set_defesa(salvar_atributos); r[i]->set_vida(salvar_atributos);
		r[i]->set_vitorias(salvar_atributos);

		for (int n = 0; n < 2; n++)//caregar bonus
		{
			load.read(reinterpret_cast <char*> (&b[n]), sizeof(int)); b[n]->criar_bonus();
		}
	}
	load.read(reinterpret_cast <char*> (&salvar_atributos), sizeof(int));set_turno(salvar_atributos);

	load.close();
}

int Jogo::get_turno()
{
	return this->turno;
}
