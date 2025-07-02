#include <iostream>
#include <stdexcept>
#include <string>

#include "baseball.cpp"
#include "gmock/gmock.h"

using std::string;

TEST(Baseball, WrongInput) {
  BaseballGame game;
  EXPECT_THROW(game.guess(string("12")), std::length_error);
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}