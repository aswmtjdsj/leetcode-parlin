#include "header.h"

class Solution {
    public:
        string multiply(string num1, string num2) {
            int l1 = num1.size(), l2 = num2.size();
            string ans = "0";
            for(int i = l1 - 1; i >= 0; i --) {
                string temp = smallMultiplyWithDigits(num1[i] - '0', num2, l1 - i - 1);
                ans = add(ans, temp);
            }
            return ans;
        }
        string smallMultiplyWithDigits(int small, string large, int digits) {
            int step = 0;
            int l = large.size();
            string ans;
            for(int i = l - 1; i >= 0; i --) {
                int temp = (large[i] - '0') * small + step;
                step = temp / 10;
                temp %= 10;
                ans += (temp + '0');
            }
            while(step > 0) {
                int temp = step;
                step = temp / 10;
                temp %= 10;
                ans += (temp + '0');
            }
            reverse(ans.begin(), ans.end());
            string zeroes(digits, '0');
            return (ans.size() == 0 && ans[0] == '0')? ans: ans + zeroes;
        }
        string add(string num1, string num2) {
            int l1 = num1.size(), l2 = num2.size();
            string ans;
            int i = l1 - 1, j = l2 - 1;
            int step = 0;
            while(i >= 0 && j >= 0) {
                int a = num1[i] - '0', b = num2[j] - '0';
                int temp = a + b + step;
                step = (temp > 9) ? 1: 0;
                temp %= 10;
                ans += (temp + '0');
                i--; j--;
            }
            while(i >= 0) {
                int a = num1[i] - '0';
                int temp = a + step;
                step = (temp > 9) ? 1: 0;
                temp %= 10;
                ans += (temp + '0');
                i--;
            }
            while(j >= 0) {
                int a = num2[j] - '0';
                int temp = a + step;
                step = (temp > 9) ? 1: 0;
                temp %= 10;
                ans += (temp + '0');
                j--;
            }
            if(step > 0) {
                ans += (step + '0');
                step = 0;
            }
            reverse(ans.begin(), ans.end());
            for(i = 0; i < ans.size(); i++) {
                if(ans[i] != '0') {
                    break;
                }
            }
            ans = ans.substr(i);
            if(ans.size() == 0) ans = "0";
            return ans;
        }
};

int main() {
    Solution a;
    cout << a.add("100", "23") << endl;
    cout << a.smallMultiplyWithDigits(11, "99", 2) << endl;
    cout << a.multiply("123", "456") << endl;
    cout << a.multiply("123", "0") << endl;
}
