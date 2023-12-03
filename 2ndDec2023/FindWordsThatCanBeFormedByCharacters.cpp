#include<bits/stdc++.h>
using namespace std;
/*
Problem name : Find Words That Can Be Formed by Characters
Problem link : https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
Explanation : 
    - We have to find the words that can be formed by the characters of the string chars.
    - We can use a map to store the frequency of the characters of the string chars.
    - Then we can iterate over the words and check if the frequency of the characters of the word is less than or equal to the frequency of the characters of the string chars.
    - If it is less than or equal to the frequency of the characters of the string chars then we can add the length of the word to the answer.
    - Time Complexity : O(n*m) where n is the number of words and m is the length of the longest word.
    - Space Complexity : O(n) where n is the number of words.
*/
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int n = words.size();
        unordered_map<char,int> mp1;
        for(auto it : chars){
            mp1[it] = 0;
        }
        for(auto it : chars){
            mp1[it]++;
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            unordered_map<char,int> mp2 ;
            bool flag = true;
            for(auto it : words[i]){
                mp2[it]++;
                if(mp2[it] > mp1[it]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans += words[i].size();
            }
        }
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    vector<string> words(n);
    for(int i = 0 ; i < n ; i++){
        cin >> words[i];
    }
    string chars;
    cin >> chars;
    Solution sol;
    cout << sol.countCharacters(words,chars) << endl;
    return 0;
}   
