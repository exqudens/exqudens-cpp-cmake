#include <iostream>

#include "other/tests.hpp"

using std::cout;
using std::endl;

EXQUDENS_TEST(test_1) {
  cout << "test_1" << std::endl;
}

EXQUDENS_TEST(test_2) {
  cout << "test_2" << std::endl;
}

int main(int argc, char* argv[]) {
  return other::tests::run(argc, argv);
}
