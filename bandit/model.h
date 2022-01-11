#include <cstddef>
#include <vector>
#include <random>
#include <chrono>


template <typename Distribution>
class Model{

public:
    template <typename... Params>
	Model(const std::size_t& arms, Params... params);
	
	double sample_reward(const std::size_t& arm) const;

	std::size_t get_arm_size() const;

	const std::vector<Distribution>& get_reward_distribution() const;

private:
	mutable std::vector<Distribution> _action_dist;
	mutable std::mt19937 _rand_engine;
};

template< typename Distribution>
template <typename... Params>
Model<Distribution>::Model(const std::size_t& arms, Params... params)
	{
		std::random_device rd{};
		_rand_engine.seed(rd());
	for(std::size_t i=0; i<arms; i++)
		_action_dist.emplace_back(Distribution(params ...));
}

template< typename Distribution>
double Model<Distribution>::sample_reward(const std::size_t& arm) const{
	if(arm >= _action_dist.size())
		return 0;
	return _action_dist[arm](_rand_engine);
}

template< typename Distribution>
const std::vector<Distribution>& Model<Distribution>::get_reward_distribution() const{
	return _action_dist;

}

template< typename Distribution>
std::size_t Model<Distribution>::get_arm_size() const{
	return _action_dist.size();
}





