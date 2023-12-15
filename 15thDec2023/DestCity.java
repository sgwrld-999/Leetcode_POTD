
import java.util.HashSet;
import java.util.List;
/*
 * problem name : Destination City
 * problem link : https://leetcode.com/problems/destination-city/
 * problem link on GeekforGeeks : https://practice.geeksforgeeks.org/problems/destination-city/1
 * 
 */
public class DestCity {
    class Solution {
        public String destCity(List<List<String>> paths) {
            int n = paths.size();
            HashSet<String> set = new HashSet<>();
    
            for (int i = 0; i < n; i++) {
                set.add(paths.get(i).get(0));
            }
    
            for (int i = 0; i < n; i++) {
                if (!set.contains(paths.get(i).get(1))) {
                    return paths.get(i).get(1);
                }
            }
            return null;
        }
    }
}
