// 8. String to Integer (atoi)

#include <algorithm>
#include <cassert>
#include <cctype>   // isspace isdigit
#include <climits>  // INT_MAX
#include <cstring>
#include <string>

// Assumption: INT_MAX is 2147483647, and INT_MIN is -2147483648. This is given
// in the problem description.
static_assert(INT_MAX == 2147483647, "INT_MAX");
static_assert(INT_MIN == -2147483648, "INT_MIN");

class Solution {
 public:
  int myAtoi(std::string str) {
    auto const space = [](int c) { return std::isspace(c); };
    auto const signedCharacter = [](int c) { return c == '+' || c == '-'; };
    auto first = std::find_if_not(str.cbegin(), str.cend(), space);
    if ((!str.empty() && first == str.cend()) ||
        (first != str.cend() && !signedCharacter(*first) &&
         !std::isdigit(*first))) {
      return 0;
    }
    bool negative = false;
    if (*first == '+') {
      ++first;
    } else if (*first == '-') {
      negative = true;
      ++first;
    }

    int value{};
    if (negative) {
      for (auto it = first; it != str.cend() && std::isdigit(*it); ++it) {
        if (value < N || (value == N && ((*it) - '0') > 8)) return INT_MIN;
        value = 10 * value - ((*it) - '0');
      }
    } else {
      for (auto it = first; it != str.cend() && std::isdigit(*it); ++it) {
        if (value > M || (value == M && ((*it) - '0') > 7)) return INT_MAX;
        value = 10 * value + ((*it) - '0');
      }
    }
    return value;
  }

  static constexpr int M = INT_MAX / 10;
  static constexpr int N = INT_MIN / 10;
};
