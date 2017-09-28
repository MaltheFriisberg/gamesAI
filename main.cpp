#include <iostream>
#include <vector>
#include <fstream>
#include "week2/Cell.h"

const int COLS = 10;
const int ROWS = 13;

int maze[COLS][ROWS] = {

        {1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,1,0,1,0,1,0,0,0,0,0,1},
        {1,0,1,0,0,0,1,0,1,1,1,0,1},
        {1,0,0,0,1,1,1,0,0,0,0,0,1},
        {1,0,1,0,0,0,0,0,1,1,1,0,1},
        {1,0,1,0,1,1,1,0,1,0,0,0,1},
        {1,0,1,0,1,0,0,0,1,1,1,0,1},
        {1,0,1,0,1,1,1,0,1,0,1,0,1},
        {1,0,0,0,0,0,0,0,0,0,1,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void printPlayingField();


using namespace std;

int main() {

    printPlayingField();
    return 0;
}

void printPlayingField() {
    for(int i = 0; i <COLS; i++) {
        for(int j = 0; j< ROWS; j++) {
            int x = maze[i][j];
            int y;
            if(x > 0) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout<<""<<endl;
    }
}



/*void displayMaze() {
    // Do the following to display the maze:
    int r, c;
    for (c=0; c<COLS; c++) {
        if (c == 0) cout << " _";
        else cout << "__";
    }
    cout << '\n';
    for (r=0; r<ROWS; r++) {
        for (c=0; c<COLS; c++) {
            if(!maze[r][c].isStart  && !maze[r][c].isGoal) {
                cout << maze[r][c];

            }else if(maze[r][c].isStart) {
                cout << "*";
            } else if(maze[r][c].isGoal) {
                cout << "G";
            }
        }
        cout << "|\n";
    }
}*/

//13 bred 10 dyb
/*int maze[13][10];
int playerXpos, playerYpos;
int goalXpos, goalYpos;

void hardcodePlayingField();
void printPlayingField();
void setupMaze();
void displayMaze();
void setVisitedFalse();
void startDFS();
bool DFS(Cell cell);

const int ROWS = 20;
const int COLS = 20;
Cell maze[ROWS][COLS];

enum DIR { NORTH, SOUTH, EAST, WEST };

int main() {
    cout << "starting game" <<endl;
    //hardcodePlayingField();
    //printPlayingField();

    setupMaze();
    startDFS();
    displayMaze();


    return 0;
}

void startDFS() {
    DFS(maze[playerXpos][playerYpos]);
}

bool DFS(Cell cell) {
    cell.setVisited(true);
    if(!cell.isGoal) {

    }
}

void setupMaze() {
    // variables
    int ran_dir;

    // Randomize the random number function.
    srand(time(NULL));

    // Create a 2-D array ([ROWS][COLS]) of Cell objects.

    // For each Cell in the maze:
    for(int row = 0; row < ROWS; row++)
        for(int col = 0; col < COLS; col++) {
            // set visited to false
            maze[row][col].setVisited(false);
            // set its position to its row and column in the maze
            maze[row][col].setPosition(row, col);
            // set the Cell's walls to Cell::WALL_ALL
            maze[row][col].setWalls(Cell::WALL_ALL);
        }

    //Create curX and curY variables and set them to a random position in the maze.
    int curX = rand() % ROWS;
    int curY = rand() % COLS;
    bool goalSet = false;

    // Create a vector of Cell objects named trail which will be used as a stack.
    vector<Cell> trail;

    // Create a vector of DIR values named live.
    vector<DIR> live;

    //Set Start state
    maze[curX][curY].isStart = true;
    playerXpos = curX;
    playerYpos = curY;
    // Grab the Cell at the curX, curY position and push it on the trail stack.
    trail.push_back(maze[curX][curY]);

    // While the trail stack is not empty do the following:
    while(trail.empty()==false) { // stay in here till display
        // Empty the live vector.
        live.clear();
        // Check the neighbors of the current cell to the north, east, south, and west.
        // If any of the neighbors have all four walls, add the direction to that
        // neighbor to the live vector.
        if(curY)
            if(maze[curX][curY-1].getWalls()==Cell::WALL_ALL) // West has all walls
                live.push_back(WEST);
        if(curY<COLS-1)
            if(maze[curX][curY+1].getWalls()==Cell::WALL_ALL) // east has all walls
                live.push_back(EAST);
        if(curX)
            if(maze[curX-1][curY].getWalls()==Cell::WALL_ALL) // North has all walls
                live.push_back(NORTH);
        if(curX<ROWS-1)
            if(maze[curX+1][curY].getWalls()==Cell::WALL_ALL) // South has all walls
                live.push_back(SOUTH);
        // If the live vector is not empty:
        if(live.empty()==false) {
            // Choose one of the directions in the live vector at random
            // ran_dir=rand() % live.size();
            // cout << "Random dir " << ran_dir << " out of " << live.size() << "\n";
            // Remove the walls between the current cell and the neighbor in that direction
            // and Change curX and curY to refer to the neighbor
            maze[curX][curY].setVisited(true);
            switch(live[rand() % live.size()]) {
                case 0:
                    maze[curX][curY].removeWall(Cell::WALL_NORTH);
                    maze[--curX][curY].removeWall(Cell::WALL_SOUTH);
                    break;
                case 1:
                    maze[curX][curY].removeWall(Cell::WALL_SOUTH);
                    maze[++curX][curY].removeWall(Cell::WALL_NORTH);
                    break;
                case 2:
                    maze[curX][curY].removeWall(Cell::WALL_EAST);
                    maze[curX][++curY].removeWall(Cell::WALL_WEST);
                    break;
                case 3:
                    maze[curX][curY].removeWall(Cell::WALL_WEST);
                    if(!goalSet) {
                        maze[curX][curY].isGoal = true;
                        goalXpos = curX;
                        goalYpos = curY;
                        goalSet = true;
                    }

                    maze[curX][--curY].removeWall(Cell::WALL_EAST);
                    break;
            }
            // Push the new current cell onto the trail stack

            trail.push_back(maze[curX][curY]);
        } //If the live vector was emtpy:
        else {
            // Pop the top item from the trail stack
            trail.pop_back();

            // If the trail stack is not empty, set curX and curY to refer to the
            // position of the top item in the trail stack.
            if(trail.empty()==false) {
                curX=trail[0].getRow();
                curY=trail[0].getColumn();
            }
        }
    }
    setVisitedFalse();

}


void setVisitedFalse() {
    for(int i= 0; i<ROWS; i++) {
        for(int j = 0; j<COLS; j++) {
            Cell cell = maze[i][j];
            cell.setVisited(false);
        }
    }
}*/

/*void hardcodePlayingField() {
    for(int i = 0; i < 10; i++) {
        maze[0][i]+=1;
        maze[12][i]+=1;
    }
    for(int j = 1; j < 13; j++) {
        maze[j][0]+=1;
        maze[j][9]+=1;
    }
    maze[2][1]+=1;
    maze[4][1]+=1;
    maze[6][1]+=1;

    maze[2][2]+=1;
    maze[6][2]+=1;
    maze[8][2]+=1;
    maze[9][2]+=1;
    maze[10][2]+=1;






}

void printPlayingField() {
    for(int i = 0; i <10; i++) {
        for(int j = 0; j< 13; j++) {
            int x = maze[j][i];
            int y;
            if(x > 0) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout<<""<<endl;
    }
}*/

/*void hardcodePlayingField() {
    for(int i = 0; i < 10; i++) {
        maze[0][i]+=1;
        maze[12][i]+=1;
    }
    for(int j = 1; j < 13; j++) {
        maze[j][0]+=1;
        maze[j][9]+=1;
    }
    maze[2][1]+=1;
    maze[4][1]+=1;
    maze[6][1]+=1;

    maze[2][2]+=1;
    maze[6][2]+=1;
    maze[8][2]+=1;
    maze[9][2]+=1;
    maze[10][2]+=1;






}*/



