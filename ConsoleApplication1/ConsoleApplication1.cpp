// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include "SimpleEngine.h"
#include <iostream>
#include <cstdlib>
#include "stdafx.h"
#include "jogador.h"
#include "danos.h"
#include "math.h"


using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	jogador p1;
	danos danop1;
	danos danoinimigo1;
	jogador inimigo1;
	int op = 0;
	while (p1.get_hp() > 0)
	{
		while (op != 10 && p1.get_ap() > 0 && inimigo1.get_hp()>= 0)
		{
			system("cls");
			cout << "escolha a opção" << "\n";
			cout << "0 = soco leve |" << "apcost:" << danop1.get_apcost(0) << "| Dano:" << danop1.get_dano(0) << "\n";
			cout << "1 = soco forte |" << "apcost:" << danop1.get_apcost(1) << "| Dano:" << danop1.get_dano(1) << "\n";
			cout << "2 = chute leve |" << "apcost:" << danop1.get_apcost(2) << "| Dano:" << danop1.get_dano(2) << "\n";
			cout << "3 = chute forte |" << "apcost:" << danop1.get_apcost(3) << "| Dano:" << danop1.get_dano(3) << "\n";
			cout << "AP :" << p1.get_ap() << "/"<< p1.apmax << "\n";
			cout << "HP :" << p1.get_hp() << "/"<< p1.hpmax << "\n";
			cout << "XP :" << p1.get_xp() << "\n";
			
			cout << "hp inimigo:" << inimigo1.get_hp() << "\n";
			cin >> op;
			p1.dano(op, danop1, inimigo1);
		}
		inimigo1.dano(rand() % 4, danoinimigo1, p1);
		p1.restoreap();
		if (inimigo1.get_hp() <= 0)
		{
			inimigo1.restorelife();
			inimigo1.restoreap();
		}
	}
	cout << "voce morreu seu burro";
	system("pause");

	return 0;
}

