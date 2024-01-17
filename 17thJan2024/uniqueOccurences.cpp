#include<bits/stdc++.h>
using namespace std;
/*
Problem: Unique Number of Occurrences
Problem Link: https://leetcode.com/problems/unique-number-of-occurrences/
Given an array of integers arr, write a function that returns true if and only if the number of occurrences of each value in the array is unique.

*/
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        map<int, int> mp;

        // Step 1: Count occurrences of each element in the array
        for (int i = 0; i < n; i++)
            mp[arr[i]]++;

        set<int> st;

        // Step 2: Check if the number of occurrences is unique
        for (auto it : mp) {
            // Attempt to insert the count into the set
            if (!st.insert(it.second).second) {
                // If insertion fails (count already exists in the set), return false
                return false;
            }
        }

        // If the loop completes without returning false, all occurrences are unique
        return true;
    }
};
