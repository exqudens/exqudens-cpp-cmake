#include <iostream>

#include "other/my_macro.hpp"

using std::cout;
using std::endl;

EXQUDENS_TEST(test_1) {
  std::cout << "test_1" << std::endl;
}

EXQUDENS_TEST(test_2) {
  std::cout << "test_2" << std::endl;
}

int main() {
  for (int i = 0; i < all_tests.size(); i++) {
    all_tests.at(i)->call();
  }
}

