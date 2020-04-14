#include "service.h"

Service::Service() {}

Service::Service(RepoFile<Carte>& r) {
	this->repo = r;
}

void Service::setRepo(RepoFile<Carte>& r) {
	this->repo = r;
}

void Service::addCarte(Carte& c) {
	repo.addItem(c);
	repo.savaToFile();
}

int Service::getSise_S() {
	return repo.getSize();
}

deque<Carte> Service::getAll() {
	return repo.getAll();
}

int Service::delCarte(Carte& c) {
	int i = repo.remove(c);
	repo.savaToFile();
	return i;
}

int Service::updataCarte(Carte& c, const char* new_name, const char* new_autor, const char* new_status){
	int i = repo.update(c, new_name, new_autor, new_status);
	repo.savaToFile();
	return i;
}

int Service::findElem(Carte& c) {
	return repo.findElem(c);
}

Carte Service::findByName(const char* name) {
	return repo.findByName(name);
}

bool Service::verificare_status(Carte& c) {
	if (strcmp(c.getStatus(), "da") == 0) {
		return true;
	}
	return false;
}

deque<Carte> Service::showBookByAutor(const char* autor_name) {
	deque<Carte> res, elem = repo.getAll();
	for (int i = 0; i < repo.getSize(); i++) {
		if (strcmp(elem[i].getAutor(), autor_name) == 0) {
			res.push_back(elem[i]);
		}
	}
	return res;
}

bool Service::raspuns(const char* raspuns) {
	if (strcmp(raspuns, "da") == 0) {
		return true;
	}
	return false;
}
Service::~Service() {}