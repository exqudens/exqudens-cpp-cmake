#ifndef TEST_2_HPP
#define TEST_2_HPP

#include <iostream>

using std::runtime_error;
using std::cout;
using std::endl;

namespace test_2 {
  void run() {
    cout << "test_2.run()" << endl;
    //throw runtime_error("test_2.run() ERROR!");
  }
}

#endif // TEST_2_HPP
