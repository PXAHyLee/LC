// 746. Min Cost Climbing Stairs
// Dynamic Programming (Easy)
// Assumption:
//     1. cost will have a length in the range [2, 1000].
//     2. Every cost[i] will be an integer in the range [0, 999].
// Condition:
//     1. Start from step index 0 or 1.
//     2. Climb 1 or 2 steps.

#include <algorithm>
#include <array>
#include <cstddef>  // std::size_t
#include <cstdint>  // std::int16_t
#include <iostream>
#include <iterator>
#include <limits>
#include <vector>

class Solution {
public:
  // [2, 1000]
  static constexpr std::size_t kMinCostLength = 2;
  static constexpr std::size_t kMaxCostLength = 1000 + 1;

  // [0, 999]
  static constexpr auto kMinCost = 0;
  static constexpr auto kMaxCost = 999;

  static_assert(std::numeric_limits<std::int16_t>::max() >= kMaxCost, "kMaxCost");

public:
  using Array = std::array<int, kMaxCostLength>;
  using size_type = Array::size_type;

public:
  // Return the value of f(cost.size()).
  // Initial condition: f(0) = 0. f(1) = 0. (Both can be the starting point.)
  // f(1) = cost[0] + f(0) = cost[0]
  // f(2) = ...
  int minCostClimbingStairs(std::vector<int>& cost) {
      Array f{};
      f.fill(std::numeric_limits<int>::max());
      f[0] = f[1] = size_type{};

      // post-condition: f(i) is determined.
      size_type i{};
      for (; i < cost.size() - 1; ++i) {
        f[i + 1] = std::min(f[i] + cost[i], f[i + 1]);
        f[i + 2] = std::min(f[i] + cost[i], f[i + 2]);
      }
      if (i % 2) {
        f[i + 1] = std::min(f[i] + cost[i], f[i + 1]);
      }
      return f[cost.size()];
    }
};
