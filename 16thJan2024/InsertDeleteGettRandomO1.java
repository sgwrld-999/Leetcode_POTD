import java.util.*;
/*
Prblem name : Insert Delete GetRandom O(1)
Problem URL : https://leetcode.com/problems/insert-delete-getrandom-o1/
Explanation : 
    Design a data structure that supports all following operations in average O(1) time.
    insert(val): Inserts an item val to the set if not already present.
    remove(val): Removes an item val from the set if present.
    getRandom: Returns a random element from current set of elements. 
        Each element must have the same probability of being returned.
    Why we are using HashMap and ArrayList? 
    Since arraylist has O(1) time complexity for add, remove and get operations but there is a one problem 
    with arraylist that it takes linear time to remove an element at random index and swap the last element
    with this index. To overcome this problem we are using hashmap which stores element and its index in 
    hashmap. So, we can remove element from arraylist in O(1) time by swapping it with last element and then
    removing last element. We can also get random element from arraylist in O(1) time.
 */
class RandomizedSet {

    private List<Integer> nums;
    private Map<Integer, Integer> map;
    private java.util.Random rand;

    public RandomizedSet() {
        nums = new ArrayList<Integer>();
        map = new HashMap<Integer, Integer>();
        rand = new java.util.Random();
    }

    public boolean insert(int val) {
        boolean contain = map.containsKey(val);
        if (contain) return false;

        map.put(val, nums.size());
        nums.add(val);

        return true;
    }

    public boolean remove(int val) {
        boolean contain = map.containsKey(val);
        if (!contain) return false;

        int loc = map.get(val);

        if (loc < nums.size() - 1) {
            int last = nums.get(nums.size() - 1);
            nums.set(loc, last);
            map.put(last, loc);
        }

        map.remove(val);
        nums.remove(nums.size() - 1);
        return true;
    }

    public int getRandom() {
        return nums.get(rand.nextInt(nums.size()));
    }
}