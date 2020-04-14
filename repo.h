#ifndef REPO_H
#define REPO_H
#include <iostream>
#include <deque>

template<class T>
class Repo {
	protected:
		std::deque<T> elem;
	public:
		Repo();
		~Repo();
		void addItem(T&);
		int delItem(T&);
		void updateItem(T&, T&);
		std::deque<T> getAll();
		int findElem(T&);
		T findByName(const char*);
		int getSize();
};

template <class T>
Repo<T>::Repo() {}

template<class T>
std::deque<T> Repo<T>::getAll() {
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
int Repo<T>::delItem(T& t) {
	int i = this->findElem(t);
	if (i != -1) {
		elem.erase(elem.begin() + i);
		return 0;
	}
	return -1;
}

template<class T>
void Repo<T>::updateItem(T& most_update, T& update) {
	most_update = update;
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
		if (strcmp(elem[i].getName(), name) == 0) {
			return elem[i];
		}
	}
	return T();
}

template<class T>
Repo<T>::~Repo() {}

#endif // !REPO_H