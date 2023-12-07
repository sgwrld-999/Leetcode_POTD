#include<bits/stdc++.h>
using namespace std;
/*
Problem name : Largest Odd Number in String
Problem link : https://leetcode.com/problems/largest-odd-number-in-string/
Explanation :
    -   Traverse the string from the end and check if the number is odd or not.
    -   If the number is odd then add it to the answer string and make a flag true.
    -   If the number is even then check if the flag is true or not.
    -   If the flag is true then add the number to the answer string.
    -   Reverse the answer string and return it.

*/
class Solution {
public:
    string largestOddNumber(string num) {
        int sizeOfNum = num.size();
        if((num[sizeOfNum-1]-'0')%2 != 0) return num;

        string ans  = "" ;
        bool flag = false;

        for(int i = sizeOfNum - 1 ; i  >= 0; i--){
            if(!flag && ((num[i]-'0')%2 != 0)){
                flag = true;
                ans += num[i];
            }else if(flag){
                ans += num[i];
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
/*
Java Code : 

import java.util.*;

class Solution {
    public String largestOddNumber(String num) {
        int sizeOfNum = num.length();
        if ((num.charAt(sizeOfNum - 1) - '0') % 2 != 0) return num;

        StringBuilder ans = new StringBuilder();
        boolean flag = false;

        for (int i = sizeOfNum - 1; i >= 0; i--) {
            if (!flag && ((num.charAt(i) - '0') % 2 != 0)) {
                flag = true;
                ans.append(num.charAt(i));
            } else if (flag) {
                ans.append(num.charAt(i));
            }
        }

        return ans.reverse().toString();
    }
}


*/