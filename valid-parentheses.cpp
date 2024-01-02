#include <stack>
#include <string>

class Solution {
public:
    // Function to check if the given string has valid parentheses
    bool isValid(std::string s) {
        // Create a stack to store opening parentheses
        std::stack<char> helper;

        // Iterate through each character in the string
        for (char c : s) {
            // Check if the stack is not empty and the current character forms a valid pair with the top of the stack
            if (helper.size() > 0 && isPair(helper.top(), c)) {
                // If yes, pop the top of the stack (matching pair found)
                helper.pop();
            } else {
                // If not, push the current character onto the stack (opening parenthesis)
                helper.push(c);
            }
        }

        // After iterating through the entire string, the stack should be empty for the string to be valid
        return helper.empty();
    }

private:
    // Function to check if the given characters form a valid pair of parentheses
    bool isPair(char open, char close) {
        return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']');
    }
};
