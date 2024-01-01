import java.util.Arrays;

/**
 * Problem name : AssignColors
 * Problem URL  : https://leetcode.com/problems/assign-cookies/
 * Explanation  :
 *             - Approah : Greedy
 *             - Why Greedy works here ? Because everytime we've to choose the MINIMUM cost stick to connect.
 *             - Why it'll not fail because of greedy ? Because we've to pick the cookies uniformly and we've to satisfy the children.
 *               such that the child with minimum appetite is satisfied first. That way we'll be able to satisfy maximum children.
 */
public class AssignColors {

    class Solution {
        public int findContentChildren(int[] childrenAppetite, int[] cookiesSize) {
            int satisfiedChildrenCount = 0;
            int childIndex = 0;
            int cookieIndex = 0;
            Arrays.sort(childrenAppetite);
            Arrays.sort(cookiesSize);
            System.out.println(Arrays.toString(childrenAppetite));
            int totalChildren = childrenAppetite.length;
            int totalCookies = cookiesSize.length;

            while (childIndex < totalChildren && cookieIndex < totalCookies) {
                if (childrenAppetite[childIndex] <= cookiesSize[cookieIndex]) {
                    childIndex++;
                    cookieIndex++;
                    satisfiedChildrenCount++;
                } else {
                    cookieIndex++;
                }
            }

            return satisfiedChildrenCount;
        }
    }

}
