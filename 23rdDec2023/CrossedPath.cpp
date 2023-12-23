#include <iostream>
#include <set>

using namespace std;
/*
Problem name : Path Crossing
Problem link : https://leetcode.com/problems/path-crossing/
Difficulty : Easy
*/
class Solution {
public:
    bool isPathCrossing(string path) {
        // Set to store visited coordinates
        set<pair<int, int>> visited;
        
        // Initial position
        int x = 0, y = 0;
        visited.insert({x, y});

        // Process each direction in the path
        for (char dir : path) {
            // Update coordinates based on the direction
            switch (dir) {
                case 'N':
                    x++;
                    break;
                case 'S':
                    x--;
                    break;
                case 'E':
                    y++;
                    break;
                case 'W':
                    y--;
                    break;
            }

            // Check if the current coordinates have been visited before
            if (visited.count({x, y}) > 0) {
                return true;
            }

            // Add the current coordinates to the set
            visited.insert({x, y});
        }

        // If no crossing is found
        return false;
    }
};

int main() {
    Solution solution;
    string path = "NSWE";
    
    // Example usage
    cout << boolalpha << solution.isPathCrossing(path) << endl;

    return 0;
}
