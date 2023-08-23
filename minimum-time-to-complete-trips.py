# -*- coding: utf-8 -*-
# @Author: Tairan Gao
# @Date:   2023-08-23 12:25:05
# @Last Modified by:   Tairan Gao
# @Last Modified time: 2023-08-23 12:44:21


import sys
from typing import List


class Solution:
    def calcBus(self, bus_costs, time):
        bus_trips = [time // x for x in bus_costs]
        return sum(bus_trips)

    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        if totalTrips == 0:
            return 0
        left = 0
        right = max(time) * totalTrips

        sol = right

        while left < right:
            mid = (left + right) // 2
            cur_trip = self.calcBus(time, mid)
            if cur_trip >= totalTrips:
                sol = min(sol, mid)

            if cur_trip >= totalTrips:
                right = mid
                continue
            if cur_trip < totalTrips:
                left = mid + 1
                continue

        return sol


if __name__ == "__main__":
    s = Solution()
    # print(s.minimumTime([1, 2, 3, 4], 10))
    # print(s.minimumTime([1, 2, 3, 4], 5))
    # print(s.minimumTime([1, 2, 3, 4], 3))
    # print(s.minimumTime([1, 2, 3, 4], 2))
    # print(s.minimumTime([1, 2, 3, 4], 1))
    # print(s.minimumTime([1, 2, 3, 4], 0))
    # print(s.minimumTime([1, 2, 3, 4], 20))
    print(s.minimumTime([2], 1))
