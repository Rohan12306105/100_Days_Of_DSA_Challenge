
// this wont pass all the testcases 
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = 0; i < digits.size(); i++)
        {
            if (i==digits.size()-1)
            {
                digits[i] + 1;
            }
            
        }
        return digits;
    }
};

// this will 
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] + 1 != 10) {
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
            if (i == 0) {
                digits.insert(digits.begin(), 1);
                return digits;
            }
        }
        return digits;        
    }
};

// for best understanding this is the solution
func plusOne(digits []int) []int {
    for i := len(digits) - 1; i >= 0; i-- {
        if digits[i] + 1 < 10 {
            digits[i]++
            return digits
        }
        digits[i] = 0
    }

    digits = append(digits, 0)
    digits[0] = 1
    return digits
}