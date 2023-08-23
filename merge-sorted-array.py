# -*- coding: utf-8 -*-
# @Author: Tairan Gao
# @Date:   2023-05-29 11:33:41
# @Last Modified by:   Tairan Gao
# @Last Modified time: 2023-05-29 11:42:14
from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i, j = 0, 0
        while i < len(nums1) and j < len(nums2):
            if nums1[i] == 0:
                nums1[i] = nums2[j]
                i += 1
                j += 1
                continue

            if nums1[i] <= nums2[j]:
                i += 1
                continue

            if nums1[i] > nums2[j]:
                nums1[i], nums2[j] = nums2[j], nums1[i]
                i += 1
        return nums1


if __name__ == "__main__":
    sol = Solution()
    print(sol.merge([4, 5, 6, 0, 0, 0], 3, [1, 2, 3], 3))
