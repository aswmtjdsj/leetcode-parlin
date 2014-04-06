#include "header.h"

class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x, obj = 0;
        while(temp > 0) {
            obj *= 10;
            obj += temp % 10;
            temp /= 10;
            
        }
        if(obj == x) {
            return true;
        }
        return false;
    }
};

int main() {
}
