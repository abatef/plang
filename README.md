# Programming Language Interpreter

An implementation of a **Bytecode Virtual Machine**
The VM is a high-performance interpreter for a custom language, capable of executing bytecode instructions efficiently.

## Features

- **Custom Bytecode**: Implements a well-defined set of bytecode instructions to represent program logic compactly.
- **Stack-Based Execution**: Uses a stack-based model for evaluating expressions and executing operations.
- **Dynamic Typing**: Supports operations on dynamically typed values like numbers, strings, and booleans.
- **Control Flow**: Includes bytecode instructions for `if` statements, loops, and function calls.
- **Function Support**: Supports user-defined functions with local variables and a call stack.
- **Error Handling**: Implements robust error detection for runtime issues such as stack overflow, invalid instructions, and type errors.

## Example Usage

```c
> print "Hello, World!";
Hello, World!
> print 2 + 3 * (4 - 1);
11
```

## Building and Running

### Prerequisites
- C compiler (e.g., `gcc` or `clang`)
- Make (optional, for build automation)

### Steps
1. Clone the repository:
   ```bash
   git clone https://github.com/abatef/plang.git
   cd plang
   ```
2. Build the project:
   ```bash
   cmake CMakeLists.txt
   make
   ```
3. Run the interpreter:
   ```bash
   ./plang
   ```

## Limitations
This implementation is a work in progress. It does not include garbage collection or advanced optimizations for memory management.

## Contributions
Contributions are welcome! Feel free to open issues or submit pull requests for new features or improvements.

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.

---
