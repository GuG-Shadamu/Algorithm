# -*- coding: utf-8 -*-
# @Author: Tairan Gao
# @Date:   2023-06-19 18:12:55
# @Last Modified by:   Tairan Gao
# @Last Modified time: 2023-06-19 18:29:28

from typing import Optional, List

import heapq


class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        for i, task in enumerate(tasks):
            task.append(i)
        tasks = sorted(tasks)
        cur = tasks[0][0]
        queue = []
        res = []

        for i in range(len(tasks)):
            task = tasks[i]
            start = task[0]
            duration = task[1]
            idx = task[2]

            while start > cur and queue:
                _, _, to_do = heapq.heappop(queue)
                cur = cur + to_do[1]
                res.append(to_do[2])

            if start > cur:
                cur = start

            heapq.heappush(queue, (duration, idx, task))

        while queue:
            _, idx, to_do = heapq.heappop(queue)
            cur = cur + to_do[1]
            res.append(idx)

        return res


if __name__ == "__main__":
    tasks = [[5, 2], [7, 2], [9, 4], [6, 3], [5, 10], [1, 1]]
    print(Solution().getOrder(tasks))
