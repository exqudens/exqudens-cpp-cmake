#include <iostream> // std::cout
#include <string>   // std:string
#include <vector>   // std::vector
#include "../../util/Strings.cpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;
using std::make_pair;
using exqudens::cpp::cmake::util::Strings;

void test01() {
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
  } else {
    cout << failed << endl;
    cout << string(header.size(), '-') << endl;
    cout << "string1: " << string1 << endl;
    cout << "string2: " << string2 << endl;
  }

  cout << string(header.size(), '=') << endl;
}

void test02() {
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
  } else {
    cout << failed << endl;
    cout << string(header.size(), '-') << endl;
    cout << "string1: " << string1 << endl;
    cout << "string2: " << string2 << endl;
  }

  cout << string(header.size(), '=') << endl;
}

void test03() {
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
  } else {
    cout << failed << endl;
    cout << string(header.size(), '-') << endl;
    cout << "string1: " << string1 << endl;
    cout << "string2: " << string2 << endl;
  }

  cout << string(header.size(), '=') << endl;
}

void test04() {
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
      2 == vector.size()
      && 0 == vector.at(0).first
      && 2 == vector.at(1).first
      && string1 == vector.at(0).second
      && part2 == vector.at(1).second
  ) {
    cout << passed << endl;
  } else {
    cout << failed << endl;
    cout << string(header.size(), '-') << endl;
    cout << "string1: " << string1 << endl;
    cout << "string2: " << string2 << endl;
  }

  cout << string(header.size(), '=') << endl;
}

int main() {
  test01();
  test02();
  test03();
  test04();
  return 0;
}
