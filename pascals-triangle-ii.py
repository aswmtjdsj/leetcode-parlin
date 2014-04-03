class Solution:
    # @return a list of integers
    def getRow(self, rowIndex):
        ans = []
        p = [1]
        for i in range(1, 1000+1):
            p.append(p[i-1] * i)
        n = rowIndex
        for i in range(n+1):
            ans.append(p[n] / p[n-i] / p[i])
        return ans

a = Solution()
print a.getRow(100)
