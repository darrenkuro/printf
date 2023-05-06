# ft_printf

## Relevant flags

N/A = undefined behavior, sp = space.

| flags | - | . | 0 | sp | + | # |
| --- | --- | --- | --- | --- | --- | --- |
| di | Y | Y | Y | Y | Y | N/A |
| u  | Y | Y | Y | N/A | N/A | N/A |
| xX | Y | Y | Y | N/A | N/A | prefix 0x/0X |
| p  | Y | N/A | N/A | N/A | N/A | N/A |
| cs | Y | Y | N/A | N/A | N/A | N/A |

- '-' overrides '0' if both are used.
- '+' overrides ' ' if both are used.
