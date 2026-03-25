#pragma once
#include <stdint.h>
#include<stdlib.h>

#define RANK_1 0x00000000000000FFULL
#define RANK_2 0x000000000000FF00ULL
#define RANK_3 0x0000000000FF0000ULL
#define RANK_4 0x00000000FF000000ULL
#define RANK_5 0x000000FF00000000ULL
#define RANK_6 0x0000FF0000000000ULL
#define RANK_7 0x00FF000000000000ULL
#define RANK_8 0xFF00000000000000ULL

#define FILE_A 0x8080808080808080ULL
#define FILE_B 0x4040404040404040ULL
#define FILE_C 0x2020202020202020ULL
#define FILE_D 0x1010101010101010ULL
#define FILE_E 0x0808080808080808ULL
#define FILE_F 0x0404040404040404ULL
#define FILE_G 0x0202020202020202ULL
#define FILE_H 0x0101010101010101ULL


typedef enum{
    WHITE,
    BLACK
}TURN;

typedef enum{
    FALSE,
    TRUE
}BOOL;


// piece positions
extern uint64_t Bpawns;
extern uint64_t Brooks;
extern uint64_t Bbishops;
extern uint64_t Bqueens;
extern uint64_t Bking;
extern uint64_t Bknight;
extern uint64_t Wpawns;
extern uint64_t Wrooks;
extern uint64_t Wbishops;
extern uint64_t Wqueens;
extern uint64_t Wking;
extern uint64_t Wknight;

// game rule
extern TURN turn;
extern BOOL BKingSideCastle;
extern BOOL BQueenSideCastle;
extern BOOL WKingSideCastle;
extern BOOL WQueenSideCastle;
extern uint64_t enpassant;

extern uint64_t moves;

void SetupPositions(const char* FEN_STRING);