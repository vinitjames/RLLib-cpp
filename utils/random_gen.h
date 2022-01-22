#ifndef RANDOM_GEN_H
#define RANDOM_GEN_H

#include <random>

class RandomGenerators{
public:
	
	static double uniform_real_generator(const double& lo, const double& up);

	static int uniform_int_generator(const int& lo, const int& up);

private:
	static std::mt19937 _engine;
	
	
};

#endif /* RANDOM_GEN_H */
