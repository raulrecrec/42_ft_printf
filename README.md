*This project has been created as part of the 42 curriculum by rexposit.*

# ft_printf

`ft_printf` is a 42 Madrid project written in C.

The goal of the project is to recreate a simplified version of the standard C `printf` function.
This implementation handles formatted output using variadic arguments and returns the number of printed characters.

The project is compiled as a static library:

```bash
libftprintf.a
```

---

## Table of Contents

* [Description](#description)
* [Project Rules](#project-rules)
* [Supported Conversions](#supported-conversions)
* [Implementation Overview](#implementation-overview)
* [How It Works](#how-it-works)
* [Instructions](#instructions)
* [Usage Examples](#usage-examples)
* [Testing](#testing)
* [Error Handling](#error-handling)
* [Project Structure](#project-structure)
* [What I Learned](#what-i-learned)
* [Resources](#resources)
* [Author](#author)

---

## Description

`ft_printf` is a custom implementation of part of the standard `printf` behavior.

The function receives a format string and a variable number of arguments.
It prints the formatted output to standard output and returns the number of characters printed.

Example:

```c
ft_printf("Hello %s, number: %d\n", "42", 2024);
```

Output:

```text
Hello 42, number: 2024
```

Return value:

```text
23
```

This project focuses on:

* variadic functions;
* format string parsing;
* type conversion;
* output with `write`;
* hexadecimal and pointer formatting;
* returning the correct printed length.

---

## Project Rules

The project must:

* be written in C;
* follow the 42 Norm;
* compile with `-Wall -Wextra -Werror`;
* provide a `Makefile`;
* create the static library `libftprintf.a`;
* implement a function named `ft_printf`;
* not implement the original `printf` by calling it internally;
* handle the required format conversions;
* return the number of printed characters.

The function prototype is:

```c
int ft_printf(const char *format, ...);
```

---

## Supported Conversions

This implementation supports the following conversions:

| Conversion | Description                                         |
| ---------- | --------------------------------------------------- |
| `%c`       | Prints a single character                           |
| `%s`       | Prints a string                                     |
| `%p`       | Prints a pointer address in hexadecimal format      |
| `%d`       | Prints a signed decimal integer                     |
| `%i`       | Prints a signed decimal integer                     |
| `%u`       | Prints an unsigned decimal integer                  |
| `%x`       | Prints an unsigned hexadecimal integer in lowercase |
| `%X`       | Prints an unsigned hexadecimal integer in uppercase |
| `%%`       | Prints a percent sign                               |

This project does not implement the full standard `printf` feature set, such as width, precision or flags.
It focuses on the mandatory conversions required by the 42 project.

---

## Implementation Overview

The project is divided into small files, each responsible for one part of the formatting process.

### Main formatter

The main `ft_printf` function:

* starts the variadic argument list with `va_start`;
* loops through the format string;
* prints normal characters directly;
* detects `%` conversions;
* delegates each conversion to `ft_format`;
* ends the variadic argument list with `va_end`;
* returns the total number of printed characters.

### Format dispatcher

`ft_format` receives the conversion character and the current `va_list`.

Depending on the conversion, it calls the correct helper function:

* `ft_putlchar` for characters;
* `ft_putlstr` for strings;
* `ft_putlnbr` for signed integers;
* `ft_putlnbr_base_xup` for hexadecimal, unsigned integers and pointers.

### Output helpers

The helper functions print values using `write`.

They also return the number of characters printed, allowing `ft_printf` to keep an accurate final count.

---

## How It Works

The function processes the format string from left to right.

Example:

```c
ft_printf("Value: %d\n", 42);
```

Step by step:

```text
V -> printed directly
a -> printed directly
l -> printed directly
u -> printed directly
e -> printed directly
: -> printed directly
space -> printed directly
%d -> replaced by the integer argument
\n -> printed directly
```

The `%d` conversion consumes one argument from the variadic argument list:

```c
va_arg(value, int)
```

Then the integer is printed and the amount of printed characters is added to the final return value.

---

## Conversion Details

### Characters

```c
ft_printf("%c", 'A');
```

Output:

```text
A
```

### Strings

```c
ft_printf("%s", "Hello");
```

Output:

```text
Hello
```

If the string is `NULL`, this implementation prints:

```text
(null)
```

### Signed integers

```c
ft_printf("%d", -42);
ft_printf("%i", 42);
```

Output:

```text
-42
42
```

### Unsigned integers

```c
ft_printf("%u", 4294967295);
```

Output:

```text
4294967295
```

### Hexadecimal

```c
ft_printf("%x", 255);
ft_printf("%X", 255);
```

Output:

```text
ff
FF
```

### Pointers

```c
ft_printf("%p", ptr);
```

Output example:

```text
0x7ffee3b8c8ac
```

If the pointer is `NULL`, this implementation prints:

```text
(nil)
```

### Percent sign

```c
ft_printf("%%");
```

Output:

```text
%
```

---

## Instructions

### Clone the repository

```bash
git clone https://github.com/raulrecrec/42_ft_printf.git
cd 42_ft_printf
```

### Compile

```bash
make
```

This creates:

```bash
libftprintf.a
```

### Makefile rules

```bash
make        # Compile the library
make clean  # Remove object files
make fclean # Remove object files and the library
make re     # Recompile from scratch
```

---

## Usage Examples

Since this project creates a static library, you can use it by compiling it with a test file.

Example `main.c`:

```c
#include "ft_printf.h"

int main(void)
{
    int count;

    count = ft_printf("Hello %s! Number: %d\n", "42", 2024);
    ft_printf("Printed characters: %d\n", count);
    return (0);
}
```

Compile with the library:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test_printf
```

Run:

```bash
./test_printf
```

Expected output:

```text
Hello 42! Number: 2024
Printed characters: 23
```

---

## Testing

A useful way to test `ft_printf` is to compare its output and return value with the original `printf`.

Example test file:

```c
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int original;
    int custom;

    original = printf("Original: %s %d %x\n", "test", 42, 255);
    custom = ft_printf("Custom: %s %d %x\n", "test", 42, 255);

    printf("printf returned: %d\n", original);
    ft_printf("ft_printf returned: %d\n", custom);

    return (0);
}
```

Compile:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test_printf
```

Run:

```bash
./test_printf
```

### Suggested test cases

```c
ft_printf("Hello world\n");
ft_printf("Character: %c\n", 'A');
ft_printf("String: %s\n", "42 Madrid");
ft_printf("Null string: %s\n", NULL);
ft_printf("Decimal: %d\n", -42);
ft_printf("Integer: %i\n", 42);
ft_printf("Unsigned: %u\n", 4294967295u);
ft_printf("Hex lower: %x\n", 255);
ft_printf("Hex upper: %X\n", 255);
ft_printf("Pointer: %p\n", &main);
ft_printf("Null pointer: %p\n", NULL);
ft_printf("Percent: %%\n");
```

### Memory test

This project mainly writes output and does not require dynamic allocation for the implemented conversions.

Still, you can run a test program with Valgrind:

```bash
valgrind --leak-check=full ./test_printf
```

---

## Error Handling

This implementation handles some important edge cases:

* `NULL` strings are printed as `(null)`;
* `NULL` pointers are printed as `(nil)`;
* normal characters are printed directly;
* unknown conversions do not trigger a specific formatted output;
* the function returns the total number of printed characters.

The return value is important because `printf`-style functions are expected to report how many characters were written.

---

## Project Structure

```text
.
├── Makefile
├── ft_printf.c
├── ft_printf.h
├── ft_format.c
├── ft_numlen.c
├── ft_putlchar.c
├── ft_putlstr.c
├── ft_putlnbr.c
└── ft_putlnbr_base.c
```

### Main files

| File                | Purpose                                                          |
| ------------------- | ---------------------------------------------------------------- |
| `ft_printf.c`       | Main function, format string loop and variadic argument handling |
| `ft_format.c`       | Conversion dispatcher                                            |
| `ft_putlchar.c`     | Character output                                                 |
| `ft_putlstr.c`      | String output and `NULL` string handling                         |
| `ft_putlnbr.c`      | Signed integer output                                            |
| `ft_numlen.c`       | Signed integer length calculation                                |
| `ft_putlnbr_base.c` | Hexadecimal, unsigned integer and pointer output                 |
| `ft_printf.h`       | Function prototypes and required includes                        |
| `Makefile`          | Compilation rules for `libftprintf.a`                            |

---

## What I Learned

This project helped me practice several important C programming concepts:

* using variadic functions with `va_list`, `va_start`, `va_arg` and `va_end`;
* parsing a format string character by character;
* dispatching behavior based on conversion specifiers;
* printing different data types using only low-level output functions;
* converting integers to decimal and hexadecimal representations;
* handling signed and unsigned values;
* printing pointer addresses;
* keeping track of the number of printed characters;
* organizing a small C library with a Makefile;
* testing behavior against the standard `printf`.

The most important lesson from this project was understanding how formatted output works internally: parsing text, consuming arguments in order, converting values and counting the final output length.

---

## Resources

Useful resources related to this project:

* 42 ft_printf subject
* 42 Norm documentation
* `man printf`
* `man write`
* `man stdarg`
* C variadic functions documentation
* ASCII table references
* Integer representation in C
* Hexadecimal number system references
* Static library creation with `ar`

---

## Author

Project developed by:

```text
rexposit
```

42 Madrid student.
