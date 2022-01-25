#include "epsilon_policy.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include "../../utils/random_gen.h"

EpsilonBanditPolicy::EpsilonBanditPolicy(std::size_t action_size, const double& epsilon = 0)
    : StatelessPolicyInterface<std::size_t, double>(action_size), _epsilon{epsilon} {}

std::size_t EpsilonBanditPolicy::sample_action() const {
	
	if(_epsilon == 0)
		return _get_max_element(_qvalue_est);
	
	double p =  RandomGenerators::uniform_real_generator(0,1);	
	if(p <= _epsilon)
		return _qvalue_est[RandomGenerators::uniform_int_generator(0, _qvalue_est.size())];
	return _get_max_element(_qvalue_est); 
}


std::size_t EpsilonBanditPolicy::_get_max_element(const std::vector<double>& vec){
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
