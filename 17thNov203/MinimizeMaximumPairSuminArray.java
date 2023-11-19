import java.util.Arrays;

class Solution {
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);
        int maxi = Integer.MIN_VALUE;
        int n = nums.length;
        for (int i = 0; i < n / 2 + n % 2; i++) {
            maxi = Math.max(maxi, nums[i] + nums[n - i - 1]);
        }

        return maxi;
    }
}
public class MinimizeMaximumPairSuminArray {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = { 3, 5, 2, 3 };
        System.out.println(s.minPairSum(nums));
    }
}
