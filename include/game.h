#pragma once
#include "chess.h"
#include "assets.h"
#include <stdio.h>
#include "defn.h"

extern PIECES board[64];

void SetupGame(char* FEN);
void SetupBoard();
void RunGame();
void DrawBoard();