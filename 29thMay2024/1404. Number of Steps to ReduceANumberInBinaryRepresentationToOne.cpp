#include<bits/stdc++.h>
using namespace std;


/*
   +-------------------------------------+
   |          Start of Algorithm         |
   +---------------------+---------------+
                         |
                         v
    +--------------+   Loop     +---------------+
    | Initialize   |----------->|   lastIndex   |
    | Variables    |           +---------------+
    +--------------+                  |
                                      |
                                      v
    +--------------+   Loop     +---------------+
    |     Get      |----------->|  currentDigit |
    | Current Digit|           +---------------+
    +--------------+                  |
                                      |
                                      v
    +--------------+               +--------------+
    |   Check if   |   No         |   Check if   |
    | currentDigit+---------'0'--->|currentDigit +--+
    | + carry == 0|   Carry == 0 | + carry == 2|  |
    +--------------+               +--------------+  |
           | Yes                            |        |
           |                                |        |
           v                                v        |
    +--------------+                 +----------------+
    |  Increment   |                 |   Increment    |
    |  stepCount   |                 |   stepCount    |
    +--------------+                 +----------------+
           |                                    |
           +------------------------------------+
                    |
                    v
    +--------------+ 
    |   Update     |          
    |   carry      |         
    +--------------+
           |
           v
    +--------------+
    |   Decrement  |<----------+
    |   lastIndex  |           |
    +--------------+           |
           |                    |
           +--------------------
                    |
                    v
   +---------------+
   |   Loop End    |
   +---------------+
           |
           v
   +------------------+
   |   Check carry    |
   |     and return   |
   +------------------+
           |
           v
   +------------------+
   |    Algorithm     |
   |      End         |
   +------------------+


*/
class Solution {
public:
    int numSteps(const string& binaryString) {
        int lastIndex = binaryString.length() - 1;
        int carry = 0;
        int stepCount = 0;

        // Process each binary digit from the end to the start
        while (lastIndex > 0) {
            int currentDigit = binaryString[lastIndex] - '0';

            if (currentDigit + carry == 0) {
                // Current digit is '0' and there is no carry
                carry = 0;
                stepCount++;
            } else if (currentDigit + carry == 2) {
                // Current digit is '1' and there is a carry
                carry = 1;
                stepCount++;
            } else {
                // Current digit is '1' and there is no carry, or
                // Current digit is '0' and there is a carry
                carry = 1;
                stepCount += 2;
            }

            lastIndex--;
        }

        // If there's a carry left after processing all digits, it needs one more step
        if (carry == 1) {
            stepCount++;
        }

        return stepCount;
    }
};


