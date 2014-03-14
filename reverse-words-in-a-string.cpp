#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        void reverseWords(string &s) {
            stringstream is(s);
            vector<string> vec;
            string temp;
            while(is >> temp) {
                vec.push_back(temp);
            }
            s = "";
            for(int i = vec.size() - 1; i >= 0; i--) {
                s += vec[i];
                if(i!=0) s += " ";
            }
            cout << s << endl;
        }
};

int main() {
    Solution a;
    string b("the sky is blue");
    a.reverseWords(b);
}
