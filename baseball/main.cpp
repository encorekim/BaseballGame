#include <iostream>
#include <stdexcept>
#include <string>

#include "baseball.cpp"
#include "gmock/gmock.h"

using std::string;

class BaseballFixture : public testing::Test {
 public:
  BaseballGame game;
  void assertIllegalArgument(string input) {
    try {
      game.guess(input);
      FAIL();
    } catch (std::exception e) {
      // PASS (with exception)
    }
  }
};

TEST_F(BaseballFixture, ShortInputError) { assertIllegalArgument("12"); }

TEST_F(BaseballFixture, WrongInputError) { assertIllegalArgument("12a"); }

TEST_F(BaseballFixture, DuplicatedInputError) { assertIllegalArgument("121"); }

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}