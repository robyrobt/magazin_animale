#include <cassert>
#include "teste_animal_companie.h"
#include "animal_de_companie.h"

void teste_animal_companie() {
	struct data data;
	data.zi = 2;
	data.luna = 9;
	data.an = 1990;
	AnimalCompanie animal(47, "pisica", 300, data, 14, 5), animal1;
	assert(animal.getCod() == 47);
	assert(strcmp(animal.getName(), "pisica") == 0);
	animal1 = animal;
	assert(animal1 == animal);
}