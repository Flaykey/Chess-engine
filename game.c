#include "game.h"
PIECES board[64];
void SetupGame(char* FEN)
{
    int i = 0;
    SetupPositions(FEN);
    SetupBoard();
    for(i = 0; i < 64; i++ ){
        if(i % 8 == 0) printf("\n");
        printf("%d ",board[i]);
    }
    

    InitWindow(1024,1024,"CHESS");
    LoadTex();
}

void SetupBoard()
{
    int i = 0;
    while(i < 64){

        if(Bbishops & (1ULL << i))board[63-i] = BBISHOP;
        else if(Brooks & (1ULL << i))board[63-i] = BROOK;
        else if(Bknight & (1ULL << i))board[63-i] = BKNIGHT;
        else if(Bqueens & (1ULL << i))board[63-i] = BQUEEN;
        else if(Bking & (1ULL << i))board[63-i] = BKING;
        else if(Bpawns & (1ULL << i))board[63-i] = BPAWN;
        else if(Wbishops & (1ULL << i))board[63-i] = WBISHOP;
        else if(Wrooks & (1ULL << i))board[63-i] = WROOK;
        else if(Wknight & (1ULL << i))board[63-i] = WKNIGHT;
        else if(Wqueens & (1ULL << i))board[63-i] = WQUEEN;
        else if(Wking & (1ULL << i))board[63-i] = WKING;
        else if(Wpawns & (1ULL << i))board[63-i] = WPAWN;
        else board[63-i] = EMPTY;
        i++;
    }
}


void DrawBoard()
{
    //draw Tiles
    for(int y = 0; y < 8; y++){
        for(int x = 0; x < 8; x++){
            int id = x+y*8;
            if(moves &  (1ULL << (63 - id))){
                if((x+y) % 2 == 0 ) DrawTexture(TileTextures[LIGHTALT],x*TILE_SIZE,y*TILE_SIZE,WHITE);
                else DrawTexture(TileTextures[DARKALT],x*TILE_SIZE,y*TILE_SIZE,WHITE);
                continue;
            }
            if((x+y) % 2 == 0 ) DrawTexture(TileTextures[LIGHT],x*TILE_SIZE,y*TILE_SIZE,WHITE);
            else DrawTexture(TileTextures[DARK],x*TILE_SIZE,y*TILE_SIZE,WHITE);
        }
    }

    // Draw Pieces
    for(int y = 0; y < 8; y++){
        for(int x = 0; x < 8; x++){
            int id = x+y*8;
            Texture2D tex =  PiecesTextures[board[id]];
            float xoff = (TILE_SIZE - tex.width) / 2.0;
            float yoff = (TILE_SIZE - tex.height) / 2.0;
            if(board[id] != EMPTY) DrawTexture(tex,x*TILE_SIZE + xoff,y*TILE_SIZE+yoff ,WHITE);
        }
    }
}

void RunGame()
{
    while(!WindowShouldClose()){
        BeginDrawing();
        DrawBoard();
        EndDrawing();
    }
    FreeTex();
    CloseWindow();
}