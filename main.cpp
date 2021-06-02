#include "Ispit.h"
#include <iostream>
#include "Windows.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
	int izbor;
	Ispit is;
	int x;

	do {
		system("cls");
		cout << "********************************************************************************\n";
		cout << "\t\t\t<1. Unesi studenta>\n";
		cout << "\t\t\t<2. Ispis ispita>\n";
		cout << "\t\t\t<3. Ispis polozenih>\n";
		cout << "\t\t\t<4. Ispis nepolozenih>\n";
		cout << "\t\t\t<5. Prolaznost>\n";
		cout << "\t\t\t<6. Pretraga>\n";
		cout << "\t\t\t<7. Student s najmanjim brojem bodova>\n";
		cout << "\t\t\t<8. Student s najvecim brojem bodova>\n";
		cout << "\t\t\t<9. Izbrisi studenta>\n";
		cout << "\t\t\t<10. Sortirani studenti po broju osvojenih bodova>\n";
		cout << "\t\t\t<11. Ispis studenata po godini studija>\n";
		cout << "\t\t\t<12. Kraj>\n";
		cout << "\n********************************************************************************\n";

		cout << endl;

		do {
			cout << "\tIzbor: ";
			cin >> izbor;
			if (izbor < 1 || izbor>12)
			{
				cout << "\t[GRESKA] - Pogresan unos!\n\n";
			}
		} while (izbor < 1 || izbor>12);
		cin.ignore();

		if (izbor == 1)
		{
			system("cls");
			cout << "--------------------------------------------------------------------------------\n";
			is.setStudenti();
			cout << endl;
			cout << "--------------------------------------------------------------------------------\n";
			Sleep(200);
			cout << "[Student mora poloziti obje parcijale da bi polozio predmet!]\n";
			Sleep(550);
			cout << "[Student mora osvojiti minimum 55% od ukupnih bodova da bi polozio predmet!]\n\n";
			Sleep(550);
			is.setPredmeti();
			cout << "\n--------------------------------------------------------------------------------\n";
			cout << "\n[Unos zavrsen!]\n";
			system("pause>0");
		}

		else if (izbor == 2)
		{
			system("cls");
			is.ispisIspita();
			system("pause>0");
		}

		else if (izbor == 3)
		{
			system("cls");
			is.PoloziliSu();
			system("pause>0");
		}

		else if (izbor == 4)
		{
			system("cls");
			is.NisuPolozili();
			system("pause>0");
		}

		else if (izbor == 5)
		{
			system("cls");
			is.Prolaznost();
			system("pause>0");
		}

		else if (izbor == 6) {
			int izbor2;
			do {
				system("cls");
				cout << "*********************************************\n";
				cout << "\tPretraga studenata i predmeta: \n";
				cout << endl;
				cout << "\t1. Pretraga po imenu\n";
				cout << "\t2. Pretraga po prezimenu\n";
				cout << "\t3. Pretraga po nazivu predmeta\n";
				cout << "\t4. Vrati se\n";
				cout << "*********************************************\n";
				cout << endl;
				cout << "\tIzbor: ";
				cin >> izbor2;
				cin.ignore();
				if (izbor2 == 1) {
					is.pretragaPoImenu();
					cout << "\nPretraga zavrsena!\n";
					system("pause>0");
					system("cls");
				}
				else if (izbor2 == 2) {
					is.pretragaPoPrezimenu();
					cout << "\nPretraga zavrsena!\n";
					system("pause>0");
					system("cls");
				}
				else if (izbor2 == 3) {
					is.pretragaPoNazivuPredmeta();
					cout << "\nPretraga zavrsena!\n";
					system("pause>0");
					system("cls");
				}
			} while (izbor2 != 4);
		}

		else if (izbor == 7)
		{
			system("cls");
			is.ispisiMinS();
			system("pause>0");
		}

		else if (izbor == 8)
		{
			system("cls");
			is.ispisiMaxS();
			system("pause>0");
		}

		else if (izbor == 9)
		{
			system("cls");
			is.ispisIspita();

			if (is.getPredmeti().size() == 0 || is.getStudenti().size() == 0)
			{
				cout << "\n\t\t\t************************\n";
				cout << "\t\t\t" << "<Nema se sta izbrisati!>\n";
				cout << "\t\t\t************************\n";
			}

			else {
				do {
					try {
						cout << "\nUnesite redni broj studenta kojeg zelite obrisati: ";
						cin >> x;
						if (x < 1) throw "Pozicija za brisanje studenta ne moze biti manja od 1!\n";
						if (x > is.getStudenti().size()) throw x;
					}
					catch (const char* poruka)
					{
						cout << poruka << endl;
					}
					catch (int x)
					{
						cout << "Unijeta pozicija " << x << " je veca od broja studenata u bazi!\n";
					}

				} while (x<1 || x>is.getStudenti().size());
				cin.ignore();
				is^x;
			}
			system("pause>0");
		}

		else if (izbor == 10)
		{
			system("cls");
			is.ispisi_sortirano();
			system("pause>0");
		}

		else if (izbor == 11)
		{
			system("cls");
			is.pretragaPoGodini();
			system("pause>0");
		}

	} while (izbor != 12);

	return 0;
}
