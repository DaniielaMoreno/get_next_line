_This project has been created as part of the 42 curriculum by danimore._

## Description

`get_next_line` is a C function that reads and returns the next line from a file descriptor, one line at a time. The project focuses on implementing efficient file I/O handling, dynamic memory management, and string manipulation.

The primary goal is to create a reusable function that can read from any file descriptor (including standard input) and return complete lines sequentially, making it useful for processing text files, parsing input, and understanding low-level file operations in C.

**Key Features:**

- Reads from any valid file descriptor
- Returns one complete line per call (including the newline character if present)
- Handles files of any size
- Uses configurable buffer size for flexibility
- Manages memory efficiently to avoid leaks

## Mandatory Part

The core functionality includes:

- **`get_next_line(int fd)`**: Main function that returns the next line from file descriptor `fd`
- **`ft_read()`**: Reads chunks from the file and accumulates data until a newline is found
- **`ft_clean_line()`**: Extracts the current line (up to and including the newline)
- **`ft_rest_line()`**: Preserves remaining data for the next call
- **Utility Functions**: String manipulation helpers (`ft_strlen`, `ft_strchr`, `ft_strjoin`, `ft_memset` and `ft_calloc`)

## Visual Representation

The following diagram illustrates the main process flow of the `get_next_line` function:

![get_next_line Flow Diagram](https://github.com/DaniielaMoreno/get_next_line/blob/main/img/Visual_representation.png?raw=true)

## Bonus Part

The bonus implementation includes all mandatory features plus:

- **Multiple File Descriptor Support**: Uses an array of static buffers to handle reading from multiple file descriptors simultaneously without interference
- **Optimized Buffer Management**: Each file descriptor maintains its own buffer, allowing seamless switching between different files
- **Enhanced Memory Efficiency**: Properly manages separate states for concurrent file reading operations

## Instructions

### Compilation

The project should be compiled with standard flags:

```bash
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -o program
```

### Key Parameters

- **BUFFER_SIZE**: Defines the chunk size for each read operation. Smaller values (like 3) are useful for testing; larger values (like 4096) are more efficient for production. Default is 3.
- **File Descriptor**: Any valid file descriptor can be used (0 for stdin, or an open file descriptor)

## Algorithm Explanation

### Strategy: Static Buffer with Newline Accumulation

The `get_next_line` implementation uses a static buffer approach combined with cumulative string joining:

1. **Initialization**: Each call checks if a static buffer already contains leftover data from the previous read. If not, create a fresh buffer.

2. **Incremental Reading**: Read `BUFFER_SIZE` bytes at a time from the file descriptor into a temporary buffer. This prevents unnecessary large allocations and is memory-efficient.

3. **Data Accumulation**: Join the static buffer with the newly read data using `ft_strjoin()`. This builds up the raw line incrementally until a newline character is found.

4. **Newline Detection**: After each read, check if the accumulated data contains `\n` using `ft_strchr()`. Stop reading once found.

5. **Line Extraction**: `ft_clean_line()` extracts only the current line (from start to and including the newline), removing unnecessary data.

6. **State Preservation**: `ft_rest_line()` extracts any data _after_ the newline and stores it as the new static buffer for the next `get_next_line()` call.

7. **Edge Cases**: Handle EOF (no newline at end of file), empty files, and files with no newlines.

### Why This Algorithm?

- **Memory Efficiency**: Reading in small chunks prevents allocating huge buffers for large files
- **Simplicity**: The cumulative joining approach is straightforward and easy to debug
- **Correctness**: Preserving state between calls allows seamless multi-line reading
- **Flexibility**: Works with any file descriptor and buffer size

### Important Implementation Details

- **Static Variable**: The `line` variable in `get_next_line()` persists between calls, maintaining state across multiple invocations
- **Overflow Protection**: `ft_strjoin()` includes checks to prevent integer overflow when allocating very large buffers
- **Memory Management**: Each temporary buffer is freed after use; the caller is responsible for freeing returned lines
- **NULL Handling**: Returns NULL on EOF or if an error occurs (invalid fd, allocation failure)

## Bonus Algorithm Explanation

The bonus version extends the static buffer concept to support multiple file descriptors:

- **Parallel Buffers**: Instead of a single static `line` variable, maintain an array of buffers indexed by file descriptor
- **Independent States**: Each file descriptor has its own buffer state, allowing you to call `get_next_line()` on fd=3, then fd=5, then fd=3 again without losing data
- **Array Bounds**: The array size accommodates typical file descriptor ranges (usually 0-255 or based on `OPEN_MAX`)

This allows reading from multiple files simultaneously without manual state management.

## Resources

### Documentation

- [man read](https://linux.die.net/man/2/read): Understanding the read() system call
- [man malloc](https://linux.die.net/man/3/malloc): Dynamic memory allocation
- [C Standard Library](https://en.cppreference.com/w/c): String and memory functions

### Articles & References

- File I/O in C: Understanding file descriptors and buffering
- Memory management best practices in C
- Static variables in C and their scope/lifetime

### 42 Resources

- 42 School Norm documentation
- The C Piscine lectures on file I/O

## AI Usage

AI was used for the following tasks in this project:

- **Debugging and Optimization**: Identifying and explaining the integer overflow vulnerability in `ft_strjoin()` when processing very large lines, and providing corrected code with proper bounds checking
- **Code Review**: Analyzing the malloc behavior with edge cases and suggesting improvements to memory management
- **Documentation**: Generating comprehensive explanations of the algorithm, technical choices, and implementation details for this README

AI did not write the core implementation code; all functionality was developed independently following 42 curriculum requirements.

## Notes

- The project must be compiled with the `-Wall -Wextra -Werror` flags as per 42 standards
- Memory leaks must be avoided; use tools like `valgrind` to verify
- The function is not thread-safe due to static variables
- Performance improves significantly with larger BUFFER_SIZE values for large files
