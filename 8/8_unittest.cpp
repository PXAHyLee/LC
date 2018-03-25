#include <climits>  // INT_MAX
#include <cstring>
#include <string>

#include "8.hpp"
#include "gtest/gtest.h"

// Arrange, Act, and Assert
TEST(StringToInteger, WhenCalledWithEmptyString_ReturnZero) {
  Solution sol;
  const char* str = "";
  std::string s(str);
  auto ret = sol.myAtoi(s);
  EXPECT_EQ(std::atoi(str), ret);
}

TEST(StringToInteger, WhenCalledWithOnlyWhitespaces_ReturnZero_1) {
  Solution sol;
  const char* str = "\f";
  std::string s(str);
  auto ret = sol.myAtoi(s);
  EXPECT_EQ(std::atoi(str), ret);
}

TEST(StringToInteger, WhenCalledWithOnlyWhitespaces_ReturnZero_2) {
  Solution sol;
  const char* str = "\f\n\t";
  std::string s(str);
  auto ret = sol.myAtoi(s);
  EXPECT_EQ(std::atoi(str), ret);
}

TEST(StringToInteger, WhenCalledWithLeadingSpaces1_ReturnOne) {
  Solution sol;
  const char* str = "\n\n\f1";
  std::string s(str);
  auto ret = sol.myAtoi(s);
  EXPECT_EQ(std::atoi(str), ret);
}

TEST(StringToInteger, WhenCalledWithInvalidString_ReturnZero) {
  Solution sol;
  // raw_characters
  // prefix(opt) R"delimiter(raw_characters)delimiter";
  const char* str = R";(" b11228552307");";
  std::string s(str);
  auto ret = sol.myAtoi(s);
  EXPECT_EQ(std::atoi(str), ret);

  const char* str2 = R";("9223372036854775809");";
  std::string s2(str);
  ret = sol.myAtoi(s);
  EXPECT_EQ(std::atoi(str2), ret);
}

TEST(StringToInteger, WhenCalledWithPlus1_ReturnOne) {
  Solution sol;
  const char* str = "+1";
  std::string s(str);
  auto ret = sol.myAtoi(s);
  EXPECT_EQ(std::atoi(str), ret);
}

TEST(StringToInteger, WhenCalledWithMinus1_ReturnMinusOne) {
  Solution sol;
  const char* str = "-1";
  std::string s(str);
  auto ret = sol.myAtoi(s);
  EXPECT_EQ(std::atoi(str), ret);
}

TEST(StringToInteger, WhenCalledWithPlusMinus1_ReturnZero) {
  Solution sol;
  const char* str = "+-1";
  std::string s(str);
  auto ret = sol.myAtoi(s);
  EXPECT_EQ(std::atoi(str), ret);
}

TEST(StringToInteger, WhenCalledWithOverflow_ReturnINTMAX) {
  Solution sol;
  const char *str = "+2147483648", *str2 = "4147483641";
  std::string s(str);
  auto ret = sol.myAtoi(s);
  EXPECT_EQ(INT_MAX, ret);  // Call std::atoi(str) ⇒ undefined behavior

  std::string s2(str2);
  auto ret2 = sol.myAtoi(s2);
  EXPECT_EQ(INT_MAX, ret2);  // Call std::atoi(str) ⇒ undefined behavior
}

TEST(StringToInteger, WhenCalledWithUnderflow_ReturnINTMIN) {
  Solution sol;
  const char* str = "-2147483649";
  std::string s(str);
  auto ret = sol.myAtoi(s);
  EXPECT_EQ(INT_MIN, ret);  // Call std::atoi(str) ⇒ undefined behavior
}

TEST(StringToInteger, WhenCalledWithINTMIN_ReturnINTMIN) {
  Solution sol;
  const char* str = "-2147483648";
  std::string s(str);
  auto ret = sol.myAtoi(s);
  EXPECT_EQ(std::atoi(str), ret);
}

TEST(StringToInteger, WhenCalledWith2147WithAdditionalCharacters_Return2147) {
  Solution sol;
  const char* str = "2147+483648";
  std::string s(str);
  auto ret = sol.myAtoi(s);
  EXPECT_EQ(std::atoi(str), ret);
}

TEST(StringToInteger, WhenCalledWith214748364_Return214748364) {
  Solution sol;
  const char* str = "214748364";
  std::string s(str);
  auto ret = sol.myAtoi(s);
  EXPECT_EQ(std::atoi(str), ret);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
