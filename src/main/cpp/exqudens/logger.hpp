#ifndef EXQUDENS_LOGGER_HPP
#define EXQUDENS_LOGGER_HPP

#include <iostream>
#include <sstream>
#include <string>

#define EXQUDENS_LOGGER_HPP_DEBUG

namespace exqudens {

  using std::string;
  using std::ostream;
  using std::ostringstream;
  using std::cout;
  using std::endl;

  class logger {

    public:
    static void debug(const string& message) {
#ifdef EXQUDENS_LOGGER_HPP_DEBUG
      debug(cout, message);
#endif
    }

    public:
    template <typename T, typename... TYPES>
    static void debug(const string& format, const T argument, const TYPES& ... arguments) {
#ifdef EXQUDENS_LOGGER_HPP_DEBUG
      debug(cout, format, argument, arguments...);
#endif
    }

    public:
    static void debug(ostream& stream, const string& message) {
      ostringstream ostringstream1;
      fill_stream(ostringstream1, message);
      string string1 = ostringstream1.str();
      stream << string1 << endl;
    }

    public:
    template <typename T, typename... TYPES>
    static void debug(ostream& stream, const string& format, const T argument, const TYPES& ... arguments) {
      ostringstream ostringstream1;
      fill_stream(ostringstream1, format, argument, arguments...);
      string string1 = ostringstream1.str();
      stream << string1 << endl;
    }

    private:
    static void fill_stream(ostream& stream, const string& message) {
      stream << message;
    }

    private:
    template <typename T, typename... TYPES>
    static void fill_stream(ostream& stream, const string& format, const T argument, const TYPES& ... arguments) {
      for (int i = 0; i < format.size(); i++) {
        if ('%' == format[i]) {
          stream << argument;
          fill_stream(stream, format.substr(i + 1, format.size()), arguments...);
          return;
        }
        stream << format[i];
      }
    }

  };

}

#endif // EXQUDENS_LOGGER_HPP
