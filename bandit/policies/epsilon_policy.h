#ifndef EPISOLN_POLICY_H
#define EPISOLN_POLICY_H


#include <cstddef>
#include <vector>
#include "stateless_policy_interface.h"

class EpsilonBanditPolicy final : public StatelessPolicyInterface<std::size_t, double> {
public:
	EpsilonBanditPolicy(std::size_t action_size, const double& epsilon);

	~EpsilonBanditPolicy() = default;

	std::size_t sample_action() const override;

private:
	static std::size_t _get_max_element(const std::vector<double>& vect);
	double _epsilon;
	
};

#endif /* EPISOLN_POLICY_H */
