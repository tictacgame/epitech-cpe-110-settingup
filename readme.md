# Setting Up: Elementary Programming in C

Hi there! This README will guide you through everything you need to know to set up and execute the project, "Setting Up."

## Project Overview

**Project Name**: Setting Up  
**Binary Name**: `setting_up`  
**Language**: C  
**Compilation**: Via `Makefile` (including `re`, `clean`, and `fclean` rules)  

### Authorized Functions

The project only allowed to use the following functions:
- `open`
- `read`
- `write`
- `close`
- `malloc`
- `free`
- `stat`

## Objectives

The goal with this project is to:
- Find the largest square on a board while avoiding obstacles.
- Replace `.` with `x` to represent the largest square I found.
- Make sure the program handles both reading a file for input and generating a board dynamically.

### Board Constraints

Here are the rules for the board:

- The first line of the file contains the number of lines on the board (and only that).
- The board consists of:
  - `.`: Representing an empty space.
  - `o`: Representing an obstacle.
- All lines (except the first) must have the same length.
- The board must contain at least one line.
- Each line ends with a `\n`.

### Program Requirements

Here’s what my program does:

1. **File Reading**:
   - It accepts a file as a program argument and processes its contents as the board layout.

2. **Dynamic Generation**:
   - It generates a board based on input parameters:
     - **Width**: Number of columns.
     - **Height**: Number of rows.
     - **Pattern**: A string that repeats along the board.

3. **Error Handling**:
   - If there’s an issue, it writes error messages to the standard error output.
   - It exits with error code `84` in case of any errors (and `0` if everything works).

### Example

#### Input File

Here’s an example of a file named `example_file`:
```
9
...........................
....o......................
............o..............
...........................
....o......................
..............o............
...........................
......o..............o.....
..o.......o................
```

#### Execution

This is how I’d run it:

```bash
./setting_up example_file
```

#### Output
```
.....xxxxxxx................
....oxxxxxxx................
.....xxxxxxxo...............
.....xxxxxxx................
....oxxxxxxx................
.....xxxxxxx...o............
.....xxxxxxx................
......o...............o.....
..o.......o.................
```

#### Generated Board Example

For dynamically generating a board, I’d do this:

```bash
./setting_up 6 "..o.."
```

Output:
```
..oxx.
.o.xx.
o....o
....o.
...o..
..o...
```

## Directory Structure

Here’s how I’ve organized the project:

```
B-CPE-110-TLS-1-1-SETTINGUP/
├── src/               # Source files for the main program logic.
    ├── functions/     # Some functions about glibc but fork my be to respect resticted functions.
    └── include/       # Header files with function declarations.
├── Makefile           # Compilation rules (re, clean, fclean).
└── README.md          # This file.
```

## Compilation and Execution

Here’s how I build and run the program:

1. Compile the program using `make`:
   ```bash
   make
   ```

2. Run it with a file:
   ```bash
   ./setting_up <filename>
   ```

3. Generate and solve a board dynamically:
   ```bash
   ./setting_up <width> <height> <pattern>
   ```

Thanks for checking out my epitech project, and happy coding!
