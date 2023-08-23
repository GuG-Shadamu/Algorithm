# -*- coding: utf-8 -*-
# @Author: Tairan Gao
# @Date:   2023-05-26 16:21:12
# @Last Modified by:   Tairan Gao
# @Last Modified time: 2023-05-26 17:04:16

from typing import List
from functools import lru_cache


class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        return self.helper(tuple(piles), 1)

    def get_piles(self, piles, x):
        if x >= len(piles):
            return sum(piles)

        return sum(piles[:x])

    @lru_cache
    def helper(self, piles_left_tuple, M):
        piles_left = list(piles_left_tuple)
        if not piles_left:
            return 0

        ret = 0
        for x in range(1, 2 * M + 1):
            cur_ret = self.get_piles(piles_left, x)
            next_M = max(M, x)
            next_ret = 0
            for next_x in range(1, 2 * next_M + 1):
                next_next_M = max(next_M, next_x)
                following_res = self.helper(
                    tuple(piles_left[x + next_x :]), next_next_M
                )
                next_ret = max(following_res, next_ret)

            ret = max(ret, cur_ret + next_ret)
        return ret


if __name__ == "__main__":
    s = Solution()
    print(s.stoneGameII([2, 7, 9, 4, 4]))
