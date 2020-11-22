#ifndef EXQUDENS_TESTS_HPP
#define EXQUDENS_TESTS_HPP

#include <string>
#include <vector>
#include <map>
#include <iostream>

#include "test.hpp"

namespace exqudens {

  using std::string;
  using std::vector;
  using std::map;
  using std::ostream;

  class tests {

    private:
    static map<string, test*> all;

    public:
    tests() = delete;

    public:
    static bool add(string name, test* t);

    public:
    static int run(
        vector<string> names,
        ostream& out,
        ostream& error_out,
        bool fail_fast
    );

    private:
    static int run_test(
        string name,
        test* t,
        ostream& out,
        ostream& error_out
    );

    public:
    static int run(
        int argc,
        char* argv[],
        ostream& out,
        ostream& error_out,
        bool fail_fast
    );

  };

}

#define EXQUDENS_TEST(test_class_name)\
\
class test_class_name : public exqudens::test {\
\
  public:\
  static const bool test_class_name##_initialized;\
\
  public:\
  void run() override;\
\
};\
\
const bool test_class_name##_initialized = exqudens::tests::add(#test_class_name, new test_class_name);\
\
void test_class_name::run()

#endif // EXQUDENS_TESTS_HPP
