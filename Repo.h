#pragma once
#include "Cost.h"

class Repo
{
public:
	int n = 0;
	Cost costs[100];
	void addElem(Cost c);
	Cost* getAll();
	int getLen();
};
