// Pushdown Automaton (PDA) Implementation in C++
// Author: Ike Iloegbu

#include <iostream>
#include <string>
#include <stack>

/**
 * A class representing a Pushdown Automaton (PDA) that processes strings
 * consisting of the characters {a-z, ␢, (, ), [, ]} and determines whether
 * the string is accepted based on balanced brackets.
 */
class PDA {
private:
    /**
     * String containing valid alphabet characters.
     */
    std::string Letters = "abcdefghijklmnopqrstuvwxyz()[] "; 

public:
    /**
     * Processes a string to check if it belongs to the defined language.
     *
     * @param str The input string to process.
     * @return True if the string is accepted, false otherwise.
     */
    bool ProcessChar(std::string str) {
        std::stack<char> s;

        for (char c : str) {
            // Reject if the character is not in the valid alphabet.
            if (Letters.find(c) == std::string::npos) {
                return false;
            }
            // Handling parentheses and brackets using stack.
            if (c == '(') {
                s.push(c);
            } else if (c == ')') {
                if (s.empty() || s.top() != '(') {
                    return false;
                }
                s.pop();
            } else if (c == '[') {
                s.push(c);
            } else if (c == ']') {
                if (s.empty() || s.top() != '[') {
                    return false;
                }
                s.pop();
            }
        }
        // The string is accepted if the stack is empty at the end.
        return s.empty();
    }
};

/**
 * Main function that takes user input, processes it using the PDA,
 * and prints whether the string is accepted or rejected.
 *
 * @return 0 upon successful execution.
 */
int main() {
    PDA pda;
    std::string input;

    std::cout << "Enter a string with matching characters: ";
    getline(std::cin, input);
    
    if (pda.ProcessChar(input)) {
        std::cout << "String \"" << input << "\" is accepted." << std::endl;
    } else {
        std::cout << "String \"" << input << "\" is rejected." << std::endl;
    }
    return 0;
}

/**
 * Example Test Cases:
 * Test 1: Input: "my dog(jack[black])" -> Accepted
 * Test 2: Input: "my dog(jack[black)]" -> Rejected
 * Test 3: Input: "my dog" -> Accepted
 * Test 4: Input: "my dog." -> Rejected (invalid character)
 * Test 5: Input: "my dog (jack)" -> Accepted
 * Test 6: Input: "my dog [jack)" -> Rejected (mismatched brackets)
 */
