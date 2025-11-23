#include"include/game.h"

int main(){
    InitGame(1024,1024,"chess","rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    RunGame();
    CloseGame();
    return 0;
}
