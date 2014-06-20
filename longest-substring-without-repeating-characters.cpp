class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int reg[200] = {0};
        int ans = 0;
        bool mark = true;
        int n = s.size();
        int i = 0, j = 0;
        while(j < n) {
            reg[s[j]]++;
            if(reg[s[j]] > 1) {
                while(reg[s[j]] > 1) {
                    reg[s[i]]--;
                    i++;
                }
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};
