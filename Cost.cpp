#include "Cost.h"
#include <string>
#include <iostream>
#include <tchar.h>

using namespace std;

Cost::Cost()
//Descr: creeaza un cost
//In: -
//Out: o instanta a Cost
{
	cout << "Default constructor cost" << endl;
	this->nr_apart = 0;
	this->tip_cost = NULL;
	this->pret = 0;
}

Cost::Cost(int nr, const char* n, int p)
//Descr: creaaza un cost
//In: numarul apartamentului, tipul si pretul sau
//Out: o instanta (cu informatii) a lui Cost
{
	cout << "Constructor cu parametri" << endl;
	this->nr_apart = nr;
	this->tip_cost = new char[strlen(n) + 1];
	strcpy_s(this->tip_cost, strlen(n) + 1, n);
	this->pret = p;
}

Cost::Cost(const Cost& c)
//Descr: creaaza un cost folosind informatia de la alt cost
//In: un cost c
//Out: o instanta a lui Cost cu informatii de la c
{
	cout << "Copiaza constructor" << endl;
	this->nr_apart = c.nr_apart;
	this->tip_cost = new char[strlen(c.tip_cost) + 1];
	strcpy_s(this->tip_cost, strlen(c.tip_cost) + 1, c.tip_cost);
	this->pret = c.pret;
}

Cost::~Cost()
//Descr: sterge un cost 
//In: un cost
//Out: -
{
	if (this->tip_cost != NULL)
	{
		delete[] this->tip_cost;
		this->tip_cost = NULL;
	}
}

int Cost::getNrApart()
//Descr: returneaza numarul apartamentului unui cost
//In: un cost
//Out: numarul apartamentului
{
	return this->nr_apart;
}

void Cost::setNrApart(int nr)
//Descr: modifica numarul apartamentului unui cost
//In: un cost cu numarul apartamentului, tipul si pretul sau
//Out: costul cu noul numar apart.
{
	this->nr_apart = nr;
}

char* const Cost::getTipCost()
//Descr: returneaza tipul unui cost
//In: un cost
//Out: tipul sau
{
	return this->tip_cost;
}

void Cost::setTipCost(char* name)
//Descr: schimba tipul unui cost
//In: un cost cu numarul apartamentului, tipul si pretul sau
//Out: costul cu noul tip
{
	if (tip_cost)
		delete[] this->tip_cost;

	this->tip_cost = new char[strlen(name) + 1];
	strcpy_s(this->tip_cost, strlen(name) + 1, name);
}

int Cost::getPret()
//Descr: returneaza pretul unui cost
//In: un cost
//Out: pretul costului
{
	return this->pret;
}

void Cost::setPret(int p)
//Descr: modifica pretul unui cost
//In: un cost cu numarul apartamentului, tipul costului si pretul
//Out: costul cu noul pret
{
	this->pret = p;
}

/*char* Cost::toString()
//Descr: transforma un cost intr-un string
//In: un cost
//Out: un string cu informatii despre cost
{
	if (this->tip_cost)
	{
		int noChars = 5 + 1 + strlen(this->tip_cost) + 1 + 5;
		char* s = new char[noChars];
		char* aux1 = new char[5];
		char* aux2 = new char[5];

		_itoa_s(this->nr_apart, aux1, 5, 10);
		strcat_s(s, noChars, aux1);
		strcat_s(s, noChars, " ; ");
		strcpy_s(s, noChars, this->tip_cost);
		strcat_s(s, noChars, " ; ");
		_itoa_s(this->pret, aux2, 5, 10);
		strcat_s(s, noChars, aux2);

		if (aux1)
		{
			delete[] aux1;
			aux1 = NULL;
		}

		if (aux2)
		{
			delete[] aux2;
			aux2 = NULL;
		}

		strcat_s(s, noChars, ";");
		return s;
	}
	else
		return 0;
}*/

bool Cost::compare(Cost& c)
//Descr: compara doua costuri
//In: doua costuri (the current one = this, another one = c)
//Out: true/false
{
	return ((this->nr_apart, c.nr_apart) && (strcmp(this->tip_cost, c.tip_cost) == 0) && (this->pret == c.pret));
}

Cost& Cost::operator=(const Cost& c)
//Descr: creaaza un nou Cost (egal cu un Cost c dat)
//In: un cost (c)
//Out: un nou cost (egal cu c)
{
	cout << "Cost : operator= ... " << endl;
	if (this != &c) {
		this->setTipCost(c.tip_cost);
		this->setPret(c.pret);
	}
	else
		cout << "self assignment ... " << endl;
	return *this;
}


