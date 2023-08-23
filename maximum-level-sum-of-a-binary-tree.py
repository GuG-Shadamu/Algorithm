# -*- coding: utf-8 -*-
# @Author: Tairan Gao
# @Date:   2023-08-05 10:03:34
# @Last Modified by:   Tairan Gao
# @Last Modified time: 2023-08-05 10:18:47
from typing import Optional
from collections import deque


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        max_sum = root.val
        max_level = 1

        queue = deque([(root, 1)])

        cur_level = 0
        cur_sum = max_sum

        while queue:
            node, level = queue.popleft()
            if level != cur_level:
                if cur_sum > max_sum:
                    max_level = cur_level
                    max_sum = cur_sum

                cur_level = level
                cur_sum = 0

            cur_sum += node.val
            if node.left:
                queue.append((node.left, level + 1))
            if node.right:
                queue.append((node.right, level + 1))

        if cur_sum > max_sum:
            max_level = cur_level

        return max_level


if __name__ == "__main__":
    sol = Solution()
    print(
        sol.maxLevelSum(
            TreeNode(
                989,
                None,
                TreeNode(
                    10250, TreeNode(98693, None, TreeNode(-32127)), TreeNode(-89388)
                ),
            )
        )
    )
