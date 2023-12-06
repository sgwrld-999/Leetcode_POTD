#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(vector<int>& cost, vector<int>& time,int index,int remain,int sizeOfCost){
        if(remain <= 0) return 0;
        if(index > sizeOfCost) return 1e7;
        int painted = cost[index] + minCost(cost,time,index+1,remain-1-time[index],sizeOfCost);
        int skip = minCost(cost,time,index+1,remain,sizeOfCost);

        return min(painted,skip);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int size = cost.size();
        return minCost(cost,time,0,size,size-1);
    }
};
int main(int argc, char const *argv[])
{
    int size ;
    cout << "Enter the size of cost/time :  " ;
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
