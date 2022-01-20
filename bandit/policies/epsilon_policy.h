#ifndef EPISOLN_POLICY_H
#define EPISOLN_POLICY_H


#include <cstddef>
#include <vector>
#include "stateless_policy_interface.h"

class EpsilonBanditPolicy final : public StatelessPolicyInterface<std::size_t, double> {
public:
	EpsilonBanditPolicy(std::size_t action_size);

	~EpsilonBanditPolicy() = default;

	std::size_t sample_action() const override;

private:
	static std::size_t _get_max_element(const std::vector<double>& vect);
	static std::size_t _select_randomly(const std::vector<std::size_t>& max_elements);
	
		
};

#endif /* EPISOLN_POLICY_H */
