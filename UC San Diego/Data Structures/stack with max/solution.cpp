#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <stack>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::stack;

// Class to implement a stack with a Max() function
class StackWithMax {
    stack<int> stack_; // Main stack to store elements
    stack<int> max_stack_; // Auxiliary stack to store maximum elements

public:
    // Function to push an element onto the stack
    void Push(int value) {
        stack_.push(value); // Push the value onto the main stack
        if (max_stack_.empty() || value >= max_stack_.top()) {
            max_stack_.push(value); // If the value is greater than or equal to the current maximum, push it onto the max stack
        }
    }

    // Function to pop an element from the stack
    void Pop() {
        assert(!stack_.empty()); // Ensure stack is not empty
        int top = stack_.top(); // Get the top element of the stack
        stack_.pop(); // Pop the element from the main stack
        if (top == max_stack_.top()) {
            max_stack_.pop(); // If the popped element is the current maximum, pop it from the max stack as well
        }
    }

    // Function to return the maximum element in the stack
    int Max() const {
        assert(!stack_.empty()); // Ensure stack is not empty
        return max_stack_.top(); // Return the top element of the max stack
    }
};

// Main function
int main() {
    int num_queries = 0;
    cin >> num_queries; // Input the number of queries

    string query;
    string value;

    StackWithMax stack; // Create a StackWithMax object

    // Process each query
    for (int i = 0; i < num_queries; ++i) {
        cin >> query; // Input the query type
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value)); // Push the value onto the stack
        }
        else if (query == "pop") {
            stack.Pop(); // Pop the top element from the stack
        }
        else if (query == "max") {
            cout << stack.Max() << "\n"; // Output the maximum element in the stack
        }
        else {
            assert(0); // Invalid query type
        }
    }
    return 0;
}
