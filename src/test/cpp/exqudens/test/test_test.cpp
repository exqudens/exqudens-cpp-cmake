#include <iostream>

#include "exqudens/test/tests.hpp"

using std::cout;
using std::endl;
using std::cerr;

EXQUDENS_TEST(test_1) {
  cout << "test_1" << endl;
}

EXQUDENS_TEST(test_2) {
  cout << "test_2" << endl;
}

int main(int argc, char* argv[]) {
  //std::cout << "AAA: " << "name" << std::endl;
  //return 0;
  return exqudens::tests::run(argc, argv, cout, cerr, false);
}
