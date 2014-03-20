#include <header.h>

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(cnt >= 2 && A[cnt-1] == A[i] && A[cnt-2] == A[i]) {
                continue;
            }
            else {
                A[cnt++] = A[i];
            }
        }
        return cnt;
    }
};

int main() {
}
