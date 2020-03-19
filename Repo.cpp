#include "Repo.h"
#include "Cost.h"
#include <string>
#include <iostream>


using namespace std;


int Repo::getLen()   //returns the number of instances of Cost that have been added in repo
{
	return n;
}

void Repo::addElem(Cost c) //adds an instance of Cost in repo
{
	costs[n] = c;
	n++;
}

Cost* Repo::getAll() //points towards the adress of where the repo array starts
{
	return costs;
}
