#include "../bandit/sample_average_solver.h"

#include <iostream>

#include "../bandit/policies/greedy_policy.h"
#include "../bandit/policies/epsilon_policy.h"
#include <random>

#define BANDIT_SIZE 10

int main(int argc, char* argv[]) {
	std::random_device rd{};
	std::mt19937 engine{rd()};
	std::normal_distribution<double>dist(0,1);
	std::vector<std::tuple<double, double>> args;
	for (int i = 0; i < BANDIT_SIZE; ++i) {
		args.push_back(std::make_tuple(dist(engine),1.0));
	}
	

  Model<std::normal_distribution<double>> model(args);
  EpsilonBanditPolicy policy1(BANDIT_SIZE, 0);
  EpsilonBanditPolicy policy2(BANDIT_SIZE, 0.1);
  int dist_count = 0;
  const auto& vec = model.get_reward_distribution();
  for (const auto& d : vec)
    std::cout << "dist no." << dist_count++ << " params" << d << std::endl;

  SampleAverageSolver<std::normal_distribution<double>, std::size_t, double>
      solver(model, policy1);

  dist_count = 0;
  for (const auto& p : policy1.get_qvalue_est())
    std::cout << "action no." << dist_count++ << "q_value_estimate " << p
              << std::endl;
  
  std::cout << "solver started" << std::endl;
  double avg_reward = solver.solve(10000);
  std::cout << "solver ended" << std::endl;
  std::cout << "avg_reward" <<avg_reward << std::endl;
  dist_count = 0;
  for (const auto& p : policy1.get_qvalue_est())
    std::cout << "action no." << dist_count++ << "q_value_estimate " << p
              << std::endl;
  return 0;
} 
