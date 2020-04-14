#include <iostream>
#include <cassert>
#include "ui.h"
#include "teste_repo.h"
#include "teste_repo_file.h"
#include "teste_service.h"
#include "repo_file.h"

using namespace std;

void teste() {
    teste_add_repo();
    teste_del_repo();
    teste_update_repo();
    teste_findElem_repo();
    teste_findByName_repo();
    teste_repo_file_add();
    teste_repo_file_del();
    teste_repo_file_update();
    teste_repo_file_findElem();
    teste_repo_file_findByName();
    TesteService test;
    test.teste_service();
    cout << "testele au trecut cu succes!!" << endl;
}

int main()
{
    teste();
    RepoFile<Carte> repo("carte.txt");
    Service serv(repo);
    UI ui(serv);
    ui.showMenu(serv);
    cout << "succes!!" << endl;
    return 0;
}
