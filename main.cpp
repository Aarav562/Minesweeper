#include<bits/stdc++.h>
using namespace std;


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

    bool isMine(int row,int col){
        if(board[row][col] == '*'){
            return true;
        }
        else{
            return false;
        }
    }

    void makeMove(int* x,int* y){
        cout<<"Enter Your Move: (row, column) -> ";
        scanf("%d%d",x,y);
        return;
    }

    void printBoard(){
        int i,j;
        cout<<" ";
        for(i=0;i<side;i++){
            cout<<i;
        }
        cout<<"\n\n";

        for(i=0;i<side;i++){
            cout<<i;
            for(j=0;j<side;j++){
                cout<<board[i][j];
            }
            cout<<"\n";
        }
        return;
    }

    int countMines(int row,int col,int mines[][2]){
        int i;
        int count =0;


        int dx[8] = {-1,-1,-1,0,0,1,1,1};
        int dy[8] = {-1,0,1,-1,1,-1,0,1};

        for(int d = 0;d<8;d++){
            int newRow = row + dx[d];
            int newCol = row + dy[d];

            if(isValid(newRow,newCol)==true){
                if(isMine(newRow,newCol)==true){
                    count++;
                }
            }
        }
        return count;
    }

    void placeMines(int Mines[][2]){
        bool mark[MaxSide*MaxSide];

        memset(mark,false,sizeof(mark));

        for(int i=0;i<mines;){
            int random = rand() % (side * side);
            int x = random/side;
            int y = random%side;

            if(mark[random] == false){
                Mines[i][0] = x;
                Mines[i][1] = y;

                board[Mines[i][0]][Mines[i][1]] = '*';
                mark[random] = true;
                i++;
            }
        }
        return;
    }

    void replaceMine(int row,int col){
        for(int i=0;i<side;i++){
            for(int j=0;j<side;j++){
                if(board[i][j]!='*'){
                    board[i][j]= '*';
                    board[row][col] = '-';
                    return;
                }
            }
        }
    }
};

void chooseDifficulty(){
    int level;
    cout<<"<-----------------Welcome To Minesweeper----------------------->"<<endl;
    cout<<"Enter the Difficulty Level: "<<endl;
    cout<<"Press 0 For Beginner."<<endl;
    cout<<"Press 1 For Intermediate."<<endl;
    cout<<"Press 2 For Advanced."<<endl;
    cin>>level;

    if(level == 0){
        side = 9;
        mines = 10;
    }

    if(level == 1){
        side = 16;
        mines = 40;
    }

    if(level == 2){
        side = 24;
        mines = 99;
    }
}