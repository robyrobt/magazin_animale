#include <iostream>
#include <string.h>
#include <vector>
#include "utils.h"
#include "animal_de_companie.h"
#include "teste_animal_companie.h"
#include "teste_produs_animal_companie.h"
#include "teste_repo.h"

void teste() {
    teste_animal_companie();
    teste_produs_animal_companie();
    teste_add_and_del_repo();
    teste_update_repo();
    teste_findElem_repo();
    teste_findByName_repo();
    std::cout << "testele au trecut cu succes!!" << std::endl;
}

int main()
{
    teste();
    std::cout << "succes";
}
