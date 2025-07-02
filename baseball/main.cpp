#include <iostream>
#include <stdexcept>
#include <string>

#include "baseball.cpp"
#include "gmock/gmock.h"

using std::string;

class BaseballFixture : public testing::Test {
 public:
  BaseballGame game{"123"};
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

TEST_F(BaseballFixture, Test123) {
  GuessResult result = game.guess("123");
  EXPECT_TRUE(result.solved);
  EXPECT_EQ(3, result.strikes);
  EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, Test143) {
  GuessResult result = game.guess("143");
  EXPECT_FALSE(result.solved);
  EXPECT_EQ(2, result.strikes);
  EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, Test213) {
  GuessResult result = game.guess("213");
  EXPECT_FALSE(result.solved);
  EXPECT_EQ(1, result.strikes);
  EXPECT_EQ(2, result.balls);
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}