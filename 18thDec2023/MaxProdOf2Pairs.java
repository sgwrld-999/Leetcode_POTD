
import java.util.Arrays;
/*
Problem name : Maximum Product Difference Between Two Pairs
Problem link : https://leetcode.com/problems/maximum-product-difference-between-two-pairs/
Problem Link GFG : 
Explanation : Sort the array and return the difference between the product of last two elements and the product of first two elements.
              Time Complexity : O(nlogn)
              Space Complexity : O(1)
              OR
              Find the maximum and second maximum element and minimum and second minimum element in the array.
              Return the difference between the product of maximum and second maximum element and the product of minimum and second minimum element.
              Time Complexity : O(n)
              Space Complexity : O(1)
 */ 
public class MaxProdOf2Pairs {
    class Solution {
        public int solveInNLogN(int[] nums){
            Arrays.sort(nums);
            int n = nums.length ;
            return ((nums[n-1]*nums[n-2]) - (nums[0] * nums[1]));
        }
        public int solveInN(int[] nums){
            int maxi1 = Integer.MIN_VALUE ;
            int maxi2 = Integer.MIN_VALUE ;
            int mini1 = Integer.MAX_VALUE ;
            int mini2 = Integer.MAX_VALUE ;
            for(int it : nums){
                if(it > maxi1){
                    maxi2 = maxi1 ;
                    maxi1 = it;
                }
                else if(it > maxi2) maxi2 = it ;
    
                if(it < mini1){
                    mini2= mini1 ;
                    mini1 = it ;
                }else if(mini2 > it) mini2 = it;
            }
    
            return (maxi1*maxi2) - (mini1*mini2);
        }
        public int maxProductDifference(int[] nums) {
            return solveInN(nums);
        }
    }
    
}
