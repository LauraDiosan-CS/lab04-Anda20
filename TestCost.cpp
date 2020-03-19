#include "testCost.h"
#include "Cost.h"
#include "Repo.h"
#include <assert.h>
#include <iostream>
using namespace std;

void tests()
{
	Cost c1 = Cost(); //empty cost
	assert(c1.getNrApart() == 0);
	assert(c1.getTipCost() == NULL);
	assert(c1.getPret() == 0);

	Cost c2 = Cost(25, "gaz", 100); //a cost with info
	assert(c2.getNrApart() == 25);
	assert(strcmp(c2.getTipCost(), "gaz") == 0);
	assert(c2.getPret() == 100);
	//assert(strcmp(c2.toString(), "25;gaz;100") == 0);

	Cost c3 = Cost(c2); //a copy of c2
	assert(c3.getNrApart() == 25);
	assert(strcmp(c3.getTipCost(), "gaz") == 0);
	assert(c3.getPret() == 100);
	//assert(strcmp(c3.toString(), "25;gaz;100") == 0);

	assert(c2.compare(c3) == true);

	cout << "Testele au trecut. Yaaaay!" << endl;
}

void testRepo()
{
	Repo r;
	Cost c1 = Cost(25, "gaz", 100);
	Cost c2 = Cost(10, "curent", 50);
	r.addElem(c1);
	r.addElem(c2);

	assert(r.getLen() == 2);

	cout << "Testele Repo au trecut. Yaaaay!" << endl;
}



