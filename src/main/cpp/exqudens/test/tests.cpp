#include "tests.hpp"

namespace exqudens {

  using std::endl;
  using std::exception;

  map<string, test*> tests::all;

  bool tests::add(string name, test* t) {
    all[name] = t;
    return true;
  }

  int tests::run(
      vector<string> names,
      ostream& out,
      ostream& error_out,
      bool fail_fast
  ) {
    int result = 0;

    if (names.empty()) {
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
      for (int i = 1; i < names.size(); i++) {
        string key = names.at(i);
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

  int tests::run(
      int argc,
      char** argv,
      ostream& out,
      ostream& error_out,
      bool fail_fast
  ) {
    vector<string> names;
    for (int i = 1; i < argc; i++) {
      string name = string(argv[i]);
      names.push_back(name);
    }
    return run(names, out, error_out, fail_fast);
  }

  int tests::run_test(string name, test* t, ostream& out, ostream& error_out) {
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

}
