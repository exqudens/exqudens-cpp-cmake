#include "exqudens/tests.hpp"
#include "exqudens/logger/test_logger.hpp"
#include "exqudens/strings/test_strings.hpp"

using std::string;
using std::map;
using test = exqudens::tests::test;

map<string, test> exqudens::tests::test_map() {
  map<string, test> map1;
  map1["exqudens_test_logger_test_1"] = exqudens::test_logger::test_1;
  map1["exqudens_test_logger_test_2"] = exqudens::test_logger::test_2;
  map1["exqudens_test_strings_test_1"] = exqudens::test_strings::test_1;
  map1["exqudens_test_strings_test_2"] = exqudens::test_strings::test_2;
  map1["exqudens_test_strings_test_3"] = exqudens::test_strings::test_3;
  map1["exqudens_test_strings_test_4"] = exqudens::test_strings::test_4;
  map1["exqudens_test_strings_test_5"] = exqudens::test_strings::test_5;
  map1["exqudens_test_strings_test_6"] = exqudens::test_strings::test_6;
  return map1;
}

int main(int argc, char* argv[]) {
  return exqudens::tests::run(argc, argv);
}
