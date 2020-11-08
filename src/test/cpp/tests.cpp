#include "tests.hpp"
#include "test_1.hpp"
#include "test_2.hpp"

using std::string;
using std::map;
using test = exqudens::tests::test;

map<string, test> exqudens::tests::test_map() {
  map<string, test> map1;
  map1["test_1_run"] = test_1::run;
  map1["test_2_run"] = test_2::run;
  return map1;
}
