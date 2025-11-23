#include"include/game.h"

PIECES board[64];
Texture2D texArray[13];
TURN turn;
int bKingSideCastle;
int bQueenSideCastle;
int wKingSideCastle;
int wQueenSideCastle;
int enpassant;
int gameOver;



void SetupBoard(PIECES *board, const char* position)
{
    bKingSideCastle = false;
    bQueenSideCastle = false;
    wKingSideCastle = false;
    wQueenSideCastle = false;
    enpassant = false;
    gameOver = false;
    int fenIndex = 0;
    int boardIndex = 0;
    for (int i = 0; i < 64; i++)
    {
        board[i] = EMPTY;
            
    }
    while(position[fenIndex] != '\0'){
        if(position[fenIndex] > '0' && position[fenIndex] <= '8'){
            boardIndex += position[fenIndex] - '0';
            fenIndex++;
            continue;
        }
        if(boardIndex >= 64){
            switch (position[fenIndex])
            {
                case 'w':
                    turn = WHITES;
                    break;
                case 'b':
                    turn = BLACKS;
                    break;
                case 'K':
                    wKingSideCastle = true;
                    break;
                case 'Q':
                    wQueenSideCastle = true;
                    break;
                case 'k':
                    bKingSideCastle = true;
                    break;
                case 'q':
                    bQueenSideCastle = true;
                    break;
                default:
                    break;
            }
            fenIndex++;
            continue;
        }
        switch (position[fenIndex])
        {
        case 'p':
            board[boardIndex] = BPAWN;
            boardIndex++;
            fenIndex++;
            break;
        case 'r':
            board[boardIndex] = BROOK;
            boardIndex++;
            fenIndex++;
            break;
        case 'n':
            board[boardIndex] = BKNIGHT;
            boardIndex++;
            fenIndex++;
            break;
        case 'b':
            board[boardIndex] = BBISHOP;
            boardIndex++;
            fenIndex++;
            break;
        case 'k':
            board[boardIndex] = BKING;
            boardIndex++;
            fenIndex++;
            break;
        case 'q':
            board[boardIndex] = BQUEEN;
            boardIndex++;
            fenIndex++;
            break;
        case 'P':
            board[boardIndex] = WPAWN;
            boardIndex++;
            fenIndex++;
            break;
        case 'R':
            board[boardIndex] = WROOK;
            boardIndex++;
            fenIndex++;
            break;
        case 'N':
            board[boardIndex] = WKNIGHT;
            boardIndex++;
            fenIndex++;
            break;
        case 'B':
            board[boardIndex] = WBISHOP;
            boardIndex++;
            fenIndex++;
            break;
        case 'K':
            board[boardIndex] = WKING;
            boardIndex++;
            fenIndex++;
            break;
        case 'Q':
            board[boardIndex] = WQUEEN;
            boardIndex++;
            fenIndex++;
            break;
        case '/':
            fenIndex++;
            break;
        default:
            break;
        
        }
   }
}

void loadTexarray()
{
    // texArray[0] = NULL;
    texArray[BPAWN] = bPawn;
    texArray[BROOK] = bRook;
    texArray[BKNIGHT] = bKnight;
    texArray[BBISHOP] = bBishop;
    texArray[BKING] = bKing;
    texArray[BQUEEN] = bQueen;
    texArray[WPAWN] = wPawn;
    texArray[WROOK] = wRook;
    texArray[WKNIGHT] = wKnight;
    texArray[WBISHOP] = wBishop;
    texArray[WKING] = wKing;
    texArray[WQUEEN] = wQueen;

}

void DrawBoard(PIECES *board)
{
    int x = 0, y = 0;
    for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                x = j*128,y= i*128;
                int index = j+i*8;
                if((i+j) % 2 == 0) DrawTexture(lSquare,x,y,WHITE);
                else DrawTexture(dSquare,x,y,WHITE);
                if(board[index] != EMPTY){
                    DrawTexture(texArray[board[index]],x,y,WHITE);
                }
            }
            
        }
}

void Input()
{
    int x = GetMouseX() / 128;
    int y = GetMouseY() / 128;
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        printf("index : %d piece: %d\n", x+y*8 ,board[x+y*8]);
    }
}

void InitGame(int w, int h, const char* c, const char* p)
{
    InitWindow(w,h,c);
    SetupBoard(board,p);
    LoadTex();
    loadTexarray();
}

void RunGame()
{
    while(!WindowShouldClose())
    {
        Input();
        BeginDrawing();
        ClearBackground(BLACK);
        DrawBoard(board);  
        EndDrawing();
    }
}

void CloseGame()
{
    UnloadTex();
    CloseWindow();
}
