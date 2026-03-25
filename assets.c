#include "assets.h"

Texture2D PiecesTextures[13];
Texture2D TileTextures[4];
void LoadTex()
{   
    PiecesTextures[EMPTY] = LoadTexture("assets/wPawn.png");
    PiecesTextures[WPAWN] = LoadTexture("assets/wPawn.png");
    PiecesTextures[WROOK] = LoadTexture("assets/wRook.png");
    PiecesTextures[WKNIGHT] = LoadTexture("assets/wKnight.png");
    PiecesTextures[WBISHOP] = LoadTexture("assets/wBishop.png");
    PiecesTextures[WQUEEN] = LoadTexture("assets/wQueen.png");
    PiecesTextures[WKING] = LoadTexture("assets/wKing.png");
    PiecesTextures[BPAWN] = LoadTexture("assets/bPawn.png");
    PiecesTextures[BROOK] = LoadTexture("assets/bRook.png");
    PiecesTextures[BKNIGHT] = LoadTexture("assets/bKnight.png");
    PiecesTextures[BBISHOP] = LoadTexture("assets/bBishop.png");
    PiecesTextures[BQUEEN] = LoadTexture("assets/bQueen.png");
    PiecesTextures[BKING] = LoadTexture("assets/bKing.png");

    TileTextures[LIGHT] = LoadTexture("assets/lightSquare.png");
    TileTextures[DARK] = LoadTexture("assets/darkSquare.png");
    TileTextures[LIGHTALT] = LoadTexture("assets/lightSquareALT.png");
    TileTextures[DARKALT] = LoadTexture("assets/darkSquareALT.png");

}

void FreeTex()
{
    for(int i = 0; i< 13; i++){
        UnloadTexture(PiecesTextures[i]);
    }
    for(int i = 0; i< 4; i++){
        UnloadTexture(TileTextures[i]);
    }
}
