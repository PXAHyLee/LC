// 8. String to Integer (atoi)

#include <algorithm>
#include <cassert>
#include <cctype>   // isspace isdigit
#include <climits>  // INT_MAX
#include <cstring>
#include <functional>
#include <string>

// Assumption: INT_MAX is 2147483647, and INT_MIN is -2147483648. This is given
// in the problem description.
static_assert(INT_MAX == 2147483647, "INT_MAX");
static_assert(INT_MIN == -2147483648, "INT_MIN");

class Solution {
 public:
  int myAtoi(std::string str) {
    auto const prefix = [](int c) {
      return std::isdigit(c) || c == '+' || c == '-';
    };
    auto first = std::find_if(str.cbegin(), str.cend(), prefix);
    if (first == str.cend()) return 0;

    bool negative{};
    int value{};
    std::function<int(int, int)> op = std::plus<int>();
    if (*first == '+') {
      ++first;
    } else if (*first == '-') {
      negative = true;
      op = std::minus<int>();
      ++first;
    }
    for (auto it = first; it != str.cend() && std::isdigit(*it); ++it) {
      if (!negative && (value > M || (value == M && ((*it) - '0') > 7)))
        return INT_MAX;
      else if (negative && (value < N || (value == N && ((*it) - '0') > 8)))
        return INT_MIN;
      value = op(10 * value, (*it) - '0');
    }
    return value;
  }

  static constexpr int M = 214748364;
  static constexpr int N = -214748364;
};
