#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //TC : O(N^2)
    //Space Complexity : O(N+M)
    vector<int> getRow(int rowIndex) {
        vector<int> prevRow(1,1);
        vector<int> curRow(2,1);
        if(rowIndex == 0)
            return prevRow;
        if(rowIndex == 1)
            return curRow;
        for(int i = 1 ; i <= rowIndex ; i++){
            vector<int> temp(i+1,1);
            for(int j = 1; j < i ; j++ ){
                temp[j] = curRow[j-1] + curRow[j];
            }
            prevRow = curRow;
            curRow = temp ;
        }
        return curRow;
    }
};

int main(int argc, char const *argv[])
{
    int rowIndex ;
    cout << "Enter the Row index : " ;
    cin >> rowIndex ; 
    vector<int> res;
    Solution obj;
    res = obj.getRow(rowIndex);
    cout << "The required row of the Pascal triangle is : " << "[ " ;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i < res.size() - 1) {
            cout << ", ";
        }
    }
    cout << " ]" << endl;
    return 0;
}
