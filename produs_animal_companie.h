#pragma once
#include <iostream>
#include "utils.h"

class Produs {
	private:
		int cod, nr_exemplare;
		char* name;
		float pret;
		struct data data_int, data_exp;
	public:
		Produs();
		Produs(int, const char*, float, struct data, struct data, int);
		Produs(const Produs&);
		Produs(std::string);
		~Produs();

		int getCod();
		char* getName();
		float getPret();
		struct data getData_int();
		struct data getData_exp();
		int getNrExemplare();

		void setCod(int);
		void setNrExemplare(int);
		void setName(const char*);
		void setPret(float);
		void setData_int(struct data);
		void setData_exp(struct data);

		bool operator == (const Produs&);
		Produs operator = (const Produs&);

		friend std::ostream& operator << (std::ostream& os, Produs);
		friend std::istream& operator >> (std::istream& is, Produs&);
};