#include<bits/stdc++.h>
using namespace std;
/*
Problem name : Minimum Time Visiting All Points
Problem link : https://leetcode.com/problems/minimum-time-visiting-all-points/
Explanation : 
    - We have to find the minimum time to visit all the points.
    - As it is given that we can move in any direction, we can move diagonally or horizontally or vertically between two points 
      and the time for vertically or horizontally moving between two is 1 and for diagonally moving between two points is sqrt(2).
      Which is nearly equal to 1.414 we can take it as 1.If we want to move to the one point to another the distace or the time which is required is 
      the maximum of the difference between the x coordinates or the difference between the y coordinates as we can move in any direction
      it'll cost us 1.
    - We can iterate over the points and add the distance between the current point and the previous point to the answer.
    - Time Complexity : O(n) where n is the number of points.
    - Space Complexity : O(1).
*/
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int dist = 0;
        int n = points.size();

        for (int i = 1; i < n; i++) {
            int x1 = points[i - 1][0];
            int y1 = points[i - 1][1];
            int x2 = points[i][0];
            int y2 = points[i][1];
            dist += max(abs(x1-x2),abs(y1-y2));
        }
        return dist;
    }
};

int main(){
    int n;
    cin >> n;
    vector<vector<int>> points(n,vector<int>(2));
    for(int i = 0 ; i < n ; i++){
        cin >> points[i][0] >> points[i][1];
    }
    Solution sol;
    cout << sol.minTimeToVisitAllPoints(points) << endl;
    return 0;
}