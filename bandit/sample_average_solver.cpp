#include "sample_average_solver.h"

#include <iostream>

#include "policies/greedy_policy.h"

int main(int argc, char* argv[]) {
  Model<std::normal_distribution<double>> model(10);
  GreedyBanditPolicy policy(10);
  int dist_count = 0;
  const auto& vec = model.get_reward_distribution();
  for (const auto& d : vec)
    std::cout << "dist no." << dist_count++ << " params" << d << std::endl;

  SampleAverageSolver<std::normal_distribution<double>, std::size_t, double>
      solver(model, policy);

  dist_count = 0;
  for (const auto& p : policy.get_qvalue_est())
    std::cout << "action no." << dist_count++ << "q_value_estimate " << p
              << std::endl;
  std::cout << "solver started" << std::endl;
  solver.solve(100000);
  std::cout << "solver ended" << std::endl;

  dist_count = 0;
  for (const auto& p : policy.get_qvalue_est())
    std::cout << "action no." << dist_count++ << "q_value_estimate " << p
              << std::endl;
  return 0;
}
