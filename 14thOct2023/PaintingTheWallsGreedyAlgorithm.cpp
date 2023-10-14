#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int costCheck(vector<pair<int,int> >&  pairCT , int sizeOfVec){
        int time = 0 ;
        int cost = 0 ;
        for(int i = 0 ; i < sizeOfVec ; i++){
            time += pairCT[i].second;
            cost += pairCT[i].first ;
            if(time >= (sizeOfVec - (i+1)))return cost;
        }
        return cost;
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<pair<int,int> > pairCT;
        int sizeOfCT = cost.size();
        if(sizeOfCT == 1) return cost[0];
        if(sizeOfCT == 2) return (cost[0] > cost[1] ? cost[1] : cost[0]);
        for(int i = 0 ; i < sizeOfCT ; i++){
            pair<int,int> temp;
            temp.first = cost[i];
            temp.second = time[i];
            pairCT.push_back(temp);
        }
        sort(begin(pairCT),end(pairCT));
        return costCheck(pairCT,sizeOfCT);
    }
};
int main(int argc, char const *argv[])
{
    int size ;
    cout << "Enter the size of cost and time" ;
    cin >> size ;
    cout << "Enter the elements of the cost and time respectively :" ;
    vector<int> cost(size);
    vector<int> time(size);
    for (int i = 0; i < size ; i++)
    {
        cout << endl << i+1 << " element :" ;
        cin >> cost[i] >> time[i]; 
    }
    Solution obj;
    cout <<  "Minimum cost : " << obj.paintWalls(cost,time) << endl ;
    return 0;
}
