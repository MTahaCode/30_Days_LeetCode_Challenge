class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> paranthesis;
        recursiveGenerate(n, n, paranthesis);
        return paranthesis;
    }
    
    void recursiveGenerate(int leftBrace, 
        int rightBrace, 
        vector<string>& paranthesis,
        string braceString = "") {
        if (leftBrace <= 0 && rightBrace <= 0) {
            paranthesis.push_back(braceString);
        }

        if (leftBrace > 0 && rightBrace > 0) {
            recursiveGenerate(leftBrace - 1, rightBrace, paranthesis, braceString + "(");
        }
        if (rightBrace > 0 && rightBrace > leftBrace) {
            recursiveGenerate(leftBrace, rightBrace - 1, paranthesis, braceString + ")");
        }
    }
};