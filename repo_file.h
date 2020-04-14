#ifndef REPO_FILE_H
#define REPO_FILE_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string.h>
#include "repo.h"

template <class T>

class RepoFile: public Repo<T>{
	private:
		const char* file_name;
	public:
		RepoFile<T>();
		RepoFile(const char*);
		void loadFromFile(const char*);	
		void savaToFile();
		~RepoFile();

};

template <class T>
RepoFile<T>::RepoFile():Repo<T>() {}

template <class T>
RepoFile<T>::RepoFile(const char* file_name):Repo<T>(){
	this->file_name = file_name;
	ifstream f(file_name);
	string linie;
	while (getline(f, linie)) {
		T c(linie);
		Repo<T>::addItem(c);
	}
	f.close();
}

template <class T>
void RepoFile<T>::loadFromFile(const char* file_name){
	Repo<T>::getAll().clear();
	this->file_name = file_name;
	ifstream f(file_name);
	string linie;
	while (getline(f,linie)) {
		T c(linie);
		Repo<T>::addItem(c);
	}
	f.close();
}

template <class T>
void RepoFile<T>::savaToFile() {
	ofstream f(file_name);
	deque<T> elem = Repo<T>::getAll();
	for (int i = 0; i < elem.size(); i++) {
		f << elem[i];
	}
	f.close();
}

template <class T>
RepoFile<T>::~RepoFile() {}
#endif // !REPO_FILE_H