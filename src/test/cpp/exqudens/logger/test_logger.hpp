#ifndef TEST_LOGGER_HPP
#define TEST_LOGGER_HPP

#include <sstream>
#include <string>

#include "exqudens/assertions.hpp"
#include "exqudens/logger.hpp"

namespace exqudens::test_logger {

  using std::ostringstream;
  using std::string;
  using exqudens::logger;

  void test_1() {
    ostringstream ostringstream1;
    string string1;

    logger::debug(ostringstream1, "aaa % %");
    string1 = ostringstream1.str();

    assertions::assert_equal("aaa % %\n", string1);
  }

  void test_2() {
    ostringstream ostringstream1;
    string string1;

    logger::debug(ostringstream1, "aaa % %", 1, 'c');
    string1 = ostringstream1.str();

    assertions::assert_equal("aaa 1 c\n", string1);
  }

}

#endif // TEST_LOGGER_HPP
