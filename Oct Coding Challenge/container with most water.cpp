/*
https://leetcode.com/problems/container-with-most-water/solutions/7246605/greedy-2-pointer-beats-100
*/

class Solution {
public:
    static inline int area(int l, int r, vector<int>& height){
        return min(height[l], height[r])*(r-l);
    }
    static int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0, r=n-1;
        int A=0;
        while (l<r){
            A=max(A, area(l, r, height));
            if(height[r]<height[l]) r--;
            else l++;
        }
        return A;   
    }
};