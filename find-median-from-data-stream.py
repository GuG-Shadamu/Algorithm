# -*- coding: utf-8 -*-
# @Author: Tairan Gao
# @Date:   2023-08-20 22:16:09
# @Last Modified by:   Tairan Gao
# @Last Modified time: 2023-08-21 13:52:37

import heapq


class MedianFinder:
    def __init__(self):
        self.upper = []
        self.lower = []

    def addNum(self, num: int) -> None:
        if len(self.upper) == 0:
            heapq.heappush(self.upper, num)
            return

        if len(self.lower) == 0:
            if num <= self.upper[0]:
                heapq.heappush(self.lower, -num)
            else:
                exchange = heapq.heappop(self.upper)
                heapq.heappush(self.lower, -exchange)
                heapq.heappush(self.upper, num)
            return

        if len(self.upper) <= len(self.lower):
            if num >= -self.lower[0]:
                heapq.heappush(self.upper, num)
                return

            else:
                exchange = -heapq.heappop(self.lower)
                heapq.heappush(self.upper, exchange)
                heapq.heappush(self.lower, -num)
                return

        if len(self.upper) > len(self.lower):
            if num <= self.upper[0]:
                heapq.heappush(self.lower, -num)
                return
            else:
                exchange = heapq.heappop(self.upper)
                heapq.heappush(self.lower, -exchange)
                heapq.heappush(self.upper, num)
                return

    def findMedian(self) -> float:
        if len(self.upper) > len(self.lower):
            return self.upper[0]
        else:
            return (self.upper[0] + -self.lower[0]) / 2


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()

if __name__ == "__main__":
    test = MedianFinder()
    test.addNum(40)
    print(test.findMedian())
    test.addNum(12)
    print(test.findMedian())
    test.addNum(16)
    print(test.findMedian())
    test.addNum(14)
    print(test.findMedian())
    test.addNum(35)
    print(test.findMedian())
    test.addNum(19)
    print(test.findMedian())
    test.addNum(34)
    print(test.findMedian())
    test.addNum(35)
    print(test.findMedian())
