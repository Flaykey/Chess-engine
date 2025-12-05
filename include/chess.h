#pragma once
#include <stdint.h>
#include <stdlib.h>
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
extern int selectedMask[64];
extern int selectedPieceIndex;
extern int bKingSideCastle;
extern int bQueenSideCastle;
extern int wKingSideCastle;
extern int wQueenSideCastle;
extern int enpassant;
extern int gameOver;

extern int knightmoves[8][2];

int* IndexToCoord(int id);
int CoordToIndex(int* postion);
int* MovesToIndex(uint64_t moves);
int MovesCount(uint64_t moves);
uint64_t MoveGeneration(PIECES piece,int index);
