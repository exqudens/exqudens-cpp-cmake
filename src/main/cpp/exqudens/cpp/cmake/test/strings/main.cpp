#include <iostream>
#include <string>
#include <vector>

#include "../../util/Strings.cpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;
using std::make_pair;
using exqudens::cpp::cmake::util::Strings;

bool test01() {
  bool result = false;
  string header = string(10, '=').append(" ").append(__FUNCTION__).append(" ").append(10, '=');
  string passed = "PASSED";
  string failed = "FAILED";
  cout << header << endl;

  string part1 = "ABC";
  string part2 = "DE";
  string part3 = "YZ";
  string part4 = "FJ";

  string string1 = part1 + part2 + part4;
  string string2 = part1 + part3 + part4;
  vector<pair<int, string>> vector = Strings::diff(string1, string2, true);

  if (
      4 == vector.size()
      && 0 == vector.at(0).first
      && 1 == vector.at(1).first
      && 2 == vector.at(2).first
      && 0 == vector.at(3).first
      && part1 == vector.at(0).second
      && part2 == vector.at(1).second
      && part3 == vector.at(2).second
      && part4 == vector.at(3).second
  ) {
    cout << passed << endl;
    result = true;
  } else {
    cout << failed << endl;
    cout << string(header.size(), '-') << endl;
    cout << "string1: " << string1 << endl;
    cout << "string2: " << string2 << endl;
    result = false;
  }

  cout << string(header.size(), '=') << endl;
  return result;
}

bool test02() {
  bool result = false;
  string header = string(10, '=').append(" ").append(__FUNCTION__).append(" ").append(10, '=');
  string passed = "PASSED";
  string failed = "FAILED";
  cout << header << endl;

  string part1 = "ABCYZFJ";
  string part2 = "---111";
  string string1 = part1;
  string string2 = part1 + part2;
  vector<pair<int, string>> vector = Strings::diff(string1, string2, true);

  if (
      2 == vector.size()
      && 0 == vector.at(0).first
      && 2 == vector.at(1).first
      && string1 == vector.at(0).second
      && part2 == vector.at(1).second
  ) {
    cout << passed << endl;
    result = true;
  } else {
    cout << failed << endl;
    cout << string(header.size(), '-') << endl;
    cout << "string1: " << string1 << endl;
    cout << "string2: " << string2 << endl;
    result = false;
  }

  cout << string(header.size(), '=') << endl;
  return result;
}

bool test03() {
  bool result = false;
  string header = string(10, '=').append(" ").append(__FUNCTION__).append(" ").append(10, '=');
  string passed = "PASSED";
  string failed = "FAILED";
  cout << header << endl;

  string part1 = "ABC";
  string part2 = "DE";
  string part3 = "YZ";
  string part4 = "FJ";

  string string1 = part1 + part2 + part4;
  string string2 = part1 + part3 + part4;
  vector<pair<int, string>> vector = Strings::diff(string1, string2);

  if (
      2 == vector.size()
      && 1 == vector.at(0).first
      && 2 == vector.at(1).first
      && part2 == vector.at(0).second
      && part3 == vector.at(1).second
  ) {
    cout << passed << endl;
    result = true;
  } else {
    cout << failed << endl;
    cout << string(header.size(), '-') << endl;
    cout << "string1: " << string1 << endl;
    cout << "string2: " << string2 << endl;
    result = false;
  }

  cout << string(header.size(), '=') << endl;
  return result;
}

bool test04() {
  bool result = false;
  string header = string(10, '=').append(" ").append(__FUNCTION__).append(" ").append(10, '=');
  string passed = "PASSED";
  string failed = "FAILED";
  cout << header << endl;

  string part1 = "ABCYZFJ";
  string part2 = "---111";
  string string1 = part1;
  string string2 = part1 + part2;
  vector<pair<int, string>> vector = Strings::diff(string1, string2);

  if (
      1 == vector.size()
      && 2 == vector.at(0).first
      && part2 == vector.at(0).second
  ) {
    cout << passed << endl;
    result = true;
  } else {
    cout << failed << endl;
    cout << string(header.size(), '-') << endl;
    cout << "string1: " << string1 << endl;
    cout << "string2: " << string2 << endl;
    result = false;
  }

  cout << string(header.size(), '=') << endl;
  return result;
}

bool test05() {
  bool result = false;
  string header = string(10, '=').append(" ").append(__FUNCTION__).append(" ").append(10, '=');
  string passed = "PASSED";
  string failed = "FAILED";
  cout << header << endl;

  string string1 = "";
  string string2 = "ABCYZFJ";
  vector<pair<int, string>> vector = Strings::diff(string1, string2);

  if (
      1 == vector.size()
      && 2 == vector.at(0).first
      && string2 == vector.at(0).second
  ) {
    cout << passed << endl;
    result = true;
  } else {
    cout << failed << endl;
    cout << string(header.size(), '-') << endl;
    cout << "string1: " << string1 << endl;
    cout << "string2: " << string2 << endl;
    result = false;
  }

  cout << string(header.size(), '=') << endl;
  return result;
}

bool test06() {
  bool result = false;
  string header = string(10, '=').append(" ").append(__FUNCTION__).append(" ").append(10, '=');
  string passed = "PASSED";
  string failed = "FAILED";
  cout << header << endl;

  string string1 = "ABCYZFJ";
  string string2 = "";
  vector<pair<int, string>> vector = Strings::diff(string1, string2);

  if (
      1 == vector.size()
      && 1 == vector.at(0).first
      && string1 == vector.at(0).second
  ) {
    cout << passed << endl;
    result = true;
  } else {
    cout << failed << endl;
    cout << string(header.size(), '-') << endl;
    cout << "string1: " << string1 << endl;
    cout << "string2: " << string2 << endl;
    result = false;
  }

  cout << string(header.size(), '=') << endl;
  return result;
}

int main() {

  typedef bool (*TestFunction)();

  vector<TestFunction> tests;

  tests.push_back(test01);
  tests.push_back(test02);
  tests.push_back(test03);
  tests.push_back(test04);
  tests.push_back(test05);
  tests.push_back(test06);

  int result = 0;

  for (int i = 0; i < tests.size(); i++) {
    bool testResult = tests.at(i)();
    if (result == 0 && !testResult) {
      result = 1;
    }
  }

  return result;
}
