
//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
/*
Problem name : Transpose of Matrix
Problem link : https://practice.geeksforgeeks.org/problems/transpose-of-matrix-1587115621/1
Prioblem link : https://leetcode.com/problems/transpose-matrix/

*/
// } Driver Code Ends
class Solution
{   
    public:  
    //Function to find transpose of a matrix.
    void transpose(vector<vector<int> >& matrix, int n)
    { 
        // code here 
        vector<vector<int>> res(n,vector<int>(n));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                res[i][j] = matrix[j][i];
            }
        }
        matrix = res ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n,vector<int>(n)); 

        for(int i=0; i<n; i++)
        {
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        ob.transpose(matrix,n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                cout<<matrix[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends