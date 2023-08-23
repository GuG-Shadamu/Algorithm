/*"+", "-", "*", "/", "(", ")"
 * @Author: Tairan Gao
 * @Date:   2023-06-07 13:35:28
 * @Last Modified by:   Tairan Gao
 * @Last Modified time: 2023-06-07 15:15:08
 */

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        auto it = s.begin();
        return helper(s, it);
    }

    int helper(const string &s, string::iterator &it)
    {

        stack<int> nums;
        bool neg = false;
        int num = 0;
        int res = 0;

        set<char>
            operators({'+', '-', ')', '('});

        while (it < s.end())
        {
            char ch = *it;
            if (ch == ' ')
            {
                it += 1;
                continue;
            }

            if (operators.find(ch) == operators.end())
            {
                num *= 10;
                num += (ch - '0');
                it += 1;
                continue;
            }

            num = neg ? -num : num;
            nums.push(num);
            num = 0;

            switch (ch)
            {
            case '+':
                neg = false;
                break;

            case '-':
                neg = true;
                break;

            case '(':
                it += 1;
                num = helper(s, it);
                break;

            case ')':
                while (!nums.empty())
                {
                    res += nums.top();
                    nums.pop();
                }
                return res;
            }

            it += 1;
        }
        num = neg ? -num : num;
        nums.push(num);
        while (!nums.empty())
        {
            res += nums.top();
            nums.pop();
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.calculate("(1 + 1)") << endl;
    cout << s.calculate(" 2-(1 + 2) ") << endl;
    cout << s.calculate("((5)-3)+ (3-(12) + 7) - 3333") << endl;
    return 0;
}
