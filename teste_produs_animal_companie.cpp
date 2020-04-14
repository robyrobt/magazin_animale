#include <cassert>
#include "teste_produs_animal_companie.h"
#include "utils.h"
#include "produs_animal_companie.h"

void teste_produs_animal_companie() {
	struct data data_int, data_exp;
	data_int.zi = 2;
	data_int.luna = 9;
	data_int.an = 1990;
	data_exp.zi = 4;
	data_exp.luna = 8;
	data_exp.an = 2020;
	Produs produs(47, "mancare_pisica", 30, data_int, data_exp, 5), produs_1;
	assert(produs.getCod() == 47);
	assert(strcmp(produs.getName(), "mancare_pisica") == 0);
	assert(produs_1.getPret() == 0);
}