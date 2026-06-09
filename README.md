*This project has been created as part of the 42 curriculum by mgiustin.*

---

# ft_printf

## Description

`ft_printf` is a project from the **42 school curriculum** that consists of re-implementing the standard C library function `printf` from scratch.

The **goal** is to deeply understand two key concepts:
1. **Variadic functions** in C — functions that accept a variable number of arguments (using `stdarg.h` macros: `va_list`, `va_start`, `va_arg`, `va_end`).
2. **Formatted output** — how C parses a format string and dispatches to the correct conversion routine for each format specifier.

The result is delivered as a **static library** (`libftprintf.a`) that can be linked into any C project as a drop-in replacement for `printf`.

### Supported Conversions

| Specifier | Description |
|:---------:|:------------|
| `%c` | Prints a single character |
| `%s` | Prints a string (prints `(null)` if the pointer is NULL) |
| `%p` | Prints a pointer address in hexadecimal format with `0x` prefix (prints `(nil)` if NULL) |
| `%d` | Prints a signed decimal (base 10) integer |
| `%i` | Prints a signed integer in base 10 (identical to `%d` for output) |
| `%u` | Prints an unsigned decimal (base 10) number |
| `%x` | Prints a number in hexadecimal (base 16) lowercase format |
| `%X` | Prints a number in hexadecimal (base 16) uppercase format |
| `%%` | Prints a literal percent sign |

---

## Algorithm and Data Structure

### Overall Architecture

The project is split into two source files:
- **`ft_printf.c`** — contains the main `ft_printf` function, the format string parser (`ft_formatter`), and the string utility (`ft_putstr`).
- **`ft_printf_utils.c`** — contains one dedicated conversion function per specifier.

### Parsing Strategy (ft_printf)

The main function iterates over the format string character by character using a `while` loop and an index `i`:
- If it encounters `%%`, it immediately prints a single `%` and advances by 2.
- If it encounters `%` followed by another character, it increments `i` to skip the `%` and calls `ft_formatter` with the next character (the specifier type).
- Otherwise, it prints the character as-is using `write`.

This approach is simple, linear (`O(n)` where `n` is the length of the format string), and requires no dynamic memory allocation.

### Dispatcher (ft_formatter)

`ft_formatter` receives the specifier character and a `va_list`. It uses a chain of `if/else if` statements to call the correct utility function and extract the argument from the `va_list` using `va_arg` with the correct type:
- `%c` → extracts `int`, stores in `char`, writes with `write`.
- `%s` → extracts `char *`, calls `ft_putstr`.
- `%d`, `%i` → extracts `int`, calls `ft_putnbr`.
- `%u` → extracts `unsigned int`, calls `ft_putunsigned`.
- `%x`, `%X` → extracts `unsigned int`, calls `ft_puthexadecimal`.
- `%p` → extracts `void *`, calls `ft_putptr`.

### Recursive Conversion (Utility Functions)

Each numeric conversion function (integer, unsigned, hexadecimal, pointer) uses the same **recursive base-conversion algorithm**:

```
function print_number(n, base):
    if n >= base:
        print_number(n / base, base)   ← recursive call for higher digits
    print digit(n % base)              ← print current digit last
```

**Why recursion?** It naturally reverses the order of digits. Division extracts the least significant digit last, so by calling recursively first and printing after the return, the digits are printed from most significant to least significant — exactly the expected order.

The call stack itself acts as the data structure that stores intermediate digits, eliminating the need for an explicit buffer or array.

### Pointer Printing (ft_putptr)

`ft_putptr` is split into two functions:
1. **`ft_putptr` (wrapper):** Handles the `NULL` check (prints `(nil)`), prints the `0x` prefix, casts the `void *` pointer to `unsigned long long` (64-bit) to store the full memory address, and calls the recursive helper.
2. **`ft_putptr_recur` (static helper):** Performs the actual base-16 recursive digit printing. It is declared `static` because it is an internal implementation detail not meant to be called directly.

Separating the wrapper from the recursion is essential to avoid printing `0x` on every recursive call.

---

## Instructions

### Compilation

Clone the repository and run `make` at the root of the project:

```bash
make
```

This will compile the source files and produce the static library `libftprintf.a`.

### Available `make` Rules

| Rule | Description |
|:-----|:------------|
| `make` / `make all` | Compiles all source files and creates `libftprintf.a` |
| `make clean` | Removes compiled object files (`.o`) |
| `make fclean` | Removes object files and `libftprintf.a` |
| `make re` | Runs `fclean` then `all` (full recompile) |

### Linking the Library in Your Project

To use `ft_printf` in your own project, include the header and link the library at compile time:

```bash
gcc -Wall -Wextra -Werror your_file.c libftprintf.a -o your_program
```

---
