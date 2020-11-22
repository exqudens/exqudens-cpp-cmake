#ifndef OTHER_TESTS_HPP
#define OTHER_TESTS_HPP

#include <string>
#include <map>
#include <iostream>

namespace other {

  using std::string;
  using std::map;
  using std::ostream;
  using std::endl;
  using std::exception;
  using std::cout;
  using std::cerr;

  class test {

    public:
    virtual void run() = 0;

  };

  class tests {

    private:
    static map<string, test*> all;

    public:
    tests() = delete;

    public:
    static bool add(string name, test* t) {
      all[name] = t;
      return true;
    }

    public:
    static int run(
        const int argc,
        const string argv[],
        ostream& out,
        ostream& error_out,
        const bool fail_fast
    ) {
      int result = 0;

      if (argc < 2) {
        for (auto&[key, val] : all) {
          int tmp_result = run_test(key, val, out, error_out);
          if (result == 0 && tmp_result != 0) {
            result = tmp_result;
            if (fail_fast) {
              return result;
            }
          }
        }
      } else {
        for (int i = 1; i < argc; i++) {
          string key = argv[i];
          if (all.contains(key)) {
            test* val = all[key];
            int tmp_result = run_test(key, val, out, error_out);
            if (result == 0 && tmp_result != 0) {
              result = tmp_result;
              if (fail_fast) {
                return result;
              }
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
        ostream& error_out,
        bool fail_fast
    ) {
      string array[argc];

      for (int i = 1; i < argc; i++) {
        array[i] = string(argv[i]);
      }

      return run(argc, array, out, error_out, fail_fast);
    }

    public:
    static int run(
        int argc,
        char* argv[],
        ostream& out,
        ostream& error_out
    ) {
      return run(argc, argv, out, error_out, false);
    }

    public:
    static int run(
        int argc,
        char* argv[],
        bool fail_fast
    ) {
      return run(argc, argv, cout, cerr, fail_fast);
    }

    public:
    static int run(
        int argc,
        char* argv[]
    ) {
      return run(argc, argv, false);
    }

    public:
    static int run(
        ostream& out,
        ostream& error_out,
        bool fail_fast
    ) {
      int argc = (int) all.size() + 1;
      string array[argc];
      array[0] = "";

      int i = 1;
      for (auto&[key, val] : all) {
        array[i] = key;
        i++;
      }

      return run(argc, array, out, error_out, fail_fast);
    }

    public:
    static int run(
        ostream& out,
        ostream& error_out
    ) {
      return run(out, error_out, false);
    }

    public:
    static int run(bool fail_fast) {
      return run(cout, cerr, fail_fast);
    }

    public:
    static int run() {
      return run(false);
    }

    private:
    static int run_test(
        const string& name,
        test* t,
        ostream& out,
        ostream& error_out
    ) {
      string passed = "PASSED";
      string failed = "FAILED";
      try {
        t->run();
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

  map<string, test*> tests::all;

}

#define EXQUDENS_TEST(test_class_name)\
\
class test_class_name : public other::test {\
\
  public:\
  static const bool test_class_name##_initialized;\
\
  public:\
  void run() override;\
\
};\
\
const bool test_class_name##_initialized = other::tests::add(#test_class_name, new test_class_name);\
\
void test_class_name::run()

#endif // OTHER_TESTS_HPP
