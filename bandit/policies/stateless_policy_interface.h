#ifndef STATELESS_POLICY_INTERFACE_H
#define STATELESS_POLICY_INTERFACE_H

#include <algorithm>
#include <utility>
#include <vector>


template <typename TAction, typename TQvalue>
class StatelessPolicyInterface {

public:
	virtual ~StatelessPolicyInterface() = default;

	virtual TAction sample_action() const = 0;

	void init_qvalue(const TAction& init_value);

	template <typename Container,
			  typename T = std::decay_t<
				  decltype(*begin(std::declval<Container>()))>>
	void init_qvalue(const Container& init_value);

	std::size_t get_action_size() const ;

	virtual const std::vector<TQvalue>& get_qvalue_est() const ;

	virtual std::vector<TQvalue>& get_qvalue_est();

protected:
	StatelessPolicyInterface(const std::size_t& action_size);
		
	std::size_t _size_action;
	std::vector<TQvalue> _qvalue_est;	
};


template<typename TAction, typename TQvalue>
StatelessPolicyInterface<TAction, TQvalue>::StatelessPolicyInterface(const std::size_t& action_size)
	: _size_action{action_size}, _qvalue_est(action_size){}


template<typename TAction, typename TQvalue>
inline std::size_t StatelessPolicyInterface<TAction, TQvalue>::get_action_size() const {
	return _size_action;
}

template<typename TAction, typename TQvalue>
inline void StatelessPolicyInterface<TAction, TQvalue>::init_qvalue(const TAction& init_value){
	std::fill(_qvalue_est.begin(), _qvalue_est.end(), init_value);
}

template<typename TAction, typename TQvalue>
template <typename Container, typename T >
inline void StatelessPolicyInterface<TAction, TQvalue>::init_qvalue(const Container& init_value){
	if(_qvalue_est.size() != init_value.size())
		return;
	std::copy(init_value.begin(), init_value.end(), _qvalue_est.begin());
}

template<typename TAction, typename TQvalue>
inline std::vector<TQvalue>& StatelessPolicyInterface<TAction, TQvalue>::get_qvalue_est(){
	return _qvalue_est;
}

template<typename TAction, typename TQvalue>
inline const std::vector<TQvalue>& StatelessPolicyInterface<TAction, TQvalue>::get_qvalue_est() const{
	return _qvalue_est;
}

#endif /* STATELESS_POLICY_INTERFACE_H */
