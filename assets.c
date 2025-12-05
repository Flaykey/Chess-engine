#include "include/assets.h"
Texture2D dSquare,lSquare,altDSquare,altLSquare;
Texture2D wPawn,wRook,wKnight,wBishop,wKing,wQueen,bPawn,bRook,bKnight,bBishop,bKing,bQueen;
void LoadTex()
{   dSquare = LoadTexture("assets/darkSquare.png");
    lSquare = LoadTexture("assets/lightSquare.png");
    altDSquare = LoadTexture("assets/darkSquareALT.png");
    altLSquare = LoadTexture("assets/lightSquareALT.png");
    wPawn = LoadTexture("assets/wPawn.png");
    wRook = LoadTexture("assets/wRook.png");
    wKnight = LoadTexture("assets/wKnight.png");
    wBishop = LoadTexture("assets/wBishop.png");
    wKing = LoadTexture("assets/wKing.png");
    wQueen = LoadTexture("assets/wQueen.png");
    bPawn = LoadTexture("assets/bPawn.png");
    bRook = LoadTexture("assets/bRook.png");
    bKnight = LoadTexture("assets/bKnight.png");
    bBishop = LoadTexture("assets/bBishop.png");
    bKing = LoadTexture("assets/bKing.png");
    bQueen = LoadTexture("assets/bQueen.png");
}

void UnloadTex()
{
    UnloadTexture(dSquare);
    UnloadTexture(lSquare);
    UnloadTexture(altDSquare);
    UnloadTexture(altLSquare);
    UnloadTexture(wPawn);
    UnloadTexture(wRook);
    UnloadTexture(wKnight);
    UnloadTexture(wBishop);
    UnloadTexture(wKing);
    UnloadTexture(wQueen);
    UnloadTexture(bPawn);
    UnloadTexture(bRook);
    UnloadTexture(bKnight);
    UnloadTexture(bBishop);
    UnloadTexture(bKing);
    UnloadTexture(bQueen);

}
