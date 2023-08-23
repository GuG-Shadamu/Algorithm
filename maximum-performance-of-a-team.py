# -*- coding: utf-8 -*-
# @Author: Tairan Gao
# @Date:   2023-05-24 15:09:13
# @Last Modified by:   Tairan Gao
# @Last Modified time: 2023-05-24 15:39:31
import heapq
import sys
from typing import List


class Solution:
    def maxPerformance(
        self, n: int, speed: List[int], efficiency: List[int], k: int
    ) -> int:
        res = 0
        a = zip(speed, efficiency)
        b = sorted(a, key=lambda x: x[1], reverse=True)
        hp = []
        min_val = sys.maxsize
        sum = 0
        for i in range(n):
            min_val = min(min_val, b[i][1])

            if len(hp) > k - 1:
                poped = heapq.heappop(hp)
                sum -= poped

            heapq.heappush(hp, b[i][0])
            sum += b[i][0]
            res = max(res, sum * min_val)

        return res


if __name__ == "__main__":
    sol = Solution()
    print(sol.maxPerformance(3, [2, 8, 2], [2, 7, 1], 2))
