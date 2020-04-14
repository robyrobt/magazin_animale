#include <cassert>
#include <string.h>
#include "teste_service.h"

TesteService::TesteService() {}

TesteService::~TesteService() {}

void TesteService::teste_service() {
	this->teste_add_and_del_service();
	this->teste_update_service();
	this->teste_findElem_service();
	this->teste_findByName_service();
	this->teste_verificare_status_service();
}

void TesteService::teste_add_and_del_service() {
	Carte c1("ion", "rebleanu", "da");
	RepoFile<Carte> repo("test_service.txt");
	Service serv(repo);
	assert(serv.getSise_S() == 4);
	serv.addCarte(c1);
	assert(serv.getSise_S() == 5);
	int i = serv.delCarte(c1);
	repo.savaToFile();
	assert(i == 0);
}

void TesteService::teste_update_service() {
	Carte c1("name_1", "autor_1", "da"),c2("name","autor","nu");
	RepoFile<Carte> repo("test_service.txt");
	Service serv(repo);
	assert(serv.getSise_S() == 4);
	int k = serv.updataCarte(c2, "name_1", "autor_1", "da");
	assert(k == -1);
	int i = serv.updataCarte(c1, "name","autor","nu");
	assert(i == 0);
	int j = serv.updataCarte(c2, "name_1", "autor_1", "da");
	assert(j == 0);
}

void TesteService::teste_findElem_service() {
	Carte c1("ion", "rebleanu", "da"), c2("name_3", "autor_3", "nu");
	RepoFile<Carte> repo("test_service.txt");
	Service serv(repo);
	assert(serv.getSise_S() == 4);
	int i = serv.findElem(c1);
	assert(i == -1);
	int j = serv.findElem(c2);
	assert(j == 2);
}

void TesteService::teste_findByName_service() {
	RepoFile<Carte> repo("test_service.txt");
	Service serv(repo);
	Carte c1("","",""), c = serv.findByName("ion"), d= serv.findByName("name_1"), d1("name_1","autor_1","da") ;
	assert(c == c1);
	assert(d == d1);
}

void TesteService::teste_verificare_status_service() {
	Carte c1("nume_1", "autor_1", "da"), c2("name_3", "autor_3", "nu");
	RepoFile<Carte> repo("test_service.txt");
	Service serv(repo);
	bool carte_3 = serv.verificare_status(c2);
	assert(carte_3 == false);
	bool carte_1 = serv.verificare_status(c1);
	assert(carte_1 == true);
}