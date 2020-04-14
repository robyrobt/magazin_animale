#include "ui.h"

UI::UI() {}

UI::UI(Service& service) {
	this->service = service;
}

void UI::adaugareCarte_UI() {
	Carte c;
	cin >> c;
	service.addCarte(c);
	cout << "carte adaugaa cu succes!!!" << endl;
}

void UI::afisareCarte_UI() {
	deque<Carte> elem = service.getAll();
	for (auto c : elem) {
		cout << c;
	}
}

void UI::stergeCarte_UI() {
	deque<Carte> elem = service.getAll();
	Carte c;
	char* name = new char[30];
	cout << "numele cartii: "; cin >> name;
	c = service.findByName(name);
	if (c == Carte("", "", "")) {
		cout << "cartea nu exista" << endl;
	}
	else {
		int i = service.delCarte(c);
		if (i != -1) {
			cout << "succes" << endl;
		}
		else {
			cout << "fail" << endl;
		}
	}
	delete[] name;
}

void UI::modificareCarte_UI() {
	deque<Carte> elem = service.getAll();
	Carte c;
	char* name = new char[30];
	cout << "numele cartii: "; cin >> name;
	c = service.findByName(name);
	if (c == Carte("", "", "")) {
		cout << "cartea nu exista" << endl;
	}
	else {
		cout << "nume nou: ";
		char* name = new char[30];
		cin >> name;
		cout << "autor nou: ";
		char* autor = new char[30];
		cin >> autor;
		cout << "status nou: ";
		char* status = new char[30];
		cin >> status;
		int update = service.updataCarte(c, name, autor, status);
		if (update != -1) {
			cout << "succes" << endl;
		}
		else {
			cout << "fail" << endl;
		}
	}
	delete[] name;
}



void UI::imprumut() {
	bool haha = false;
	while (!haha) {
		char* name = new char[30];
		cout << "numele carti: "; cin >> name;
		Carte c = service.findByName(name);
		if (c == Carte("", "", "")) {
			cout << "cartea nu exista" << endl;
		}
		else {
			if (!service.verificare_status(c)) {
				int i = service.updataCarte(c, c.getName(), c.getAutor(), "da");
				cout << "succes" << endl;
				haha = true;
			}
			else {
				deque<Carte> res = service.showBookByAutor(c.getAutor());
				cout << endl;
				for (auto c : res) {
					cout << c;
				}
				cout << endl;

			}
		}
		delete[] name;
	}
}

void UI::returnare() {
	bool haha = false;
	while (!haha) {
		char* name = new char[30];
		cout << "numele carti: "; cin >> name;
		Carte c = service.findByName(name);
		if (c == Carte("", "", "")) {
			cout << "cartea nu exista" << endl;
		}
		else {
			if (service.verificare_status(c)) {
				int i = service.updataCarte(c, c.getName(), c.getAutor(), "nu");
				cout << "succes" << endl;
				haha = true;
			}
			else {
				cout << endl;
				cout << "cartea nu a fost imprumutata!!" << endl;
				cout << endl;
				char* raspuns = new char[30];
				cout << "doriti sa continuati?: "; cin >> raspuns;
				if (!service.raspuns(raspuns)) {
					haha = true;
				}
			}
		}
		delete[] name;
	}
}

void UI::Menu() {
	cout << endl;
	cout << "1. adaugare carte" << endl;
	cout << "2. afisare carti" << endl;
	cout << "3. stergere carte" << endl;
	cout << "4. modificare carte" << endl;
	cout << "5. imprumutare carte" << endl;
	cout << "6. returnare carte" << endl;
	cout << "0. close" << endl;
}

void UI::showMenu(Service& serv) {
	bool gata = false;
	int opt;
	while (!gata) {
		Menu();
		cout << "opt: "; cin >> opt;
		switch (opt)
		{
		case 1: this->adaugareCarte_UI(); break;
		case 2: this->afisareCarte_UI(); break;
		case 3: this->stergeCarte_UI(); break;
		case 4: this->modificareCarte_UI(); break;
		case 5: this->imprumut(); break;
		case 6: this->returnare(); break;
		case 0: gata = true; break;
		default:
			break;
		}
	}
}

UI::~UI() {}