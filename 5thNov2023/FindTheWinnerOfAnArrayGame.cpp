#include<bits/stdc++.h>
using namespace std;

/*
To solve any question the major thing is to understand the question.
That is what is given and what is asked.
And what we need to do to get the desired output.
And what is the desired output of the question.

Input : arr = [2,1,3,5,4,6,7], k = 2
Output : 5
Explanation :
we need to return the number which is greater than k numbers in the array.Means 
if k = 2 the current number should be greater than 2 next number in the array.
It can be any number in the array but it should be greater than 2 next numbers in the array.
We can do it one oiteration of the array.

*/
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int curWin = arr[0];
        int ctr = 0;
        int n = arr.size();
        for(int i = 1 ; i < n ; i++){
            if(arr[i] > curWin){
                curWin = arr[i];
                ctr = 1 ;
            }else{
                ctr++;
            }
            if(ctr == k) return curWin;
            
        }
        return curWin ;
    }
    int getWinnerUsingMap(vector<int>& arr, int k) {
        int ctr = 0;
        int n = arr.size();
        int i = 0 ;
        int j = 1 ;
        map<int,int>mp;
        while(i < n && j < n){
            if(arr[i] > arr[j]){
                mp[arr[i]]++;
            }else {
                mp[arr[j]]++;
                i = j ;
            }
            if(mp[arr[i]] == k) return arr[i];
            j++;
        }
        return (*max_element(arr.begin(),arr.end()));
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << obj.getWinner(arr,k) << endl;
    return 0;
}