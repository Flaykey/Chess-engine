#include "chess.h"
#include<stdio.h>

uint64_t Bpawns;
uint64_t Brooks;
uint64_t Bbishops;
uint64_t Bqueens;
uint64_t Bking;
uint64_t Bknight;
uint64_t Wpawns;
uint64_t Wrooks;
uint64_t Wbishops;
uint64_t Wqueens;
uint64_t Wking;
uint64_t Wknight;

TURN turn;
BOOL BKingSideCastle;
BOOL BQueenSideCastle;
BOOL WKingSideCastle;
BOOL WQueenSideCastle;
uint64_t enpassant;

uint64_t moves;

void SetRules(char c){
    switch (c)
    {
    case 'w':
        turn = WHITE;
        return;
    case 'b':
        turn = BLACK;
        return;
    case 'K':
        WKingSideCastle = TRUE;
        return;
    case 'Q':
        WQueenSideCastle = TRUE;
        return;
    case 'k':
        BKingSideCastle = TRUE;
        return;
    case 'q':
        BQueenSideCastle = TRUE;
        return;
    default:
        break;
    }

    // enpassant 
    switch (c)
    {
    case 'a':
        enpassant |= FILE_A;
        break;
    case 'b':
        enpassant |= FILE_B;
        break;
    case 'c': 
        enpassant |= FILE_C;
        break;
    case 'd':
        enpassant |= FILE_D;
        break;
    case 'e':
        enpassant |= FILE_E;
        break;
    case 'f':
        enpassant |= FILE_F;
        break;
    case 'g':
        enpassant |= FILE_G;
        break;
    case 'h':
        enpassant |= FILE_H;
        break;
    default:
        break;
    }

    // if(enpassant != 0){
    //     int n = atoi(&c);
    //     switch (n)
    //     {
        
    //     case 1:
    //         enpassant &= RANK_1;
    //         break;
    //     case 2:
    //         enpassant &= RANK_2;
    //         break;
    //     case 3:
    //         enpassant &= RANK_3;
    //         break;
    //     case 4:
    //         enpassant &= RANK_4;
    //         break;
    //     case 5:
    //         enpassant &= RANK_5;
    //         break;
    //     case 6:
    //         enpassant &= RANK_6;
    //         break;
    //     case 7:
    //         enpassant &= RANK_7;
    //         break;
    //     case 8:
    //         enpassant &= RANK_8;
    //         break;
    //     default:
    //         break;
    //     }
    // }

}
void SetupPositions(const char *FEN_STRING)
{

    WKingSideCastle = FALSE;
    BKingSideCastle = FALSE;
    WQueenSideCastle = FALSE;
    BQueenSideCastle = FALSE;
    enpassant = 0;
    moves = 0;
    int rules = 0;
    int i = 0;
    int bit = 0;
    while(FEN_STRING[i] != '\0'){
        printf("%d\n",bit);
        if(FEN_STRING[i] == '/') {
            i++;
            continue;
        }
        if(FEN_STRING[i] == ' '){
            i++;
            rules = 1;
        }
        if( rules == 0){
            switch (FEN_STRING[i])
            {
            case 'r':
                Brooks |= (1ull  << (63-bit));
                break;
            case 'n':
                Bknight |= (1ull  << (63-bit)) ;
                break;
            case 'b':
                Bbishops |= (1ull  << (63-bit));
                break;
            case 'k':
                Bking |= (1ull  << (63-bit)) ;
                break;
            case 'q':
                Bqueens |= (1ull  << (63-bit));
                break;
            case 'p':
                Bpawns |= (1ull << (63-bit));
                break;
            case 'R':
                Wrooks |= (1ull  << (63-bit));
                break;
            case 'N':
                Wknight |= (1ull  << (63-bit));
                break;
            case 'B':
                Wbishops |= (1ull  << (63-bit));
                break;
            case 'K':
                Wking |= (1ull  << (63-bit));
                break;
            case 'Q':
                Wqueens |= (1ull  << (63-bit));
                break;
            case 'P':
                Wpawns |= (1ull << (63-bit));
                break;
            default:
                break;
        }

            char c = FEN_STRING[i];
            int num = atoi(&c);
            // printf("%d,%c\n",num,c);
            if(num >= 1 && num <= 8){
                bit += num;
            }else{
                bit++;
            }
        }
        else SetRules(FEN_STRING[i]);
        i++;
    }




    printf("Bpawns: %llx\n", Bpawns);
    printf("Brooks: %llx\n", Brooks);
    printf("Bbishops: %llx\n", Bbishops);
    printf("Bqueens: %llx\n", Bqueens);
    printf("Bking: %llx\n", Bking);
    printf("Bknight: %llx\n", Bknight);
    printf("Wpawns: %llx\n", Wpawns);
    printf("Wrooks: %llx\n", Wrooks);
    printf("Wbishops: %llx\n", Wbishops); 
    printf("Wqueens: %llx\n", Wqueens);
    printf("Wking: %llx\n", Wking);
    printf("Wknight: %llx\n", Wknight);

    printf("bk: %d\n", BKingSideCastle);
    printf("bq: %d\n", BQueenSideCastle);
    printf("wk: %d\n", WKingSideCastle);
    printf("wq: %d\n", WQueenSideCastle);

    printf("enpassant: %u\n", enpassant);

}