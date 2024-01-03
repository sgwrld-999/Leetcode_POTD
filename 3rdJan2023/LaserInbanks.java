
/*
 * Problem name : Laser In Banks
 * Problem Link : https://leetcode.com/problems/laser-beam-in-bank/
 * Explanation  : 
               - Intituion :
                            - The problem is to find the number of beams that can be formed in the given bank.
                            - The beams can be formed in the following ways :
                               1. If they don't belong to the same row.
                               2. If there is a no beam in the next row. Means the beam can only pass through 
                                  when there is no laser light in the next row. Or in simple terms beam will be 
                                  eliminated if there is a laser light in the next row.
               - Approach :
                          - We will iterate through the bank and count the number of beams in each row.                    
                          - If the row is the first row then we will simply count the number of beams in that row.
                          - If the row is not the first row then we will count the number of beams in that row and
                            multiply it with the number of beams in the previous row.
                          - We will add the number of beams in each row to the total number of beams.
                          - We will return the total number of beams.
  
 */
class Solution {
    public int numberOfBeams(String[] bank) {
        int rows = bank.length;
        int previousCount = 0;
        int currentCount = 0;
        int totalBeams = 0;

        for (int i = 0; i < rows; i++) {
            int columns = bank[i].length();

            for (int j = 0; j < columns; j++) {
                if (i == 0) {
                    if (bank[i].charAt(j) == '1') {
                        currentCount++;
                    }
                } else {
                    if (bank[i].charAt(j) == '1') {
                        currentCount++;
                    }
                }
            }

            if (currentCount != 0) {
                totalBeams += currentCount * previousCount;
                previousCount = currentCount;
                currentCount = 0;
            }
        }
        return totalBeams;
    }
}
