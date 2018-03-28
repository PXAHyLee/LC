#include <vector>

#include "sol.hpp"
#include "gtest/gtest.h"

using IntVector = std::vector<int>;

TEST(minCostClimbingStairs, Sample1_Return15) {
  IntVector v{10, 15, 20};
  Solution sol;
  EXPECT_EQ(15, sol.minCostClimbingStairs(v));
}

TEST(minCostClimbingStairs, Sample2_Return6) {
  IntVector v{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  Solution sol;
  EXPECT_EQ(6, sol.minCostClimbingStairs(v));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
