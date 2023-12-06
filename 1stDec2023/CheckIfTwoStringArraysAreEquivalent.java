/*
    Problem name : Check If Two String Arrays are Equivalent
    Problem Link : https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
    Explanation :
    Just simply concatenate all the strings in both the arrays and compare them. If they are equal then return true else false at any point 
    if they mismatch return false.
 */
class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        StringBuilder sb1 = new StringBuilder();
        StringBuilder sb2 = new StringBuilder();
        
        for (int i = 0; i < word1.length; i++) {
            for (int j = 0; j < word1[i].length(); j++) {
                sb1.append(word1[i].charAt(j));
            }
        }
        
        for (int i = 0; i < word2.length; i++) {
            for (int j = 0; j < word2[i].length(); j++) {
                sb2.append(word2[i].charAt(j));
            }
        }
        
        if (sb1.length() != sb2.length()) return false;

        for (int i = 0; i < sb1.length(); i++) {
            if (sb1.charAt(i) != sb2.charAt(i)) return false;
        }

        return true;
    }
}

public class CheckIfTwoStringArraysAreEquivalent {
    public static void main(String[] args) {
        Solution sol = new Solution();
        String[] word1 = {"ab", "c"};
        String[] word2 = {"a", "bc"};
        System.out.println(sol.arrayStringsAreEqual(word1, word2));
    }
}