class Solution {
public:
    int countOdds(int low, int high) {
        
        // count nikalne ka formula
        // This calculates the number of full (even, odd) or (odd, even) pairs in the range.
        int count = (high - low) / 2;  
        
        // agar low odd hai ya high odd hai to +1 kar denge (extra odd number)
        // If low is odd, the range starts with an odd number.
        // If high is odd, the range ends with an odd number.
        // If both are odd, the first one covers the extra odd count.
        if(low % 2 != 0 || high % 2 != 0){
            count++;
        }
        
        return count;
    }
};
