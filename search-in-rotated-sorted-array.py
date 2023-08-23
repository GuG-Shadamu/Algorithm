# -*- coding: utf-8 -*-
# @Author: Tairan Gao
# @Date:   2023-08-08 10:09:13
# @Last Modified by:   Tairan Gao
# @Last Modified time: 2023-08-08 11:00:42

from typing import Optional, List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        while left <= right:
            mid = (right + left) // 2

            if nums[mid] == target:
                return mid

            if nums[mid] < nums[left]:
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
                continue

            if nums[mid] > nums[right]:
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
                continue

            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        return -1


if __name__ == "__main__":
    sol = Solution()
    print(sol.search([4, 5, 6, 7, 8, 1, 2, 3], 1))
