#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    // This function takes in a vector of integers 'nums' and an integer 'k' as input.
    // It returns an integer which represents the maximum score of a good array.
    int maximumScore(vector<int>& nums, int k) {
        int sizeOfNums = nums.size();
        int leftIdxPtr = k;
        int rightIdxPtr = k;
        int currMin = nums[k];
        int res = nums[k];

        // This while loop runs until either the leftIdxPtr or the rightIdxPtr reaches the end of the array.
        while (leftIdxPtr > 0 || rightIdxPtr < sizeOfNums - 1) {
            // These two lines of code get the values of the elements to the left and right of the current subarray.
            int leftValue = (leftIdxPtr > 0) ? nums[leftIdxPtr - 1] : INT_MIN;
            int rightValue = (rightIdxPtr < sizeOfNums - 1) ? nums[rightIdxPtr + 1] : INT_MIN;

            // If the left element is greater than the right element, then we move the leftIdxPtr to the left.
            // We also update the currMin variable to be the minimum of the current minimum and the value of the new left element.
            // Otherwise, we move the rightIdxPtr to the right and update the currMin variable in the same way.
            if (leftValue > rightValue) {
                leftIdxPtr--;
                currMin = min(currMin, nums[leftIdxPtr]);
            } else {
                rightIdxPtr++;
                currMin = min(currMin, nums[rightIdxPtr]);
            }

            // We update the res variable to be the maximum of the current res and the product of the currMin and the length of the current subarray.
            res = max(res, currMin * (rightIdxPtr - leftIdxPtr + 1));
        }

        // Finally, we return the maximum score of the good array.
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,4,3,7,4,5};
    int k = 3;
    int maxScore = sol.maximumScore(nums, k);
    cout << "Maximum score of good array: " << maxScore << endl;
    return 0;
}
