#include "epsilon_policy.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

EpsilonBanditPolicy::EpsilonBanditPolicy(std::size_t action_size, const double& epsilon )
    : StatelessPolicyInterface<std::size_t, double>(action_size), _epsilon{epsilon} {}

std::size_t EpsilonBanditPolicy::sample_action() const {
	double p = std::normal_distribution<double>  
	if(p <= epsilon)
		return _select_randomly();
	return _get_max_element(_qvalue_est); 
}

std::size_t GreedyBanditPolicy::_get_max_element(const std::vector<double>& vec){
	double max = vec[0];
	std::vector<std::size_t> max_elements{0};
	for(std::size_t i=1; i<vec.size(); i++){
		if(max > vec[i])
			continue;
	    if (max == vec[i]){
			max_elements.push_back(i);
			continue;
		}
		max = vec[i];
		max_elements = {i};
	}
	return _select_randomly(max_elements); 	
} 

std::size_t GreedyBanditPolicy::_select_randomly(const std::vector<std::size_t>& max_elements){
	std::uniform_int_distribution<>dis(0, max_elements.size()-1);
	static std::random_device rd;
	static std::mt19937 gen(rd());
	return max_elements[dis(gen)];
}
