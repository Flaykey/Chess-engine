#pragma once
#include<stdio.h>
#include<raylib.h>
#include"assets.h"

typedef enum Pieces{
    EMPTY,
    BPAWN,
    BROOK,
    BKNIGHT,
    BBISHOP,
    BKING,
    BQUEEN,
    WPAWN,
    WROOK,
    WKNIGHT,
    WBISHOP,
    WKING,
    WQUEEN
} PIECES;

typedef enum Turn{
    WHITES,
    BLACKS
} TURN;

extern PIECES board[64];
extern Texture2D texArray[13];
extern TURN turn;
extern int bKingSideCastle;
extern int bQueenSideCastle;
extern int wKingSideCastle;
extern int wQueenSideCastle;
extern int enpassant;
extern int gameOver;

void SetupBoard(PIECES* board, const char* position);
void loadTexarray();
void DrawBoard(PIECES* board);
void Input();
void InitGame(int w, int h, const char* c, const char* p);
void RunGame();
void CloseGame();