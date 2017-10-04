//
// Created by malthe on 10/4/17.
//

#ifndef AI_ASTAR_H
#define AI_ASTAR_H


class Astar {

private:
    const static int COLS = 10;
    const static int ROWS = 13;

    const static int goalX = 8;
    const static int goalY = 11;
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

};


#endif //AI_ASTAR_H
