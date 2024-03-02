#include <iostream>
#include <stack>
#include <string>

// Define a struct for brackets
struct Bracket {
    Bracket(char type, int position) :
        type(type),
        position(position)
    {}

    // Function to check if the bracket matches with the given character
    bool Match(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;      // type of bracket
    int position;   // position of bracket in the input string
};

int main() {
    std::string text;
    getline(std::cin, text); // Get input string from the user

    std::stack<Bracket> opening_brackets_stack; // Stack to store opening brackets
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position]; // Get the next character from the input string

        if (next == '(' || next == '[' || next == '{') {
            // If the character is an opening bracket, push it onto the stack
            opening_brackets_stack.push(Bracket(next, position + 1)); // position + 1 is used to display position starting from 1 instead of 0
        }

        if (next == ')' || next == ']' || next == '}') {
            // If the character is a closing bracket
            if (opening_brackets_stack.empty()) {
                // If there are no opening brackets to match, print the position of the closing bracket and exit
                std::cout << position + 1 << std::endl;
                return 0;
            }

            Bracket top = opening_brackets_stack.top(); // Get the top bracket from the stack
            opening_brackets_stack.pop(); // Pop the top bracket from the stack
            if (!top.Match(next)) {
                // If the top opening bracket does not match with the closing bracket, print the position of the closing bracket and exit
                std::cout << position + 1 << std::endl;
                return 0;
            }
        }
    }

    if (opening_brackets_stack.empty()) {
        // If all opening brackets are matched with closing brackets, print "Success"
        std::cout << "Success" << std::endl;
    }
    else {
        // If there are unmatched opening brackets, print the position of the top opening bracket
        std::cout << opening_brackets_stack.top().position << std::endl;
    }

    return 0;
}
