#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    //The question is based upon the recurrence relation: f(n, k) = f(n - 1, k) + 1 - f(n - 1, k - 2^(n - 2))
    //Explanation: The idea is to find the parent of the current node. 
    //If the parent is 0, then the current node is the left child of the parent. Otherwise, it is the right child of the parent. 
    //We can find the parent of the current node by dividing the current node index by 2. If the current node is the left child of the parent, then the parent node is at index k / 2 in the previous row. Otherwise, the parent node is at index k / 2 + 1 in the previous row. 
    //We can use this idea to find the parent of the current node and then recursively find the value of the current node.
    int kthGrammar(int n, int k) {
        if (n == 1) {//Base case
            return 0;
        }
        
        int mid = pow(2, n - 2);//Mid point of the row
        //If k is less than or equal to mid, then the kth element will be same as kth element in the previous row
        //Or the previous row will be same as the current row
        //Else the kth element will be the complement of k - mid element in the previous row
        if (k <= mid) {
            return kthGrammar(n - 1, k);
        } else {
            return 1 - kthGrammar(n - 1, k - mid);
        }
    }
};
int main() {
    Solution sol;
    int n, k;
    cin >> n >> k;
    cout << sol.kthGrammar(n, k) << endl;
    return 0;
}