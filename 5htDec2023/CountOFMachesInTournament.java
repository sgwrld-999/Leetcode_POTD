import java.util.Scanner;
/*
 * Problem Name : Count of Matches in Tournament
 * Problem Link : https://leetcode.com/problems/count-of-matches-in-tournament/
 * 
 */
class Solution {
    public int numberOfMatches(int n) {
        int ans = 0 ; 
        while(n > 1){
            if(n%2 == 0){
                ans += n / 2;
                n = n / 2;
            }
            else{
                ans += (n-1)/2;
                n = (n-1)/2 + 1;
            }
        }
        return ans;
    }
}
public class CountOFMachesInTournament {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Solution s = new Solution();
        System.out.println(s.numberOfMatches(n));
        sc.close();
    }
}