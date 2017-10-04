//
// Created by malthe on 10/4/17.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <thread>
#include <queue>
#include "Point.cpp"

class Astar {
private:
    const static int COLS = 10;
    const static int ROWS = 13;

    const static int goalX = 8;
    const static int goalY = 11;

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


    


//A* with heuristics
    void aStar() {
        priority_queue <Point, vector<Point>, ComparePoints> queue1;
        Point goal(goalX,goalY, goalX, goalY);
        Point start(playerX,playerY, goalX, goalY);

        queue1.push(start);

        while(!queue1.empty()) {

            Point current = queue1.top();
            visited[current.x()][current.y()] =1;
            printPlayingField();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            playerX = current.x();
            playerY = current.y();
            if(playerX==goalX && playerY==goalY) {
                return;
            }
            current.print(cout);
            cout << current.dist(goal) <<endl;
            queue1.pop();

            Point up(playerX,playerY-1,goalX,goalY);
            Point right(playerX+1,playerY, goalX, goalY);
            Point down(playerX, playerY+1, goalX, goalY);
            Point left(playerX-1,playerY, goalX, goalY);

            if(isValidPosition(up)) {
                queue1.push(up);
            }

            //look right

            if(isValidPosition(right)) {
                queue1.push(right);
            }
            //look down
            if(isValidPosition(down)) {
                queue1.push(down);
            }
            //look left
            if(isValidPosition(left)) {
                queue1.push(left);
            }


        }

    }

    bool isValidPosition(Point point) {
        int test = maze[point.x()][point.y()];
        int test1 = 1;

        if(point.x() >= 0 && point.x() < COLS && point.y() >=0 &&
           point.y() <ROWS && maze[point.x()][point.y()] ==0
           &&visited[point.x()][point.y()] ==0) {
            //&&visited[point.x()][point.y()] ==0
            return true;
        }
        return false;
    }
    bool isValidPosition(int x, int y) {
        int test = maze[x][y];
        int test1 = 1;
        if(x >= 0 && x < COLS && y >=0 && y <ROWS && maze[x][y] ==0 &&visited[x][y] ==0 ) {
            return true;
        }
        return false;
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






};



