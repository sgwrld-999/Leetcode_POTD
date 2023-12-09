import java.util.*;
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}
class Solution {
    List<Integer> arr = new ArrayList<Integer>();
    public List<Integer> inorderTraversal(TreeNode root) {
        if(root != null){
            inorderTraversal(root.left);
            arr.add(root.val);
            inorderTraversal(root.right);
        }
        return arr;
    }
}
/*
 * Problem : https://leetcode.com/problems/binary-tree-inorder-traversal/
 * Problem Name : Binary Tree Inorder Traversal
 * 
 */