#include<bits/stdc++.h>
using namespace std;

#define Beginner 0
#define Intermediate 1
#define Advanced 2
#define MaxSide 25
#define MaxMines 99
#define MoveSize 526

int side;
int mines;

bool isValid(int row,int col){
    return (row>=0) && (row<side) && (col>=0) && (col<side);
}

class Board{
    public:
    char** board;
    Board(){
        board = new char*[MaxSide + 1];
        for(int i=0;i<=MaxSide;i++){
            board[i] = new char[MaxSide+1];
            for(int j=0;j<=MaxSide;j++){
                board[i][j] = '-';
            }
        }
    }
};