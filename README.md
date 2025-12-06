# A Chess Engine(In Progress)

- This is a project to learn how chess engines work(It is not meant to be performant).
- In this project the raylib library is used to do the rendering of the chess board.

# Board Preview
![Alt text](readme_images/boardPreview.png)

# How to compile
- Since the raylib library is statically linked

```bash
gcc assets.c game.c chess.c main.c -o main.exe -lraylib
```