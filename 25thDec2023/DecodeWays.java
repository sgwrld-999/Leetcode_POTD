import java.util.Arrays;
/*
 * Problem name : Decode Ways
 * Problem URL  : https://leetcode.com/problems/decode-ways/
 * Explanation  : 
 *              Thought process :
 *                              - We've to count all the possible ways to decode the given string which means we've to use the recursion.
 *                              - Next thing to notice is that we can take one or two characters at a time as we can decode the string such that the characters are mapped to 'A' to 'Z' means 1 to 26.
 *                              - Next thing is when the character is 1 then second char can be anything from 0 to 9.
 *                              - When the character is 2 then second char can be anything from 0 to 6.
 *                              - If the first character is 0 then we can't decode the string as 0 is not mapped to any character.
 *                              - Draw the recursion tree and you'll get the idea.
 *              Implementation part : 
 *                             - We'll start from the first character and check if it is 0 then we can't decode the string.
 *                             - If the first character is not 0 then we'll take one character at a time and check if we can decode the string.
 *                             - Then we'll take two characters at a time and check if we can decode the string.
 *                             - We'll add the result of both the cases and return the result.
 *                             - We'll use the memoization to optimize the solution.
 *             Time Complexity : O(n)
 *            Space Complexity : O(n)
 * 
 */
class Solution {
    public int countDecodings(int currentIndex, int length, String str) {
        if (currentIndex == length) return 1;
        if (str.charAt(currentIndex) == '0') return 0;

        int takeOne = countDecodings(currentIndex + 1, length, str);
        int takeTwo = 0;

        // Check if the current character is '1' or '2' and the next character is between '0' and '6' (inclusive)
        if (currentIndex + 1 < length && (str.charAt(currentIndex) == '1' || (str.charAt(currentIndex) == '2' && str.charAt(currentIndex + 1) >= '0' && str.charAt(currentIndex + 1) <= '6'))) {
            takeTwo = countDecodings(currentIndex + 2, length, str);
        }

        return takeOne + takeTwo;
    }

    public int countDecodingsMemo(int currentIndex, int length, String str, int[] dp) {
        if (currentIndex == length) return dp[currentIndex] = 1;
        if (dp[currentIndex] != -1) return dp[currentIndex];
        if (str.charAt(currentIndex) == '0') return dp[currentIndex] = 0;

        int takeOne = countDecodingsMemo(currentIndex + 1, length, str, dp);
        int takeTwo = 0;

        // Check if the current character is '1' or '2' and the next character is between '0' and '6' (inclusive)
        if (currentIndex + 1 < length && (str.charAt(currentIndex) == '1' || (str.charAt(currentIndex) == '2' && str.charAt(currentIndex + 1) >= '0' && str.charAt(currentIndex + 1) <= '6'))) {
            takeTwo = countDecodingsMemo(currentIndex + 2, length, str, dp);
        }

        return dp[currentIndex] = takeOne + takeTwo;
    }

    public int numDecodings(String s) {
        int length = s.length();
        int[] dp = new int[length + 1];
        Arrays.fill(dp, -1);
        return countDecodingsMemo(0, length, s, dp);
    }
}
