# Building
*its recomended that you use the clang c compiler for this, just because it's the one i use, and it guarentees compiler difference issues be resolved*
## debian/ubuntu based
- install packages
```sudo apt install clang cmake && sudo apt update && sudo apt upgrade```
## arch
```sudo pacman -Syu clang cmake```
## compile the code from terminal
- build with cmake
```mkdir build && cd build && cmake ..```
## build with visual studio/vscode
open this with your featured text editor, like visual studio, 
configure the cmake project in any way the editor tells you,
and then just click build