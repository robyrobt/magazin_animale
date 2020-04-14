#ifndef CARTE_H
#define CARTE_H

#include<iostream>

using namespace std;

class Carte {
private:
	char* name, * autor, * status;
public:
	Carte();
	Carte(const char*, const char*, const char*);
	Carte(const Carte&);
	Carte(string);

	char* getName();
	char* getAutor();
	char* getStatus();

	void setName(const char*);
	void setAutor(const char*);
	void setStatus(const char*);

	friend ostream& operator << (ostream& out, Carte);
	friend istream& operator >> (istream& is, Carte&);
	bool operator == (const Carte&);
	Carte operator = (const Carte&);
	~Carte();
};

#endif // !CARTE_H
