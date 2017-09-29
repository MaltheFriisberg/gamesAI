#include <iostream>
#include <vector>
#include <fstream>
#include <thread>
#include "week2/Cell.h"

const int COLS = 10;
const int ROWS = 13;

const int goalX = 8;
const int goalY = 11;

struct Position{
    int x;
    int y;
};


int playerX, playerY;

int visited[COLS][ROWS];

int maze[COLS][ROWS] = {

        {1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,1,0,1,0,1,0,0,0,0,0,1},
        {1,0,1,0,0,0,1,0,1,1,1,0,1},
        {1,0,0,0,1,1,1,0,0,0,0,0,1},
        {1,0,1,0,0,0,0,0,1,1,1,0,1},
        {1,0,1,0,1,1,1,0,1,0,0,0,1},
        {1,0,1,0,1,0,0,0,1,0,1,0,1},
        {1,0,1,0,1,1,1,0,1,0,1,0,1},
        {1,0,0,0,0,0,0,0,0,0,1,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void printPlayingField();
bool dfs(int x, int y);
bool isValidPosition(int x, int y);
//void clearScreen();
int distance(int x, int y);

using namespace std;

int main() {
    playerX =3;
    playerY = 2;

    dfs(playerX, playerY);
    return 0;
}

bool dfs(int x, int y) {
    if(x== goalX && y == goalY) {
        return true;
    }
    playerX = x;
    playerY = y;
    visited[x][y]=1;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    //clearScreen();
    printPlayingField();
    int distanceToGoal = distance(x, y);
    cout << "{" << x << " , " << y << "} " << "distance to goal is " << distanceToGoal <<endl;
    //look up
    if(isValidPosition(x,y+1) && dfs(x,y+1)) {
        return true;
    }

    //look right
    if(isValidPosition(x+1,y) &&dfs(x+1,y)) {
        return true;
    }
    //look down
    if(isValidPosition(x,y+1) && dfs(x,y+1)) {
        return true;
    }
    //look left
    if(isValidPosition(x-1,y) && dfs(x-1,y)) {
        return true;
    }
    cout << "{" << x << " , " << y <<"}"<<endl;
    return false;
}

int distance(int xs, int ys) {
    int xdistance = abs(goalX -xs);
    int ydistance = abs(goalY -ys);

    int result = xdistance + ydistance;
    return result;
}

char decideDirection(int x, int y) {

}

bool isValidPosition(int x, int y) {
    int test = maze[x][y];
    int test1 = 1;
    if(x >= 0 && x < COLS && y >=0 && y <ROWS && maze[x][y] ==0 &&visited[x][y] ==0 ) {
        return true;
    }
    return false;
}



void printPlayingField() {
    for(int i = 0; i <COLS; i++) {
        for(int j = 0; j< ROWS; j++) {
            int x = maze[i][j];
            int y;
            if(i==goalX && j==goalY) {
                cout << 'g';
            } if(i==playerX && j==playerY) {
                cout << 'p';
            } else if(x > 0) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout<<""<<endl;
    }
}

void clearScreen()
{
    int n;
    for (n = 0; n < 10; n++)
        printf( "\n\n\n\n\n\n\n\n\n\n" );
}

