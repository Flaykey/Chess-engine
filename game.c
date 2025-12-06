#include"include/game.h"

#include<string.h>

Texture2D texArray[13];
TURN turn;
uint64_t moves = 0;

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
    int rulesPart = false;
    for (int i = 0; i < 64; i++)
    {
        board[i] = EMPTY;
        selectedMask[i] = 0;
            
    }
    while(position[fenIndex] != '\0'){
        if(position[fenIndex] > '0' && position[fenIndex] <= '8'){
            boardIndex += position[fenIndex] - '0';
            fenIndex++;
            continue;
        }
        if(rulesPart == true){
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
        case ' ':
            rulesPart = true;
            fenIndex++;
            break;
        default:
            break;
        
        }
    }
}

void loadTexarray()
{
    texArray[EMPTY] = dSquare;
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
                int ox = 0, oy = 0;
                ox = 128 - texArray[board[index]].width;
                oy = 128 - texArray[board[index]].height;
                ox = ox  /  2;
                oy = oy / 2;
                if((i+j) % 2 == 0) DrawTexture(lSquare,x,y,WHITE);
                else DrawTexture(dSquare,x,y,WHITE);
                
                
                if(selectedMask[index] == 1){
                    if((i+j) % 2 == 0) DrawTexture(altLSquare,x,y,WHITE);
                    else DrawTexture(altDSquare,x,y,WHITE);
                }
                
                if(board[index] != EMPTY){
                    DrawTexture(texArray[board[index]],x+ox,y+oy,WHITE);
                }
            }
            
        }
}

void SetSelectedTile(uint64_t m){
    int id = 0;
    while(m != 0){
        if(m & 1ULL) selectedMask[id] = 1;
        m = m>>1ULL;
        id++;
    }
}

void Input()
{
    // movesIndex  = NULL;
    int x = GetMouseX() / 128;
    int y = GetMouseY() / 128;
    if(x < 0 || x >= 8 || y < 0 || y >= 8) return;
    int id =  x+y*8 ;
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && board[id] != EMPTY && selectedMask[id] == 0){
        if((turn == WHITES)&&(!(board[id] >= WPAWN && board[id] <= WQUEEN)))return;
        else if((turn == BLACKS)&&(!(board[id] >= BPAWN && board[id] <= BQUEEN))) return;
        selectedPieceIndex = id;
        moves = 0ULL;
        for(int i = 0 ; i<64 ; i++){
            if( selectedMask[i] == 1) selectedMask[i] = 0;
        }
        moves =  MoveGeneration(board[id],id);
        SetSelectedTile(moves);
    }
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && selectedMask[id] == 1 ){
        turn = !turn;
        if(id == enpassant){
            if(board[selectedPieceIndex] == WPAWN) board[id + 8] = EMPTY;
            if(board[selectedPieceIndex] == BPAWN) board[id - 8] = EMPTY;

        }
        if(board[selectedPieceIndex] == BROOK){
            if(selectedPieceIndex % 8 == 0){
                bQueenSideCastle = false;
            }
            if(selectedPieceIndex % 8 == 7){
                bKingSideCastle = false;
            }
        }
        if(board[selectedPieceIndex] == WROOK){
            if(selectedPieceIndex % 8 == 0){
                wQueenSideCastle = false;
            }
            if(selectedPieceIndex % 8 == 7){
                wKingSideCastle = false;
            }
        }
        if(board[selectedPieceIndex] == BKING){
            if(id % 8 == 2 && (bQueenSideCastle)) {
                board[3] = BROOK;
                board[0] = EMPTY;
            }else if(id % 8 == 6 && (bKingSideCastle)) {
                board[5] = BROOK;
                board[7] = EMPTY;
            }
            bQueenSideCastle = false;
            bKingSideCastle = false;
        }
        if(board[selectedPieceIndex] == WKING){
            if(id % 8 == 2 && (wQueenSideCastle)) {
                board[59] = WROOK;
                board[56] = EMPTY;
            }else if(id % 8 == 6 && (wKingSideCastle)) {
                board[61] = WROOK;
                board[63] = EMPTY;
            }
            wQueenSideCastle = false;
            wKingSideCastle = false;
        }
        if(board[selectedPieceIndex] == WPAWN && selectedPieceIndex - id == 16) enpassant = id + 8;
        else if(board[selectedPieceIndex] == BPAWN && id - selectedPieceIndex == 16) enpassant = id - 8;
        else enpassant = -1;
        printf("\nen passant square %d \n", enpassant);
        
        printf("SELECETED!!\n");
        board[id] = board[selectedPieceIndex];
        board[selectedPieceIndex] = EMPTY;
        selectedPieceIndex = 0;
        for(int i = 0 ; i<64 ; i++){
            if( selectedMask[i] == 1) selectedMask[i] = EMPTY;
        }
    }
}


void InitGame(int w, int h, const char* c)
{
    char p[100];
    char in;
    printf("Custom Starting position? (Y/N): ");
    scanf("%c",&in);
    if(in == 'y' || in == 'Y'){
        printf("Enter FEN string: ");
        scanf(" %[^\n]%*c",p);
        printf("%s",p);
    }else{
        strcpy(p, "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    }
    
    
    InitWindow(w,h,c);
    SetupBoard(board,p);
    PrintRules();
    Image img = LoadImage("assets/wKnight.png");
    SetWindowIcon(img);
    LoadTex();
    loadTexarray();
}

void RunGame()
{
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawBoard(board);  
        EndDrawing();
        Input();
    }
}

void CloseGame()
{
    UnloadTex();
    CloseWindow();
}

void PrintRules(){
    char *t = (turn == WHITES)? "WHITE" : "BLACK";
    printf("TURN: %s\n", t);
    printf("WHITE KINGSIDE CASTLE: %d\n", wKingSideCastle);
    printf("WHITE QUEENSIDE CASTLE: %d\n", wQueenSideCastle);
    printf("BLACK KINGSIDE CASTLE: %d\n", bKingSideCastle);
    printf("BLACK QUEENSIDE CASTLE: %d\n", bQueenSideCastle);
}