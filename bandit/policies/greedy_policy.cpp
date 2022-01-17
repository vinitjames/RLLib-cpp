#include "greedy_policy.h"

#include <algorithm>

GreedyBanditPolicy::GreedyBanditPolicy(std::size_t action_size)
    : StatelessPolicyInterface<std::size_t, double>(action_size) {}

std::size_t GreedyBanditPolicy::sample_action() const {
  return std::distance(
      _qvalue_est.begin(),
      std::max_element(_qvalue_est.begin(), _qvalue_est.end()));
}
