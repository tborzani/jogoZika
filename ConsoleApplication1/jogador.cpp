#include "stdafx.h"
#include "jogador.h"
#include "SimpleEngine.h"


jogador::jogador() 
{
	hpmax = SimpleEngine::hpmaxinicial();
	apmax = SimpleEngine::apmaxinicial();
	hpatual = hpmax;
	apatual = apmax;
	xpatual = 0;
}


jogador::~jogador()
{

}

void jogador::looselife(int x)
{
	hpatual = hpatual - x;
}
void jogador::looseap(int x)
{
	apatual = apatual - x;
}
void jogador::restorelife()
{
	hpatual = hpmax;
}
void jogador::restoreap()
{
	apatual = apmax;
}
void jogador::dano(int op, danos &danojogador, jogador &inimigo)
{
	if (danojogador.get_apcost(op) <= this->apatual)
	{
		inimigo.looselife(danojogador.get_dano(op));
		looseap(danojogador.get_apcost(op));
		danojogador.usedattack(op);
		danojogador.counterpassedlimit();
		if (inimigo.get_hp() <= 0)
		{
			int blabla;
			inimigo.~jogador();
			cout << "voce matou o cara" << "pressione algo para continuar" ;
			cin >> blabla ;
			gainxp(xprewarded);
		}
	}
	else
	{
		cout << "nao ha ap suficiente para realizar esta accao";
		
	}
}

void jogador::addlvl(int op)
{
	switch(op)
	{
	case 0:
	
		hpmax = hpmax + SimpleEngine::nextlvlpointrewarded(lvlpointrewarded, n1);
		break;
	
	case 1:
	
		apmax = apmax + SimpleEngine::nextlvlpointrewarded(lvlpointrewarded, n1);
		break;
	
	}
	restoreap();
	restorelife();
}

const int jogador::get_hp()
{
	return this->hpatual;
}

void jogador::gainxp(int xp)
{
	this->xpatual = xpatual + xp;
	if (xpatual >= xpneeded)
	{
		cout << "LVL UP!";
		cout << "/n";
		system("cls");
		cout << "digite 1 para aumentar seu apmax e 0 para aumentar seu hpmax";
		int op = 0;
		cin >> op;
		addlvl(op);
		xpneeded = SimpleEngine::nextxpneeded(xpneeded, n3);
		xprewarded = SimpleEngine::nextxprewarded(xprewarded, n2);
	}
}

const int jogador::get_ap()
{
	return this->apatual;
}

const int jogador::get_xp()
{
	return this->xpatual;
}
