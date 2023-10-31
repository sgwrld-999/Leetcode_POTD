#include<bits/stdc++.h>
using namespace std;

/*
To find the og number we need to take XOR of the result with precalculated result.
Input array :  [5,2,0,3,1]
Output array : [5,7,2,3,2]
Explanation :
5 ^ 2 = 7 
Resultant array : [5,7,0,0,0]
5 ^ 7 ^ 0 = 2
Resultant array : [5,7,2,0,0]
5 ^ 7 ^ 2 ^ 3 = 3
Resultant array : [5,7,2,3,0]
5 ^ 7 ^ 2 ^ 3 ^ 1 = 2
Resultant array : [5,7,2,3,2]

*/
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int sizeOfPref = pref.size();
        vector<int> res(sizeOfPref);
        res[0] = pref[0];
        for (int i = 1 ; i < sizeOfPref ; i++) {
            res[i]= pref[i] ^ pref[i-1];
        }
        return res;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> pref(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> pref[i];
    }
    Solution obj;
    vector<int> res = obj.findArray(pref);
    for (int i = 0 ; i < n ; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}