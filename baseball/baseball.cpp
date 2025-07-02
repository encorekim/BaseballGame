#include <stdexcept>
#include <string>

using std::string;

class BaseballGame {
 public:
  void guess(const string& string) {
    throw std::length_error("Must be three letters");
  }
};