/*
 * @Author: Tairan Gao
 * @Date:   2023-08-23 10:33:24
 * @Last Modified by:   Tairan Gao
 * @Last Modified time: 2023-08-23 11:18:42
 */

#include <vector>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

class Solution
{
public:
    string reorganizeString(string s)
    {
        vector<pair<int, int>> book(26, make_pair(0, 0));
        int max_num = 0;
        for (const auto &c : s)
        {
            book[c - 'a'].first += 1;
            book[c - 'a'].second = c;
            max_num = max(book[c - 'a'].first, max_num);
        }

        if (max_num > (s.size() + 1) / 2)
            return "";

        priority_queue<pair<int, int>> maxq; // max queue
        for (int i = 0; i < 26; i++)
        {
            if (book[i].first == 0)
                continue;
            maxq.push(book[i]);
        }
        int curr_ch = maxq.top().second;
        int curr_count = maxq.top().first;
        maxq.pop();

        for (int i = 0; i < s.size(); i += 2)
        {
            if (curr_count <= 0)
            {
                curr_ch = maxq.top().second;
                curr_count = maxq.top().first;
                maxq.pop();
            }
            curr_count -= 1;
            s[i] = static_cast<char>(curr_ch);
        }
        for (int i = 1; i < s.size(); i += 2)
        {
            if (curr_count <= 0)
            {
                curr_ch = maxq.top().second;
                curr_count = maxq.top().first;
                maxq.pop();
            }
            curr_count -= 1;
            s[i] = static_cast<char>(curr_ch);
        }
        cout << s << endl;
        return s;
    }
};

int main()
{
    Solution s;
    string str = "aabc";
    string sol = s.reorganizeString(str);
    cout << sol << endl;
    return 0;
}