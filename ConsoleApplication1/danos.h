#pragma once
#include "SimpleEngine.h"
class danos
{
	public:
		danos();

		~danos();
		void counterpassedlimit();
		const int get_dano(int n)
		{
			return dano[n];
		}
		const int get_apcost(int n)
		{
			return apcost[n];
		}
		void usedattack(int op);


	private:
		int dano[4];
		int usecounter[4];
		int apcost[4];
		void recalc(int dano[] , int apcost[]);
		
		
};

