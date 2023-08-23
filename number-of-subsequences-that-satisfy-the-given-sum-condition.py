# -*- coding: utf-8 -*-
# @Author: Tairan Gao
# @Date:   2023-06-06 15:08:13
# @Last Modified by:   Tairan Gao
# @Last Modified time: 2023-06-06 15:14:04


from typing import List


class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        nums.sort()
        l = 0
        r = len(nums) - 1
        res = 0
        mod = 10**9 + 7
        while l <= r:
            if nums[l] + nums[r] > target:
                r -= 1
            else:
                res += pow(2, r - l, mod)
                l += 1
        return res % mod


if __name__ == "__main__":
    nums = [2, 3, 3, 4, 6, 7]
    target = 12
    output = Solution().numSubseq(nums, target)
    print(output)
