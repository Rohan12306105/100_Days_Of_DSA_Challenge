class Solution {
public:
    int jump(vector<int>& nums) {
        int fuel = 0;
        int count = 0;
        for (int i = 0; i < nums.size()-1; i++)
        {
            
            fuel += nums[i];
            if(fuel>nums.size()){
                
                break;
            }
            count++;
            fuel--;
        }
        return count;
    }
};











//for all test cases
class Solution {
public:
    int jump(vector<int>& nums) {
        // Track the minimum number of jumps needed
        int jumpCount = 0;
      
        // Track the farthest position reachable so far
        int maxReach = 0;
      
        // Track the end of the current jump range
        int currentJumpEnd = 0;
      
        // Iterate through array except the last element (we don't need to jump from the last position)
        for (int i = 0; i < nums.size() - 1; ++i) {
            // Update the farthest position we can reach from current position
            maxReach = max(maxReach, i + nums[i]);
          
            // If we've reached the end of the current jump range
            if (i == currentJumpEnd) {
                // We must make a jump to continue
                ++jumpCount;
              
                // Update the range end to the farthest position we can reach
                currentJumpEnd = maxReach;
            }
        }
      
        return jumpCount;
    }
};
