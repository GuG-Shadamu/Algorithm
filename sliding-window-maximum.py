# -*- coding: utf-8 -*-
# @Author: Tairan Gao
# @Date:   2023-08-16 13:56:52
# @Last Modified by:   Tairan Gao
# @Last Modified time: 2023-08-16 14:16:12
from collections import deque
from typing import List


class MonotonicQueue:
    def __init__(self) -> None:
        self.queue = deque([])
        self.size = 0

    def push_back(self, element) -> None:
        while self.size > 0:
            if self.queue[-1] < element:
                self.queue.pop()
                self.size -= 1

            else:
                break
        self.queue.append(element)
        self.size += 1

    def get_max(self):
        return self.queue[0]

    def pop_max(self):
        self.queue.popleft()
        self.size -= 1


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        queue = MonotonicQueue()
        for i in range(k):
            queue.push_back(nums[i])

        sol = [queue.get_max()]

        for i in range(k, len(nums)):
            left = i - k
            if nums[left] == queue.get_max():
                queue.pop_max()
            queue.push_back(nums[i])
            sol.append(queue.get_max())

        return sol


if __name__ == "__main__":
    sol = Solution()
    nums = [1]
    k = 1
    print(sol.maxSlidingWindow(nums, k))
