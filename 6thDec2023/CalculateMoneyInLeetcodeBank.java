

/*
 * Problem name : Calculate Money in Leetcode Bank
 * Problem link : https://leetcode.com/problems/calculate-money-in-leetcode-bank/
 * Explanation :
 * According to the question, we need to calculate the total money that the user will have after n days.
 * 1st week : 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28 = 28
 * 2nd week : 2 + 3 + 4 + 5 + 6 + 7 + 8 = 28 + 7 = 35
 * 3rd week : 3 + 4 + 5 + 6 + 7 + 8 + 9 = 28 + 14 = 42
 * 4th week : 4 + 5 + 6 + 7 + 8 + 9 + 10 = 28 + 21 = 49
 * 5th week : 5 + 6 + 7 + 8 + 9 + 10 + 11 = 28 + 28 = 56
 * 
 * If we look at the above pattern, we can see that the total money in the bank is increasing by 7 every week or it's forming an AP with common difference 7.
 * Genral formula for AP is : a + (n-1)d
 * According to the question -> a = 1, d = 7, n = numOfWeeks
 * For the remaining days, we need to add the money for each day separately or remDays * (remDays + 1) / 2 + (numOfWeeks * remDays) this will work as well.
 * Because remDays * (remDays + 1) / 2 will give us the sum of the AP with common difference 1 and remDays * numOfWeeks will give us the sum of the AP with common difference 7.
 * 
 * 
 */

class Solution {
    public int totalMoney(int n) {
        int numOfWeeks = n / 7 ;
        int total = 28 * numOfWeeks ;
        total += (7 * numOfWeeks * (numOfWeeks -1)) / 2 ;
        int remDays = n % 7;
        total += (remDays * (remDays + 1)) / 2 + (numOfWeeks * remDays); 
        return total;
    }
}