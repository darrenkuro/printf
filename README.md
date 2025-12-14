<h1 align="center">Printf</h1>

<p align="center">
    <img src="https://img.shields.io/badge/license-MIT-blue.svg" alt="License"/>
    <img src="https://img.shields.io/badge/score-125%2F100-3CB371?style=flat-square&logo=42&logoColor=white" alt="Score"/>
    <img src="https://img.shields.io/static/v1?label=date&message=May%208th,%202023&color=ff6984&logo=Cachet&logoColor=green" alt="Date"/>
</p>

> This repo contains a reimplementation of the standard C printf function. It is part of the 42 common core curriculum. It handles the following specifiers: %c, %s, %p, %d, %i, %u, %x, %X, %%, and the following flags: ., #, space, +, -, 0.

---

## 🚀 Overview

This project implements `ft_printf`, a drop-in, format-string-driven printing function compatible with the most commonly used subset of C’s `printf`. The goal is to: A) learn variadic functions and format parsing, B) handle edge cases and undefined behaviors safely, and C) write a small, reusable formatting library that can be linked into other 42 projects.

## 🧰 Tech Stack: ![C](https://img.shields.io/badge/-C-A8B9CC?style=flat-square&logo=C&logoColor=black) ![Make](https://img.shields.io/badge/-Make-000000?style=flat-square&logo=gnu&logoColor=white)

## 📦 Features

- **Core specifiers**: characters, strings, pointers, signed/unsigned integers, hex (lower/upper), and literal `%`.
- **Flags & width/precision**: `-`, `0`, `#`, `+`, space; field width and precision for supported specifiers.
- **Robust edge handling**: null strings, zero precision on integers, pointer formatting with `0x` prefix, integer limits.
- **No libc `printf`**: implemented parsing, conversion, and output from scratch (except permitted libc calls like `write`).
- **Modular design**: parser → dispatcher → printers; easy to extend or unit-test components.

---

## 🛠️ Configuration

### Prerequisites
- **Compiler:** `gcc` or `clang`
- **Build tool:** `make`

### Installation & Usage
```bash
git clone https://github.com/darrenkuro/printf.git && cd printf
make # build libftprintf.a
clang main.c libftptinf.a -Iinclude
```

### Examples & Demo
```c
#include "ft_printf.h"

int main(void) {
    // char: A | string: abcde     |
    ft_printf("char: %c | string: %-10.5s|\n", 'A', "abcdef");

    // d:-123 i:123 u:4294967295
    ft_printf("d:%d i:%i u:%u\n", -123, 123, 4294967295u);

    // hex lower:0xbeef | upper:0XBEEF
    ft_printf("hex lower:%#x | upper:%#X\n", 0xbeef, 0xBEEF);

    // width:      42 | left:42       | zero:00000042 | prec:00042
    ft_printf("width:%8d | left:%-8d | zero:%08d | prec:%.5d\n", 42, 42, 42, 42);

    // ptr:0x16f746854 | null:(nil)
    int x = 7;
    ft_printf("ptr:%p | null:%p\n", &x, NULL);

    // progress: 100%
    ft_printf("progress: 100%%\n");
    return 0;
}

```

---

## 📝 Notes

### Relevant flags

N/A = undefined behavior, sp = space.

|     | -   | .   | 0   | sp  | +   | #            |
| --- | --- | --- | --- | --- | --- | ------------ |
| di  | Y   | Y   | Y   | Y   | Y   | N/A          |
| u   | Y   | Y   | Y   | N/A | N/A | N/A          |
| xX  | Y   | Y   | Y   | N/A | N/A | prefix 0x/0X |
| p   | Y   | N/A | N/A | N/A | N/A | N/A          |
| cs  | Y   | Y   | N/A | N/A | N/A | N/A          |

- '-' overrides '0' if both are used.
- '+' overrides ' ' if both are used.

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).

---

## 📫 Contact

Darren Kuro – [darren0xa@gmail.com](mailto:darren0xa@gmail.com)
GitHub: [@darrenkuro](https://github.com/darrenkuro)

