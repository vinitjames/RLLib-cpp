#include "model.h"

#include <iostream>
#include <random>

int main(int argc, char *argv[]) {
  Model<std::normal_distribution<double>> m{5, 1, 1};
  
  std::cout << m.get_arm_size() << '\n';
  std::cout << m.sample_reward(1) << '\n';

  return 0;
}
