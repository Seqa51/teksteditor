

#include <iostream>
#include<string>

using namespace std;

void unos(string &tekst) {
	cout << "Unesite tekst: " << endl;
	getline(cin, tekst);
}


void duljina(string &tekst) {
	cout << "Duljina teksta je: " << tekst.length() << endl;
}

void velikamala(string &tekst) {
	int i;
	int j;
	cout << "Zelite li pretvoriti slova u velika ili mala slova?\n 1.) Velika\n2.) Mala\n0.) Vrati me nazad!" << endl;
	cin >> j;
	cin.ignore();
		switch (j) {
		case 1:
			for (i = 0; i < tekst.length(); i++) {
				tekst[i] = toupper(tekst[i]);
			}
			cout << "Tekst sada izgleda ovako: " << tekst << endl;
			break;
		case 2:
			for (i = 0; i < tekst.length(); i++) {
				tekst[i] = tolower(tekst[i]);
			}
			cout << "Tekst sada izgleda ovako: " << tekst << endl;
			break;
		default:
			cout << "Unesli ste nepoznatu radnju!" << endl;
		break;
		}

}

void spajanje(string& tekst) {
	cout << "Odabreite izbor: " << endl;
	cout << "1.) Na pocetku teksta. \n2.) Na kraj teksta.\n0.) Vrati me nazad!" << endl;
	int j;
	string tekst2;
	cin >> j;
	cin.ignore();
	switch (j) {
	case 1:
		cout << "Unesite tekst koji zelite dodati: " << endl;
		getline(cin, tekst2);
		tekst = tekst2 + tekst;
		cout << "Vas tekst sada ovako izgleda: " << tekst << endl;
		break;
	case 2:
		cout << "Unesite tekst koji zelite dodati: " << endl;
		getline(cin, tekst2);
		tekst = tekst + tekst2;
		cout << "Vas tekst sada ovako izgleda: " << tekst << endl;
		break;
	default:
		break;
	}
}

void fqr(string &tekst) {
	string tekst1;
	string tekst2;
	int pozicija;

	cout << "Rijec koju zelis zamijenit: ";
	getline(cin, tekst1);
	cout << "Rijec s kojom je zelis zamijneit: ";
	getline(cin, tekst2);

	pozicija = tekst.rfind(tekst1);
	while (pozicija != string::npos) {
		tekst.erase(pozicija, tekst1.length());
		tekst.insert(pozicija, tekst2);
		pozicija = tekst.rfind(tekst1, pozicija - 1);
	}

	cout << endl << "Obradeni tekst: " << tekst << endl;

}



int main() {
	int izbornik = 0;
	string tekst;
	do {
		cout << "\nIzaberite radnju: " << endl;
		cout << "1.) Unos teksta.\n2.)Ispis duljine teksta." << endl;
		cout << "3.) Pretvorba u velika / mala slova." << endl;
		cout << "4.) Spajanje teksta." << endl;
		cout << "5.) Find and replace." << endl;
		cout << "0.)Izlazak iz programa.!" << endl;
		cout << "Izbor: " << endl;
		cin >> izbornik;
		cin.ignore();

		switch(izbornik) {
		case 1:
			unos(tekst);
			break;
		case 2:
			duljina(tekst);
			break;
		case 3:
			velikamala(tekst);
			break;
		case 4:
			spajanje(tekst);
			break;
		case 5:
			fqr(tekst);
			break;
		default:
			cout << "Unesli ste nepoznatu radnju!" << endl;
			break;

		}
	} while (izbornik!=0);

}

