#ifndef SAMPLE_AVERAGE_SOLVER_H
#define SAMPLE_AVERAGE_SOLVER_H


#include "model.h"
#include "policies/stateless_policy_interface.h"

template<typename Distribution, typename TAction, typename TQvalue>
class SampleAverageSolver{

public:

	SampleAverageSolver(Model<Distribution>& model,
						StatelessPolicyInterface<TAction, TQvalue>& policy);

	double solve(const std::size_t& steps);
	

 private:
	Model<Distribution>& _model;
	StatelessPolicyInterface<TAction, TQvalue>& _policy;
	std::vector<std::size_t> _action_count;
};

template<typename Distribution, typename TAction, typename TQvalue>
SampleAverageSolver<Distribution, TAction, TQvalue>::
SampleAverageSolver(Model<Distribution>& model,
					StatelessPolicyInterface<TAction, TQvalue>& policy)
	: _model(model), _policy(policy), _action_count(model.get_arm_size()){}


template<typename Distribution, typename TAction, typename TQvalue>
inline double  SampleAverageSolver<Distribution, TAction, TQvalue>::solve(const std::size_t& steps){
	_policy.init_qvalue(1.0);
	double cumm_reward = 0;
	for (int i = 0; i < steps; ++i) {
		std::size_t action = _policy.sample_action();
		double reward = _model.sample_reward(action);
		_action_count[action]++;
		_policy.get_qvalue_est()[action] +=
			(reward  - _policy.get_qvalue_est()[action]) / _action_count[action];
		cumm_reward += reward;		
	}
	return cumm_reward/steps;
}


#endif /* SAMPLE_AVERAGE_SOLVER_H */
