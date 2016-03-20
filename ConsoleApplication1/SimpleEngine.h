#pragma once
#include <cstdlib>
#include <iostream>

using namespace std;


class SimpleEngine
{
public:
	static int nextxpneeded(int xpneeded, int &n3);
	static int nextlvlpointrewarded(int lvlpointrewarded, int &n1);
	static int nextxprewarded(int xprewarded, int &n2);
	static int hpmaxinicial();
	static int apmaxinicial();
	static int limit();

};