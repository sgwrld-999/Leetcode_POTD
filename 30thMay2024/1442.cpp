#include<bits/stdc++.h>
using namespace std;

/*
Problem link on leetcode : https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/
Problem link on geeksforgeeks : https://practice.geeksforgeeks.org/problems/count-triplets-with-xor-equal-to-xor-of-rest-of-array3136/1
Explanation : 
We've to find the tripplet whicch can form two arrays of equal xor.
Basic Approach : Do what it said.
Three iterators i, j, k with conditon 0 <= i < j <= k < size of array.

For these three we need to check if xor of i to j-1 is equal to xor of j to k.
As said to the question 
three loops 
    1. Outer loop 
        Will be from 0 to j-1 and initializing the array a.
    2. Middle loop
        Calculate the xor of array element to a.
        Initialize the array b.
    3. Inner loop
        Calculate the xor of array element to b.
        If the xor of a and b is equal then increment the count.

Time Complexity : O(n^3)
Space Complexity : O(1)
*/

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int sizeOfArr = arr.size();

        int ctr = 0 ;

        for(int i = 0 ; i < sizeOfArr - 1 ; i++){
            int a = 0 ;

            for(int j = i + 1 ; j < sizeOfArr ; j++){
                a ^= arr[j-1];

                int b = 0 ;
                

                for(int k = j ; k < sizeOfArr ; k++){
                    b ^= arr[k];

                    if(a == b) ctr++;
                }
            }
        }
        return ctr;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {2,3,1,6,7};
    cout << sol.countTriplets(arr) << endl;
    return 0;
}