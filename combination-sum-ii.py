# -*- coding: utf-8 -*-
# @Author: Tairan Gao
# @Date:   2023-05-11 13:17:29
# @Last Modified by:   Tairan Gao
# @Last Modified time: 2023-05-11 15:40:27

from copy import deepcopy
from typing import List


class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        candidates.sort()

        def dfs(idx, path, cur):
            if cur > target:
                return
            if cur == target:
                res.append(path)
                return
            for i in range(idx, len(candidates)):
                if i > idx and candidates[i] == candidates[i - 1]:
                    continue
                dfs(i + 1, path + [candidates[i]], cur + candidates[i])

        dfs(0, [], 0)
        return res


sol = Solution()
print(sol.combinationSum2([10, 1, 2, 7, 6, 1, 5], 8))
