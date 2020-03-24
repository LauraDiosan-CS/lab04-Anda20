#include "Services.h"
#include "repository.h"
#include <cstring>
using namespace std;

void meniu()
{
	char* tip = new char[100];
	int nrApartament;
	int suma, left, right, sumaNoua;
	vector<Apartament> apartamente;
	vector<Apartament> selectati;

	int limita;

	Apartament a1 = Apartament();
	int optiune;

	do
	{
		cout << "1) Adaugare in vector\n";
		cout << "2) Afisare vector\n";
		cout << "3) Exit\n";
		cout << "4) Afisare in functie de limita - nr apartament si suma\n";
		cout << "5) Afisare lungime vector\n";
		cout << "6) Afisare informatii apartamente\n";
		cout << "7) Eliminare dupa nr apartament\n";
		cout << "8) Eliminare dupa un interval de apartamente\n";
		cout << "9) Eliminare dupa tip\n";
		
		cin >> optiune;

		switch (optiune)
		{
		case 1:
			cout << "Introduceti tipul ";
			cin >> tip;

			cout << "Introduceti numarul apartamentului ";
			cin >> nrApartament;

			cout << "Introduceti suma ";
			cin >> suma;

			a1 = Apartament(nrApartament, tip, suma);
			addElem(a1);

			break;

		case 2:
			apartamente = getAll();

			for (Apartament a1 : apartamente)
			{
				cout << a1.getNumar_ap() << " " << " " << a1.getTip() << " " << a1.getSuma() << endl;

			}

			cout << '\n';

			break;

		case 4:
			cout << "Introduceti limita ";
			cin >> limita;

			selectati = apartamenteSelectate(limita);

			for (Apartament a : selectati)
			{
				cout << "Numarul apartamentului: " << a.getNumar_ap() << ", suma: " << a.getSuma() << '\n';
			}

			cout << '\n';

			break;

		case 5:
			apartamente = getAll();
			cout << "Lungimea vectorului: " << apartamente.size() << '\n';
			break;

		case 6:
			apartamente = getAll();
			for (Apartament a : apartamente)
			{
				cout << "Numarul apartamentului: " << a.getNumar_ap() << endl;
				cout << "Tipul apartamentului: " << a.getTip() << endl;
				cout << "Suma pentru apartament: " << a.getSuma() << endl;

				cout << endl;
			}

			break;

		case 7:
			apartamente = getAll();
			cout << "Dati numarul apartamentului de sters: ";
			cin >> nrApartament;

			eliminareNrApartament(nrApartament);
			break;

		case 8:
			apartamente = getAll();

			cout << "Dati capatul stang al intervalului: ";
			cin >> left;

			cout << "Dati capatul drept al intervalului: ";
			cin >> right;

			eliminareIntervalApartamente(left, right);

			break;

		case 9:
			apartamente = getAll();

			cout << "Dati tipul de eliminat ";
			cin >> tip;

			eliminareTip(tip);
			break;
					   
		case 3:
			cout << "Bye bye...\n";
			break;
		}

		cout << endl;

	} while (optiune != 3);
}

int main()
{

	meniu();

	system("pause");
	return 0;
}