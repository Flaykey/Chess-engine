#pragma once

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
extern int bKingSideCastle;
extern int bQueenSideCastle;
extern int wKingSideCastle;
extern int wQueenSideCastle;
extern int enpassant;
extern int gameOver;

