#include "exqudens/tests.hpp"

namespace exqudens::test_tests {
  int run_args_executed = 0;
  int run_executed = 0;

  void run_args() {
    run_args_executed++;
  }

  void run() {
    run_executed++;
  }
}

using std::string;
using std::map;
using test = exqudens::tests::test;

map<string, test> exqudens::tests::test_map() {
  map<string, test> map1;
  map1["exqudens_test_tests_run_args"] = exqudens::test_tests::run_args;
  map1["exqudens_test_tests_run"] = exqudens::test_tests::run;
  return map1;
}
