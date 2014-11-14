class Solution {
public:
    int maxProduct(int A[], int n) {
        int ans = A[0], cur_max = A[0], cur_min = A[0];
        for(size_t i = 1; i < n; i++) {
            int prev_max = cur_max;
            cur_max = max(A[i], max(cur_max * A[i], cur_min * A[i]));
            cur_min = min(A[i], min(prev_max * A[i], cur_min * A[i]));
            ans = max(ans, cur_max);
        }
        return ans;
    }
};
