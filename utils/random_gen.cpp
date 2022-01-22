#include "random_gen.h"
#include <iostream>

std::mt19937 RandomGenerators::_engine{std::random_device{}()};

double RandomGenerators::uniform_real_generator(const double& min, const double& max){
	std::uniform_real_distribution<double> dist(min, max);
	return dist(_engine);
}

int RandomGenerators::uniform_int_generator(const int& min, const int& max){
	std::uniform_real_distribution<double> dist(min, max);
	return dist(_engine);
}
