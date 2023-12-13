#include<bits/stdc++.h>
using namespace std;
/*
Problem name : 1464. Maximum Product of Two Elements in an Array
Problem link : https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
Problem link in GFG : https://practice.geeksforgeeks.org/problems/maximum-product-of-two-numbers/0

*/

class Solution {
public:
    int solveInNsq(vector<int>& nums){
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i = 0 ; i < n-1 ; i ++){
            for(int j = i + 1 ; j < n ; j ++){
                maxi = max(maxi,((nums[i]-1)*(nums[j]-1)));
            }
        }
        return maxi ;
    }
    int solveInNLogN(vector<int>&nums){
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int maxi = (nums[n-2]-1) * (nums[n-1]-1);
        return maxi ;
    }
    int solveInN(vector<int>&nums){
        int maxi1 = 0 ;
        int maxi2 = 0 ;

        for(int it : nums){
            if(it > maxi1){
                maxi2 = maxi1;
                maxi1 = it;
            } 
            else maxi2  = max(maxi2,it);
        }

        return ((maxi1-1)*(maxi2-1));
    }
    int maxProduct(vector<int>& nums) {
        return solveInN(nums);
    }
};