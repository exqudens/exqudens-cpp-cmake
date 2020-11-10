#ifndef TEST_STRINGS_HPP
#define TEST_STRINGS_HPP

#include <string>
#include <vector>

#include "../../../main/cpp/exqudens/strings.hpp"
#include "../assertions.hpp"

namespace exqudens::test_strings {

  using std::string;
  using std::vector;
  using std::pair;
  using exqudens::strings;
  using exqudens::assertions;

  void test_1() {
    string part1 = "ABC";
    string part2 = "DE";
    string part3 = "YZ";
    string part4 = "FJ";

    string string1 = part1 + part2 + part4;
    string string2 = part1 + part3 + part4;
    vector<pair<int, string>> vector = strings::diff(string1, string2, true);

    assertions::assert_equal(4, vector.size());
    assertions::assert_equal(0, vector.at(0).first);
    assertions::assert_equal(1, vector.at(1).first);
    assertions::assert_equal(2, vector.at(2).first);
    assertions::assert_equal(0, vector.at(3).first);
    assertions::assert_equal(part1, vector.at(0).second);
    assertions::assert_equal(part2, vector.at(1).second);
    assertions::assert_equal(part3, vector.at(2).second);
    assertions::assert_equal(part4, vector.at(3).second);
  }

  void test_2() {
    string part1 = "ABCYZFJ";
    string part2 = "---111";
    string string1 = part1;
    string string2 = part1 + part2;
    vector<pair<int, string>> vector = strings::diff(string1, string2, true);

    assertions::assert_equal(2, vector.size());
    assertions::assert_equal(0, vector.at(0).first);
    assertions::assert_equal(2, vector.at(1).first);
    assertions::assert_equal(string1, vector.at(0).second);
    assertions::assert_equal(part2, vector.at(1).second);
  }

  void test_3() {
    string part1 = "ABC";
    string part2 = "DE";
    string part3 = "YZ";
    string part4 = "FJ";

    string string1 = part1 + part2 + part4;
    string string2 = part1 + part3 + part4;
    vector<pair<int, string>> vector = strings::diff(string1, string2);

    assertions::assert_equal(2, vector.size());
    assertions::assert_equal(1, vector.at(0).first);
    assertions::assert_equal(2, vector.at(1).first);
    assertions::assert_equal(part2, vector.at(0).second);
    assertions::assert_equal(part3, vector.at(1).second);
  }

  void test_4() {
    string part1 = "ABCYZFJ";
    string part2 = "---111";
    string string1 = part1;
    string string2 = part1 + part2;
    vector<pair<int, string>> vector = strings::diff(string1, string2);

    assertions::assert_equal(1, vector.size());
    assertions::assert_equal(2, vector.at(0).first);
    assertions::assert_equal(part2, vector.at(0).second);
  }

  void test_5() {
    string string1 = "";
    string string2 = "ABCYZFJ";
    vector<pair<int, string>> vector = strings::diff(string1, string2);

    assertions::assert_equal(1, vector.size());
    assertions::assert_equal(2, vector.at(0).first);
    assertions::assert_equal(string2, vector.at(0).second);
  }

  void test_6() {
    string string1 = "ABCYZFJ";
    string string2 = "";
    vector<pair<int, string>> vector = strings::diff(string1, string2);

    assertions::assert_equal(1, vector.size());
    assertions::assert_equal(1, vector.at(0).first);
    assertions::assert_equal(string1, vector.at(0).second);
  }

}

#endif // TEST_STRINGS_HPP
