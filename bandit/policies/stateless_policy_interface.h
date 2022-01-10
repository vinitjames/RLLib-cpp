#ifndef STATELESS_POLICY_INTERFACE_H
#define STATELESS_POLICY_INTERFACE_H


template <typename TAction>
class StatelessPolicyInterface {

public:
	virtual ~StatelessPolicyInterface() = default;

	virtual TAction sample_action() = 0;

	std::size_t get_action_size() const { return _size_action; }

protected:
	StatelessPolicyInterface(const std::size_t& action_size)
		: _size_action{action_size}{}
	
	std::size_t _size_action;
};


#endif /* STATELESS_POLICY_INTERFACE_H */
