/*
jo sting h usko character array ki tarh treat 
kro aur last se iterate krna shuru kro jaha space 
mile wha break krdo aur jaha flag raise ho wha bhi 
break krdo
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size(),
            flag=0,
            count=0;
        for (int i = n-1; i >= 0; i--)
        {
            if(s[i]==' '&& flag){
                break;
            }
            else if(s[i]!=' '){
                flag = 1;
                count++;
            }
        }
        return count;
    }
};