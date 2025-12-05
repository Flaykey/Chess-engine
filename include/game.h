#pragma once
#include<stdio.h>
#include<raylib.h>
#include"assets.h"
#include"chess.h"


extern Texture2D texArray[13];
extern TURN turn;
extern uint64_t moves;

void SetupBoard(PIECES* board, const char* position);
void loadTexarray();
void DrawBoard(PIECES* board);
void Input();
void InitGame(int w, int h, const char* c);
void RunGame();
void CloseGame();