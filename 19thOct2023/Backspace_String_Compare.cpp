#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompareApproach1(string s, string t) {
        //The problem with this greedy approach is that it's not 
        //comparing the string its just working upon the size of string
        //it's comparing if the string are same lenght of not if the hash is removed
        int sizeOfStringS = s.size();
        int sizeOfStringT = t.size();
        if(sizeOfStringS != sizeOfStringT) return false;
        if(sizeOfStringS == 1) return (s[0] == '#' && t[0] == '#');
        int numOfBSInS = 0 ;
        int numOfBSInT = 0 ;
        for(int i = 0 ; i < sizeOfStringS ; i++){
            if(s[i] == '#'){
                numOfBSInS++;            }
            if(t[i] == '#'){
                numOfBSInT++;
            }
        }
        int finalS = sizeOfStringS - numOfBSInS * 2;
        int finalT = sizeOfStringT - numOfBSInT * 2;
        if(finalS == finalT){
            return true;
        }
        return false;
    }
    bool backspaceCompareApproach2(string s, string t) {
        //this can be done using the stirng as well
        //Creating the stacks for storing the string integer
        stack<char> stOfS;
        stack<char> stOfT;
        //Storing the size
        int sizeOfS = s.size();
        int sizeOfT = t.size();
        //Declare the iterating variable
        int i = 0;
        //Storeing the values in the stack for both the  s and t
        while (i < sizeOfS) {
            if (s[i] != '#') {
                stOfS.push(s[i]);
            } else if (!stOfS.empty()) {
                stOfS.pop();
            }
            i++;
        }
        i = 0;
        while (i < sizeOfT) {
            if (t[i] != '#') {
                stOfT.push(t[i]);
            } else if (!stOfT.empty()) {
                stOfT.pop();
            }
            i++;
        }
        //Checking if the size is same or not
        if (stOfS.size() != stOfT.size()) {
            return false;
        }
        //Comparing the top values and poping if they are the same
        // If they are not same then return false.
        while (!stOfS.empty() && !stOfT.empty()) {
            if (stOfS.top() != stOfT.top()) {
                return false;
            }
            stOfS.pop();
            stOfT.pop();
        }
        return true;
    }
    //Most optimal approach in terms of the space complexity
    bool backspaceCompare(string s, string t) {
        int m = s.length();
        int n = t.length();
        //Iterating from backwards
        int i = m-1, j = n-1;
        int skip_s = 0;
        int skip_t = 0;
        
        while(i >= 0 || j >= 0) {
            
            while(i >= 0) {
                if(s[i] == '#') {
                    skip_s++;
                    i--;
                } else if(skip_s > 0) {
                    skip_s--;
                    i--;
                } else {
                    break;
                }
            }
            
            while(j >= 0) {
                if(t[j] == '#') {
                    skip_t++;
                    j--;
                } else if(skip_t > 0) {
                    skip_t--;
                    j--;
                } else {
                    break;
                }
            }
            
            char first  = i < 0 ? '$' : s[i];
            char second = j < 0 ? '$' : t[j];
            
            if(first != second)
                return false;
            
            i--;
            j--;
        }
        
        return true;
        
    }
};