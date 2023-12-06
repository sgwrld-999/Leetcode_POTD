#include<bits/stdc++.h>
using namespace std;
/*
Problem Name : Largest 3 digit number in a string
Problem Link : https://leetcode.com/problems/largest-good-number/
Explanation : 
Given string check if the string contains 3 consecutive same digits by iterating over the string.
And comparing the current character with the next two characters.
*/
//Method 1: Using set
class Solution1 {
public:
    string largestGoodInteger(string num) {
        set<string> st;
        for (int i = 0; i < num.size() - 2; i++) {
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                st.insert(num.substr(i, 3));
            }
        }

        if (st.empty()) {
            return "";  
        }

        auto it = st.end();
        --it;
        return *it;
    }
};
//Method 2 : Using map
class Solution2 {
public:
    string largestGoodInteger(string num) {
        map<string, int> mp;
        for (int i = 0; i < num.size() - 2; i++) {
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                mp[num.substr(i, 3)]++;
            }
        }

        if (mp.empty()) {
            return "";
        }

        auto it = mp.end();
        --it;
        return it->first;
    }
};
//Method 3 : Using max function and storing in a string
class Solution3 {
public:
    string largestGoodInteger(string num) {
        int result = -1;
        for (int i = 0; i + 2 < num.length(); i++) {
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                result = max(result, num[i] - '0');
            }
        }
        return (result == -1) ? "" : string(3, '0' + result);
    }
};

int main() {
    Solution1 sol1;
    Solution2 sol2;
    Solution3 sol3;
    string num = "1234567890";
    cout << sol1.largestGoodInteger(num) << endl;
    cout << sol2.largestGoodInteger(num) << endl;
    cout << sol3.largestGoodInteger(num) << endl;
    return 0;
}