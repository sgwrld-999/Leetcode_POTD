import java.util.HashMap;
import java.util.Map;
/*
 * Problem name : Min Operations to Make Array Empty
 * Problem Link : https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/
 * Explanation  : 
 *              - Intituion : Greedy approach is used to solve this problem.
 *              - Approach :
 *                 Why greedy approach ? Becuase we need to find the minimum steps to make the array empty. 
 *                 Why greedy approach will work ? Because we need to find the minimum steps to make the array empty in 
 *                 such a way that will cost minimun steps that can be done when we pick the elements in trio. But one thing to notice is
 *                 that we can't pick the elements in trio if there is only one element in the array or 2 element frequency.
 *                 Since there are only 3 kinds of numbers wrt to 3n, 3n+1 and 3n+2.
 *                 If the frequency is 3n+1 we've subtract 4 from the frequency and add 2 to the result to make it 3n.
 *                 If the frequency is 3n+2 we've subtract 2 from the frequency and add 1 to the result to make it 3n+1.
 * 
 */
class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;

        Map<Integer, Integer> frequencyMap = new HashMap<>();

        // Count the frequency of each element
        for (int num : nums) {
            frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
        }

        int result = 0;

        // Calculate operations based on frequency
        for (int freq : frequencyMap.values()) {
            if (freq == 1) {
                return -1; // If there is any element with frequency 1, it's not possible
            }

            result += Math.ceil((double) freq / 3);
        }

        return result;
    }
}
