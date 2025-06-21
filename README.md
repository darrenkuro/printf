<h1 align="center">Printf</h1>

<p align="center">
    <img src="https://img.shields.io/badge/license-MIT-blue.svg" alt="License"/>
    <img src="https://img.shields.io/badge/score-125%2F100-3CB371?style=flat-square&logo=42&logoColor=white" alt="Score"/>
    <img src="https://img.shields.io/static/v1?label=date&message=May%208th,%202023&color=ff6984&logo=Cachet&logoColor=green" alt="Date"/>
</p>

> This repo contains a reimplementation of the standard C printf function. It is part of the 42 common core curriculum. It handles the following specifiers: %c, %s, %p, %d, %i, %u, %x, %X, %%, and the following flags: ., #, space, +, -, 0.

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

Darren Kuro – [darrenkuro@icloud.com](mailto:darrenkuro@icloud.com)  
GitHub: [@darrenkuro](https://github.com/darrenkuro)
