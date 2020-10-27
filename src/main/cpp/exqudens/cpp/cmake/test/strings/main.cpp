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

void test1() {
  string string1 = "ABCDEFJ";
  string string2 = "ABCYZFJ";

  cout << "===" << endl;
  cout << "string1: " << string1 << endl;
  cout << "string2: " << string2 << endl;
  cout << "---" << endl;
  vector<pair<int, string>> vector = Strings::diff(string1, string2);
  for (int i = 0; i < vector.size(); i++) {
    string operation;

    if (0 == vector.at(i).first) {
      operation = "EQUAL";
    } else if (1 == vector.at(i).first) {
      operation = "DELETE";
    } else if (2 == vector.at(i).first) {
      operation = "INSERT";
    }

    cout << operation << ": " << vector.at(i).second << endl;
  }
  cout << "===" << endl;
}

void test2() {
  string string1 = "";
  string string2 = "ABCYZFJ";

  cout << "===" << endl;
  cout << "string1: " << string1 << endl;
  cout << "string2: " << string2 << endl;
  cout << "---" << endl;
  vector<pair<int, string>> vector = Strings::diff(string1, string2);
  for (int i = 0; i < vector.size(); i++) {
    string operation;

    if (0 == vector.at(i).first) {
      operation = "EQUAL";
    } else if (1 == vector.at(i).first) {
      operation = "DELETE";
    } else if (2 == vector.at(i).first) {
      operation = "INSERT";
    }

    cout << operation << ": " << vector.at(i).second << endl;
  }
  cout << "===" << endl;
}

void test3() {
  string string1 = "ABCYZFJ";
  string string2 = "";

  cout << "===" << endl;
  cout << "string1: " << string1 << endl;
  cout << "string2: " << string2 << endl;
  cout << "---" << endl;
  vector<pair<int, string>> vector = Strings::diff(string1, string2);
  for (int i = 0; i < vector.size(); i++) {
    string operation;

    if (0 == vector.at(i).first) {
      operation = "EQUAL";
    } else if (1 == vector.at(i).first) {
      operation = "DELETE";
    } else if (2 == vector.at(i).first) {
      operation = "INSERT";
    }

    cout << operation << ": " << vector.at(i).second << endl;
  }
  cout << "===" << endl;
}

void test4() {
  string string1 = "ABCYZFJ";
  string string2 = "ABCYZFJ---111";

  cout << "===" << endl;
  cout << "string1: " << string1 << endl;
  cout << "string2: " << string2 << endl;
  cout << "---" << endl;
  vector<pair<int, string>> vector = Strings::diff(string1, string2);
  for (int i = 0; i < vector.size(); i++) {
    string operation;

    if (0 == vector.at(i).first) {
      operation = "EQUAL";
    } else if (1 == vector.at(i).first) {
      operation = "DELETE";
    } else if (2 == vector.at(i).first) {
      operation = "INSERT";
    }

    cout << operation << ": " << vector.at(i).second << endl;
  }
  cout << "===" << endl;
}

int main() {
  //test1();
  //test2();
  //test3();
  test4();
  return 0;
}
