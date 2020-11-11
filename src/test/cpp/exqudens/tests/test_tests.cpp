#include <string>
#include <stdexcept>
#include <iostream>
#include <sstream>

#include "test_implementation_tests.hpp"

using std::to_string;
using std::exception;
using std::runtime_error;
using std::ostringstream;
using std::cerr;
using std::cout;
using std::endl;

void exqudens_test_tests_test_1();
void exqudens_test_tests_test_2();

int main(int argc, char* argv[]) {
  if (argc >= 2) {

    string name = string(argv[1]);

    if ("exqudens_test_tests_test_1" == name) {
      try {
        exqudens_test_tests_test_1();
        return 0;
      } catch (exception& e) {
        cerr << e.what() << endl;
        return 1;
      }
    } else if ("exqudens_test_tests_test_2" == name) {
      try {
        exqudens_test_tests_test_2();
        return 0;
      } catch (exception& e) {
        cerr << e.what() << endl;
        return 1;
      }
    }

  }

  cerr << "no tests selected" << endl;
  return 1;
}

void exqudens_test_tests_test_1() {
  string error;

  if (
      exqudens::test_tests::run_args_executed == 0
      && exqudens::test_tests::run_executed == 0
    ) {

    string names[2] = {"tests", "exqudens_test_tests_run_args"};
    ostringstream out;
    ostringstream error_out;

    exqudens::tests::run(2, names, out, error_out);

    if (
        exqudens::test_tests::run_args_executed == 1
        && exqudens::test_tests::run_executed == 0
    ) {
      return;
    }

    error = string(__FUNCTION__)
        .append(" check 2")
        .append(" run_args_executed: '")
        .append(to_string(exqudens::test_tests::run_args_executed))
        .append("', run_executed: '")
        .append(to_string(exqudens::test_tests::run_executed))
        .append("'");
    throw runtime_error(error);

  }

  error = string(__FUNCTION__)
      .append(" check 1")
      .append(" run_args_executed: '")
      .append(to_string(exqudens::test_tests::run_args_executed))
      .append("', run_executed: '")
      .append(to_string(exqudens::test_tests::run_executed))
      .append("'");
  throw runtime_error(error);
}

void exqudens_test_tests_test_2() {
  string error;

  if (
      exqudens::test_tests::run_args_executed == 0
      && exqudens::test_tests::run_executed == 0
  ) {

    ostringstream out;
    ostringstream error_out;

    exqudens::tests::run(out, error_out);

    if (
        exqudens::test_tests::run_args_executed == 1
        && exqudens::test_tests::run_executed == 1
    ) {
      return;
    }

    error = string(__FUNCTION__)
        .append(" check 2")
        .append(" run_args_executed: '")
        .append(to_string(exqudens::test_tests::run_args_executed))
        .append("', run_executed: '")
        .append(to_string(exqudens::test_tests::run_executed))
        .append("'");
    throw runtime_error(error);

  }

  error = string(__FUNCTION__)
      .append(" check 1")
      .append(" run_args_executed: '")
      .append(to_string(exqudens::test_tests::run_args_executed))
      .append("', run_executed: '")
      .append(to_string(exqudens::test_tests::run_executed))
      .append("'");
  throw runtime_error(error);
}
