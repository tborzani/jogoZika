#pragma once
#include "stdafx.h"
#include "SimpleEngine.h"
#include <cstdlib>
#include <iostream>
#include <cmath>







int SimpleEngine::nextxpneeded(int xpneeded, int &n3)
{
	n3++;

	return pow(xpneeded, 2)/n3;
}

int SimpleEngine::nextlvlpointrewarded(int lvlpointrewarded, int &n1)
{

	n1++;

	return pow(lvlpointrewarded,2)/(2*n1);

}
int SimpleEngine::nextxprewarded(int xprewarded, int &n2)
{
	n2++;
	return pow(xprewarded, 2)/(1.8*n2);
}

int SimpleEngine::hpmaxinicial()
{
	return 10;
}

int SimpleEngine::apmaxinicial()
{
	return 8;
}

int SimpleEngine::limit()
{
	return 5;
}