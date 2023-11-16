/*
Problem Name : Find Unique Binary String
Problem Link : https://leetcode.com/problems/find-unique-binary-string/
Explanation : 

Checking at the ith position of each string, if it is 0 then append 1 to the result string else append 0.


*/

class Solution {
    public String findDifferentBinaryString(String[] nums) {
        StringBuilder sb = new StringBuilder();

        for(int i = 0 ; i < nums.length ; i++){
            sb.append(nums[i].charAt(i) == '0' ? "1" : "0" );
        }
        return new String(sb);
    }
}
public class FindUniqueBinaryString {
    public static void main(String[] args) {
        Solution s = new Solution();
        String[] nums = {"111","011","001"};
        System.out.println(s.findDifferentBinaryString(nums));
    }
}