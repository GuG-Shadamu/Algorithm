# -*- coding: utf-8 -*-
# @Author: Tairan Gao
# @Date:   2023-06-19 10:16:35
# @Last Modified by:   Tairan Gao
# @Last Modified time: 2023-06-19 10:57:16


# Definition for singly-linked list.

from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        oddHead = head
        evenHead = ListNode()
        evenTrack = evenHead

        odd = oddHead

        while odd:
            even = None

            if odd.next:
                even = odd.next

            if even:
                evenHead.next = even
                evenHead = evenHead.next
                odd = even.next
                even.next = None
            else:
                break

        odd.next = evenTrack.next
        return head


if __name__ == "__main__":
    head = ListNode(
        1,
        ListNode(
            2,
            ListNode(
                3,
                ListNode(4, ListNode(5, ListNode(6, ListNode(7, ListNode(8))))),
            ),
        ),
    )
    Solution().oddEvenList(head)
