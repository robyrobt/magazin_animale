#include <sstream>
#include "utils.h"
#include "produs_animal_companie.h"

Produs::Produs() {
	this->cod = 0;
	this->name = NULL;
	this->pret = 0;
	this->data_int.an = 0;
	this->data_int.luna = 0;
	this->data_int.zi = 0;
	this->data_exp.an = 0;
	this->data_exp.luna = 0;
	this->data_exp.zi = 0;
	this->nr_exemplare = 0;
}

Produs::Produs(int cod, const char* name, float pret, struct data data_int, struct data data_exp, int nr_exemplare) {
	this->cod = cod;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->pret = pret;
	this->data_int.an = data_int.an;
	this->data_int.luna = data_int.luna;
	this->data_int.zi = data_int.zi;
	this->data_exp.an = data_exp.an;
	this->data_exp.luna = data_exp.luna;
	this->data_exp.zi = data_exp.zi;
	this->nr_exemplare = nr_exemplare;
}

Produs::Produs(const Produs& produs) {
	this->cod = produs.cod;
	this->name = new char[strlen(produs.name) + 1];
	strcpy_s(this->name, strlen(produs.name) + 1, produs.name);
	this->pret = produs.pret;
	this->data_int.an = produs.data_int.an;
	this->data_int.luna = produs.data_int.luna;
	this->data_int.zi = produs.data_int.zi;
	this->data_exp.an = produs.data_exp.an;
	this->data_exp.luna = produs.data_exp.luna;
	this->data_exp.zi = produs.data_exp.zi;
	this->nr_exemplare = produs.nr_exemplare;
}

Produs::Produs(std::string linie) {
	std::istringstream iss(linie);
	std::string cod, name, pret, data_int, data_exp, nr_exempalre;
	this->cod = std::stoi(cod);
	this->name = new char[strlen(name.c_str()) + 1];
	strcpy_s(this->name, strlen(name.c_str() + 1), name.c_str());
	this->pret = strtof((pret).c_str(), 0);
	struct data data_int_a = convert_string_to_data(data_int,'/'), data_exp_a = convert_string_to_data(data_exp, '/');
	this->data_int.zi = data_int_a.zi;
	this->data_int.luna = data_int_a.luna;
	this->data_int.an = data_int_a.an;
	this->data_exp.zi = data_exp_a.zi;
	this->data_exp.luna = data_exp_a.luna;
	this->data_exp.an = data_exp_a.an;
	this->nr_exemplare = std::stoi(nr_exempalre);
}

Produs::~Produs() {
	this->cod = 0;
	this->name = NULL;
	this->pret = 0;
	this->data_int.an = 0;
	this->data_int.luna = 0;
	this->data_int.zi = 0;
	this->data_exp.an = 0;
	this->data_exp.luna = 0;
	this->data_exp.zi = 0;
	this->nr_exemplare = 0;
}

char* Produs::getName() {
	return this->name;
}

float Produs::getPret() {
	return this->pret;
}

int Produs::getCod() {
	return this->cod;
}

int Produs::getNrExemplare() {
	return this->nr_exemplare;
}

struct data Produs::getData_int() {
	return this->data_int;
}

struct data Produs::getData_exp() {
	return this->data_exp;
}

void Produs::setCod(int new_cod) {
	this->cod = new_cod;
}

void Produs::setNrExemplare(int new_nr) {
	this->nr_exemplare = new_nr;
}

void Produs::setName(const char* new_name) {
	if (this->name) {
		delete[] name;
	}
	this->name = new char[strlen(new_name) + 1];
	strcpy_s(this->name, strlen(new_name) + 1, new_name);
}

void Produs::setPret(float new_pret) {
	this->pret = new_pret;
}

void Produs::setData_int(struct data new_data) {
	this->data_int.an = new_data.an;
	this->data_int.luna = new_data.luna;
	this->data_int.zi = new_data.zi;
}

void Produs::setData_exp(struct data new_data) {
	this->data_exp.an = new_data.an;
	this->data_exp.luna = new_data.luna;
	this->data_exp.zi = new_data.zi;
}

bool Produs::operator == (const Produs& produs) {
	return this->cod == produs.cod;
}

Produs Produs::operator = (const Produs& produs) {
	if (this == &produs) {
		return *this;
	}
	this->setCod(produs.cod);
	this->setName(produs.name);
	this->setPret(produs.pret);
	this->setData_int(produs.data_int);
	this->setData_exp(produs.data_exp);
	this->setNrExemplare(produs.nr_exemplare);
	return *this;
}

std::ostream& operator << (std::ostream& os, Produs produs) {
	os << produs.getCod() << " " << produs.getName() << " " << produs.getPret() << produs.getData_int().zi << "/" << produs.getData_int().luna << "/" << produs.getData_int().an << " " << produs.getData_exp().zi << "/" << produs.getData_int().luna << "/" << produs.getData_int().an << " " << produs.getNrExemplare() << std::endl;
	return os;
}

std::istream& operator >> (std::istream& is, Produs& produs) {
	int cod, nr_exemplare;
	char* name = new char[30];
	float pret;
	struct data data_int, data_exp;
	std::cout << "cod: "; is >> cod;
	std::cout << "name: "; is >> name;
	std::cout << "pret :"; is >> pret;
	std::cout << "data introducerii in magazin" << std::endl;
	std::cout << "zi: "; is >> data_int.zi;
	std::cout << "luna: "; is >> data_int.luna;
	std::cout << "anul: "; is >> data_int.an;
	std::cout << "data expirarii produsului" << std::endl;
	std::cout << "zi: "; is >> data_exp.zi;
	std::cout << "luna: "; is >> data_exp.luna;
	std::cout << "anul: "; is >> data_exp.an;
	std::cout << "numar exemplare: "; is >> nr_exemplare;
	produs.setCod(cod);
	produs.setName(name);
	produs.setPret(pret);
	produs.setData_int(data_int);
	produs.setData_exp(data_exp);
	produs.setNrExemplare(nr_exemplare);
	return is;
}