# Pushdown Automaton (PDA) in C++

## Overview
This project implements a **Pushdown Automaton (PDA)** in C++ that processes strings containing the characters `{a-z, ␢, (, ), [, ]}` and determines whether they are accepted based on balanced parentheses and brackets.

## Features
- Implements **stack-based processing** for parentheses and brackets.
- Ensures that only valid characters are accepted.
- Determines if a string is **accepted** based on balance rules.
- Handles user input dynamically.

## How It Works
1. **Initialize the Automaton**: A `PDA` object is created.
2. **Process Input**:
   - The user enters a string consisting of `a-z, ␢, (, ), [, ]`.
   - The automaton verifies that only valid characters are present.
   - It uses a **stack** to track opening and closing brackets/parentheses.
3. **Stack Operations**:
   - Push opening brackets `(`, `[` onto the stack.
   - Pop them when encountering matching closing brackets `)`, `]`.
   - If a closing bracket does not match the expected top of the stack, the string is **rejected**.
4. **Output Result**: Displays whether the input string is **accepted** or **rejected**.

## Installation
Ensure you have a C++ compiler installed. You can use **GCC** or **MSVC**.

## Compilation & Execution
### Using g++
```bash
g++ -o pda pda.cpp
./pda
```
### Using MSVC (Windows)
```powershell
cl pda.cpp
pda.exe
```

## Example Output
```
Enter a string with matching characters: my dog(jack[black])
String "my dog(jack[black])" is accepted.
```
```
Enter a string with matching characters: my dog(jack[black)]
String "my dog(jack[black)]" is rejected.
```

## Example Test Cases
| Test # | Input                     | Expected Output  |
|--------|---------------------------|------------------|
| 1      | "my dog(jack[black])"      | Accepted        |
| 2      | "my dog(jack[black)]"      | Rejected        |
| 3      | "my dog"                   | Accepted        |
| 4      | "my dog."                   | Rejected        |
| 5      | "my dog (jack)"            | Accepted        |
| 6      | "my dog [jack)"            | Rejected        |

## License
This project is open-source and free to use.
