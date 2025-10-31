/*
https://leetcode.com/problems/number-of-laser-beams-in-a-bank/solutions/7303903/multiplicative-principle-of-counting
*/

    int numberOfBeams(vector<string>& bank) {
        int ans=0, prev=0;
        for(auto& row: bank){
            int device=count(row.begin(), row.end(), '1');
            if (device>0){
                ans+=exchange(prev,device)*device;
            }
        }
        return ans;
    }