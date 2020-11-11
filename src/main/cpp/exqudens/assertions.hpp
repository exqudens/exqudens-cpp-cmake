#ifndef EXQUDENS_ASSERTIONS_HPP
#define EXQUDENS_ASSERTIONS_HPP

#include <string>
#include <stdexcept>

namespace exqudens {

  using std::string;
  using std::to_string;
  using std::runtime_error;

  class assertions {

    public:
    static void assert_equal(
        const string& expected,
        const string& actual
    ) {
      assert_equal(
          expected,
          actual,
          string("'string1' not equal 'string2' expected: '")
              .append(expected)
              .append("' actual: '")
              .append(actual)
              .append("'")
      );
    }

    public:
    static void assert_equal(
        const int& expected,
        const int& actual
    ) {
      assert_equal(
          expected,
          actual,
          string("'int1' not equal 'int2' expected: '")
              .append(to_string(expected))
              .append("' actual: '")
              .append(to_string(actual))
              .append("'")
      );
    }

    public:
    static void assert_equal(
        const string& expected,
        const string& actual,
        const string& errorMessage
    ) {
      assert_true(expected == actual, errorMessage);
    }

    public:
    static void assert_equal(
        const int& expected,
        const int& actual,
        const string& errorMessage
    ) {
      assert_true(expected == actual, errorMessage);
    }

    public:
    static void assert_true(const bool& condition, const string& errorMessage) {
      if (!condition) {
        throw runtime_error(errorMessage);
      }
    }

    public:
    static void assert_false(const bool& condition, const string& errorMessage) {
      if (condition) {
        throw runtime_error(errorMessage);
      }
    }

  };

}

#endif // EXQUDENS_ASSERTIONS_HPP
