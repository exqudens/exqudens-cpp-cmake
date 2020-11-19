#ifndef MY_MACRO_HPP
#define MY_MACRO_HPP

#include <vector>

using std::vector;

class test {

  public:
  virtual void call() = 0;

};

static vector<test*> all_tests;

#define EXQUDENS_TEST(test_class_name)\
\
class test_class_name : public test {\
\
  public:\
  void call() override;\
\
};\
\
struct test_class_name##_static_block {\
\
  test_class_name##_static_block() {\
    all_tests\
    .push_back(new test_class_name);\
  }\
\
};\
\
static test_class_name##_static_block test_class_name##_static_block;\
\
void test_class_name::call()

#endif // MY_MACRO_HPP
