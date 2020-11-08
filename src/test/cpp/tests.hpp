#ifndef TESTS_HPP
#define TESTS_HPP

#include <iostream>
#include <map>
#include <string>

namespace exqudens {

  using std::cout;
  using std::endl;
  using std::cerr;
  using std::string;
  using std::exception;
  using std::map;

  class tests {

    public:
    typedef void (*test)();

    public:
    static map<string, test> test_map();

    public:
    static int run(int argc, char* argv[]) {
      map<string, test> map1 = test_map();

      int result = 0;

      for (int i = 1; i < argc; i++) {
        string key = string(argv[i]);
        if (map1.contains(key)) {
          test val = map1[key];
          int tmp_result = run_test(key, val);
          if (result == 0 && tmp_result != 0) {
            result = tmp_result;
          };
        }
      }

      return result;
    }

    public:
    static int run() {
      map<string, test> map1 = test_map();

      int result = 0;

      for (auto& [key, val] : map1) {
        int tmp_result = run_test(key, val);
        if (result == 0 && tmp_result != 0) {
          result = tmp_result;
        };
      }

      return result;
    }

    private:
    static int run_test(string name, test t) {
      try {
        t();
      } catch (exception& e) {
        string header = string(10, '=')
            .append(" ")
            .append(name)
            .append(" ")
            .append(10, '=');

        cerr << header << endl;
        cerr << e.what() << endl;
        cerr << string(header.size(), '=');

        return 1;
      }

      return 0;
    }

  };

}

#endif // TESTS_HPP
