/*
 * @Author: Tairan Gao
 * @Date:   2024-01-08 12:05:34
 * @Last Modified by:   Tairan Gao
 * @Last Modified time: 2024-01-08 15:06:42
 */


#include <unordered_map>
#include <map>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <queue>
#include <numeric>
#include <utility>



class Solution {
public:


    int jobScheduling(std::vector<int>& startTime, std::vector<int>& endTime,
        std::vector<int>& profit) {
        using pi = std::pair<int, int>;
        // Create a vector of indices
        std::vector<int> indices(startTime.size());
        std::iota(indices.begin(), indices.end(), 0); // Fill with 0, 1, 2, ...

        // Custom comparator for sorting indices based on startTime
        auto cmp = [&startTime, &endTime](int a, int b) {
            if (startTime[a] == startTime[b]) {
                return endTime[a] < endTime[b];
            }
            return startTime[a] < startTime[b];
            };
        std::sort(indices.begin(), indices.end(), cmp);

        // Reorder startTime, endTime, and profit based on the sorted indices
        std::vector<int> sortedStartTime(startTime.size());
        std::vector<int> sortedEndTime(endTime.size());
        std::vector<int> sortedProfit(profit.size());

        for (size_t i = 0; i < indices.size(); ++i) {
            sortedStartTime[i] = startTime[indices[i]];
            sortedEndTime[i] = endTime[indices[i]];
            sortedProfit[i] = profit[indices[i]];
        }

        std::priority_queue<pi, std::vector<pi>, std::greater<pi>> pq;
        int cur_profit = 0;

        int idx = 0;
        while (true) {
            if (pq.empty()) {
                if (idx == sortedStartTime.size()) {
                    break;
                }
                pq.emplace(sortedEndTime[idx], cur_profit + sortedProfit[idx]);
                idx++;
                continue;
            }
            if (idx < sortedStartTime.size() && pq.top().first > sortedStartTime[idx]) {
                pq.emplace(sortedEndTime[idx], cur_profit + sortedProfit[idx]);
                idx++;
                continue;
            }
            else { //pq.front() <= startTime[idx]
                cur_profit = std::max(pq.top().second, cur_profit);
                pq.pop();
            }
        }

        return cur_profit;
    }
};


int main()
{
    Solution s;
    std::vector<int> startTime{ 1,1,1 };
    std::vector<int> endTime{ 2,3,4 };
    std::vector<int> profit{ 5,6,4 };
    std::cout << s.jobScheduling(startTime, endTime, profit) << std::endl;
    return 0;
}