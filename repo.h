#pragma once
#include <deque>
#include <string.h>
#include <iostream>

using namespace std;
template<class T>

class Repo {
protected:
	deque<T> elem;
public:
	Repo<T>();
	deque<T> getAll();
	void addItem(T&);
	int getSize();
	int remove(T&);
	int update(T&, const char*, const char*, const char*);
	int findElem(T&);
	T findByName(const char*);
	~Repo();
};

template <class T>
Repo<T>::Repo() {}

template <class T>
deque<T> Repo<T>::getAll() {
	return this->elem;
}

template <class T>
void Repo<T>::addItem(T& c) {
	elem.push_back(c);
}

template <class T>
int Repo<T>::getSize() {
	return this->elem.size();
}

template <class T>
int Repo<T>::remove(T& t) {
	int i = this->findElem(t);
	if (i != -1) {
		elem.erase(elem.begin() + i);
		return 0;
	}
	return -1;
}

template <class T>
int Repo<T>::update(T& c, const char* name, const char* autor, const char* status) {
	for (int iter = 0; iter < elem.size(); iter++) {
		if (elem[iter] == c) {
			elem[iter].setName(name);
			elem[iter].setAutor(autor);
			elem[iter].setStatus(status);
			return 0;
		}
	}
	return -1;
}

template <class T>
int Repo<T>::findElem(T& t) {
	for (int i = 0; i < this->getSize(); i++) {
		if (elem[i] == t) {
			return i;
		}
	}
	return -1;
}

template <class T>
T Repo<T>::findByName(const char* name) {
	for (int i = 0; i < this->getSize(); i++) {
		if (strcmp(elem[i].getName(),name) == 0) {
			return elem[i];
		}
	}
	return T("", "", "");
}

template <class T>
Repo<T>::~Repo() {}