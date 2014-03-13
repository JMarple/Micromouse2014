#include "RobotModel/RobotModel.h"
#include "DataComponents.h"

#define FORWARD 0
#define REVERSE 1
#define LEFT 2
#define RIGHT 3

#define USELESS 1024

int determineNextMove() {
    int bestDistance = getDistance(mouse.x, mouse.y);
    int bestDirection;

    if ((bestDistance > getNeighborDistance(mouse.x, mouse.y, mouse.direction)) &&
            (isWallFront() == 0)) {
        bestDirection = mouse.direction;
        bestDistance = getNeighborDistance(mouse.x, mouse.y, bestDirection);
    }
    if ((bestDistance > getNeighborDistance(mouse.x, mouse.y, NORTH)) &&
            (getN() == 0)) {
        bestDirection = NORTH;
        bestDistance = getNeighborDistance(mouse.x, mouse.y, bestDirection);
    }
    if ((bestDistance > getNeighborDistance(mouse.x, mouse.y, EAST)) &&
            (getE() == 0)) {
        bestDirection = EAST;
        bestDistance = getNeighborDistance(mouse.x, mouse.y, bestDirection);
    }
    if ((bestDistance > getNeighborDistance(mouse.x, mouse.y, WEST)) &&
            (getW() == 0)) {
        bestDirection = WEST;
        bestDistance = getNeighborDistance(mouse.x, mouse.y, bestDirection);
    }
    if ((bestDistance > getNeighborDistance(mouse.x, mouse.y, SOUTH)) &&
            (getS() == 0)) {
        bestDirection = SOUTH;
        bestDistance = getNeighborDistance(mouse.x, mouse.y, bestDirection);
    }
    
    return bestDirection;
}

int getNeighborDistance(int x, int y, int direction) {
    int neighbor;
    if ((direction == NORTH) && (y != 1)) {
        neighbor = cells[x][y - 1];
    } else if ((direction == SOUTH) && (y != 16)) {
        neighbor = cells[x][y + 1];
    } else if ((direction == EAST) && (x != 16)) {
        neighbor = cells[x + 1][y];
    } else if ((direction == WEST) && (x != 1)) {
        neighbor = cells[x - 1][y];
    } else {
        return USELESS;
    }

    return getDistance(neighbor);
}

int getDistance(int x, int y) {
    return cells[x - 1][y - 1].;
}