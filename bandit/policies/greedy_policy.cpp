#include "greedy_policy.h"
#include <algorithm>


GreedyBanditPolicy::GreedyBanditPolicy(std::size_t action_size)
		: StatelessPolicyInterface<std::size_t>(action_size), _q_value_est(action_size){}


std::size_t GreedyBanditPolicy::sample_action() const{
	return std::distance(_q_value_est.begin(),
						 std::max_element(_q_value_est.begin(),
										  _q_value_est.end()));
}

const std::vector<double>& GreedyBanditPolicy::get_q_value_est() const {
	return _q_value_est;
}

std::vector<double>& GreedyBanditPolicy::get_q_value_est(){
	return _q_value_est;
}


