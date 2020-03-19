#pragma once

#include <iostream>
using namespace std;

class Cost
{
private:
	int nr_apart;
	char* tip_cost;
	int pret;
public:
	Cost();
	Cost(int nr, const char* n, int p);
	Cost(const Cost& c);
	~Cost();

	int getNrApart();
	void setNrApart(int nr);

	char* const getTipCost();
	void setTipCost(char* name);

	int getPret();
	void setPret(int p);

	char* toString();

	bool compare(Cost& c);

	Cost& operator=(const Cost& c);
};