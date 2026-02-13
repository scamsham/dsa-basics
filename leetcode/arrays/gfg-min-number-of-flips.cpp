/*
    https://www.geeksforgeeks.org/problems/min-number-of-flips3210/1
*/

class Solution {
  public:
    int minFlips(string& s) {
        // code here
        int flipZeros = 0, flipOnes = 0, n = s.length();

        for(int i = 0; i < n; i++){
            // The pattern will be either
            // 1. 010101010101 or
            // 2, 101010101010
            if(i % 2 == 0){
                s[i] == '0' ? flipOnes++ : flipZeros++;
            }else{
                s[i] == '1' ? flipOnes++ : flipZeros++;
            }
        }
        return min(flipZeros, flipOnes);
    }
};
