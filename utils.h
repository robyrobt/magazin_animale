#pragma once
#include <iostream>
#include <vector>
struct data {
	int an, luna, zi;
};

struct data convert_string_to_data(const std::string, char delim);