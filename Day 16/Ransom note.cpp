/*
dono strings ko iterate kro with help of for range loop
magazine string ke characters ko ek hashmap mai store krlo 
aur uski no. of occurences ko values bnake add krdo

fir ransomnote ko iterate krke hasmaps mai se ocuurences ko minus 
kro aur agar <= zero aaye toh false return krdo immediately 
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> magahash;
        for (char c:magazine){
            magahash[c]++;
        }
        for(char c: ransomNote){
            if(magahash[c]<=0){
                return false;
            }
            magahash[c]--;
        }
        return true;
    }
};