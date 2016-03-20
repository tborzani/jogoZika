#pragma once


#include "danos.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class jogador
{
public:


	int hpmax;
	int apmax;

	jogador();

	~jogador();
	void dano(int op, danos &danojogador, jogador &inimigo);
	void looselife(int x);
	void looseap(int x);
	void restorelife();
	void restoreap();
	void addlvl(int op);
	const int get_hp();
	const int get_ap();
	const int get_xp();
	void gainxp(int xp);


private:
	int previousxprewarded = 2;
	int previousxpneeded = 2;
	int xprewarded = 4;
	int xpneeded = 4;
	int lvlpointrewarded = 2;
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	int hpatual;
	int apatual;
	int lvl;
	int xpatual;
	danos danojogador;
	





};

