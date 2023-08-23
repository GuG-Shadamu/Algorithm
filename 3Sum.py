# -*- coding: utf-8 -*-
# @Author: Tairan Gao
# @Date:   2023-05-21 14:03:05
# @Last Modified by:   Tairan Gao
# @Last Modified time: 2023-05-21 14:08:42
from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ret = set()
        sol = []
        for idx, val in enumerate(nums):
            _ret = self.twoSum(nums[idx+1:], -val)
            if _ret:
                for x, y in _ret:
                    ret.add((val, x, y))
        
        for l in ret:
            sol.append(list(l))
        return sol


    def twoSum(self, nums, target):
        i, j = 0, len(nums)-1
        ret = []
        while i < j:
            x, y = nums[i], nums[j]
            if x + y == target:
                ret.append([x, y])
                j -= 1
                continue
            elif x + y > target:
                j -= 1
                continue
            else:
                i += 1
                continue
        
        return ret
        

if __name__ == '__main__':
    sol = Solution()
    print(sol.threeSum([-1,0,1,2,-1,-4]))
    