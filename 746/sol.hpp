// 746. Min Cost Climbing Stairs
// Dynamic Programming (Easy)
// Assumption:
//     1. cost will have a length in the range [2, 1000].
//     2. Every cost[i] will be an integer in the range [0, 999].
// Condition:
//     1. Start from step index 0 or 1.
//     2. Climb 1 or 2 steps.

#include <algorithm>
#include <vector>

class Solution {
 public:
  using value_type = int;
  using size_type = std::vector<value_type>::size_type;

 public:
  // Return the value of f(cost.size()).
  // Initial condition: f(0) = 0. f(1) = 0. (Both can be the starting point.)
  // f(1) = cost[0] + f(0) = cost[0]
  // f(2) = ...
  int minCostClimbingStairs(std::vector<int>& cost) {
    value_type dp[] = {0, 0};  // f(0), f(1)
    auto const size = cost.size();
    size_type j = 0;
    for (size_type i = 2; i <= size; ++i) {
      dp[j] = std::min(dp[1 - j] + cost[i - 1], dp[j] + cost[i - 2]);
      j = 1 - j;
    }
    return dp[1 - j];
  }
};
