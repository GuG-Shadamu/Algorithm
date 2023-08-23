# -*- coding: utf-8 -*-
# @Author: Tairan Gao
# @Date:   2023-05-29 10:47:43
# @Last Modified by:   Tairan Gao
# @Last Modified time: 2023-05-29 10:49:23

from typing import List


class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        last_max = arrays[0][-1]
        last_min = arrays[0][0]
        cur_max, cur_min = None, None
        ret = 0
        for i in range(1, len(arrays)):
            cur_max = arrays[i][-1]
            cur_min = arrays[i][0]
            ret = max(abs(cur_max - last_min), abs(last_max - cur_min), ret)
            last_max = max(last_max, cur_max)
            last_min = min(last_min, cur_min)

        return ret


if __name__ == "__main__":
    sol = Solution()
    print(
        sol.maxDistance(
            [[-8, -7, -7, -5, 1, 1, 3, 4], [-2], [-10, -10, -7, 0, 1, 3], [2]]
        )
    )
