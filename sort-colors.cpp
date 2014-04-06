#include "header.h"

class Solution {
public:
    void sortColors(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int z = 0, o = 0, t = 0;
        for(int i = 0; i < n; i++) {
            if(A[i] == 0) z++;
            else if(A[i] == 1) o++;
            else t++;
        }
        for(int i = 0; i < n; i++) {
            if(i < z) A[i] = 0;
            else if(i < o + z) A[i] = 1;
            else A[i] = 2;
        }
    }
};

int main() {
}
