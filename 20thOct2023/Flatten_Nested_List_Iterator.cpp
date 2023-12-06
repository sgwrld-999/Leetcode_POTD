#include<bits/stdc++.h>
using namespace std;
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    stack<NestedInteger> st;
    NestedIterator(vector<NestedInteger> &nestedList) {
        //This function will push the element in the stack
        int n = nestedList.size();
        for(int i = n - 1 ; i >= 0 ; i--){
            //Iterating from backwards as the to get the list in the 
            //Given order not in the reverse order
            st.push(nestedList[i]);
        }
    }
    
    int next() {
        //It'll check if the element at top is int or not
        int num = st.top().getInteger();
        st.pop();
        return num;
    }
    
    bool hasNext() {
        //It'll check if the top element is the int or not 
        //If it's not interger than get the list and store the interger value
        //in the stack 
        while(!st.empty()){
            NestedInteger obj = st.top();
            if(obj.isInteger()){
                return true;
            }
            st.pop();
            vector<NestedInteger> tempVec = obj.getList();
            for(int i = tempVec.size() - 1; i >= 0 ; i--){
                st.push(tempVec[i]);
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */