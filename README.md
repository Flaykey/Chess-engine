# A Chess Engine(In Progress)

- This is a project to learn how chess engines work(It is not meant to be performant).
- In this project the raylib library is used to do the rendering of the chess board.

# Board Preview
![Alt text](readme_images/boardPreview.png)

# How to compile
- Since the raylib library is statically linked you can run the following command in your terminal.
- If the following doesn't Work you have to link other libraries that raylib depends on , for that you can try the alternative code.
```bash
gcc assets.c game.c chess.c main.c -o main.exe -lraylib
```
- ALTERNATE
```bash
gcc assets.c game.c chess.c main.c -o main.exe -lraylib -lraylib -lopengl32 -lgdi32 -lwinmm
```