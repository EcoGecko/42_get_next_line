# Get_next_line
##### Graded 125/100.

### About
This project is about creating a function that will read a line from a given file descriptor and returns it in a new allocated variable. It introduces the concepts of file descriptors and static variables.

### Compiling
To compile and use this function you need to compile it together with main.c. This repo contains two sets of function, one that reads from a unique fd and the bonus that can read from multiple fds at a time without losing the reading thread of each fd. The functionality is the same so you can just use the bonus files for example:
```sh
$ cc main.c get_next_line_bonus.c get_next_line_utils_bonus.c
```
