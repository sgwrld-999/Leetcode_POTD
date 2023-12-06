#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sizeOfNum;
    int K ; 
    int solve(int prev,int curr,vector<int>& nums){
        if(curr >= sizeOfNum) return 0 ; //Base : destination or Out of bound
        
        int res = 0 ;
        if(prev == -1){
            int take     = nums[curr] + solve(curr,curr+1,nums);

            int not_take = solve(prev, curr + 1, nums);

            res = max(take,not_take);
        }
        else if(curr - prev <= K){
            int take     = nums[curr] + solve(curr,curr+1,nums);

            int not_take = solve(prev, curr + 1, nums);

            res = max(take,not_take);
        }
        return res;
    }
    int constrainedSubsetSum(vector<int>& nums, int k) {
       sizeOfNum = nums.size();
       K = k ;
       int check =  solve(-1,0,nums);
       if(check == 0){
            check = *max_element(begin(nums),end(nums));
       }
       return  check ;
    }
};

class Solution2 {
public:
    int sizeOfNum;
    int K ; 
    int solve(int prev, int curr, vector<int>& nums, vector<vector<int>>& dp) {
        if (curr >= sizeOfNum) return 0; // Base: destination or out of bound
        if (dp[prev + 1][curr] != -1) return dp[prev + 1][curr];
        int res = 0;
        if (prev == -1 || curr - prev <= K) {
            int take = nums[curr] + solve(curr, curr + 1, nums, dp);
            int not_take = solve(prev, curr + 1, nums, dp);
            res = max(take, not_take);
        }
        dp[prev + 1][curr] = res;
        return dp[prev + 1][curr];
    }

    int constrainedSubsetSum(vector<int>& nums, int k) {
       sizeOfNum = nums.size();
       K = k;
       vector<vector<int>> dp(sizeOfNum + 1, vector<int>(sizeOfNum, -1));
       int check = solve(-1, 0, nums, dp);
       
       if (check == 0) {
            check = *max_element(begin(nums), end(nums));
       }
       return check;
    }
};

int main() {
    vector<int> nums = {10, 2, 3, 5, -10 , -1};
    int k = 3;

    Solution sol1;
    int result1 = sol1.constrainedSubsetSum(nums, k);
    cout << "Result from Solution class: " << result1 << endl;

    Solution2 sol2;
    int result2 = sol2.constrainedSubsetSum(nums, k);
    cout << "Result from Solution2 class: " << result2 << endl;

    return 0;
}
