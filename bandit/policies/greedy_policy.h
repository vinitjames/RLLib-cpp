#ifndef GREEDY_POLICY_H
#define GREEDY_POLICY_H


#include <cstddef>
#include <vector>
#include "stateless_policy_interface.h"

class GreedyBanditPolicy final : public StatelessPolicyInterface<std::size_t> {
public:
	GreedyBanditPolicy(std::size_t action_size);

	~GreedyBanditPolicy() = default;

	std::size_t sample_action() const;

	const std::vector<double>& get_q_value_est() const;

	std::vector<double>& get_q_value_est();
	
	
private:
	std::vector<double> _q_value_est;
};

#endif /* GREEDY_POLICY_H */

