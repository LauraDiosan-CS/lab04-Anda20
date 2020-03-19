// Apartamente1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Cost.h"
#include "Repo.h"
#include "testCost.h"
#include<string>
#include<iostream>
using namespace std;

int main()
{
	tests();
	testRepo();
	Repo r;
	Cost c1 = Cost(25, "gaz", 100);
	r.addElem(c1);
	return 0;
}

