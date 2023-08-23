/*
 * @Author: Tairan Gao
 * @Date:   2023-06-08 22:16:46
 * @Last Modified by:   Tairan Gao
 * @Last Modified time: 2023-06-09 13:26:18
 */

#include <string>
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<int> lengths;
        unordered_set<string> words;
        for (const auto &word : wordDict)
        {
            lengths.insert(word.size());
            words.insert(word);
        }
        vector<bool> dp(s.size() + 1, false);
        helper(s, 0, dp, lengths, words);
        return dp[s.size()];
    }
    void helper(
        const string &s,
        int start,
        vector<bool> &dp,
        unordered_set<int> &lengths,
        unordered_set<string> &words)
    {
        dp[start] = true;

        for (const auto &len : lengths)
        {
            if (dp[s.size()])
                return;

            if (start + len > s.size())
                continue;

            string substr = s.substr(start, len);
            if (dp[start + len])
                continue;

            if (words.count(substr) > 0)
            {
                helper(s, start + len, dp, lengths, words);
                continue;
            }
        }
    }
};

int main()
{
    Solution s;
    string str = "aaaaaaaaa";
    vector<string> wordDict = {"a", "aa"};
    cout << s.wordBreak(str, wordDict) << endl;
    return 0;
}