*This project has been created as part of the 42 curriculum by aelberka.*

# get_next_line

## Description

A C function that reads one line per call from a file descriptor, including standard input.

```c
char *get_next_line(int fd);
```

The returned line includes `\n` when present. The function returns `NULL` at the end of the input or on error. The caller must free each returned line.

## Instructions

Use a test `main.c` that opens `test.txt`, calls `get_next_line` until it returns `NULL`, frees each line, and closes the file. Compile and run:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl_test
./gnl_test
```

`BUFFER_SIZE` controls the bytes requested per read, not the line length. Without `-D BUFFER_SIZE=42`, the default is `20`. To test standard input, call the function with file descriptor `0`.

## Algorithm

1. Check the arguments and allocate a reading buffer.
2. Read chunks, add `\0`, and join them to the stored text. Free the previous allocation after joining. Stop when the collected text contains `\n` or reading reaches the end. On a read error, free the stored text and return `NULL`.
3. Free the reading buffer. Separate the first line, keeping its `\n` if present.
4. Copy any text after that line into a static pointer for the next call. Return the line. At the end of input, return any final text without a newline, then `NULL` on the following call.

A static pointer remembers remaining text between calls. This prevents losing bytes when one read contains several lines. Dynamic allocation supports lines longer than `BUFFER_SIZE`. String joining is simple, but repeatedly copies text for long lines.

## Resources

- Project subject.
- [GeeksforGeeks: Static Variables in C](https://www.geeksforgeeks.org/c/static-variables-in-c/).
- [read manual](https://man7.org/linux/man-pages/man2/read.2.html).
- [malloc and free manual](https://man7.org/linux/man-pages/man3/malloc.3.html).

AI helped review the code, explain pointers, static variables and file descriptors, and suggest checking saved text before reading again.
