#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        if (n != m) return false;

        map<char, int> map1;
        map<char, int> map2;

        for (char ch : word1) {
            map1[ch]++;
        }

        for (char ch : word2) {  
            map2[ch]++;
        }

        int s = 1e5;
        vector<int> vec(s);
        for (auto it : map1) vec[it.second]++;
        for (auto it : map2) vec[it.second]++;

        for (auto it : vec) {
            if (it % 2 != 0) return false; 
        }

        return true;
    }
};

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> hash1(26, 0);
        vector<int> hash2(26, 0);
        set<char> set1;
        set<char> set2;

        for (char ch : word1) {
            hash1[ch - 'a']++;
            set1.insert(ch);
        }

        for (char ch : word2) {
            hash2[ch - 'a']++;
            set2.insert(ch);
        }

        sort(begin(hash1), end(hash1));
        sort(begin(hash2), end(hash2));

        return (hash1 == hash2 && set1 == set2);
    }
};
