#include "header.h"

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // This isn't the most efficient way, the best way to do it is solving it from backward of A
        for(int i = m - 1; i >= 0; i--) {
            A[i + n] = A[i];
        }
        int i = n, j = 0;
        int cnt = 0;
        while(i < m + n && j < n) {
            if(A[i] < B[j]) {
                A[cnt++] = A[i];
                i++;
            }
            else {
                A[cnt++] = B[j];
                j++;
            }
        }
        while(i < m + n) {
            A[cnt++] = A[i++];
        }
        while(j < n) {
            A[cnt++] = B[j++];
        }
        return ;
    }
};

int main() {
}
