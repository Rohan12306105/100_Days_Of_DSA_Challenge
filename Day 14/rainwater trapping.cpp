//solution for all test cases ( using DP )

class Solution {
public:
    //total water is trapped into the bars
    int trap(vector<int>& h) {
        int l=0,r=h.size()-1,lmax=INT_MIN,rmax=INT_MIN,ans=0;
        while(l<r){
            lmax=max(lmax,h[l]);
            rmax=max(rmax,h[r]);
            ans+=(lmax<rmax)?lmax-h[l++]:rmax-h[r--];
        }
        return ans;
    }
};









/*
THIS WILL GIVE TLE (O(n^2))


class Solution {
public:
    int trap(std::vector<int>& height) {
        // Get the number of bars.
        int n = height.size();
        
        // If there are less than 3 bars, no water can be trapped.
        if (n < 3) {
            return 0;
        }

        // Variable to store the total amount of trapped water.
        int totalWater = 0;

        // Iterate through each bar from the second to the second-to-last.
        // We skip the first and last bars because they cannot trap any water.
        for (int i = 1; i < n - 1; ++i) {
            
            // Step 1: Find the maximum height of a bar on the left side of the current bar.
            int leftMax = 0;
            for (int j = 0; j < i; ++j) {
                leftMax = std::max(leftMax, height[j]);
            }

            // Step 2: Find the maximum height of a bar on the right side of the current bar.
            int rightMax = 0;
            for (int j = i + 1; j < n; ++j) {
                rightMax = std::max(rightMax, height[j]);
            }

            // Step 3: Calculate the water trapped at the current position.
            // The water level is determined by the shorter of the two boundary walls (leftMax and rightMax).
            // The amount of water is the water level minus the current bar's height.
            int waterLevel = std::min(leftMax, rightMax);
            
            // Only add water if the water level is higher than the current bar.
            if (waterLevel > height[i]) {
                totalWater += waterLevel - height[i];
            }
        }
        
        // Return the total amount of trapped water.
        return totalWater;
    }
};
*/