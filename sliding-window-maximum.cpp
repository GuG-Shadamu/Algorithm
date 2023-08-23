/*
 * @Author: Tairan Gao
 * @Date:   2023-08-16 14:17:11
 * @Last Modified by:   Tairan Gao
 * @Last Modified time: 2023-08-16 14:29:38
 */

#include <vector>
#include <iostream>
#include <deque>

using namespace std;

template <typename T>
class MonotoniceQueue
{
private:
    size_t size;

public:
    deque<T> queue;
    MonotoniceQueue()
    {
        size = 0;
    }

    T get_max()
    {
        return queue.front();
    }

    void push_back(T element)
    {
        while (size > 0)
        {
            if (queue.back() < element)
            {
                queue.pop_back();
                size -= 1;
            }
            else
            {
                break;
            }
        }
        queue.push_back(element);
        size += 1;
    }

    void pop_max()
    {
        queue.pop_front();
        size -= 1;
    }
};

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {

        MonotoniceQueue<int> queue;
        for (int i = 0; i < k; i++)
        {
            queue.push_back(nums[i]);
        }
        vector<int> sol({queue.get_max()});
        for (int i = k; i < nums.size(); i++)
        {
            int left = i - k;
            if (queue.get_max() == nums[left])
            {
                queue.pop_max();
            }
            queue.push_back(nums[i]);
            sol.push_back(queue.get_max());
        }
        return sol;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1};
    int k = 1;

    vector<int> res = s.maxSlidingWindow(nums, k);

    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;
}