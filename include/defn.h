#pragma once
#define TILE_SIZE 128
typedef enum{
    EMPTY,
    WPAWN,
    WROOK,
    WKNIGHT,
    WBISHOP,
    WQUEEN,
    WKING,
    BPAWN,
    BROOK,
    BKNIGHT,
    BBISHOP,
    BQUEEN,
    BKING
}PIECES;

typedef enum{
    LIGHT,
    DARK,
    LIGHTALT,
    DARKALT
}TILE;