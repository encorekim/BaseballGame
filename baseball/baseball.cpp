#include <stdexcept>
#include <string>

using std::string;

struct GuessResult {
  bool solved;
  int strikes;
  int balls;
};

class BaseballGame {
 public:
  explicit BaseballGame(const string& question) : question{question} {}
  GuessResult guess(const string& numbers) { assertIllegalArgument(numbers);
    if (numbers == question) {
      return {true, 3, 0};
    } else {
      return {false, 0, 3};
    }
  }

 private:
  string question = nullptr;
  bool isDuplicated(const std::string& numbers) {
    return numbers[0] == numbers[1] || numbers[1] == numbers[2] ||
           numbers[0] == numbers[2];
  }

  void assertIllegalArgument(const std::string& numbers) {
    if (numbers.length() != 3) {
      throw std::length_error("Must be three letters");
    }
    for (char num : numbers) {
      if (num < '0' || num > '9') {
        throw std::invalid_argument("Must be all numbers");
      }
    }
    if (isDuplicated(numbers)) {
      throw std::invalid_argument("Must not have duplicated numbers");
    }
  }
};