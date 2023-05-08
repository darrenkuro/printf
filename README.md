<h1 align="center">FT_PRINTF</h1>

<p align="center">
    <img alt="score" src="https://img.shields.io/static/v1?label=passed&message=125/100&color=brightgreen&logo=42&logoColor=green">
    <img alt="date" src="https://img.shields.io/static/v1?label=date&message=May%208th,%202023&color=ff6984&logo=Cachet&logoColor=green">
    <img alt="size" src="https://img.shields.io/github/languages/code-size/darrenkuro/42_ft_printf?label=size">
    <img alt="loc" src="https://img.shields.io/tokei/lines/github/darrenkuro/42_ft_printf?label=lines">
    <img alt="file" src="https://img.shields.io/github/directory-file-count/darrenkuro/42_ft_printf/submitted/srcs?label=files">
    <img alt="commit" src="https://img.shields.io/github/last-commit/darrenkuro/42_ft_printf">
</p>

### Relevant flags

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
