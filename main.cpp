#include <iostream>
#include <vector>
#include <fstream>
#include <thread>
#include <queue>
#include "week2/Cell.h"
#include "cmake-build-debug/week4/Point.cpp"

const int COLS = 10;
const int ROWS = 13;

const int goalX = 8;
const int goalY = 11;

class ComparePoints{
public:
    bool operator()(Point& t1, Point& t2)
    {

        Point goal(goalX, goalY);

        if (t1.dist(goal) < t2.dist(goal)) return true;
        if (t1.dist(goal) == t2.dist(goal)) return true;
        //if (t1.h == t2.h && t1.m == t2.m && t1.s < t2.s) return true;
        return false;
    }
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
char decideDirection(Point p);
void bfs();
using namespace std;

int main() {
    playerX =3;
    playerY = 2;
    bfs();
    //dfs(playerX, playerY);
    return 0;
}
//with heuristics
void bfs() {
    priority_queue <Point, vector<Point>, ComparePoints> queue1;
    Point goal(goalX,goalY);
    Point zero(0,0);
    Point up(playerX,playerY+1,goalX,goalY);
    Point right(playerX+1,playerY, goalX, goalY);
    Point down(playerX, playerY+1, goalX, goalY);
    Point left(playerX-1,playerY, goalX, goalY);

    queue1.push(zero);
    queue1.push(up);
    queue1.push(right);
    queue1.push(down);
    queue1.push(left);

    while(!queue1.empty()) {
        Point point = queue1.top();
        point.print(cout);
        cout << point.dist(goal);
        queue1.pop();
    }

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
    Point p(x,y);
    //char direction = decideDirection(p);
    //cout << "{" << x << " , " << y << "} " << "distance to goal is " << distanceToGoal <<" going "<<direction<< endl;
    Point up(x,y+1);
    Point right(x+1,y);
    Point down(x, y+1);
    Point left(x-1,y);
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

char decideDirection(Point p, Point p1) {

    //up
    /*Point up(p.x(),p.y()-1);
    Point right(p.x()+1, p.y());
    Point down(p.x(), p.y()+1);
    Point left(p.x()-1,p.y());
    Point goal(goalX, goalY);

    if(up.dist(goal) > right.dist(goal) && up.dist(goal) > left.dist(goal)
       && up.dist(goal) > down.dist(goal)) {
        return 'u';
    } else if(right.dist(goal) > up.dist(goal) && right.dist(goal) > left.dist(goal)
              && right.dist(goal) > down.dist(goal)) {
        return 'r';
    } else if(left.dist(goal) > up.dist(goal) && left.dist(goal) > right.dist(goal)
              && left.dist(goal) > down.dist(goal)) {
        return 'l';
    }
    return 'd';*/
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

