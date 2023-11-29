#include<bits/stdc++.h>
using namespace std;
/*
Problem name : Number of 1 Bits
Problem link : https://leetcode.com/problems/number-of-1-bits/
*/
class Solution {
public:
/*
Explanation of the code : 
Let's take an example of 1100
1100 - 1 = 1011
1100 & 1011 = 1000
1000 - 1 = 0111
1000 & 0111 = 0000
So, we can see that we have reduced the number of 1s by 1 in each iteration.
This works perfectly fine because in each iteration we are unsetting the rightmost set bit 
or removing the rightmost set bit.
*/
    int hammingWeight(uint32_t n) {
        int ctr = 0 ;
        while(n > 0){
            n = n & (n -1);
            ctr++;
        }
        return ctr;
    }
};
int main(){
    Solution s;
    cout << s.hammingWeight(00000000000000000000000000001011);
    return 0;
}