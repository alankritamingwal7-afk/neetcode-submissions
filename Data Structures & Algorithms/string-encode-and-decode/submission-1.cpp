#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // Encode: each string becomes "<len>#<string>"
    string encode(vector<string>& strs) {
        string final;
        for (auto &s : strs) {
            final += to_string(s.size()) + "#" + s;
        }
        return final;
    }

    // Decode: read length, then extract that many characters
    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') j++;  // find separator
            int len = stoi(s.substr(i, j - i));
            string str = s.substr(j + 1, len);
            result.push_back(str);
            i = j + 1 + len;
        }
        return result;
    }
};