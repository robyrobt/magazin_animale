#include <cassert>
#include "teste_repo_file.h"
#include "repo_file.h"

void teste_repo_file_add() {
	RepoFile<Carte> repo("test_repo_file.txt");
	assert(repo.Repo<Carte>::getSize() == 4);
	Carte c("name_5", "autor_5", "nu");
	repo.Repo<Carte>::addItem(c);
	assert(repo.Repo<Carte>::getSize() == 5);
}

void teste_repo_file_del() {
	RepoFile<Carte> repo("test_repo_file.txt");
	assert(repo.Repo<Carte>::getSize() == 4);
	Carte c("name_5", "autor_5", "nu");
	repo.Repo<Carte>::addItem(c);
	assert(repo.Repo<Carte>::getSize() == 5);
	repo.Repo<Carte>::remove(c);
	assert(repo.Repo<Carte>::getSize() == 4);
}

void teste_repo_file_update() {
	RepoFile<Carte> repo("test_repo_file.txt");
	assert(repo.Repo<Carte>::getSize() == 4);
	Carte c("name_5", "autor_5", "nu");
	repo.Repo<Carte>::addItem(c);
	assert(repo.Repo<Carte>::getSize() == 5);
	repo.Repo<Carte>::update(c,"name","autor","da");
	deque<Carte> elem = repo.Repo<Carte>::getAll();
	assert(strcmp(elem[4].getName(),"name") == 0);
}

void teste_repo_file_findElem() {
	RepoFile<Carte> repo("test_repo_file.txt");
	assert(repo.Repo<Carte>::getSize() == 4);
	Carte c("name_5", "autor_5", "nu"), c1("name_1", "autor_1","da");
	int i = repo.Repo<Carte>::findElem(c);
	assert(i == -1);
	int j = repo.Repo<Carte>::findElem(c1);
	assert(j == 0);
}

void teste_repo_file_findByName() {
	RepoFile<Carte> repo("test_repo_file.txt");
	assert(repo.Repo<Carte>::getSize() == 4);
	Carte c("", "", ""), c1("name_1", "autor_1", "da");
	Carte i = repo.Repo<Carte>::findByName("name");
	assert(i == c);
	Carte j = repo.Repo<Carte>::findByName("name_1");
	assert(j == c1);
}
