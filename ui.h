#pragma once

#include "service.h"

class UI {
	private:
		Service service;
		void Menu();
		void adaugareCarte_UI();
		void afisareCarte_UI();
		void stergeCarte_UI();
		void modificareCarte_UI();
		void imprumut();
		void returnare();
	public:
		UI();
		UI(Service&);
		void showMenu(Service&);
		~UI();
};