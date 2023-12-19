/*
 * Problem name : Image Smoother
 * Problem: https://leetcode.com/problems/image-smoother/
 * Explnation : 
 *  Imagine you've a 3x3 matrix and you've to find the average of all the elements in the matrix.
 *  That what we've to do here.
 *  If they are valid then add them to the temp variable and increment the counter pof valid counter. 
 *  */

public class ImageSoomther {
    class Solution {
        public int[][] imageSmoother(int[][] img) {
            int n = img.length;
            int m = img[0].length;
            int[][] ans = new int[n][m];
            
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int temp = 0;
                    int ctr = 0;
                    
                    for (int row = -1; row < 2; row++) {
                        for (int col = -1; col < 2; col++) {
                            if (isSafe(i + row, j + col, n, m)) {
                                ctr++;
                                temp += img[i + row][j + col];
                            }
                        }
                    }
                    
                    ans[i][j] = temp / ctr; 
                }
            }
            
            return ans;
        }
        private boolean isSafe(int x, int y, int n, int m) {
            return x >= 0 && x < n && y >= 0 && y < m;
        }
    }
    
}
