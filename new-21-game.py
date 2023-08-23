# -*- coding: utf-8 -*-
# @Author: Tairan Gao
# @Date:   2023-05-26 11:28:08
# @Last Modified by:   Tairan Gao
# @Last Modified time: 2023-05-26 12:18:59


class Solution:
    def new21Game(self, n: int, k: int, maxPts: int) -> float:
        dp = [0 for i in range(k + maxPts)]
        for i in range(k + maxPts - 1, k - 1, -1):
            if i > n:
                dp[i] = 0
                continue

            if i >= k:
                dp[i] = 1
                continue

        temp_sum = max(0, n - k + 1)
        for i in range(k - 1, -1, -1):
            dp[i] = min(temp_sum / maxPts, 1)
            temp_sum += dp[i] - dp[i + maxPts]

        return dp[0]


if __name__ == "__main__":
    s = Solution()
    # print(s.new21Game(21, 17, 10))
    print(s.new21Game(185, 183, 2))
