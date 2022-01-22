#include "greedy_policy.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include "../../utils/random_gen.h"

GreedyBanditPolicy::GreedyBanditPolicy(std::size_t action_size)
    : StatelessPolicyInterface<std::size_t, double>(action_size) {}

std::size_t GreedyBanditPolicy::sample_action() const {
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
	return max_elements[RandomGenerators::uniform_int_generator(0,max_elements.size())]; 	
} 

