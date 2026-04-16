# _printf

A custom implementation of the C standard library `printf` function, developed as part of the **Holberton School** low-level programming curriculum. This project demonstrates a deep understanding of variadic functions, formatted output, and modular C programming.

---

## Table of Contents

- [Description](#description)
- [File Structure](#file-structure)
- [Usage](#usage)
- [Examples](#examples)
- [Flowchart](#flowchart)
- [Man Page](#man-page)
- [Authors](#authors)

---

## Description

`_printf` is a custom function that mimics the behavior of the standard C library function `printf(3)`. It processes a format string and outputs characters to `stdout`, handling conversion specifiers that begin with `%`.

When an unknown specifier is encountered, `_printf` prints the `%` character followed by the unknown character literally.

**Return value:**
- On success: the total number of characters printed.
- On failure: `-1` if the format string is `NULL` or if a `%` is the last character in the format string.

---


## File Structure

| File                 | Description                                              |
|----------------------|----------------------------------------------------------|
| `main.h`             | Header file with function prototypes and includes        |
| `_printf.c`          | Core `_printf` function and specifier dispatcher         |
| `print_functions.c`  | Handler functions: `print_char`, `print_string`, `print_percent` |
| `_printf.3`          | Man page for `man_3_printf`                                   |

---


## Usage

Include the header in your C file and call `_printf` the same way you would call `printf`:

```c
#include "main.h"

int main(void)
{
    _printf("Hello, %s!\n", "World");
    _printf("Character: %c\n", 'H');
    _printf("Percent: %%\n");
    return (0);
}
```

**Output:**
```
Hello, World!
Character: H
Percent: %
```

---

## Examples

### Handling NULL strings
```c
_printf("Value: %s\n", NULL);
```


### Unknown specifier (prints literally)
```c
_printf("%r\n");
```


### Counting characters
```c
int len = _printf("Hi %s\n", "there");
_printf("Printed %d chars\n", len);
```

---

## Flowchart

```
         ┌─────────────────────┐
         │   _printf(format)   │
         └─────────┬───────────┘
                   │
          ┌────────▼────────┐
          │ format == NULL?  │──── Yes ───► return (-1)
          └────────┬────────┘
                   │ No
          ┌────────▼────────┐
          │  Read format[i]  │◄──────────────────┐
          └────────┬────────┘                    │
                   │                             │
          ┌────────▼────────┐                    │
          │  Is it '%' ?     │── No ──► write char, count++
          └────────┬────────┘                    │
                   │ Yes                         │
          ┌────────▼────────┐                    │
          │ Read next char   │                   │
          │ format[i+1]      │                   │
          └────────┬────────┘                    │
                   │                             │
          ┌────────▼────────┐                    │
          │ Is it '\0' ?     │── Yes ──► return (-1)
          └────────┬────────┘                    │
                   │ No                          │
          ┌────────▼────────┐                    │
          │ Find matching    │                   │
          │ handler function │                   │
          └────────┬────────┘                    │
                   │                             │
            ┌──────┴──────┐                      │
         Found         Not Found                 │
            │              │                     │
     ┌──────▼──────┐ ┌────▼──────────┐           │
     │ Call handler │ │ Print '%' +   │          │
     │ count += ret │ │ unknown char  │          │
     └──────┬──────┘ └────┬──────────┘           │
            │              │                     │
            └──────┬───────┘                     │
                   │                             │
          ┌────────▼────────┐                    │
          │  i++, continue   │───────────────────┘
          └────────┬────────┘
                   │ (when format[i] == '\0')
          ┌────────▼────────┐
          │  return (count)  │
          └─────────────────┘
```

---

## Authors

- **AbdullaH Alzara** — [GitHub](https://github.com/JSAbdullaH)
- **Afnan Aljohani** — [GitHub](https://github.com/AfnanAljohani)

> Holberton School — Low-Level Programming Project
