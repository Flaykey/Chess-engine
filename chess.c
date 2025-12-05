#include"include/chess.h"
#include<stdio.h>

PIECES board[64];
int selectedMask[64];
int selectedPieceIndex;
int bKingSideCastle;
int bQueenSideCastle;
int wKingSideCastle;
int wQueenSideCastle;
int enpassant;
int gameOver;
int knightmoves[8][2] = {{1,2},{-1,2},{1,-2},{-1,-2},
                         {2,1},{-2,1},{2,-1},{-2,-1}};

int *IndexToCoord(int id)
{
    int x = id % 8;
    int y = id / 8;
    int* res =(int*) malloc(sizeof(int) * 2);
    res[0] = x;
    res[1] = y;
    return res;
}

int CoordToIndex(int* position)
{
    return position[0] + position[1]*8;
}

int MovesCount(uint64_t moves){
    uint64_t temp = moves;
    int count = 0;
    while(temp != 0){
        if( temp & 1ULL ) count++;
        temp = temp >> 1ULL;
    }
    printf("returned number of moves\n");
    return count;
}
int *MovesToIndex(uint64_t moves)
{
    int index = 0;
    int noOfMoves = MovesCount(moves);
    int *moveIndexs = (int*) malloc(noOfMoves*sizeof(int));
    noOfMoves = 0;

    while (moves!= 0)
    {
        if( moves & 1ULL ){ 
            moveIndexs[noOfMoves] = index;
            noOfMoves++;
        }
        index++;
        moves = moves >> 1ULL;
    }
    printf("DONE");
    return moveIndexs;
}
void printBinary(uint64_t x) {
    for (int i = 63; i >= 0; i--) {
        putchar((x & (1ULL << i)) ? '1' : '0');

        // Optional: add space every 8 bits
        if (i % 8 == 0) putchar(' ');
    }
    putchar('\n');
}

uint64_t MoveGeneration(PIECES piece, int index)
{
    uint64_t moves = 0ULL;

    if(piece == BKNIGHT || piece == WKNIGHT){
        int* position = IndexToCoord(index);

        for(int i = 0; i < 8; i++){

            int canMoveCoord[2] = {position[0] + knightmoves[i][0],position[1] + knightmoves[i][1]};
            if(!(canMoveCoord[0] >=0 && canMoveCoord[0] < 8 && canMoveCoord[1] >=0 && canMoveCoord[1] < 8)) continue;

            int canMoveIndex = CoordToIndex(canMoveCoord);
            if(board[canMoveIndex] == EMPTY){ moves |= (1ULL << canMoveIndex);}
            else if((piece >= WPAWN && piece <= WQUEEN) && (board[canMoveIndex] >= BPAWN && board[canMoveIndex] <= BQUEEN)) moves |= (1ULL << canMoveIndex);
            else if((piece >= BPAWN && piece <= BQUEEN) && (board[canMoveIndex] >= WPAWN && board[canMoveIndex] <= WQUEEN)) moves |= (1ULL << canMoveIndex);


            printf("can move indexes : %d",canMoveIndex);

        }
        free(position);
    }
    return moves;
}

