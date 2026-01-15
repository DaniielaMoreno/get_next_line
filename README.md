_This project has been created as part of the 42 curriculum by danimore._

## Description

`get_next_line` is a C function that reads and returns the next line from a file descriptor, one line at a time. The project focuses on implementing efficient file I/O handling (open and read), dynamic memory management, and string manipulation.

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

![get_next_line Flow Diagram](https://github.com/DaniielaMoreno/get_next_line/blob/main/img/Visual%20explanation%20by%20Daniela%20Moreno.png?raw=true)

## Bonus Part

The bonus implementation includes:

- **Multiple File Descriptor Support**: Uses an array of static buffers to handle reading from multiple file descriptors simultaneously without interference
- **Use of only one static variable**

## Instructions

### Compilation

The project should be compiled with standard flags:

```bash
gcc gcc -Wall -Werror -Wextra -D BUFFER_SIZE=xx get_next_line.c get_next_line_utils.c
```

### Key Parameters

- **BUFFER_SIZE**: Defines the chunk size for each read operation. Smaller values (like 3) are useful for testing; larger values (like 4096) are more efficient for production. Default is 3.
- **File Descriptor**: Any valid file descriptor can be used (0 for stdin, or an open file descriptor)

## Algorithm Explanation

### Strategy: Static Buffer with Newline Accumulation

The `get_next_line` implementation uses a static buffer approach combined with cumulative string joining:

1. **Initialization**: Each call checks if the static buffer (raw_line) already contains leftover data from the previous read. If not, allocate memory for the static buffer and create another buffer to store de chunks of BUFFER_SIZE of each read.

2. **Newline Detection**: Before each read, check if the accumulated data contains `\n` using `ft_strchr()`. Stop reading once found or reached EOF.

3. **Incremental Reading**: Read `BUFFER_SIZE` bytes at a time from the file descriptor into the buffer.

4. **Data Accumulation**: Join the static buffer with the newly read data using `ft_strjoin()`. This builds up the "raw_line" incrementally.

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
- **Array Bounds**: The array size accommodates typical file descriptor ranges (based on `OPEN_MAX`)

This allows reading from multiple files simultaneously without manual state management.

## Resources

### Articles & References

- Memory management best practices in C - GeeksforGeeks(https://www.geeksforgeeks.org/c/static-variables-in-c/)
- read() — Read from a file or socket - IBM Documentation help (https://www.ibm.com/docs/en/zos/3.1.0?topic=functions-read-read-from-file-socket)

### 42 Resources

- 42 School Norm documentation

## AI Usage

AI was used for the following tasks in this project:

- **Debugging and Optimization**: Identifying and explaining the integer overflow vulnerability in `ft_strjoin()` when processing very large lines
- **Documentation**: Generating comprehensive explanations of the algorithm, technical choices, and implementation details for this README

AI did not write the core implementation code; all functionality was developed independently following 42 curriculum requirements.

## Notes

- The project must be compiled with the `-Wall -Wextra -Werror` flags as per 42 standards
- Memory leaks must be avoided; use tools like `valgrind` to verify
- The function is not thread-safe due to static variables
- Performance improves significantly with larger BUFFER_SIZE values for large files
