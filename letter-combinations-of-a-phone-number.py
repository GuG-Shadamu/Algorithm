# -*- coding: utf-8 -*-
# @Author: Tairan Gao
# @Date:   2023-08-05 08:23:15
# @Last Modified by:   Tairan Gao
# @Last Modified time: 2023-08-05 08:37:56

from typing import List


class Solution:
    def __init__(self) -> None:
        self.letterDict = {
            2: ["a", "b", "c"],
            3: ["d", "e", "f"],
            4: ["g", "h", "i"],
            5: ["j", "k", "l"],
            6: ["m", "n", "o"],
            7: ["p", "q", "r", "s"],
            8: ["t", "u", "v"],
            9: ["w", "x", "y", "z"]
        }
        self.res = []
    
    def letterCombinations(self, digits: str) -> List[str]:
        self.backTrack(digits, 0, "")

        return self.res
    
    def backTrack(self, digits, ind, cur):
        if (ind == len(digits)):
            if cur:
                self.res.append(cur)
            return
        
        num = int(digits[ind])
        for letter in self.letterDict[num]:
            cur += letter
            self.backTrack(digits, ind + 1, cur)
            cur = cur[:-1]

    

if __name__ == "__main__":
    test = Solution()
    print(test.letterCombinations("23"))
    