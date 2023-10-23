#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfFourApproach3(int n){
        //Using the log property
        if(n == 0) return false;
        if(n == 1) return true;
        int x = log(n)/log(4);
        if(n == pow(4,x)) return true;
        return false;
    }
    bool isPowerOfFourApproach2(int n){
        if(n == 0){
            return false;
        }else if(n == 1){
            return true;
        }
        while(n%4 == 0){
            n /= 4 ;
        }
        if(n == 1) return true;
        return false ;
    }
    bool isPowerOfFourApproach1(int n) {
        //to get x which is n=4^x 
        int x=log(pow(2,31))/log(4); // Maximum of the range of int is 2^31-1 that will be 4^x can hold
        int low = 0 , high = x;
        while(low <= high)
        {
            int mid=( low + high ) / 2;
            if(pow(4,mid)==n)
                return true;
            else if(pow(4,mid)<n)
                low=mid+1;
            else
                high=mid-1;
        }
        return false;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (sol.isPowerOfFourApproach3(n)) {
        cout << n << " is a power of four." << endl;
    } else {
        cout << n << " is not a power of four." << endl;
    }
    return 0;
}
