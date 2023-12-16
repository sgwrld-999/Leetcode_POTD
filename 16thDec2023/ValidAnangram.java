
import java.util.HashMap;
import java.util.Map;
/*
 * Problem name : Valid Anagram
 * Problem link : https://leetcode.com/problems/valid-anagram/
 * Explanation  : Count the frequency of each character in both the strings and compare the maps.
 *                If the maps are equal then the strings are anagrams of each other.
 *                Time Complexity : O(n)
 *                Space Complexity : O(n)
 * 
 * 
 */

class Solution {
    public boolean isAnagram(String s, String t) {
         if (s.length() != t.length()) {
            return false;
        }

        Map<Character, Integer> map1 = new HashMap<>();
        Map<Character, Integer> map2 = new HashMap<>();

        for (char c : s.toCharArray()) {
            map1.put(c, map1.getOrDefault(c, 0) + 1);
        }

        for (char c : t.toCharArray()) {
            map2.put(c, map2.getOrDefault(c, 0) + 1);
        }

        return map1.equals(map2);
    }
}