class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int i = 0, left = 0, right = 0, n=s.length(); //generate 2 pointers
        while (i<n)
        {
            while(i < n && s[i] ==' '){ //skips spaces
                i++;
            }
            if (i == n)
                break;
            while(i < n && s[i] !=' '){ //copies the word from i loop to pointers loop
                s[right++] = s[i++];
            }
            reverse(s.begin() + left, s.begin() + right);//reverses the copied word
            s[right++] = ' ';//adds space
            left = right;//moves to the next word
            i++;
        }
        s.resize(right - 1);//resizes the string finally
        return s;
    }
};