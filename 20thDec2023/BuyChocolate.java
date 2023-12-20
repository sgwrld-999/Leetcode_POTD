
import java.util.*;
/*
 * Problem name : Buy Two Chocolate
 * Problem Link : https://leetcode.com/problems/buy-two-chocolates/description/
 * Explanation  :
 *              - Approach 1 : Sort the array and find the minimum two elements and subtract them from the money.
 *              - Approach 2 : Find the minimum two elements in a single pass and subtract them from the money.
 * 
 */
public class BuyChocolate {
    class Solution {
        public int solutionInNlogN(int[] prices, int money) {
            Arrays.sort(prices);
            if((prices[0]+ prices[1]) <= money){
                return (money - (prices[0]+prices[1]) );
            }
    
            return money;
        }
        public int solutionInN(int[] prices, int money) {
            int min1 = Integer.MAX_VALUE;
            int min2 = Integer.MAX_VALUE;
    
            for (int it : prices) {
                if (it < min1) {
                    min2 = min1;  
                    min1 = it;   
                } else if (it < min2) {
                    min2 = it;   
                }
            }
    
            return (money >= min1 + min2) ? money - (min1 + min2) : money;
        }
    
    
        public int buyChoco(int[] prices, int money) {
            return solutionInN(prices,money);
        }
    }
}
