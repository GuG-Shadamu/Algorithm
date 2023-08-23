# -*- coding: utf-8 -*-
# @Author: Tairan Gao
# @Date:   2023-05-11 13:17:29
# @Last Modified by:   Tairan Gao
# @Last Modified time: 2023-05-11 14:53:58

from copy import deepcopy
from typing import List


class Solution:
    def __init__(self):
        self.res = []

    def calc_invalid(self, n, location):
        x, y = location
        invalid = set()
        for i in range(n + 1):
            invalid.add((i, y))
            invalid.add((x, i))

        for j in range(n):
            temp_x = x + j
            temp_y = y + j
            if 0 <= temp_x < n and 0 <= temp_y < n:
                invalid.add((temp_x, temp_y))

            temp_y = y - j
            if 0 <= temp_x < n and 0 <= temp_y < n:
                invalid.add((temp_x, temp_y))

        return invalid

    def solveNQueens(self, n: int) -> List[List[str]]:
        if n == 1:
            return [["Q"]]

        if n == 2 or n == 3:
            return []

        self.backTrack(n, 0, [], set())
        return len(self.res)

    def backTrack(self, n, idx, locations, invalid):
        if idx == n:
            self.res.append(locations)
            return

        for i in range(n):
            location = (idx, i)
            if location in invalid:
                continue
            new_invalid = deepcopy(invalid)
            new_invalid.update(self.calc_invalid(n, location))
            new_locations = deepcopy(locations)
            new_locations.append(location)
            self.backTrack(n, idx + 1, new_locations, new_invalid)


sol = Solution()
print(sol.solveNQueens(4))
