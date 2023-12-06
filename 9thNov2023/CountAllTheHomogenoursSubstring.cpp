#include<bits/stdc++.h>
using namespace std;
/*
Probl;em Link: https://leetcode.com/problems/count-number-of-homogenous-substrings/
Explanation : 
We have to calculate the number of homogenous substrings.
Lets understand with an example:
aaaaa
Len = 1 -> 5 times i.e a,a,a,a,a
Len = 2 -> 4 times i.e aa,aa,aa,aa
Len = 3 -> 3 times i.e aaa,aaa,aaa
Len = 4 -> 2 times i.e aaaa,aaaa
Len = 5 -> 1 times i.e aaaaa
So the total number of homogenous substrings are 5+4+3+2+1 = 15 (Sum of first n natural numbers)
Flow of code :
1. We will iterate over the string and check if the current character is same as the previous character.
2. If it's same then we will increase the length of the substring by 1.
3. Else we will make the length of the substring as 1.
4. We will add the length of the substring to the answer. Adding at each step will give us the total number of homogenous substrings.
5. We will return the answer.


*/
class Solution {
public:
    int mod = 1e9 + 7 ;
    int countHomogenous(string s) {
        int len = 0 ;
        int ans = 0 ;
        for(int i = 0 ; i < s.size() ; i++){
            if(i > 0 && s[i] == s[i-1]){
                len++;
            }else{
                len = 1;
            }
            ans = (ans + len)%mod ;
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.countHomogenous("abbcccaa") << endl;
    return 0;
}