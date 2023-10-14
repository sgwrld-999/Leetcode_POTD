#include<bits/stdc++.h>
using namespace std;
class Solution1 {
public: 
    //Brute Force approach : Time complexity  : O(N * M)
    //                     : Space Complexity : O(people.size()) 
    vector<int> minAndMax(vector<vector<int>>& flowers){
        int mini = INT_MAX ;
        int maxi = INT_MIN ;
        for(int i = 0 ; i < flowers.size() ; i++){
            mini = min(mini, flowers[i][0]);
            maxi = max(maxi, flowers[i][1]);
        }
        vector<int> ans(2, 0);
        ans[0] = mini ;
        ans[1] = maxi ;
        return ans; 
    }

    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> mp;
        vector<int> maxAndMinVec = minAndMax(flowers);
        
        // Initializing the map
        for(int i = maxAndMinVec[0] ; i <= maxAndMinVec[1] ; i++){
            mp[i] = 0;
        }
        
        // Finding the total number of flowers in that particular column
        for(int i = 0 ; i < flowers.size() ; i++){
            for(int j = flowers[i][0] ; j <= flowers[i][1] ; j++){
                mp[j]++;
            }
        }
        
        vector<int> ans;
        for(int i = 0 ; i < people.size() ; i++){
            ans.push_back(mp[people[i]]);
        }
        return ans;
    }
};

class Solution {
public:
    // Optmial approach : TC : O(N) + O(log(N) * M)
    //                  : SC ; O(N) + O(N) + O(N)
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int sizeofFlowers = flowers.size();
        int sizeofPeople = people.size();
        vector<int> start;
        vector<int> end;

        for (int i = 0; i < sizeofFlowers; i++) {
            start.push_back(flowers[i][0]);
            end.push_back(flowers[i][1]); 
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        vector<int> res(sizeofPeople);

        for (int i = 0; i < sizeofPeople; i++) {
            int bloomed = upper_bound(start.begin(), start.end(), people[i]) - start.begin();
            int faded = lower_bound(end.begin(), end.end(), people[i]) - end.begin();
            res[i] = bloomed - faded;
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    //Do it latee
    return 0;
}
