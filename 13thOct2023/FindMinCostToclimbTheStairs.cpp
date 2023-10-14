#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bottomUpApproach(vector<int>& cost, int n) {
        // Step 1: Creation of table and base case 
        vector<int> dp(n + 1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i <= n; i++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        // Return the minimum cost of reaching the top
        return min(dp[n - 1], dp[n]);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        return bottomUpApproach(cost, size - 1);
    }
};
int main(int argc, char const *argv[])
{
    vector<int> ipVec={10,15,20};
    Solution obj ; 
    return obj.minCostClimbingStairs(ipVec);
}
