#include<bits/stdc++.h>
using namespace std;
/*
Problem name : Reduction Operations to Make the Array Elements Equal
Problem link : https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/

Explanation : 
    we have to convert all the elements of the array to a single element
    so we have to find the minimum element of the array and then we have to 
    and convert all the elements in the array.

    For that we'll use a greedy approach, we'll find the minimum element of the array.
    We will calculate the frequency of each element in the array and store it in a map.
    and reverse iterate the map and calculate the sum of the frequency of the elements.
    or except the first element of the map we'll add the frequency of the previous element
    to the sum and return the sum.
*/
class Solution {
public:
    int reductionOperations(std::vector<int>& nums) {
        int sizeOfNums = nums.size();
        map<int, int> mp;
        
        for (int i = 0; i < sizeOfNums; i++) {
            mp[nums[i]]++;
        }

        int sum = 0;
        int prevFreq = 0;
        //Using the iterator to reverse iterate the map and calculate the sum
        for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
            sum += prevFreq;
            prevFreq += it->second;
        }

        return sum;
    }
};