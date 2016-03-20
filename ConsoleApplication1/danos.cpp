#include "stdafx.h"
#include "danos.h"
#include "SimpleEngine.h"


danos::danos()
{
	dano[0] = 1;
	dano[1] = 2;
	dano[2] = 3;
	dano[3] = 4;
	usecounter[0] = 0;
	usecounter[1] = 0;
	usecounter[2] = 0;
	usecounter[3] = 0;
	apcost[0] = 1;
	apcost[1] = 2;
	apcost[2] = 3;
	apcost[3] = 4;

}


danos::~danos()
{
}

void danos::recalc(int dano[], int apcost[])
{
	int x = 10;
	for (int i = 0; i < 4; i++)
	{
		int temp = rand() % 4;
		if ((x - temp) >= 0)
		{
			dano[i] = temp;
			x = x - temp;
			if (x > 0 && temp == 0)
			{
				while (temp == 0)
				{
					temp = rand() % 4;
				}
				dano[i] = temp;
				x = x - temp;
			}
		}
		else
			if (x == 0)
			{
				dano[i] = 0;
			}



	}
	for (int i = 0; i < 4; i++)
	{
		int temp = rand() % 4;
		if (x - temp >= 0)
		{
			apcost[i] = temp;
			x = x - temp;
			if (x > 0 && temp == 0)
			{
				while (temp == 0)
				{
					temp = rand() % 4;
				}
				apcost[i] = temp;
				x = x - temp;

			}
		}
		else
			if (x == 0)
			{
				apcost[i] = 0;
			}



	}

}

void danos::counterpassedlimit()
{
	int whatev;



	for (int i = 0; i < 4; i++)
	{
		if (usecounter[i] >= SimpleEngine::limit())
		{
			for (int i = 0; i < 4; i++)
			{
				usecounter[i] = 0;
			}
			cout << "OS ATAQUES RANDOMIZARAM";
			cin >> whatev;
			danos::recalc(this->dano, this->apcost);
		}
	}
}

void danos::usedattack(int op)
{
	usecounter[op] ++;
}