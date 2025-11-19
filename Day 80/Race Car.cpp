/*
https://leetcode.com/problems/race-car/solutions/2462888/c-dp-solutionin-o-tlogt-by-mdsameer31239-n28a
*/

class Solution {
public:
    int racecar(int t) {
        
        vector< int> dp( t+1,INT_MAX);
        int r=1;
        for( int i=1;i<=t;i++){
            
            if( i==pow( 2,r)-1){
                dp[i]=r;
                r++;
            }
            else{
                int u= pow( 2,r)-1;
                int l=pow( 2,r-1)-1;
                
                for( int j=0;j<r-1;j++){
                    dp[i]= min(dp[i], ( r-1)+1+1+j+ dp[i-l+pow(2,j)-1]);
                }
                dp[i]=min( dp[i] , r+1+dp[ u- i] );
            }
        }
        return dp[t];
    }
};