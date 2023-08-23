# -*- coding: utf-8 -*-
# @Author: Tairan Gao
# @Date:   2023-08-23 11:43:43
# @Last Modified by:   Tairan Gao
# @Last Modified time: 2023-08-23 12:13:14


# UNFINISHED!!!!!!!!!!!!!!!!!!!!
from typing import List


class Solution:
    def findMedian(self, nums):
        n = len(nums)
        if n % 2 == 0:
            return (nums[(n - 1) // 2] + nums[n // 2]) / 2
        else:
            return nums[int((n - 1) // 2)]

    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if not nums1:
            return self.findMedian(nums2)
        if not nums2:
            return self.findMedian(nums1)

        n1 = len(nums1)
        n2 = len(nums2)
        if n1 < n2:
            return self.findMedianSortedArrays(nums2, nums1)
        k = (n1 + n2 + 1) // 2

        left = 0
        right = n1

        while left < right:
            m1 = int((left + right) // 2)
            m2 = k - m1

            left_mid = nums1[m1 - 1]
            right_mid = nums2[m2 - 1]

            if left_mid < right_mid:
                left = m1 + 1
                continue

            if left_mid > right_mid:
                right = m1 - 1
                continue

            break

        median_left = max(left_mid, right_mid)
        median_right = min(nums1[m1], nums2[m2])
        if (n1 + n2) % 2 == 0:  # even
            return (median_left + median_right) / 2
        else:
            return median_left


if __name__ == "__main__":
    s = Solution()
    # print(s.findMedianSortedArrays([1, 2, 3, 3], [2, 3]))
    # print(s.findMedianSortedArrays([1, 2], [3, 4]))
    # print(s.findMedianSortedArrays([0, 0], [0, 0]))
    # print(s.findMedianSortedArrays([], [1]))
    # print(s.findMedianSortedArrays([2], []))
    # print(s.findMedianSortedArrays([1, 2, 3, 4, 5], [6, 7, 8, 9, 10]))
    print(s.findMedianSortedArrays([1], [2, 3]))
    # print(s.findMedianSortedArrays([1, 2, 3, 4, 5], [6, 7, 8, 9, 10, 11]))
    # print(s.findMedianSortedArrays([1, 2, 3, 4, 5], [6, 7, 8, 9, 10, 11, 12]))
    # print(s.findMedianSortedArrays([1, 2, 3, 4, 5], [6, 7, 8, 9, 10, 11, 12, 13]))
    # print(s.findMedianSortedArrays([1, 2, 3, 4, 5], [6, 7, 8, 9, 10, 11, 12, 13, 14]))
    # print(
    #     s.findMedianSortedArrays([1, 2, 3, 4, 5], [6, 7, 8, 9, 10, 11, 12, 13, 14, 15])
    # )
    # print(
    #     s.findMedianSortedArrays(
    #         [1, 2, 3, 4, 5], [6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]
    #     )
    # )
    # print(
    #     s.findMedianSortedArrays(
    #         [1, 2, 3, 4, 5], [6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17]
    #     )
    # )
    # print(
    #     s.findMedianSortedArrays(
    #         [1, 2, 3, 4, 5], [6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18]
    #     )
    # )
    # print(
    #     s.findMedianSortedArrays(
    #         [1, 2, 3, 4, 5], [6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19]
    #     )
    # )
