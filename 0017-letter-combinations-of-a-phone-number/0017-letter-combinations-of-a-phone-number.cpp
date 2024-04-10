class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        
        unordered_map<char, string> digit_letters;

        digit_letters['2'] = "abc";
        digit_letters['3'] = "def";
        digit_letters['4'] = "ghi";
        digit_letters['5'] = "jkl";
        digit_letters['6'] = "mno";
        digit_letters['7'] = "pqrs";
        digit_letters['8'] = "tuv";
        digit_letters['9'] = "wxyz";

        vector<string> combinations;
        getCombination(digits, 0, combinations, digit_letters);

        return combinations;
        
    }
    
    void getCombination(string digits, 
        int index, vector<string>& combinations, 
        unordered_map<char, string>& digit_letters, 
        string comb = "") {

        if (index >= digits.length()) {
            combinations.push_back(comb);
            return;
        }

        for (char c : digit_letters[digits[index]]) {
            getCombination(digits, index + 1, combinations, digit_letters, comb + c);
        }
    }
};