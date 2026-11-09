
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string encode(vector<string>& arr) {
        string s = "";

        for (string str : arr) {
            s += to_string(str.length()) + "/" + str;
        }

        return s;
    }

    vector<string> decode(string& s) {
        vector<string> ans;
        int i = 0;

        while (i < s.length()) {
            int j = i;

            while (s[j] != '/') {
                j++;
            }

            int len = stoi(s.substr(i, j - i));

            string str = s.substr(j + 1, len);

            ans.push_back(str);

            i = j + 1 + len;
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<string> arr = {"Hello", "World"};

    
    string encoded = obj.encode(arr);

    cout << "Encoded String: " << encoded << endl;

    
    vector<string> decoded = obj.decode(encoded);

    cout << "Decoded Strings: ";

    for (string str : decoded) {
        cout << str << " ";
    }

    cout << endl;

    return 0;
}
