#ifndef EXQUDENS_TESTS_HPP
#define EXQUDENS_TESTS_HPP

#include <iostream>
#include <map>
#include <string>

namespace exqudens {

  using std::ostream;
  using std::cout;
  using std::endl;
  using std::cerr;
  using std::string;
  using std::exception;
  using std::map;

  class tests {

    public:
    typedef void (* test)();

    public:
    static map<string, test> test_map();

    public:
    static int run(
        const int argc,
        const string argv[],
        ostream& out,
        ostream& error_out
    ) {
      map<string, test> map1 = test_map();

      int result = 0;

      if (argc < 2) {
        for (auto&[key, val] : map1) {
          int tmp_result = run_test(key, val, out, error_out);
          if (result == 0 && tmp_result != 0) {
            result = tmp_result;
          }
        }
      } else {
        for (int i = 1; i < argc; i++) {
          string key = argv[i];
          if (map1.contains(key)) {
            test val = map1[key];
            int tmp_result = run_test(key, val, out, error_out);
            if (result == 0 && tmp_result != 0) {
              result = tmp_result;
            }
          }
        }
      }

      return result;
    }

    public:
    static int run(
        int argc,
        char* argv[],
        ostream& out,
        ostream& error_out
    ) {
      string array[argc];

      for (int i = 1; i < argc; i++) {
        array[i] = string(argv[i]);
      }

      return run(argc, array, out, error_out);
    }

    public:
    static int run(
        int argc,
        char* argv[]
    ) {
      return run(argc, argv, cout, cerr);
    }

    public:
    static int run(
        ostream& out,
        ostream& error_out
    ) {
      map<string, test> map1 = test_map();

      int argc = map1.size() + 1;
      string array[argc];
      array[0] = "";

      int i = 1;
      for (auto&[key, val] : map1) {
        array[i] = key;
        i++;
      }

      return run(argc, array, out, error_out);
    }

    public:
    static int run() {
      return run(cout, cerr);
    }

    private:
    static int run_test(
        const string name,
        const test t,
        ostream& out,
        ostream& error_out
    ) {
      string passed = "PASSED";
      string failed = "FAILED";
      try {
        t();
        string header = string(name)
            .append(" ")
            .append(passed);
        out << header << endl;
      } catch (exception& e) {
        string header = string(10, '=')
            .append(" ")
            .append(name)
            .append(" ")
            .append(failed)
            .append(" ")
            .append(10, '=');

        error_out << header << endl;
        error_out << e.what() << endl;
        error_out << string(header.size(), '=');

        return 1;
      }

      return 0;
    }

  };

}

#endif // EXQUDENS_TESTS_HPP
