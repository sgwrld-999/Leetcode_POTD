#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Both the approaches are correct but the problem in the appraoch 1 is that it's optimised 
    // but the constraints are very high and it's not passing all the test cases.
    /*
    Dry run for the approach 1:
    sx = 1 , sy = 1 , fx = 7 , fy = 8, t = 10
    
    11 12 13 14 15 16 17 18
    21 22 23 24 25 26 27 28
    31 32 33 34 35 36 37 38
    41 42 43 44 45 46 47 48
    51 52 53 54 55 56 57 58
    61 62 63 64 65 66 67 68
    71 72 73 74 75 76 77 78

    For the above example the answer should be true but it's giving false.
    If we move diagonally till 77 then we can move to 78 in one step.
    And the time taken to reach 77 is 6 and 77 to 78 is 1.
    Total time taken is 7 which is less than 10. And for the remaining three we can 
    wwaste if needed ot reach the 78.
    But the minimum time taken to reach 78 is 7 which is less than 10.
    So the answer should be true.
    but since the constraints are very high it's giving TLE.
    
    
    */
    bool isReachableAtTimeApproach1(int sx, int sy, int fx, int fy, int t) {
        int ctr = 0;
        if(sx == fx && sy == fy && t == 1) return false;
        while (sx != fx || sy != fy) {
            if (ctr > t) return false; 

            if (sx < fx) {
                sx++;
            } else if (sx > fx) {
                sx--;
            }
            if (sy < fy) {
                sy++;
            } else if (sy > fy) {
                sy--;
            }

            ctr++;
        }

        return (ctr <= t);
        int distX = abs(sx-fx);
        int distY = abs(sy-fy);
        int maxi = max(distX,distY);
        return ((maxi <= t) ? true : false) ;
    }
    //In approaach 2 we are not moving diagonally.
    //but the main part here  is that we need to find the maximum distance between the
    //X and Y direction.
    bool isReachableAtTimeApproach2(int sx, int sy, int fx, int fy, int t) {
        int ctr = 0;
        if(sx == fx && sy == fy && t == 1) return false;
        int distX = abs(sx-fx);
        int distY = abs(sy-fy);
        int maxi = max(distX,distY);
        return ((maxi <= t) ? true : false) ;
    }
};

int main(){
    Solution s;
    cout<<s.isReachableAtTimeApproach1(1,1,7,8,10)<<endl;
    cout<<s.isReachableAtTimeApproach2(1,1,7,8,10)<<endl;
    return 0;
}