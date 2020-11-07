#ifndef STRINGS_CPP
#define STRINGS_CPP

#include <string>
#include <vector>

namespace exqudens {

  using std::string;
  using std::pair;
  using std::make_pair;
  using std::vector;

  class strings {
    public:
      static vector<pair<int, string>> diff(string string1, string string2, bool includeEqual) {
        int string1Size;
        int string2Size;
        int string1MaxIndex;
        int string2MaxIndex;
        int indexMax;
        vector<pair<int, string>> vector;

        string1Size = string1.size();
        string2Size = string2.size();
        string1MaxIndex = string1Size - 1;
        string2MaxIndex = string2Size - 1;
        indexMax = string1Size >= string2Size ? string1MaxIndex : string2MaxIndex;

        for (int i = 0; i <= indexMax; i++) {

          bool string1ContainsIndex;
          bool string2ContainsIndex;
          char char1;
          char char2;
          int vectorSize;
          int vectorMaxIndex;

          string1ContainsIndex = string1MaxIndex >= i;
          string2ContainsIndex = string2MaxIndex >= i;

          char1 = string1ContainsIndex ? string1[i] : '\0';
          char2 = string2ContainsIndex ? string2[i] : '\0';

          vectorSize = vector.size();
          vectorMaxIndex = vectorSize - 1;

          if (string1ContainsIndex && string2ContainsIndex) {
            if (char1 == char2 && includeEqual) {

              if (
                  vectorMaxIndex >= 0
                  && 0 == vector.at(vectorMaxIndex).first
              ) {
                vector.at(vectorMaxIndex).second.append(1, char1);
              } else {
                vector.push_back(make_pair(0, string(1, char1)));
              }

            } else if (char1 != char2) {

              if (
                  vectorMaxIndex >= 1
                  && 1 == vector.at(vectorMaxIndex - 1).first
                  && 2 == vector.at(vectorMaxIndex).first
              ) {
                vector.at(vectorMaxIndex - 1).second.append(1, char1);
                vector.at(vectorMaxIndex).second.append(1, char2);
              } else {
                vector.push_back(make_pair(1, string(1, char1)));
                vector.push_back(make_pair(2, string(1, char2)));
              }

            }
          } else if (string1ContainsIndex) {

            if (
                vectorMaxIndex >= 0
                && 1 == vector.at(vectorMaxIndex).first
            ) {
              vector.at(vectorMaxIndex).second.append(1, char1);
            } else {
              vector.push_back(make_pair(1, string(1, char1)));
            }

          } else if (string2ContainsIndex) {

            if (
                vectorMaxIndex >= 0
                && 2 == vector.at(vectorMaxIndex).first
            ) {
              vector.at(vectorMaxIndex).second.append(1, char2);
            } else {
              vector.push_back(make_pair(2, string(1, char2)));
            }

          }

        }

        return vector;
      }

      static vector<pair<int, string>> diff(string string1, string string2) {
        return diff(string1, string2, false);
      }
  };

}

#endif