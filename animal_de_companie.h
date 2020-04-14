#pragma once
#include <string.h>
#include <iostream>
#include "utils.h"

class AnimalCompanie {
	private:
		int cod, varsta, nr_exemplare;
		char* name;
		float pret;
		struct data data;
	public:
		AnimalCompanie();
		AnimalCompanie(int, const char*, float, struct data, int, int);
		AnimalCompanie(const AnimalCompanie&);
		AnimalCompanie(std::string);
		~AnimalCompanie();

		int getCod();
		int getVarsta();
		int getNrExemplare();
		char* getName();
		float getPret();
		struct data getData();
		void setCod(int);
		void setVarsta(int);
		void setNrExemplare(int);
		void setName(const char*);
		void setPret(float);
		void setData(struct data);

		bool operator == (const AnimalCompanie&);
		AnimalCompanie operator = (const AnimalCompanie&);

		friend std::ostream& operator << (std::ostream& os, AnimalCompanie);
		friend std::istream& operator >> (std::istream& is, AnimalCompanie&);

};