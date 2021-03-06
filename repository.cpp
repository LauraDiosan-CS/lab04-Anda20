#include "repository.h"
#include <string.h>

void ApartamentRepository::addElem(Apartament a)
{
	apartamente.push_back(a);
}

vector<Apartament>ApartamentRepository::getAll()
{
	return apartamente;
}
vector <Apartament>ApartamentRepository::apartamenteSelectate(int limita)
{
	vector<Apartament>apartamenteSelectate;
	for (Apartament a : apartamente)
	{
		if (a.getNumar_ap() > limita&& a.getSuma() > limita)
		{
			apartamenteSelectate.push_back(a);
		}
	}
	return apartamenteSelectate;
}

void ApartamentRepository::eliminareNrApartament(int nrApartament)
{
	// Parcurgem toate apartamentele
	for (int i = 0; i < apartamente.size(); i++)
	{
		// Aflam apartamentul curent (aflat la pozitia i)
		Apartament ap = apartamente.at(i);

		if (ap.getNumar_ap() == nrApartament)
		{
			apartamente.erase(apartamente.begin() + i); // stergem al i-lea apartament
			i--;
		}
	}
}

void ApartamentRepository::eliminareIntervalApartamente(int left, int right)
{
	// Parcurgem toate apartamentele
	for (int i = 0; i < apartamente.size(); i++)
	{
		// Aflam apartamentul curent (aflat la pozitia i)
		Apartament ap = apartamente.at(i);

		// Parcurgem toate numerele de apartamente care trebuie sa fie sterse
		for (int j = left; j <= right; j++)
		{
			// Daca apartamentul curent are numarul de apart. care trebuie sters 
			if (ap.getNumar_ap() == j)
			{
				apartamente.erase(apartamente.begin() + i);
				i--;
				break;
			}
		}
	}
}

void ApartamentRepository::eliminareTip(char* tip)
{

	// Parcurgem toate apartamentele
	for (int i = 0; i < apartamente.size(); i++)
	{
		// Aflam apartamentul curent (aflat la pozitia i)
		Apartament ap = apartamente.at(i);

		if (strcmp(ap.getTip(), tip) == 0)
		{
			apartamente.erase(apartamente.begin() + i);
			i--;
		}
	}
}

