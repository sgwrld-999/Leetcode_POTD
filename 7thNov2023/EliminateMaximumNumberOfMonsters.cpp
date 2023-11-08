#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Greedy Approach 1 : Correctness is not 100% 
    int eliminateMaximumGreedyApproach1(vector<int>& dist,vector<int>& speed) {
        int n = dist.size();
        int j = 1;
        int ctr = 1;
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            arr[i] = ceil((float)(dist[i]) / speed[i]);
        }
        for(int i = 0 ; i < n ; i++){
            arr[i]--;
        }
        while (j < n) {
            
            if (arr[j] <= 0) {
                return ctr;
            } else {
                ctr++;
                j++;
                for (int i = 0; i < n; i++) {
                    arr[i]--;
                }
            }
        }
        return ctr;
    }
    // Greedy Approach 2 : 
    int eliminateMaximum(vector<int>& dist,vector<int>& speed) {
        int n = dist.size();
        int time_Passed = 1;
        int ctr = 1;
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            arr[i] = ceil((float)(dist[i]) / speed[i]);
        }

        sort(arr.begin(),arr.end());

        for(int i = 1 ; i < n ; i++){
            if(arr[i] - time_Passed <= 0){
                return ctr;
            }
            ctr++;
            time_Passed++;
        }
        return ctr;
    }
};

int main(){
    Solution s;
    vector<int> dist  = {3,5,7,4,5} ;
    vector<int> speed = {2,3,6,3,2} ;
    cout<<s.eliminateMaximum(dist,speed);
    return 0;
}