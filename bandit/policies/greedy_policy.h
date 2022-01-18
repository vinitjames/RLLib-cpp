#ifndef GREEDY_POLICY_H
#define GREEDY_POLICY_H


#include <cstddef>
#include <vector>
#include "stateless_policy_interface.h"

class GreedyBanditPolicy final : public StatelessPolicyInterface<std::size_t, double> {
public:
	GreedyBanditPolicy(std::size_t action_size);

	~GreedyBanditPolicy() = default;

	std::size_t sample_action() const override;

private:
	static std::size_t _get_max_element(const std::vector<double>& vect);
	static std::size_t _select_randomly(const std::vector<std::size_t>& max_elements);
	
		
};

#endif /* GREEDY_POLICY_H */

