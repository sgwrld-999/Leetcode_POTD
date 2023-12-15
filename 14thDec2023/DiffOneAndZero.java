
/*
 * Problem name : Diiference between Sum of Ones and Sum of Zeros in Matrix
 * Problem link : https://leetcode.com/problems/calculate-difference-between-sums-of-odd-and-even-indexed-elements/
 * Problem Link on GeekforGeeks : https://practice.geeksforgeeks.org/problems/difference-between-sums-of-odd-and-even-indexed-elements/1
 * 
 */

class Solution {
    public int[][] onesMinusZeros(int[][] grid) {
        int m = grid.length ; 
        int n = grid[0].length ; 

        int[] oneRow = new int[m];
        int[] oneCol = new int[n];

        int[] zeroRow = new int[m];
        int[] zeroCol = new int[n];
        int ctr1 = 0 ;
        int ctr0 = 0 ;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1)ctr1++;
                else ctr0++;
            }
            oneRow[i] = ctr1;
            ctr1 = 0;
            zeroRow[i] = ctr0;
            ctr0 = 0;
        }
        for(int j = 0 ; j < n ; j++){ 
            for(int i = 0 ; i < m ; i++){  
                if(grid[i][j] == 1)ctr1++;
                else ctr0++;
            }
            oneCol[j] = ctr1;
            ctr1 = 0;
            zeroCol[j] = ctr0;
            ctr0 = 0;
        }
        int[][] ans = new int[m][n];
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                ans[i][j] = oneRow[i] + oneCol[j] - zeroRow[i] - zeroCol[j];
            }
        }

        return ans;
    }
}
