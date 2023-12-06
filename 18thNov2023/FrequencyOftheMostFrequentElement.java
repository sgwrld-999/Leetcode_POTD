import java.util.* ;
/*
    * 1838. Frequency of the Most Frequent Element
    * https://leetcode.com/problems/frequency-of-the-most-frequent-element/
    * Explanation : 
        Sort the array.  
        For each element, find the maximum frequency of the element by traversing the array from the end.  
        Return the maximum frequency.
        Time complexity : O(nlogn) + O(n^2) = O(n^2)
        Space complexity : O(n)
 */
class Solution1 {
    public int maxFrequency(int[] nums, int k) {
        Arrays.sort(nums);
        int sizeOfNums = nums.length;
        int[] ans = new int[sizeOfNums];

        for (int i = sizeOfNums - 1; i >= 0; i--) {
            int temp = k;
            int j = i - 1;
            int ctr = 1;

            while (j >= 0 && nums[i] - nums[j] <= temp && temp > 0) {
                ctr++;
                temp -= (nums[i] - nums[j]);
                j--;
            }

            ans[i] = ctr;
        }

        int max = Integer.MIN_VALUE;
        for (int i = 0; i < sizeOfNums; i++) {
            max = Math.max(max, ans[i]);
        }

        return max;
    }
}

class Solution2 {
    public int maxFrequency(int[] nums, int k) {
        
        int maxFrequency = 0;
        long currentSum = 0;

        Arrays.sort(nums);

        for (int left = 0, right = 0; right < nums.length; ++right) {
            
            currentSum += nums[right];
            
            while (currentSum + k < (long) nums[right] * (right - left + 1)) {
            
                currentSum -= nums[left];
                left++;
            
            }
            
            maxFrequency = Math.max(maxFrequency, right - left + 1);
        }

        return maxFrequency;
    }
}

public class FrequencyOftheMostFrequentElement {
    public static void main(String[] args) {
        Solution1 s1 = new Solution1();
        Solution2 s2 = new Solution2();
        int[] nums = { 1, 2, 4 };
        int k = 5;
        System.out.println(s1.maxFrequency(nums, k));
        System.out.println(s2.maxFrequency(nums, k));
    }
}
