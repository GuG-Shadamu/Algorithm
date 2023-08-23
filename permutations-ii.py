# -*- coding: utf-8 -*-
# @Author: Tairan Gao
# @Date:   2023-05-11 13:17:29
# @Last Modified by:   Tairan Gao
# @Last Modified time: 2023-05-11 15:54:55

from copy import deepcopy
from typing import List


class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()

        def helper(used, path):
            if len(path) == len(nums):
                res.append(path)
                return

            for idx, val in enumerate(nums):
                if idx in used:
                    continue
                if idx > 0 and nums[idx] == nums[idx - 1] and idx - 1 not in used:
                    continue

                used.add(idx)
                helper(used, path + [val])
                used.remove(idx)

        helper(set(), [])
        return res


sol = Solution()
print(sol.permuteUnique([1, 1, 2]))
