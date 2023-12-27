// package 27thdec2023;
/*
 * Problem name : Ballons
 * Problem URL  : https://leetcode.com/problems/minimum-cost-to-connect-sticks/
 * Explanation  :
 *              - Approah : Greedy 
 *              - Why Greedy works here ? Becuase everytime we've to choose the minimum cost stick to connect.
 *                and we don't have to explore all the cases as no matter what order we choose the sticks we'll get the same result 
 *                as we've to minimise the solution.
 *              - Example : 1 10 20  In this list to minimise it we'll choose 1 and 10 to remove no matter what order we choose.
 *                10 1 20 or 20 1 10 or 1 20 10 or 10 20 1 or 20 10 1 or 1 10 20 all will give the same result.
 *               
 * 
 */
public class Ballons {
    class Solution {
        public int minCost(String colors, int[] neededTime) {
            int n = neededTime.length ;
            int currTime = 0;
            int timeReq  = 0;
            int prevMax  = 0;
    
            for(int i = 0 ; i < n ; i++){
                
                if(i > 0 && colors.charAt(i) != colors.charAt(i-1))prevMax = 0 ;
                currTime = neededTime[i];
                timeReq += Math.min(currTime,prevMax);
                prevMax  = Math.max(prevMax,currTime);
            } 
            return timeReq;
        }
    }
}
