#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <iostream>
#include <vector>
#include "Apartament.h"

using namespace std;

class ApartamentRepository
{
private:
	vector<Apartament>apartamente;

public:
	void addElem(Apartament a);
	vector<Apartament>getAll();
	vector<Apartament>apartamenteSelectate(int limita);
	void eliminareNrApartament(int nrApartament);
	void eliminareIntervalApartamente(int left, int right);
	void eliminareTip(char* tip);
};
#endif // !REPOSITORY_H
