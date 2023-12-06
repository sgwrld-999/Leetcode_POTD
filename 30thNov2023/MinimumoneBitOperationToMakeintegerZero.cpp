#include<bits/stdc++.h>
using namespace std;
/*
Problem name : Minimum One Bit Operations to Make Integers Zero
Problem link : https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/

Solution :
This question is kinda special question as it is not a very common question and if it's asked in an interview,
then the interviewer will give HINTS to solve this question.

So, According to this question we've given an integer n and we have to make it zero by performing some operations 
And the operations are :
1. Change the rightmost (0th) bit in the binary representation of n means the LSB can be zero without checking any condition.
2. If the ith bit is 1 in the binary representation of n and the (i-1)th bit is 0 then we can change the ith bit to 0 
   by flipping all the bits from 0 to i-1.
   Example : 
    1100 Here 4th bit is 1 and i - 1 th bit i.e is 3rd bit is 1 as well after the remaing bits are 0. So, we can change the 4th bit to 0.
    And the result will be 0100.

And about the HINT the interviewer will give us HINT in form question that is :
How we can change the a number if it only have only 1 bit set in the binary representation of the number?
So, Let's solving this part first will lead us to the solution of the problem.  
We'll travel from left to right not right to left because let's say we have a number 1000 and we want to change it to 0000.
So, if we travel from right to left then for changing the 4th bit we've to change the 3rd bit as set bit and it'll take some additional operations.
But if we travel from left to right then we can change the 4th bit directly to 0 without changing any other bit.
1000 -> 1100 -> 0100 -> 0000

So for setting the ith bit we have to convert the i-1ith bit to 1 and for converting it'll take x steps and for converting the 110000.. number to 01000.. it'll take 1 step.
Now,let x be again the same number steps to convert the 010000.. number to 00000.. number.

So the formula is : F(i) = 2*F(i-1) + 1 
And the base case is : F(0) = 1
So now we've solved the sub part of the problem.

Now let's solve the main problem.
To change any number to 0 :
Let's we have given a number 1100
To converting it 1100 to 0000 
In previous problem we've solved that 1000 to 0000 in the middle step we've encountered the 1100 
so Converting of the 1100 to 0000 can be found as :
f(1100 -> 0000) = f(1000 -> 0000) - f(1100 -> 1000) 
f(1100 -> 0000) = f(1000 -> 0000) - f(100 -> 000) [As the LSB is same in both number so we can remove it]
f(1100) = F(3) - F(2) 
f(1101101) = F(6) - F(5) + F(4) - F(3) + F(2) - F(1) + F(0) 
And the sign will be changed after each operation as we are changing if we open it with formula then the sign will be changed.


*/
class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n == 0) return 0;

        vector<long long> F(32,0);
        F[0] = 1 ;
        for(int i = 1 ; i <= 31 ; i++){
            F[i] = 2*F[i-1] + 1 ;
        }

        int result = 0 ; 
        int sign = 1;

        for(int i = 31 ; i >= 0 ; i--){
            int ith_bit = ((1 << i) & n);

            if(ith_bit == 0) continue;

            if(sign > 0) result += F[i];
            else result -= F[i];

            sign *= -1;
        }
        return result;
    }
};

int main(){
    Solution s;
    cout << s.minimumOneBitOperations(9);
    return 0;
}