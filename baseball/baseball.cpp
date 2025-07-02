#include <stdexcept>
#include <string>

using std::string;

class BaseballGame {
 public:
  void guess(const string& numbers) {
    if (numbers.length() != 3) {
      throw std::length_error("Must be three letters");
    }
    for (char num : numbers) {
      if (num < '0' || num > '9') {
        throw std::invalid_argument("Must be all numbers");
      }
    }
  }
};