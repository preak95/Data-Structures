#include <iostream>

using namespace std;

class Position{
public:
    int row,col;
    Position(int row, int col){
        this->row = row;
        this->col = col;
    }
};

Position* solveNQueenProblem(int n){
    Position* positions[n];
    bool hasSolution = nQueen(n, 0, &positions);
    if(hasSolution = true)
        return &positions;
    else
        return NULL;
}

bool nQueen(int n, int row, Position* positions){
    if(n == row)
        return true;
    int col = 0;
    for(col=0; col<n; col++){
        bool foundSafe = true;
        for(int row = 0; row<n; row++){
            if(positions->)
        }
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
