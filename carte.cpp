#include <string.h>
#include <sstream>
#include "carte.h"

Carte::Carte() {
	this->name = NULL;
	this->autor = NULL;
	this->status = NULL;
}

Carte::Carte(const char* name, const char* autor, const char* status) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->autor = new char[strlen(autor) + 1];
	strcpy_s(this->autor, strlen(autor) + 1, autor);
	this->status = new char[strlen(status) + 1];
	strcpy_s(this->status, strlen(status) + 1, status);
}

Carte::Carte(const Carte& p) {
	this->name = new char[strlen(p.name) + 1];
	strcpy_s(this->name, strlen(p.name) + 1, p.name);
	this->autor = new char[strlen(p.autor) + 1];
	strcpy_s(this->autor, strlen(p.autor) + 1, p.autor);
	this->status = new char[strlen(p.status) + 1];
	strcpy_s(this->status, strlen(p.status) + 1, p.status);
}

Carte::Carte(string linie) {
	std::istringstream iss(linie);
	string name_f, autor_f, status_f;
	iss >> name_f >> autor_f >> status_f;
	name = new char[name_f.size() + 1];
	autor = new char[autor_f.size() + 1];
	status = new char[status_f.size() + 1];
	strcpy_s(name, name_f.size() + 1, name_f.c_str());
	strcpy_s(autor, autor_f.size() + 1, autor_f.c_str());
	strcpy_s(status, status_f.size() + 1, status_f.c_str());
}

char* Carte::getName() {
	return this->name;
}

char* Carte::getAutor() {
	return this->autor;
}

char* Carte::getStatus() {
	return this->status;
}

void Carte::setName(const char* new_name) {
	if (this->name) {
		delete[] this->name;
	}
	this->name = new char[strlen(new_name) + 1];
	strcpy_s(this->name, strlen(new_name) + 1, new_name);
}

void Carte::setAutor(const char* new_autor) {
	if (this->autor) {
		delete[] this->autor;
	}
	this->autor = new char[strlen(new_autor) + 1];
	strcpy_s(this->autor, strlen(new_autor) + 1, new_autor);
}

void Carte::setStatus(const char* new_status) {
	if (this->status) {
		delete[] this->status;
	}
	this->status = new char[strlen(new_status) + 1];
	strcpy_s(this->status, strlen(new_status) + 1, new_status);
}

ostream& operator << (ostream& os, Carte c) {
	os << c.name << " " << c.autor << " " << c.status << endl;
	return os;
}

istream& operator >>(istream& is, Carte& c) {
	cout << "numele cartii: ";
	char* name = new char[30];
	cin >> name;
	cout << "autorul cartii: ";
	char* autor = new char[30];
	cin >> autor;
	cout << "status: ";
	char* status = new char[30];
	cin >> status;
	c.setName(name);
	c.setAutor(autor);
	c.setStatus(status);
	return is;
}

bool Carte::operator == (const Carte& c) {
	if (strcmp(this->name, c.name) == 0) {
		return true;
	}
	return false;
}

Carte Carte::operator = (const Carte& c) {
	if (this == &c) {
		return *this;
	}
	this->setName(c.name);
	this->setAutor(c.autor);
	this->setStatus(c.status);
	return *this;
}

Carte::~Carte() {}