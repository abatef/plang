# Bytecode Virtual Machine Implementation

An implementation of a **Bytecode Virtual Machine**
The VM is a high-performance interpreter for a custom language, capable of executing bytecode instructions efficiently.

## Features

- **Custom Bytecode**: Implements a well-defined set of bytecode instructions to represent program logic compactly.
- **Stack-Based Execution**: Uses a stack-based model for evaluating expressions and executing operations.
- **Dynamic Typing**: Supports operations on dynamically typed values like numbers, strings, and booleans.
- **Control Flow**: Includes bytecode instructions for `if` statements, loops, and function calls.
- **Function Support**: Supports user-defined functions with local variables and a call stack.
- **Error Handling**: Implements robust error detection for runtime issues such as stack overflow, invalid instructions, and type errors.

## Architecture

The virtual machine consists of the following components:

1. **Chunk**: A container for bytecode instructions and constants.
2. **Value Stack**: A stack used to manage intermediate values during execution.
3. **Call Stack**: A separate stack to handle function calls and return addresses.
4. **Instruction Set**: A collection of operations like arithmetic, logical operations, jumps, and function calls.
5. **Interpreter Loop**: A `switch`-based loop that fetches and executes instructions one by one.

### Example Instruction Set

| Instruction      | Description                               |
|------------------|-------------------------------------------|
| `OP_CONSTANT`    | Push a constant value onto the stack.     |
| `OP_ADD`         | Pop two values, add them, and push result.|
| `OP_SUBTRACT`    | Pop two values, subtract, and push result.|
| `OP_MULTIPLY`    | Pop two values, multiply, and push result.|
| `OP_DIVIDE`      | Pop two values, divide, and push result.  |
| `OP_RETURN`      | End the current function and return.      |

### Control Flow Instructions

- `OP_JUMP`: Unconditionally jump to a specified instruction.
- `OP_JUMP_IF_FALSE`: Jump if the top stack value is false.
- `OP_LOOP`: Jump backward for loops.

## Code Structure

- **`chunk.h` and `chunk.c`**: Defines the `Chunk` structure, which stores bytecode and constants.
- **`value.h` and `value.c`**: Implements a flexible value system supporting multiple data types.
- **`vm.h` and `vm.c`**: Contains the core virtual machine logic, including the stack and instruction loop.
- **`compiler.h` and `compiler.c`**: Compiles source code into bytecode for the VM to execute.
- **`main.c`**: Entry point for the program, handling user input and executing scripts.

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
