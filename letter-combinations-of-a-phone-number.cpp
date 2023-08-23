/*
 * @Author: Tairan Gao
 * @Date:   2023-08-05 08:38:30
 * @Last Modified by:   Tairan Gao
 * @Last Modified time: 2023-08-05 09:18:38
 */

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if (digits.empty())
            return res;

        unordered_map<int, string> dict;
        dict = {{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
        string cur(digits.size(), ' ');
        backTrack(digits, 0, cur, dict, res);

        return res;
    }

    void backTrack(string &digits, int idx, string cur, unordered_map<int, string> &dict, vector<string> &res)
    {
        if (cur.back() != ' ')
        {
            res.push_back(cur);
            return;
        }

        int num = digits[idx] - '0';
        for (auto const &letter : dict[num])
        {
            cur[idx] = letter;
            backTrack(digits, idx + 1, cur, dict, res);
        }
        return;
    }
};

int main()
{
    Solution s;
    string digits = "23";
    vector<string> res = s.letterCombinations(digits);

    for (auto const &str : res)
    {
        cout << str << endl;
    }

    return 0;
}