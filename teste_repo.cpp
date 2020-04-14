#include <cassert>
#include "teste_repo.h"
#include "repo.h"
#include "animal_de_companie.h"

void teste_add_and_del_repo() {
	Repo<AnimalCompanie> repo;
	assert(repo.getSize() == 0);
	struct data data_caine, data_pisica;
	data_caine.zi = 12;
	data_caine.luna = 5;
	data_caine.an = 1900;
	data_pisica.zi = 3;
	data_pisica.luna = 1;
	data_pisica.an = 200;
	AnimalCompanie a1(1, "caine", 39, data_caine, 12, 3), a2(2, "pisica", 34, data_pisica, 1, 3);
	assert(a1.getCod() == 1);
	assert(a1.getData().an == 1900);
	repo.addItem(a1);
	repo.addItem(a2);
	assert(repo.getSize() == 2);
	int i = repo.delItem(a1);
	assert(i == 0);
	assert(repo.getSize() == 1);
}

void teste_update_repo() {
	Repo<AnimalCompanie> repo;
	assert(repo.getSize() == 0);
	struct data data_caine, data_pisica, data_miel;
	data_caine.zi = 12;
	data_caine.luna = 5;
	data_caine.an = 1900;
	data_pisica.zi = 3;
	data_pisica.luna = 1;
	data_pisica.an = 200;
	data_miel.zi = 2;
	data_miel.luna = 10;
	data_miel.an = 1940;
	AnimalCompanie a1(1, "caine", 39, data_caine, 12, 3), a2(2, "pisica", 34, data_pisica, 1, 3), a3(3, "miel", 200, data_miel, 2, 3);
	repo.addItem(a1);
	repo.addItem(a2);
	repo.updateItem(a1, a3);
	assert(a1.getCod() == 3);
	assert(strcmp(a1.getName(), "miel") == 0);
}

void teste_findElem_repo() {
	Repo<AnimalCompanie> repo;
	assert(repo.getSize() == 0);
	struct data data_caine, data_pisica, data_miel;
	data_caine.zi = 12;
	data_caine.luna = 5;
	data_caine.an = 1900;
	data_pisica.zi = 3;
	data_pisica.luna = 1;
	data_pisica.an = 200;
	data_miel.zi = 2;
	data_miel.luna = 10;
	data_miel.an = 1940;
	AnimalCompanie a1(1, "caine", 39, data_caine, 12, 3), a2(2, "pisica", 34, data_pisica, 1, 3), a3(3, "miel", 200, data_miel, 2, 3);
	assert(a1.getCod() == 1);
	assert(a1.getData().an == 1900);
	repo.addItem(a1);
	repo.addItem(a2);
	assert(repo.getSize() == 2);
	int i = repo.findElem(a1);
	assert(i == 0);
	int j = repo.findElem(a3);
	assert(j == -1);
}

void teste_findByName_repo() {
	Repo<AnimalCompanie> repo;
	assert(repo.getSize() == 0);
	struct data data_caine, data_pisica;
	data_caine.zi = 12;
	data_caine.luna = 5;
	data_caine.an = 1900;
	data_pisica.zi = 3;
	data_pisica.luna = 1;
	data_pisica.an = 200;
	AnimalCompanie a1(1, "caine", 39, data_caine, 12, 3), a2(2, "pisica", 34, data_pisica, 1, 3);
	assert(a1.getCod() == 1);
	assert(a1.getData().an == 1900);
	repo.addItem(a1);
	repo.addItem(a2);
	assert(repo.getSize() == 2);
	AnimalCompanie b = repo.findByName("caine");
	assert(b == a1);
	AnimalCompanie b1 = repo.findByName("miel");
	assert(b1 == AnimalCompanie());
}