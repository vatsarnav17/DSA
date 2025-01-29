class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int, int> mpp; // Stores counts of 5s and 10s

        for (int bill : bills) {
            mpp[bill]++;  // Increase count of the received bill

            if (bill == 10) {  // Customer pays with $10
                if (mpp[5] > 0) {
                    mpp[5]--;  // Give back one $5 bill
                } else {
                    return false;  // No change available
                }
            } 
            else if (bill == 20) {  // Customer pays with $20
                if (mpp[10] > 0 && mpp[5] > 0) {
                    mpp[10]--;  // Give one $10
                    mpp[5]--;   // Give one $5
                } 
                else if (mpp[5] >= 3) {  
                    mpp[5] -= 3;  // Give three $5 bills
                } 
                else {
                    return false;  // No valid change
                }
            }
        }
        return true;
    }
};
