#include <cassert>
#include "teste_repo.h"
#include "repo.h"

void teste_add_repo() {
	Carte c1("ion", "rebleanu", "da"), c2("iona","nu stiu","nu");
	Repo<Carte> repo;
	assert(repo.getSize() == 0);
	repo.addItem(c1);
	repo.addItem(c2);
	assert(repo.getSize() == 2);
	assert(strcmp(repo.getAll()[0].getAutor(), "rebleanu") == 0);
}

void teste_del_repo() {
	Carte c1("ion", "rebleanu", "da"), c2("iona", "nu stiu", "nu");
	Repo<Carte> repo;
	repo.addItem(c1);
	repo.addItem(c2);
	assert(repo.getSize() == 2);
	int i = repo.remove(c2);
	assert(repo.getSize() == 1);
	int j = repo.remove(c1);
	assert(repo.getSize() == 0);
}

void teste_update_repo() {
	Carte c1("ion", "rebleanu", "da"), c2("iona", "nu stiu", "nu");
	Repo<Carte> repo;
	repo.addItem(c1);
	repo.addItem(c2);
	assert(strcmp(repo.getAll()[1].getName(), "iona") == 0);
	int i = repo.update(c2, "mara", "slavici", "da");
	assert(i = -1);
	assert(strcmp(repo.getAll()[1].getName(), "mara") == 0);
}

void teste_findElem_repo() {
	Carte c1("ion", "rebleanu", "da"), c2("iona", "nu stiu", "nu"), c3("harry potter","nu stiu", "da");
	Repo<Carte> repo;
	repo.addItem(c1);
	repo.addItem(c2);
	int i = repo.findElem(c2);
	assert(i == 1);
	int j = repo.findElem(c3);
	assert(j == -1);
}

void teste_findByName_repo() {
	Carte c, d, c1("ion", "rebleanu", "da"), c2("iona", "nu stiu", "nu");
	Repo<Carte> repo;
	repo.addItem(c1);
	repo.addItem(c2);
	c = repo.findByName("ion");
	assert(c == c1);
	d = repo.findByName("enigma");
	assert(d == Carte("", "", ""));
}