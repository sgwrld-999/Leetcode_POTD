#include<bits/stdc++.h>
using namespace std;
/*
Problem Name : Sort Vowels in a String
Problem Link : https://leetcode.com/problems/sort-vowels-of-a-string/
Problem Statement: Given a string s, sort the string in the following way:
Explanation :
We have to sort the vowels as Capital and Small letters and just the vowels.
So naive way is to store the vowels in a vector and sort it and then replace the vowels in the string with the sorted vector.
Time Complexity : O(nlogn) + O(n) = O(nlogn)
Space Complexity : O(n)

*/
class Solution {
public:
    string sortVowels(string ch) {
        vector<char> vowelsVec;

        for (int i = 0; i < ch.size(); i++) {
            char lowercaseChar = tolower(ch[i]);
            if (lowercaseChar == 'a' || lowercaseChar == 'e' || lowercaseChar == 'i' ||
                lowercaseChar == 'o' || lowercaseChar == 'u') {
                vowelsVec.push_back(ch[i]);
            }
        }

        sort(begin(vowelsVec), end(vowelsVec));

        int idx = 0;
        for (int i = 0; i < ch.size(); i++) {
            char lowercaseChar = tolower(ch[i]);
            if (lowercaseChar == 'a' || lowercaseChar == 'e' || lowercaseChar == 'i' ||
                lowercaseChar == 'o' || lowercaseChar == 'u') {
                ch[i] = vowelsVec[idx++];
            }
        }

        return ch;
    }
};

int main(){
    Solution sol;
    string ch = "LEetcOdE";
    cout << sol.sortVowels(ch) << endl;
    return 0;
}